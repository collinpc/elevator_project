//
//  car.cpp
//  HW4
//
//  Created by Jacob Briede on 7/28/16.
//  Copyright © 2016 JacobBriede. All rights reserved.
//

#include "car.h"
#include "floor.h"
#include "elevator_system.h"

Elevator_System::Car::Car(Elevator_System * Elevator_System_ptr) {
    current_floor = home_floor;
    elevator_system_ptr = Elevator_System_ptr;
    time_to_next_floor = 0;
    direction = "home";
    for (int c = 0; c < number_of_floors; c++) {
        floors_to_stop_at[c] = "Null";
    }
    busy = 0;
}

bool Elevator_System::Car::is_busy() //not done
{
	return busy;
}

void Elevator_System::Car::send_to_floor(int floor, string intended_direction) {
    
    time_to_next_floor = time_between_floors;
    // add return 0 if elevator is busy
    //Elevator_System::Car::direction = direction;
    busy = true;
    floors_to_stop_at[floor] = intended_direction;
    change_direction_floor = floor;
    
    if (floor > current_floor) {
        direction = "up";
    } else if (floor < current_floor) {
        direction = "down";
    } else if (current_floor == floor){
        if (direction == "down") {
            load_car(elevator_system_ptr->floors[floor].down_queue);
        } else {
            load_car(elevator_system_ptr->floors[floor].up_queue);
            
        }
    }    
}

//Remove people from floor que and add them to Car Que. Also signal floors to stop at.
void Elevator_System::Car::load_car(queue<Passenger> *new_passengers) {
    cout << "Loading Passengers" << endl;
    for (unsigned int c = 0; c < new_passengers->size(); c++) {
        Passenger passenger = new_passengers->front();
        cout << "Passenger going to floor " << passenger.get_floor_to() << endl;
        passengers->push_front(passenger);
        if (floors_to_stop_at[passenger.get_floor_to()] == "Null")
            floors_to_stop_at[passenger.get_floor_to()] = "unspecified";
        if ((passenger.get_floor_to() > current_floor) && (passenger.get_floor_to() > get_highest_floor())) {
            change_direction_floor = passenger.get_floor_to();
        } else if ((passenger.get_floor_to() < current_floor) && (passenger.get_floor_to() < get_highest_floor())) {
            change_direction_floor = passenger.get_floor_to();
        }
        new_passengers->pop();
        busy = 1;
        if (direction == "up")
            if (elevator_system_ptr->up_list->Get(current_floor)) {
                elevator_system_ptr->up_list->Remove(current_floor);
            }
        
        else if (direction == "down") {
            if (elevator_system_ptr->up_list->Get(current_floor)) {
                elevator_system_ptr->up_list->Remove(current_floor);
            }
        }
    }
}


void Elevator_System::Car::move() {
    if (direction == "down") {
        if (time_to_next_floor == 0) {
            current_floor--;
            if (check_floor()) {
                cout << "stopping at floor " << current_floor << endl;
                handle_floor_load_unload();
            }
            time_to_next_floor = 3;
        } else if (time_to_next_floor > 0) {
            time_to_next_floor--;
        }
    } else if (direction == "up") {
        if (time_to_next_floor == 0) {
            current_floor++;
            if (check_floor()) {
                cout << "stopping at floor " << current_floor << endl;
                handle_floor_load_unload();
            }
            
            time_to_next_floor = 3;
        } else if(time_to_next_floor > 0) {
            time_to_next_floor--;
        }
    }
    else if (direction == "home") {
        if (time_to_next_floor > 0)
            time_to_next_floor--;
    }
}

string Elevator_System::Car::get_direction() {
    return direction;
}

bool Elevator_System::Car::check_floor() {

    if (current_floor == home_floor)
        direction = "home";
    if ((floors_to_stop_at[current_floor] == "down") && (current_floor == change_direction_floor)) {
        direction = "down";
        floors_to_stop_at[current_floor] = "Null";
        return 1;
    } else if ((floors_to_stop_at[current_floor] == "up") & (current_floor == change_direction_floor)) {
        direction = "up";
        floors_to_stop_at[current_floor] = "Null";
        return 1;
    } else if (floors_to_stop_at[current_floor] != "Null") {
        floors_to_stop_at[current_floor] = "Null";
        return 1;
    }
    else if (elevator_system_ptr->down_list->Get(current_floor) && direction =="down") {
        return 1;
    }
    else if (elevator_system_ptr->up_list->Get(current_floor) && direction =="up") {
        return 1;
    }
    return false;
}

int Elevator_System::Car::get_lowest_floor()
{
	for (unsigned int c = 0; c < number_of_floors; c++)
	{
		if (floors_to_stop_at[c] != "Null")
		{
			return c;
		}
	}
	return -99;
}

int Elevator_System::Car::get_highest_floor()
{
    
	for (int c = 11; c >= 0; c--)
	{
		if (floors_to_stop_at[c] != "Null")
		{
            //cout << "returning " << c << endl;
			return c;
		}
	}
	return 0;
}

// Removes passengers who are on the correct floor
void Elevator_System::Car::unload_car() {
    
    forward_list<Passenger>* passengers1 = new forward_list<Passenger>;
    
    for (auto it = passengers->begin(); it != passengers->end(); ++it) {
        time_to_next_floor = time_to_next_floor + pass_load_time;
        if ((*it).get_floor_to() == current_floor) {
            it->~Passenger();
        } else {
            passengers1->push_front(*it);
        }
    }
    passengers = passengers1;
}


void Elevator_System::Car::handle_floor_load_unload() {
    time_to_next_floor = min_floor_time;
    unload_car();
    
    if (direction == "down") {
        busy = 1;
        load_car(elevator_system_ptr->floors[current_floor].down_queue);
    }
    else if (direction == "up") {
        busy = 1;
        load_car(elevator_system_ptr->floors[current_floor].up_queue);
    }
    if (passengers->empty()) {
        busy = 0;
        send_home();
    }
}

void Elevator_System::Car::send_home() {
    if (current_floor > home_floor) {
        direction = "down";
    } else if (current_floor < home_floor) {
        direction = "up";
    }
    else {
        direction = "home";
    }
}

void Elevator_System::Car::stats() {
    cout << "Passenger length>1 " << !passengers->empty() << endl;
    cout << "Current Floor: " << current_floor << endl;
    cout << "Direction: " << direction << endl;
    cout << "Busy: " << busy << endl;
    cout << "Next floor in " << time_to_next_floor << endl << endl;
}
