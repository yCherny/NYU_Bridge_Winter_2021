/* Yegor Chernyshev NYU Bridge 2021*/

#include <iostream>
using namespace std;

const int HOURS_IN_DAY = 24, MINUTES_IN_HOUR = 60;

int main() {

    int johnDays, johnHours, johnMinutes;
    int billDays, billHours, billMinutes;
    int totalNumberOfDaysInMinutes, totalNumberOfHoursInMinutes, totalNumberOfMinutes;
    int totalDaysWorked, totalHoursWorked, totalMinutesWorked;

    /* John Timesheet */
    cout<<"Please enter the number of days John has worked: ";
    cin>>johnDays;

    cout<<"Please enter the number of hours John has worked: ";
    cin>>johnHours;

    cout<<"Please enter the number of minutes John has worked: ";
    cin>>johnMinutes;
    cout<<endl;

    /* Bill Timesheet */
    cout<<"Please enter the number of days Bill has worked: ";
    cin>>billDays;

    cout<<"Please enter the number of hours Bill has worked: ";
    cin>>billHours;

    cout<<"Please enter the number of minutes Bill has worked: ";
    cin>>billMinutes;
    cout<<endl;

    /* Math */
    totalNumberOfDaysInMinutes = ((johnDays + billDays) * HOURS_IN_DAY * MINUTES_IN_HOUR);
    totalNumberOfHoursInMinutes = ((johnHours + billHours) * MINUTES_IN_HOUR);
    totalNumberOfMinutes = (totalNumberOfDaysInMinutes + totalNumberOfHoursInMinutes + (johnMinutes + billMinutes));

    totalDaysWorked = (totalNumberOfMinutes/MINUTES_IN_HOUR) / HOURS_IN_DAY;
    totalNumberOfMinutes -= (totalDaysWorked * HOURS_IN_DAY)*MINUTES_IN_HOUR;
    totalHoursWorked = (totalNumberOfMinutes/MINUTES_IN_HOUR);
    totalNumberOfMinutes -= (totalHoursWorked*MINUTES_IN_HOUR);
    totalMinutesWorked = totalNumberOfMinutes;

    cout<<"The total time both of them worked together is: "<<totalDaysWorked<<" days, "<<totalHoursWorked<<" hours and "<<totalMinutesWorked<<" minutes."<<endl;

    return 0;
}
