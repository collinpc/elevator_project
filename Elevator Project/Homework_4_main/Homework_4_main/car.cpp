//
//  car.cpp
//  HW4
//
//  Created by Jacob Briede on 7/28/16.
//  Copyright © 2016 JacobBriede. All rights reserved.
//

#include "car.h"

Car::Car() {
    //Queue Demo
    Passenger* passenger1 = new Passenger();
    
    passengers->push(*passenger1);
    passengers->front().calculate_trip_time();
    cout << passengers->front().get_wait_total() << endl;
}

//Take people from floor que and ad them to Car Que
void Car::load_car(queue<Passenger> *new_passengers) {
    for (unsigned int c; c < new_passengers->size(); c++) {
        passengers->push(new_passengers->front());
        new_passengers->pop();
    }
}