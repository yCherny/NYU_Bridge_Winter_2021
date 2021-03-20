//
// Created by Yegor Chernyshev on 2/25/21.
//

#include<iostream>
#include<cmath>
#include<string>
using namespace std;

// Func
void analyzeDivisors(int num, int& outCountDivs, int& outSumDivs);
bool isPerfect(int num);
void isAmicable(int num, string& amicNumbers);

int main() {

    string perfNumbers, amicNumbers;
    int userInt, outCountDivs, outSumDivs;

    cout<<"Please enter a positive integer >=2: ";
    cin>>userInt;

    for (int i = 2; i <= userInt; i++) {
        if (isPerfect(i)) {
            if (perfNumbers == "") {
                perfNumbers += to_string(i);
            } else {
                perfNumbers += ", " + to_string(i);
            }
        } else {
            isAmicable(i, amicNumbers);
        }
    }

    cout<<"All perfect numbers between 2 and "<<userInt<<": "<<perfNumbers<<"."<<endl;
    cout<<"All amicable numbers between 2 and "<<userInt<<": "<<amicNumbers<<endl;

    return 0;
}

bool isPerfect(int num) {
    int divs = 0, sum = 0;
    analyzeDivisors(num, divs, sum);
    if (sum == num) {
        return true;
    } else {
        return false;
    }
}

void isAmicable(int num, string& amicNumbers) {
    int divsNumOne = 0, divsNumTwo = 0;
    int sumNumOne = 0, sumNumTwo = 0;

    analyzeDivisors(num, divsNumOne, sumNumOne);
    analyzeDivisors(sumNumOne, divsNumTwo, sumNumTwo);

    if (num == sumNumTwo && num < sumNumOne) {
        amicNumbers += "("+to_string(num)+", "+to_string(sumNumOne)+"), ";
    }
}

void analyzeDivisors(int num, int& outCountDivs, int& outSumDivs) {
    int properDivisorsCount = 0;
    int properDivisorsSum = 0;
    int maxDivisor = sqrt(num);

    for (int divisor = 1; divisor <= maxDivisor; divisor++) {
        if (num % divisor == 0) {
            //cout<<divisor<<" ";
            int quotient = (num / divisor);
            if (quotient != num && quotient != divisor) {
                //cout<<quotient<<" ";
                properDivisorsSum += quotient;
                properDivisorsCount++;
            }
            properDivisorsCount++;
            properDivisorsSum += divisor;
        }
    }

    outCountDivs = properDivisorsCount;
    outSumDivs = properDivisorsSum;
}
