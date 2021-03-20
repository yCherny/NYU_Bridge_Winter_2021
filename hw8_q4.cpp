//
// Created by Yegor Chernyshev on 2/27/21.
// 

#include <iostream>
#include <ctime>
#include <string>

using namespace std;

// Constants
const int ASCII_CONVERSION = 48;
const int MAX_ARRAY_SIZE = 10;
const string GENERATED_PIN = "57433";

// Function Declarations
void generateRandomMapping(int arr[]);
bool isPinCorrect(string input, int pin[], int map[]);
int convertPin(string input, int pin[], int map[], bool hashed);
int getIndexOfElement(int value, int pin[]);
int getElementAtIndex(int value, int arr[]);

int main() {

    int pinArray[MAX_ARRAY_SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int numArray[MAX_ARRAY_SIZE];

    string userInput;

    generateRandomMapping(numArray);
    cin>>userInput;

    if (isPinCorrect(userInput, pinArray, numArray)) {
        cout<<"Your PIN is correct"<<endl;
    } else {
        cout<<"Your PIN is not correct"<<endl;
    }

    return 0;
}

// Functions
bool isPinCorrect(string input, int pin[], int map[]) {
    int secretPin, inputPin;

    // Converts Secret Pin Into Generated Map Values
    secretPin = convertPin(GENERATED_PIN, pin, map, true);
    inputPin = convertPin(input, pin, map, false);

    if (secretPin == inputPin) {
        return true;
    } else {
        return false;
    }
}

int convertPin(string input, int pin[], int map[], bool hashed) {
    int index, number;

    int elementIndex, elementValue;
    int resultingValue = 0;

    for (index = 0; index < input.length(); index++) {
        number = ((int)input[index] - ASCII_CONVERSION);
        resultingValue *= 10;

        if (hashed) {
            elementIndex = getIndexOfElement(number, pin);
            elementValue = getElementAtIndex(elementIndex, map);
            resultingValue += elementValue;
        } else {
            resultingValue += number;

        }
    }

    return resultingValue;
}

// Loops Through an Array and Returns the Index of the Element
int getIndexOfElement(int value, int pin[]) {
    int index;
    for (index = 0; index < MAX_ARRAY_SIZE; index++) {
        if (pin[index] == value) {
            return index;
        }
    }
}

// Returns the Element at the Index, Given Some Array
int getElementAtIndex(int value, int arr[]) {
    return arr[value];
}

void generateRandomMapping(int arr[]) {
    char tab = '\t';
    int index, randomValueSelected;
    // Random Value Instantiation
    srand(time(0));

    cout<<"Please enter your PIN according to the following mapping:"<<endl;
    cout<<"PIN:"<<tab<<"0 1 2 3 4 5 6 7 8 9"<<endl;
    cout<<"NUM:"<<tab;

    for (index = 0; index < 10; index++) {
        randomValueSelected = ((rand() % 3) + 1);
        arr[index] = randomValueSelected;
        cout << randomValueSelected << " ";
    }

    cout<<endl;
}
