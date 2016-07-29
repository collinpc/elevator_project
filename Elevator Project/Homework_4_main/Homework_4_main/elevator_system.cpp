//
//  elevator_system.cpp
//  HW4
//
//  Created by Jacob Briede on 7/28/16.
//  Copyright © 2016 JacobBriede. All rights reserved.
//
#include "elevator_system.h"
#include <stdio.h>

void Elevator_System::call_elevator(int floor, string directions) {
    if (directions == "down") {
        down_list->Add(floor, 1);
    } else {
        up_list->Add(floor, 1);
    }
}