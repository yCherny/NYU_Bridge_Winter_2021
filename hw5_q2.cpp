//
// Created by Yegor Chernyshev on 2/11/21.
// 

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Constants
const int MAX_GUESS_COUNT = 5;
const int MIN_GUESS = 1;
const int MAX_GUESS = 100;
const char NL = '\n';

int main() {

    int guessCount = 0;
    int compGuess, userGuess;
    int rangeStart, rangeEnd;

    // Random Guess Instantiation
    srand(time(0));
    compGuess = ((rand() % 100) + 1);

    // Range Instantiation
    rangeStart = 1;
    rangeEnd = 100;

    cout<<"I thought of a number between "<<MIN_GUESS<<" and "<<MAX_GUESS<<"! Try to guess it."<<endl;

    // Main Game Logic
    while (guessCount < MAX_GUESS_COUNT) {

        cout<<"Range: ["<<rangeStart<<","<<rangeEnd<<"], Number of guesses left: "<<(MAX_GUESS_COUNT - guessCount)<<endl;
        cout<<"Your guess: ";
        cin>>userGuess;
        guessCount++;

        if (userGuess == compGuess) {
            // User Guessed Correctly
            cout<<"Congrats! You guessed my number in "<<guessCount<<" guesses."<<endl;
            break;
        } else {
            // Guess Was Incorrect
            if (guessCount >= MAX_GUESS_COUNT) {
                // Game Over
                cout<<"Out of guesses! My number is "<<compGuess;
                break;
            } else {
                // User Still Has Guesses -> Assist User
                if (compGuess > userGuess) {
                    cout<<"Wrong! My number is bigger."<<endl<<NL;
                    rangeStart = (userGuess+1);
                } else {
                    cout<<"Wrong! My number is smaller."<<endl<<NL;
                    rangeEnd = (userGuess-1);
                }
            }
        }
    }

    return 0;
}
