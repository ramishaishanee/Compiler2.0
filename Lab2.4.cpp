#include <iostream>
using namespace std;

int main() {
    char input[10000];
    int length = 0;
    cin >> input;

    while (input[length] != '\0') {
        length++;
    }

    if (length == 0) {
        cout << "Not an identifier." << endl;
        return 0;
    }

    if (!((input[0] >= 'A' && input[0] <= 'Z') ||
          (input[0] >= 'a' && input[0] <= 'z') ||
          input[0] == '_')) {
        cout << "Not an identifier." << endl;
        return 0;
    }

    for (int i = 1; i < length; i++) {
        if (!((input[i] >= 'A' && input[i] <= 'Z') ||
              (input[i] >= 'a' && input[i] <= 'z') ||
              (input[i] >= '0' && input[i] <= '9') ||
              input[i] == '_')) {
            cout << "Not an identifier." << endl;
            return 0;
        }
    }

    cout << "This is an identifier." << endl;
    return 0;
}
