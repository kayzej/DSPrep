//
//  time.cpp
//  DataStructures2
//
//  Created by Jeffrey Kayzerman on 8/16/15.
//  Copyright (c) 2015 Jeffrey Kayzerman. All rights reserved.
//
#include <iostream>
#include "time.h"

Time::Time(){
    second = 0;
    minute =0;
    hour = 0;
}

Time::Time(int aSecond, int aMinute, int aHour){
    second = aSecond;
    minute = aMinute;
    hour = aHour;
}

int Time::getSecond() const {
    return second;
}

int Time::getMinute() const {
    return minute;
}

int Time::getHour() const {
    return hour;
}

void Time::setSecond(int aSecond) {
    second = aSecond;
}

void Time::setMinute(int aMinute){
    minute = aMinute;
}

void Time::setHour(int aHour){
    hour = aHour;
}

void Time::printAmPm(){
    std::string hour, minute, second, am_pm;
    
    if( getHour() > 12){
        am_pm = "pm";
        hour = std::to_string(getHour() - 12);
    } else{
        am_pm = "am";
        hour = std::to_string(getHour());
    }
    
    if( getMinute() < 10 )
        minute = "0" + std::to_string( getMinute() );
    else
        minute = std::to_string(getMinute());
    
    if( getSecond() < 10 )
        second = "0" + std::to_string( getSecond() );
    else
        second = std::to_string(getSecond());
    
    std::cout << hour << ":" << minute << ":" << second << " " << am_pm<< std::endl;
}




