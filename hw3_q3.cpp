//
// Created by Yegor Chernyshev on 1/29/21.
//

#include <iostream>;
#include <cmath>;
using namespace std;

int main() {

    double a, b, c;
    double numberOfSolutionsDeterminant;
    double solutionA, solutionB;

    cout << "Please enter value of a: ";
    cin >> a;

    cout << "Please enter value of b: ";
    cin >> b;

    cout << "Please enter value of c: ";
    cin >> c;

    // MATH
    numberOfSolutionsDeterminant = (b*b)-(4*a*c);
    if((a==0)&&(b==0)&&(c==0)) {
        cout << "This equation has infinite solutions";
    } else if ((a==0) && (b==0)) {
        cout<<"This equation has no solution";
    } else if (numberOfSolutionsDeterminant == 0) {
        solutionA -= (b)/(2*a);
        cout<<"This equation has a single real solution x="<<solutionA<<endl;
    } else if (numberOfSolutionsDeterminant > 0) {
        solutionA = (-b)+(sqrt(numberOfSolutionsDeterminant))/(2*a);
        solutionB = (-b)-(sqrt(numberOfSolutionsDeterminant))/(2*a);
        cout<<"This equation has two real solutions x1="<<solutionA<<" and x2="<<solutionB<<endl;
    } else {
        cout<<"This equation has no real solutions"<<endl;

    }

    return 0;
}