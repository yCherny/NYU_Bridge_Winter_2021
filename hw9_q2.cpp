//
// Created by Yegor Chernyshev on 3/11/21.
// 

#include <iostream>
#include <string>

using namespace std;

// Function Declarations
bool areAnagrams(string stringOne, string stringTwo);
void charactersInString(string text, int charsInAlphabet[]);

// Constant Declarations
const int ALPHABET_SIZE = 26;
const int CASE_DIFFERENCE = 32;
const int MIN_ASCII = 65;   // ASCII Value of A
const int MAX_ASCII = 122;  // ASCII Value of z

int main() {

    string userInputOne, userInputTwo;
    bool isAnagram;

    cout<<"Please enter the first string: "<<endl;
    getline(cin, userInputOne);
    cout<<"Please enter the second string: "<<endl;
    getline(cin, userInputTwo);

    isAnagram = areAnagrams(userInputOne, userInputTwo);
    if (isAnagram) {
        cout<<"The strings are anagrams."<<endl;
    } else {
        cout<<"The strings are not anagrams."<<endl;
    }

    return 0;
}

bool areAnagrams(string stringOne, string stringTwo) {
    bool isAnagram = true;
    int stringOneCharacters[26];
    int stringTwoCharacters[26];

    int index;
    for (index = 0; index < ALPHABET_SIZE; index++) {
        stringOneCharacters[index] = 0;
        stringTwoCharacters[index] = 0;
    }

    charactersInString(stringOne, stringOneCharacters);
    charactersInString(stringTwo, stringTwoCharacters);

    int check = 0;
    while (check < ALPHABET_SIZE && isAnagram) {
        if (stringOneCharacters[check] != stringTwoCharacters[check]) {
            isAnagram = false;
        }
        check++;
    }

    return isAnagram;
}


void charactersInString(string text, int charsInAlphabet[]) {
    int charIndex, index = 0;
    while (index < text.length()) {

        if (text[index] <= MAX_ASCII && text[index] >= MIN_ASCII) {
            // Character is a Letter
            if (text[index] > 90) {
                charIndex = ((text[index]) - (CASE_DIFFERENCE + MIN_ASCII));
                charsInAlphabet[charIndex] = charsInAlphabet[charIndex] + 1;
            } else {
                charIndex = ((text[index]) - (MIN_ASCII));
                charsInAlphabet[charIndex] = charsInAlphabet[charIndex] + 1;
            }
        }

        index++;
    }
}
