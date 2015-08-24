//
//  time.h
//  DataStructures2
//
//  Created by Jeffrey Kayzerman on 8/16/15.
//  Copyright (c) 2015 Jeffrey Kayzerman. All rights reserved.
//

#ifndef DataStructures2_time_h
#define DataStructures2_time_h

class Time {
public:
    Time();
    Time(int aSecond, int aMinute, int aHour);
    // ACCESSORS
    int getSecond() const;
    int getMinute() const;
    int getHour() const;
    // MODIFIERS
    void setSecond(int aSecond);
    void setMinute(int aMinute);
    void setHour(int aHour);
    void printAmPm();
private: // REPRESENTATION (member variables)
    int hour;
    int minute;
    int second;
};


#endif
