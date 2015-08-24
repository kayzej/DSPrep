//
//  main.cpp
//  DataStructures2
//
//  Created by Jeffrey Kayzerman on 8/16/15.
//  Copyright (c) 2015 Jeffrey Kayzerman. All rights reserved.
//

#include <iostream>
#include "time.cpp"

int main(int argc, const char * argv[]) {
    Time t1;
    Time t2(1, 2, 3);
    
    Time t3(39, 24, 13);
    
    std::cout << "t1 second is: " << t1.getSecond() << std::endl;
    std::cout << "t2 second is: " << t2.getSecond() << std::endl;
    
    t3.printAmPm();
    
    return 0;
}
