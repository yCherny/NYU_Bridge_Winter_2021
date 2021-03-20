//
// Created by Yegor Chernyshev on 2/27/21.
// 

#import <iostream>
#import <string>
using namespace std;

// Function Declarations
bool isPalindrome(string str);

int main() {

    string userWord;

    cout<<"Please enter a word: ";
    cin>>userWord;

    if (isPalindrome(userWord)) {
        cout<<userWord<<" is a palindrome"<<endl;
    } else {
        cout<<userWord<<" is not a palindrome"<<endl;
    }

    return 0;
}

bool isPalindrome(string str) {
    int index = 0;
    int stringLength = str.length();
    int stringLengthHalved = (int)(stringLength / 2);
    bool palindrome = true;

    // While Not All Characters Have Been Iterated Through, Keep Looping.
    // If there are ever two characters that are not equal, the word is not a palindrome, break out of loop.
    while ((index < stringLengthHalved) && (palindrome)) {
        int mirroredIndex = (stringLength - (index+1));
        if (str[index] == str[mirroredIndex]) {
            palindrome = true;
        } else {
            palindrome = false;
        }

        index++;
    }

    return palindrome;
}
