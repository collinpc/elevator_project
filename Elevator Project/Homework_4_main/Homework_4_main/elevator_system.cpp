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
    struct Request r = {6, "down"};
    requests->push(r);
    // Create list of floors
}
// Access que of correct floor and direction, add passenger to that queue
void Elevator_System::add_to_que(int floor, Passenger *passenger, string direction) {
	floors[floor].add_to_queue(passenger, direction);

}


void Elevator_System::add_floor(int floor, string direction)
{

	if (direction == "up")
	{
		up_list->Add(floor, true);
	}
	else if (direction == "down")
	{
		down_list->Add(floor, true);

	}
	else
	{
		cout << "\n\nfloor error";
	}

}

bool Elevator_System::car_in_route(int floor, string direction) // iterates through all the cars, for each car, looks at floors each car has to go to (array) wip, check if same direction as front of stack (request->front) 
{
	for (auto it = cars.begin(); it != cars.end(); ++it)
	{

		if (it->get_direction() == direction && direction == "down")
		{
			if (it->get_lowest_floor() <= floor)
			{
				return true;
			}

		}

		if (it->get_direction() == direction && direction == "up")
			if (it->get_highest_floor() >= floor)
			{
				return true;
			}
	}
	return false;
}



void Elevator_System::add_request(int floor, string direction)
{

	struct Request temp_request = {floor, direction};
	requests->push(temp_request);
	
}

Car * Elevator_System::pick_car()
{
	for (auto it = cars.begin(); it != cars.end(); ++it)

		if (!(it->is_busy())) {
			return &(*it);
		}
		else 
		{
			return NULL;
		}
    return NULL;
}



void Elevator_System::call_elevator(int floor, string direction, Passenger* passenger)
{
	add_to_que(floor, passenger, direction);
	add_floor(floor, direction);

	if (car_in_route(floor, direction))
	{
		return;
	}
	else
	{
		Car * temp_car = pick_car();
		if (temp_car != NULL) //if car is found
		{
			temp_car->send_to_floor(floor);
		}

		else
		{
			add_request(floor, direction);
		}
		delete temp_car;

	}
}
