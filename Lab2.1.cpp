#include <iostream>
using namespace std;

int main() {
    string input;

    cout << "Enter input: ";
    cin >> input;

    // Checking characters
    for (int i = 0; i < (int)input.length(); i++) {
        if (input[i] < 48 || input[i] > 57) {
            cout << "This is not a numeric constant." << endl;
            return 0;
        }
    }
    cout << "This is a numeric constant." << endl;

    return 0;
}

