#include <iostream>
using namespace std;

int main() {
    char input[100];
    cout << "Enter input: ";
    cin.getline(input, 10000);

    for (int i = 0; input[i] != '\0'; i++) {
        char ch = input[i];
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            cout << ch << " = operator" << endl;
        } else {
            cout << ch << " = not operator" << endl;
        }
    }

    return 0;
}

