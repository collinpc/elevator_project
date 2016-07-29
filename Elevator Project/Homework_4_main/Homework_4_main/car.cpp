//
//  car.cpp
//  HW4
//
//  Created by Jacob Briede on 7/28/16.
//  Copyright © 2016 JacobBriede. All rights reserved.
//

#include "car.h"

Car::Car() {
}

//Remove people from floor que and add them to Car Que. Also signal floors to stop at.
void Car::load_car(queue<Passenger> *new_passengers) {
    cout << "Loading Passenger" << endl;
    for (unsigned int c; c < new_passengers->size(); c++) {
        Passenger passenger = new_passengers->front();
        cout << "Passenger going to floor " << passenger.get_floor_to() << endl;
        passengers->push(passenger);
        floors_to_stop_at[passenger.get_floor_to()] = true;
        new_passengers->pop();
    }
}