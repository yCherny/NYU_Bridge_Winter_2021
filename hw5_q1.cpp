//
// Created by Yegor Chernyshev on 2/11/21.
//

#include <iostream>
using namespace std;

const char TAB = '\t';

int main() {

    int rows, columns;
    int userInput;

    cout<<"Please enter a positive integer:"<<endl;
    cin>>userInput;

    rows = 1;
    while(rows <= userInput) {
        for(columns=1;columns<=userInput;columns++) {
            cout<<(rows*columns)<<TAB;
        }

        rows++;
        cout<<endl;
    }

    return 0;
}
