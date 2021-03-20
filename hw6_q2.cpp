//
// Created by Yegor Chernyshev on 2/19/21.
//

#include <iostream>
using namespace std;

// Function Declarations
void printPineTree(int n, char symbol);
void printShiftedTriangle(int n, int m, char symbol);

int main() {

    int treeSize;
    char symbol;

    cout<<"Please enter a positive integer indicating the size of your pine tree: ";
    cin>>treeSize;
    cout<<"Please enter a symbol you wish to decorate your tree with: ";
    cin>>symbol;

    printPineTree(treeSize, symbol);

    return 0;
}

void printShiftedTriangle(int n, int m, char symbol) {
    // 'n' Is the Layer of Rows
    // 'm' Is the Left-Padding
    char gap = ' ';

    // Triangle Layer
    for (int tLayer = 1; tLayer < (n+1); tLayer++) {

        // Insert Left-Padding
        for(int lPadding = (m-tLayer); lPadding > 0; lPadding--) {
            cout<<gap;
        }

        // Insert Symbol
        for(int starIndex = 1; starIndex<=((2*tLayer)-1); starIndex++) {
            cout<<symbol;
        }

        cout<<endl;
    }
}

// Prints Pine Tree with 'n' Layers
void printPineTree(int n, char symbol) {
    for (int i = 0; i < n; i++) {

        int treeLayer = 2;
        treeLayer += i;

        int insert = (n+1);
        printShiftedTriangle(treeLayer, insert, symbol);
    }
}
