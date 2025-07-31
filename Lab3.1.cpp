#include <iostream>
#include <cstdio> // for FILE, fopen, fgets, fclose
using namespace std;

// Keywords, operators, punctuations
const char* keywords[] = {"int", "float", "if", "else", "while", "return", "char", "void"};
const char* operators[] = {"+", "-", "*", "/", "=", "==", "++", "--"};
const char punctuations[] = {';', ',', '(', ')', '{', '}'};

// Compare two strings manually
int match(const char* a, const char* b) {
    int i = 0;
    while (a[i] && b[i]) {
        if (a[i] != b[i]) return 0;
        i++;
    }
    return a[i] == b[i];
}

// Check if character is a letter
int isLetter(char ch) {
    return (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122); // A-Z or a-z
}

// Check if character is a digit
int isDigit(char ch) {
    return ch >= 48 && ch <= 57;
}

// Check if character is underscore
int isUnderscore(char ch) {
    return ch == 95;
}

// Check if token is a keyword
int isKeyword(const char* str) {
    for (int i = 0; i < 8; i++) {
        if (match(str, keywords[i])) return 1;
    }
    return 0;
}

// Check if token is an operator
int isOperator(const char* str) {
    for (int i = 0; i < 8; i++) {
        if (match(str, operators[i])) return 1;
    }
    return 0;
}

// Check if token is punctuation
int isPunctuation(const char* str) {
    if (str[1] != '\0') return 0;
    for (int i = 0; i < 6; i++) {
        if (str[0] == punctuations[i]) return 1;
    }
    return 0;
}

// Check if valid identifier using ASCII values
int isValidIdentifier(const char* str) {
    if (!(isLetter(str[0]) || isUnderscore(str[0]))) return 0;
    for (int i = 1; str[i]; i++) {
        if (!(isLetter(str[i]) || isDigit(str[i]) || isUnderscore(str[i]))) return 0;
    }
    return 1;
}

// Remove newline from fgets line
void removeNewline(char* str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] == '\n' || str[i] == '\r') {
            str[i] = '\0';
            break;
        }
    }
}

int main() {
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        cout << "Could not open input.txt\n";
        return 1;
    }

    char line[100];
    while (fgets(line, 100, file)) {
        removeNewline(line); // remove newline from end
        if (line[0] == '\0') continue; // skip empty lines

        // Classify the token
        if (isKeyword(line)) cout << line << " : Keyword\n";
        else if (isOperator(line)) cout << line << " : Operator\n";
        else if (isPunctuation(line)) cout << line << " : Punctuation\n";
        else if (isValidIdentifier(line)) cout << line << " : Valid Identifier\n";
        else cout << line << " : Invalid Identifier / Unknown\n";
    }

    fclose(file); // close file
    return 0;
}
