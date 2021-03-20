//
// Created by Yegor Chernyshev on 3/11/21.
// 

#include <iostream>
#include <string>

using namespace std;

// Constant Declarations
const int ALPHABET_SIZE = 26;
const int CASE_DIFFERENCE = 32;
const int MIN_ASCII = 65;   // ASCII Value of A
const int MAX_ASCII = 122;  // ASCII Value of z
const char TAB = '\t';
const char SPACE = ' ';
const char COMMA = ',';
const char PERIOD = '.';

int numberOfWordsInInput(string& input);
bool substringHasLetters(string& word);
void countStringLetters(string& text);

int main() {

    string userInput;
    int numberOfWords;

    cout<<"Please enter a line of text:"<<endl;
    getline(cin, userInput);

    numberOfWords = numberOfWordsInInput(userInput);
    cout<<to_string(numberOfWords)<<TAB<<"words"<<endl;
    cout<<"Compressed input: "<<userInput<<endl;
    countStringLetters(userInput);
    return 0;
}

int numberOfWordsInInput(string& input) {
    int wordCount = 0;
    int index = 0;
    int wordStartIndex = 0;
    int wordEndIndex = 0;
    string compressedWord;

    while (index <= input.length()) {
        string subString;
        char currentChar = input[index];

        if (currentChar == SPACE || currentChar == COMMA || currentChar == PERIOD || index == input.length()) {

            // End of the Word Found -> Evaluate
            wordStartIndex = wordEndIndex;
            wordEndIndex = index;

            // Loop Through the Substring -> Evaluate if it is only full of digits
            subString = input.substr(wordStartIndex, (wordEndIndex - wordStartIndex));
            cout<<"Input Length: "<<input.length()<<"Index: "<<index<<"Substring: "<<subString<<endl;
            // If Substring Has Letters -> Increment Word Count
            if (substringHasLetters(subString)) {
                wordCount++;
                compressedWord += subString;
            }
        }

        index++;
    }

    input = compressedWord;
    return wordCount;
}

// Assumes substring passed in has no characters. Loops through substring to find any.
bool substringHasLetters(string& word) {
    bool hasLetters = false;
    int index = 0;

    while (index < word.length() && !hasLetters) {
        if (word[index] >= MIN_ASCII && word[index] <= MAX_ASCII) {
            hasLetters = true;
        }
        index++;
    }

    return hasLetters;
}

void countStringLetters(string& text) {
    int index, charIndex;
    int characters[26];

    for (index = 0; index < ALPHABET_SIZE; index++) {
        characters[index] = 0;
    }

    int secondIndex = 0;
    while (secondIndex < text.length()) {

        if (text[secondIndex] <= MAX_ASCII && text[secondIndex] >= MIN_ASCII) {
            // Character is a Letter
            if (text[secondIndex] > 90) {
                charIndex = ((text[secondIndex]) - (CASE_DIFFERENCE + MIN_ASCII));
                characters[charIndex] = characters[charIndex] + 1;
            } else {
                charIndex = ((text[secondIndex]) - (MIN_ASCII));
                characters[charIndex] = characters[charIndex] + 1;
            }
        }

        secondIndex++;
    }

    int check = 0;
    while (check < ALPHABET_SIZE) {
        if(characters[check] != 0) {
            cout<<characters[check]<<TAB<<(char)(check+MIN_ASCII)<<endl;
        }
        check++;
    }
}
