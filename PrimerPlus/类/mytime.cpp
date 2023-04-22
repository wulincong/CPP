#include <iostream>
#include "mytime.h"

Time::Time()
{
    hours = minutes = seconds = 0;
}

Time::Time(int h, int m, int s){
    hours = h;
    minutes = m;
    seconds = s;
}

Time Time::operator+(const Time & t) const{
    Time sum;
    sum.seconds = seconds + t.seconds;
    sum.minutes = minutes + t.minutes + sum.seconds / 60; 
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    sum.seconds %= 60;
    return sum;
}

bool Time::operator>(const Time & t) const{
    if(hours > t.hours) return true;
    else if(hours < t.minutes) return false;
    else{
        if(minutes > t.minutes) return true;
        else if(minutes < t.minutes) return false;
        else{
            if(seconds > t.seconds) return true;
            else if(seconds < t.seconds) return false;
            else return false;
        }
    }
}

bool Time::operator==(const Time & t) const{
    return hours == t.hours && minutes == t.minutes && seconds == t.seconds;
}

bool Time::operator<(const Time & t) const{
    return ! *this > t && ! *this == t;
}



