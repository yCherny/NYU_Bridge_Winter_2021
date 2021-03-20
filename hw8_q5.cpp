//
// Created by Yegor Chernyshev on 2/27/21.
// 

#include <iostream>
#include <string>
using namespace std;

// Function Declarations
string refactorName(string first, string middle, string last);

int main() {

    string firstName, middleName, lastName;

    cout<<"Please enter your first, middle and last name separated by spaces:"<<endl;
    cin>>firstName>>middleName>>lastName;
    cout<<refactorName(firstName, middleName, lastName);

    return 0;
}

string refactorName(string first, string middle, string last) {
    string output;
    output = (last + ", " + first + " " + middle[0] + ".");
    return output;
}
