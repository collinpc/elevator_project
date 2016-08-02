#pragma once

// knows wait times, knows how long at each floor, knows passengers

#ifndef CAR
#define CAR
#include <iostream>
#include <queue>
#include "passenger.h"
#include <map>
#include "floor.h"
#include "elevator_system.h"
#include <forward_list>
//#include "elevator_system.h"
#include <string>
#include "bst.h"
using namespace std;



class Elevator_System::Car
{
    
private:

	int travel_time_total;
    const static int number_of_floors = 12;
	int time_between_floors = 3; // seconds
	int const min_floor_time = 5; // seconds
	int const pass_load_time = 1; // Time for each passenger to load
    
    // These calls have priority and hold the direction which the passenger whos has
    // been waiting the longest needs to go **
   // string floors_to_stop_at[number_of_floors]; put this in public, idk 
    
    bool busy;
    int const home_floor = 0; // home floor
    int current_floor;
    int change_direction_floor;
    int time_to_next_floor; // time until the elevator will reach next floor
    int time_until_departure;
    string direction;
    
    //NEED TO MAKE THIS SOMETHING ELSE
    forward_list<Passenger>* passengers = new forward_list<Passenger>;
    
    Elevator_System * elevator_system_ptr;
    
    void handle_floor_load_unload();
    
    void unload_car();
    
public:
    Car(Elevator_System * Elevator_System_ptr);

    bool is_busy();
	string floors_to_stop_at[number_of_floors];
    void move();
    
    int get_current_floor() {
        return current_floor;
    }
    
    void stats();
    
    void send_home();
    
    //Take people from floor que and ad them to Car Que **
    void load_car(queue<Passenger>* new_passengers);
    

	void send_to_floor(int floor, string intended_direction); //**

	string get_direction();
	int get_lowest_floor();
	int get_highest_floor();
    
    bool check_floor();

};
#endif