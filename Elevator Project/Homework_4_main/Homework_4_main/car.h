#pragma once

// knows wait times, knows how long at each floor, knows passengers

#ifndef CAR
#define CAR
#include <iostream>
#include <queue>
#include "passenger.h"
#include <map>
#include <queue>
//#include "elevator_system.h"
#include <string>
#include "bst.h"
using namespace std;



class Car
{
    
private:

	int travel_time_total;
    int static const number_of_floors = 12;
	int const time_between_floors = 3; // seconds
	int const min_floor_time = 5; // seconds
	int const pass_load_time = 1; // Time for each passenger to load
    
    // These calls have priority and hold the direction which the passenger whos has
    // been waiting the longest needs to go **
    string floors_to_stop_at[number_of_floors];
    
    int busy;
    int const home_floor = 3; // home floor
    int current_floor;
    int next_floor;
    int time_to_next_floor; // time until the elevator will reach next floor
    int time_until_departure;
    string direction;
    
    queue<Passenger>* passengers = new queue<Passenger>;
    
protected:
    
    
public:
    Car();
    
    bool is_busy();
    
    void move();
    
    
    //Take people from floor que and ad them to Car Que **
    void load_car(queue<Passenger>* new_passengers);

	void send_to_floor(int floor); //**

};
#endif