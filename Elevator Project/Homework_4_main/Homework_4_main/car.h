#pragma once

// knows wait times, knows how long at each floor, knows passengers

#ifndef CAR
#define CAR
#include <iostream>
#include <queue>
#include "passenger.h"
#include <map>
#include <queue>
#include "elevator_system.h"
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
	int const home_floor = 3; // home floor
	int const floor_current = 3;
    string direction;
	
    int floors_to_stop_at[number_of_floors];
    
    queue<Passenger>* passengers = new queue<Passenger>;
    

public:
    Car();
    
	void go_up(); 
	void go_down();
    
    //Take people from floor que and ad them to Car Que
    void load_car(queue<Passenger>* new_passengers);


};












#endif