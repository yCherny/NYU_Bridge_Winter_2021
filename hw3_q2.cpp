//
// Created by Yegor Chernyshev on 1/29/21.
//

#include <iostream>
#include <string>
using namespace std;

int main() {

    string name;
    int graduationYear, currentYear;
    int yearDifference;

    cout<<"Please enter your name: ";
    cin>>name;

    cout<<"Please enter your graduation year: ";
    cin>>graduationYear;

    cout<<"Please enter current year: ";
    cin>>currentYear;

    yearDifference = graduationYear - currentYear;

    if (yearDifference <= 0) {
        cout<<name<<", you Graduated"<<endl;
    } else if (yearDifference == 1) {
        cout<<name<<", you are a Senior"<<endl;
    } else if (yearDifference == 2) {
        cout<<name<<", you are a Junior"<<endl;
    } else if (yearDifference == 3) {
        cout<<name<<", you are a Sophomore"<<endl;
    } else if (yearDifference == 4) {
        cout<<name<<", you are a Freshman"<<endl;
    } else {
        cout<<name<<" you are not in college yet"<<endl;
    }
}
