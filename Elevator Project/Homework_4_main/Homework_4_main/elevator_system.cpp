//
//  elevator_system.cpp
//  HW4
//
//  Created by Jacob Briede on 7/28/16.
//  Copyright © 2016 JacobBriede. All rights reserved.
//
#include "elevator_system.h"
#include <stdio.h>

Elevator_System::Elevator_System(int num_of_floors, int num_of_cars) {
    number_of_floors = num_of_floors;
    number_of_cars = num_of_cars;
    // Create list of cars
    // Create list of floors
}

void Elevator_System::call_elevator(int floor, string direction, Passenger* passenger) {
    
    // Add passenger to floor queue
    add_to_que(floor, passenger, direction);
    
}

// Access que of correct floor and direction, add passenger to that queue
void Elevator_System::add_to_que(int floor, Passenger *passenger, string direction) {

	floors[floor].add_to_queue(passenger, direction);

}