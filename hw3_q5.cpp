//
// Created by Yegor Chernyshev on 1/29/21.
//

#include <iostream>;
using namespace std;

const double POUND_TO_KILOS = 0.453592;
const double INCH_TO_METERS = 0.0254;

int main() {

    double weightInPounds, heightInInches;
    double weightInKilograms, heightInMeters;
    double indexBMI;

    cout<<"Please enter weight (in pounds): ";
    cin>>weightInPounds;

    cout<<"Please enter height (in inches): ";
    cin>>heightInInches;

    // MATH
    weightInKilograms = weightInPounds * POUND_TO_KILOS;
    heightInMeters = heightInInches * INCH_TO_METERS;
    indexBMI = weightInKilograms / (heightInMeters * heightInMeters);

    if (indexBMI >= 30) {
        cout<<"The weight status is: Obese";
    } else if (30 > indexBMI && indexBMI >= 25) {
        cout<<"The weight status is: Overweight";
    } else if (25 > indexBMI && indexBMI >= 18.5) {
        cout<<"The weight status is: Normal";
    } else {
        cout<<"The weight status is: Underweight";
    }

    return 0;
}