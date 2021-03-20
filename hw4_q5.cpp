//
// Created by Yegor Chernyshev on 2/2/21.
//

#include <iostream>
using namespace std;

int main() {

    // Input and Output
    int userInput;
    int userInput2N;
    int starIndex;
    int starIndexInline;
    int difference;
    int gapIndex;
    char gap = ' ';

    // User Data Retrieval
    cout<<"Please input a positive integer: ";
    cin>>userInput;
    userInput2N = (userInput*2);

    // Upper Form of Star Design
    for (starIndex = (userInput2N-1); starIndex > 0; starIndex-= 2) {
        starIndexInline = 0;

        difference = (int)((userInput2N-starIndex) / 2);

        if (difference > 0) {
            for (gapIndex = 0; (gapIndex < difference); gapIndex++) {
                cout<<gap;
            }
        }

        while (starIndexInline < starIndex) {
            cout<<"*";
            starIndexInline++;
        }
        cout<<endl;
    }

    // Lower Form of Star Design
    for (starIndex = 1; starIndex < (userInput2N); starIndex+= 2) {
        starIndexInline = 0;

        difference = (int)((userInput2N-starIndex) / 2);

        if (difference > 0) {
            for (gapIndex = 0; (gapIndex < difference); gapIndex++) {
                cout<<gap;
            }
        }

        while (starIndexInline < starIndex) {
            cout<<"*";
            starIndexInline++;
        }
        cout<<endl;
    }

    return 0;
}
