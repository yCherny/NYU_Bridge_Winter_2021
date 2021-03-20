//
// Created by Yegor Chernyshev on 1/29/21.
//

#include <iostream>;
#include <string>;

using namespace std;

const double WEEKDAY_PEAK_RATE = 0.40;
const double WEEKDAY_OFF_HOURS_RATE = 0.25;
const double WEEKEND_RATE = 0.15;

int main() {

    string dayOfWeek;
    int hour, minutes, callMinutes;
    double cost;
    char divider;

    cout<<"Please enter the day of the week the call was made (i.e. Fr): ";
    cin>>dayOfWeek;

    cout<<"Please enter the time the call was started using 24-hour notation: ";
    cin>>hour>>divider>>minutes;

    cout<<"Please enter the length of the call in minutes: ";
    cin>>callMinutes;

    if (dayOfWeek == "Mo" || dayOfWeek == "Tu" || dayOfWeek == "We" || dayOfWeek == "Th" || dayOfWeek == "Fr") {
        // Weekday
        if (8 <= hour && hour < 18) {
            // Peak Hours
            cost = (callMinutes * WEEKDAY_PEAK_RATE);
        } else {
            // Off Hours
            cost = (callMinutes * WEEKDAY_OFF_HOURS_RATE);
        }
    } else {
        // Weekend
        cost = (callMinutes * WEEKEND_RATE);
    }

    cout<<"The total cost of the call is: $"<<cost<<endl;

    return 0;
}