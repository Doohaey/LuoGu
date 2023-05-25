#include <iostream>
#include <cstdio>
using namespace std;

#define TIME_CLASS_BEGIN 480
#define TIME_FOR_SORTING 10
#define MINUTES_PER_DAY 1440

int main() {
    double distance, speed, timeCost, timeLeaveHome;
    int hour, minute;
    
    // Reading distance and speed from user
    cin >> distance >> speed;
    
    // Calculating time cost including sorting and travel time
    timeCost = TIME_FOR_SORTING + (distance / speed);
    
    // Calculating time to leave home
    timeLeaveHome = TIME_CLASS_BEGIN - timeCost;

    // Handling negative time
    if (timeLeaveHome < 0) {
        timeLeaveHome = MINUTES_PER_DAY + timeLeaveHome;
    }

    // Converting time to hours and minutes
    hour = timeLeaveHome / 60;
    minute = timeLeaveHome - (hour * 60);

    // Printing the result
    printf("%02d:%02d", hour, minute);
    return 0;
}
