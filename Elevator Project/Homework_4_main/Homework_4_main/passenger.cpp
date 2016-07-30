#include "passenger.h"
#include <iostream>

// Constructors

// create function to output information (time it took to do whatever)

Passenger::Passenger() {
    cout << "creating new passenger" << endl;
    set_floor_to(2);
    set_floor_to(3);
    set_call_time(2);
    set_arival_time(4);
    set_exit_time(10);
}

// Functions
void Passenger::calculate_trip_time() {
    wait_total = exit_time - call_time;
}

int Passenger::calculate_arrival_weight_time() {
    int time = arrive_time - call_time;
    return time;
}

void Passenger::set_floor_from(int floor) {
    floor_from = floor;
}

void Passenger::set_floor_to(int floor) {
    floor_to = floor;
}