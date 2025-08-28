#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Step 1: Declare at least 5 keywords
    const char *keywords[] = {"int", "char", "bool", "float", "double"};
    int keywordCount = 5;

    ifstream file("input.txt");  // input.txt will contain your test cases
    if (!file) {
        cout << "Error: input.txt not found!" << endl;
        return 0;
    }

    char str[100];

    // Step 2: Read each line from file
    while (file.getline(str, 100)) {
        int i = 0;

        // Skip spaces
        while (str[i] == ' ') i++;

        // Check for valid keyword
        bool validKeyword = false;

        for (int k = 0; k < keywordCount; k++) {
            int j = 0;
            int temp = i;
            while (keywords[k][j] != '\0' && str[temp] == keywords[k][j]) {
                j++;
                temp++;
            }
            if (keywords[k][j] == '\0') { // full keyword matched
                validKeyword = true;
                i = temp;
                break;
            }
        }

        if (!validKeyword) {
            cout << str << "  --> Incorrect declaration" << endl;
            continue;
        }

        // Skip spaces after keyword
        while (str[i] == ' ') i++;

        // Function name check
        if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))) {
            cout << str << "  --> Incorrect declaration" << endl;
            continue;
        }

        while ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            i++;
        }

        // Skip spaces
        while (str[i] == ' ') i++;

        // Must have ()
        if (str[i] != '(' || str[i+1] != ')') {
            cout << str << "  --> Incorrect declaration" << endl;
            continue;
        }
        i += 2;

        // Skip spaces
        while (str[i] == ' ') i++;

        // Check ending
        if (str[i] == ';' && str[i+1] == '\0') {
            cout << str << "  --> Correct declaration" << endl;
        }
        else if (str[i] == '{' && str[i+1] == '}' && str[i+2] == '\0') {
            cout << str << "  --> Correct declaration" << endl;
        }
        else {
            cout << str << "  --> Incorrect declaration" << endl;
        }
    }

    file.close();
    return 0;
}
