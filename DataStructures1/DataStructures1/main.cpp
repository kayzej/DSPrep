//
//  main.cpp
//  DataStructures1
//
//  Created by Jeffrey Kayzerman on 8/16/15.
//  Copyright (c) 2015 Jeffrey Kayzerman. All rights reserved.
//

#include <iostream>
#include "julian.cpp"

int
main()
{
    int months [10];
    int days [10];
    int julianDays[10];
    int year=2014;
    
    for(int i=0; i<10; i++){
        months[i] = i;
        days[i] = i;
    }
    
    for(int i=0; i<10; i++){
        julianDays[i] = julian_day( months[i], days[i], year);
        std::cout << julianDays[i] << "\n";
    }
    
    return 0;
}
