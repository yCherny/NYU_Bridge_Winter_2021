//
// Created by Yegor Chernyshev on 2/19/21.
//

#include <iostream>
using namespace std;

// Function Declaration
double eApprox(int n);

// Constant Declaration
const double NUMERATOR = 1;

int main() {

    cout.precision(30);

    for (int n = 1; n <= 15; n++) {
        cout<<"n = "<<n<<'\t'<<eApprox(n)<<endl;
    }

    return 0;
}

double eApprox(int n) {
    double sum = 1;
    double factorial = 1;

    for (int start = 1; start <= n; start++) {
        factorial *= (double)start;
        sum += (NUMERATOR / factorial);
    }

    return sum;
}
