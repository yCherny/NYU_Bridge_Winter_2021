//
// Created by Yegor Chernyshev on 3/16/21.
// 

#include <iostream>
#include <string>

using namespace std;

// Constant Declarations
const char SPACE = ' ';
const int NOPOS = -1;

// Function Declarations
string* createWordsArray(string sentence, int &outWordsArrSize);

int main() {

    int outWordsArraySize = 5;
    string sentence;
    string* words;

    cout<<"Please enter a sentence: "<<endl;
    getline(cin, sentence);

    words = createWordsArray(sentence, outWordsArraySize);

    cout<<"[";
    int i;
    for (i=0; i<outWordsArraySize; i++) {
        if (i==0) {
            cout<<words[i];
        } else {
            cout<<", "<<words[i];
        }
    }
    cout<<"]";

    delete [] words;
    words = nullptr;

    return 0;
}

// Functions
string* createWordsArray(string sentence, int &outWordsArrSize) {
    int index, endingIndex;
    int maxWordCount = 1, wordCount = 0;

    // Count Max Words
    for (index = 0; index < sentence.size(); index++) {
        if (sentence[index] == SPACE) {
            maxWordCount++;
        }
    }

    // Generate New Array
    string * tempWords = new string[maxWordCount];
    string word, remainingSentence;

    // Get Words
    while (!sentence.empty()) {
        int startingIndex = 0;

        // If the Starting Index is a Space, Find the Next Character that is NOT a Space.
        if (sentence[startingIndex] == SPACE) {
            startingIndex = sentence.find_first_not_of(SPACE);
        }

        endingIndex = sentence.find_first_of(SPACE, startingIndex);
        remainingSentence = sentence.substr(endingIndex+1, sentence.size());

        if (endingIndex == NOPOS) {
            endingIndex = sentence.size();
            remainingSentence = "";
        }

        word = sentence.substr(startingIndex, (endingIndex - startingIndex));
        tempWords[wordCount] = word;
        wordCount++;

        sentence = remainingSentence;
    }

    outWordsArrSize = wordCount;
    return tempWords;
}
