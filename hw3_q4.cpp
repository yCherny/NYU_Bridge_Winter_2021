//
// Created by Yegor Chernyshev on 1/29/21.
//

#include <iostream>
using namespace std;

const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;

int main() {

    int userMethod;
    float userNumber, userNumberAltered;

    cout<<"Please enter a Real number:"<<endl;
    cin>>userNumber;

    cout<<"Choose your rounding method:"<<endl;
    cout<<"1. Floor round"<<endl;
    cout<<"2. Ceiling round"<<endl;
    cout<<"3. Round to the nearest whole number"<<endl;
    cin>>userMethod;

    switch (userMethod) {
        case FLOOR_ROUND:
            userNumberAltered = (int)userNumber;
            cout<<userNumberAltered<<endl;
            break;
        case CEILING_ROUND:
            userNumberAltered = (int)(userNumber+1) ;
            cout<<userNumberAltered<<endl;
            break;
        case ROUND:
            userNumberAltered = (int)(userNumber+0.5);
            cout<<userNumberAltered<<endl;
            break;
        default:
            cout<<"Such an option doesn't exist. Please choose 1, 2 or 3.";
            break;
    }


    return 0;
}

