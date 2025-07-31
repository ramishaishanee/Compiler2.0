
#include <iostream>
#include <cstdio> // for FILE, fopen, fgets, fclose
using namespace std;

// Predefined keywords, operators, punctuations
const char* keywords[] = {"int", "float", "if", "else", "while", "return", "char", "void"};
const char* operators[] = {"+", "-", "*", "/", "=", "==", "++", "--"};
const char punctuations[] = {';', ',', '(', ')', '{', '}'};

// Match two strings
int match(const char* a, const char* b) {
    int i = 0;
    while (a[i] && b[i]) {
        if (a[i] != b[i]) return 0;
        i++;
    }
    return a[i] == b[i];
}

// ASCII check: is letter
int isLetter(char ch) {
    return (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122);
}

// ASCII check: is digit
int isDigit(char ch) {
    return (ch >= 48 && ch <= 57);
}

// ASCII check: is underscore
int isUnderscore(char ch) {
    return ch == 95;
}

// Check keyword
int isKeyword(const char* str) {
    for (int i = 0; i < 8; i++) {
        if (match(str, keywords[i])) return 1;
    }
    return 0;
}

// Check operator
int isOperator(const char* str) {
    for (int i = 0; i < 8; i++) {
        if (match(str, operators[i])) return 1;
    }
    return 0;
}

// Check punctuation
int isPunctuation(const char* str) {
    if (str[1] != '\0') return 0;
    for (int i = 0; i < 6; i++) {
        if (str[0] == punctuations[i]) return 1;
    }
    return 0;
}

// Check valid identifier
int isValidIdentifier(const char* str) {
    if (!(isLetter(str[0]) || isUnderscore(str[0]))) return 0;
    for (int i = 1; str[i]; i++) {
        if (!(isLetter(str[i]) || isDigit(str[i]) || isUnderscore(str[i]))) return 0;
    }
    return 1;
}

// Remove newline at end
void removeNewline(char* str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] == '\n' || str[i] == '\r') {
            str[i] = '\0';
            break;
        }
    }
}

// Manual token splitter
void splitAndClassify(char* line) {
    int i = 0, j = 0;
    char token[100];

    while (1) {
        char ch = line[i];

        // End of line or space = end of token
        if (ch == ' ' || ch == '\0') {
            if (j > 0) {
                token[j] = '\0'; // null-terminate token

                // Classify token
                if (isKeyword(token)) cout << token << " : Keyword\n";
                else if (isOperator(token)) cout << token << " : Operator\n";
                else if (isPunctuation(token)) cout << token << " : Punctuation\n";
                else if (isValidIdentifier(token)) cout << token << " : Valid Identifier\n";
                else cout << token << " : Invalid Identifier / Unknown\n";

                j = 0; // reset token index
            }

            if (ch == '\0') break; // stop at end of line
        } else {
            token[j++] = ch; // build token character by character
        }

        i++;
    }
}

int main() {
    FILE* file = fopen("input40.txt", "r");
    if (file == NULL) {
        cout << "Could not open input.txt\n";
        return 1;
    }

    char line[200];

    while (fgets(line, 200, file)) {
        removeNewline(line);
        if (line[0] == '\0') continue; // skip empty lines

        splitAndClassify(line); // process all tokens in the line
    }

    fclose(file);
    return 0;
}
