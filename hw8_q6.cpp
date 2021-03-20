//
// Created by Yegor Chernyshev on 2/27/21.
// 

#include <iostream>
#include <string>

using namespace std;

// Constants
const int MIN_ASCII = 48;   // ASCII Value of 0
const int MAX_ASCII = 57;   // ASCII Value of 9
const char space = ' ';

// Function Declarations
string redactNumbers(string& text);
bool stringHasOnlyDigits(string str);
void redactString(string& str);

int main() {

    string lineOfText, cypheredText;

    cout<<"Please enter a line of text:"<<endl;
    getline(cin, lineOfText);

    cypheredText = redactNumbers(lineOfText);
    cout<<cypheredText<<endl;

    return 0;

}

string redactNumbers(string& text) {
    int index = 0;

    int startOfSubString, endOfSubString = 0;
    string redactedString, substring;

    while (index <= text.length()) {

        if (text[index] == space || index == text.length()) {
            // Space is reached or it is the end of the entire string -> Evaluate the previous word

            startOfSubString = endOfSubString;
            endOfSubString = index;

            // Loop Through the Substring -> Evaluate if it is only full of digits
            substring = text.substr(startOfSubString, (endOfSubString - startOfSubString));
            if (stringHasOnlyDigits(substring)) {
                redactString(substring);
            }

            redactedString += substring;
        }

        index++;
    }

    return redactedString;
}

bool stringHasOnlyDigits(string str) {
    int index = 0;
    bool containsOnlyDigits = true;

    while ((index < str.length()) && (containsOnlyDigits)) {
        if (!(((int)str[index] <= MAX_ASCII) && (int)(str[index] >= MIN_ASCII) || str[index] == space)) {
            containsOnlyDigits = false;
        }

        index++;
    }

    return containsOnlyDigits;
}

void redactString(string& str) {
    int index;
    for (index = 0; index < str.length(); index++) {
        if (str[index] != space) {
            str[index] = 'x';
        }
    }
}
