//
//  car.cpp
//  HW4
//
//  Created by Jacob Briede on 7/28/16.
//  Copyright © 2016 JacobBriede. All rights reserved.
//

#include "car.h"

Car::Car(vector<Floor> *  floors) {
    current_floor = home_floor;
    floors_ptr = floors;
}

bool Car::is_busy() //not done
{
	return false;
}

void Car::send_to_floor(int floor, string intended_direction) {
    // add return 0 if elevator is busy
    busy = true;
    floors_to_stop_at[floor] = intended_direction;
    next_floor = floor;
    if (floor > current_floor) {
        direction = "up";
    } else if (floor < current_floor) {
        direction = "down";
    } else if (floor == current_floor) {
        // load car
        load_car((*floors_ptr)[floor].get_passengers(intended_direction));
    } else {
        
        cout << "an error has occured" << endl;
    }
}

//Remove people from floor que and add them to Car Que. Also signal floors to stop at.
void Car::load_car(queue<Passenger> *new_passengers) {
    cout << "Loading Passenger" << endl;
    for (unsigned int c = 0; c < new_passengers->size(); c++) {
        Passenger passenger = new_passengers->front();
        cout << "Passenger going to floor " << passenger.get_floor_to() << endl;
        passengers->push(passenger);
        floors_to_stop_at[passenger.get_floor_to()] = "unspecified";
        new_passengers->pop();
    }
}
// All of this code is questionable as I am very inebriated
void Car::move() {
    if (direction == "down") {
        if (time_to_next_floor == 0) {
            current_floor--;
            time_to_next_floor = time_between_floors;
//            if (check_for_passengers(current_floor, direction)) {
//                load_car((*floors_ptr)[current_floor].get_passengers("down"));
//            };
        } else {
            time_to_next_floor--;
        }
    } else if (direction == "up") {
        if (time_to_next_floor == 0) {
            current_floor++;
            time_to_next_floor = time_between_floors;
//            if (check_for_passengers(current_floor, direction)) {
//                load_car((*floors_ptr)[current_floor].get_passengers("down"));
//            };
        } else {
            time_to_next_floor--;
        }
    }
    else {
        //your on the right floor
    }
}

string Car::get_direction() {
    return direction;
}
bool check_for_passengers(int floor, string direction) {
    return 0;
}

int Car::get_lowest_floor()
{
	for (unsigned int c = 0; c < number_of_floors; c++)
	{
		if (floors_to_stop_at[c] != "null")
		{
			return c;
		}
	}
	return -99;
}

int Car::get_highest_floor()
{
	for (unsigned int c = number_of_floors; c<0; c--)
	{
		if (floors_to_stop_at[c] != "null")
		{
			return c;
		}
	}
	return -99;
}
