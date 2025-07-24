#include <iostream>
using namespace std;

int main() {
    char input[10000];

    cout << "Enter a line: ";
    cin.getline(input, 10000);

    if (input[0] == '/' && input[1] == '/') {
        cout << "This is a single-line comment." << endl;
    }
    else if (input[0] == '/' && input[1] == '*') {
        int i;
        for (i = 2; input[i] != '\0'; i++) {
            if (input[i] == '*' && input[i + 1] == '/') {
                cout << "This is a multi-line comment." << endl;
                return 0;
            }
        }
    }
    else {
        cout << "This is not a comment." << endl;
    }

    return 0;
}


