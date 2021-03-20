//
// Created by Yegor Chernyshev on 2/25/21.
//

#include <iostream>
using namespace std;

// Constant Declarations
const int DAYS_IN_WEEK = 7;
const int MONTHS_IN_YEAR = 12;

// Function Declaration
int printMonthCalender(int numOfDays, int startingDay);
void printYearCalender(int year, int startingDay);

int main() {

    int year, startDay;

    cout<<"Please enter a year for your calendar: ";
    cin>>year;
    cout<<"Please enter the day of week to begin with (Mon = 1...Sun = 7): ";
    cin>>startDay;

    printYearCalender(year, startDay);

    return 0;
}

void printYearCalender(int year, int startingDay) {
    bool isLeapYear = false;
    startingDay = startingDay;

    // Checks if Leap Year
    if ((year % 400 == 0) || (year % 4 == 0) && (year % 100 != 0)) {
        isLeapYear = true;
    }

    // Generates the Calendar
    for (int month = 1; month <= MONTHS_IN_YEAR; month++) {
        int daysInMonth;
        switch (month) {
            case 1:
                cout<<"January"<<" "<<year<<endl;
                daysInMonth = 31;
                startingDay = printMonthCalender(daysInMonth, startingDay);
                break;
            case 2:
                cout<<"February"<<" "<<year<<endl;

                // February
                if (isLeapYear) {
                    daysInMonth = 29;
                    startingDay = printMonthCalender(daysInMonth, startingDay);
                } else {
                    daysInMonth = 28;
                    startingDay = printMonthCalender(daysInMonth, startingDay);
                }

                break;
            case 3:
                cout<<"March"<<" "<<year<<endl;
                daysInMonth = 31;
                startingDay = printMonthCalender(daysInMonth, startingDay);
                break;
            case 4:
                cout<<"April"<<" "<<year<<endl;
                daysInMonth = 30;
                startingDay = printMonthCalender(daysInMonth, startingDay);
                break;
            case 5:
                cout<<"May"<<" "<<year<<endl;
                daysInMonth = 31;
                startingDay = printMonthCalender(daysInMonth, startingDay);
                break;
            case 6:
                cout<<"June"<<" "<<year<<endl;
                daysInMonth = 30;
                startingDay = printMonthCalender(daysInMonth, startingDay);
                break;
            case 7:
                cout<<"July"<<" "<<year<<endl;
                daysInMonth = 31;
                startingDay = printMonthCalender(daysInMonth, startingDay);
                break;
            case 8:
                cout<<"August"<<" "<<year<<endl;
                daysInMonth = 31;
                startingDay = printMonthCalender(daysInMonth, startingDay);
                break;
            case 9:
                cout<<"September"<<" "<<year<<endl;
                daysInMonth = 30;
                startingDay = printMonthCalender(daysInMonth, startingDay);
                break;
            case 10:
                cout<<"October"<<" "<<year<<endl;
                daysInMonth = 31;
                startingDay = printMonthCalender(daysInMonth, startingDay);
                break;
            case 11:
                cout<<"November"<<" "<<year<<endl;
                daysInMonth = 30;
                startingDay = printMonthCalender(daysInMonth, startingDay);
                break;
            case 12:
                cout<<"December"<<" "<<year<<endl;
                daysInMonth = 31;
                startingDay = printMonthCalender(daysInMonth, startingDay);
                break;
            default:
                break;
        }
        cout<<'\n'<<endl;
    }
}


int printMonthCalender(int numOfDays, int startingDay) {
    int lastDayOfMonth = (startingDay + numOfDays) % 7;
    int currentDay = 1;
    char emptyDay = ' ';
    char tab = '\t';

    // Headers
    for (int header = 1; header <= DAYS_IN_WEEK; header++) {
        switch (header) {
            case 1:
                cout<<"Mon"<<tab;
                break;
            case 2:
                cout<<"Tue"<<tab;
                break;
            case 3:
                cout<<"Wed"<<tab;
                break;
            case 4:
                cout<<"Thr"<<tab;
                break;
            case 5:
                cout<<"Fri"<<tab;
                break;
            case 6:
                cout<<"Sat"<<tab;
                break;
            case 7:
                cout<<"Sun"<<tab;
                break;
            default:
                break;
        }
    }

    cout<<endl;

    // Numerical Dates
    while (currentDay < (numOfDays+startingDay)) {
        if (currentDay < startingDay) {
            cout<<emptyDay<<tab;
        } else {
            cout<<(currentDay-(startingDay-1))<<tab;
        }

        if (currentDay % 7 == 0 && (currentDay+1 != numOfDays+startingDay)) {
            cout<<endl;
        }

        currentDay++;
    }


    if (lastDayOfMonth == 0) {
        return 7;
    } else {
        return lastDayOfMonth;
    }
}
