/* Yegor Chernyshev NYU Bridge 2021*/

#include <iostream>
using namespace std;

int main() {

    int userNumOne, userNumTwo;
    int sum, diff, product, divResult, modResult;
    double quotient;

    cout<<"Please enter two positive integers, separated by a space: "<<endl;
    cin>>userNumOne>>userNumTwo;

    sum=(userNumOne+userNumTwo);
    cout<<userNumOne<<" + "<<userNumTwo<<" = "<<sum<<endl;

    diff=(userNumOne-userNumTwo);
    cout<<userNumOne<<" - "<<userNumTwo<<" = "<<diff<<endl;

    product=(userNumOne*userNumTwo);
    cout<<userNumOne<<" * "<<userNumTwo<<" = "<<product<<endl;

    quotient=((double)userNumOne/(double)userNumTwo);
    cout<<userNumOne<<" / "<<userNumTwo<<" = "<<quotient<<endl;

    divResult=(userNumOne/userNumTwo);
    cout<<userNumOne<<" div "<<userNumTwo<<" = "<<divResult<<endl;

    modResult=(userNumOne%userNumTwo);
    cout<<userNumOne<<" mod "<<userNumTwo<<" = "<<modResult<<endl;


    return 0;
}
