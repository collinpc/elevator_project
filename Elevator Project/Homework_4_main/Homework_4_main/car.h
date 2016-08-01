#pragma once

// knows wait times, knows how long at each floor, knows passengers

#ifndef CAR
#define CAR
#include <iostream>
#include <queue>
#include "floor.h"
#include "passenger.h"
#include <map>
//#include "elevator_system.h"
#include <queue>
//#include "elevator_system.h"
#include <string>
#include "bst.h"
#include <vector>

using namespace std;


class Car
{

protected:
    // Cars check these to see if they can pick up a passengers traveling in the same direction,
    // similar to a real elevator.
    static BinarySearchTree<int, bool> up_list; // up binary search tree
    static BinarySearchTree<int, bool> down_list; // down binary search tree
    
private:

	int travel_time_total;
    int static const number_of_floors = 12;
	int const time_between_floors = 3; // seconds
	int const min_floor_time = 5; // seconds
	int const pass_load_time = 1; // Time for each passenger to load
    
    // These calls have priority and hold the direction which the passenger whos has
    // been waiting the longest needs to go **
   // string floors_to_stop_at[number_of_floors]; put this in public, idk 
    
    int busy;
    int const home_floor = 3; // home floor
    int current_floor;
    int next_floor;
    int time_to_next_floor; // time until the elevator will reach next floor
    int time_until_departure;
    string direction;
    
    queue<Passenger>* passengers = new queue<Passenger>;
    
    bool check_for_passengers(int floor, string direction);
    
    
public:
    Car();

    Car(vector<Floor> * floors);
    
    bool is_busy();
	string floors_to_stop_at[number_of_floors];
    void move();
    
    
    vector<Floor> * floors_ptr = NULL;
    
    //Take people from floor que and ad them to Car Que **
    void load_car(queue<Passenger>* new_passengers);

	void send_to_floor(int floor, string intended_direction); //**

	string get_direction();
	int get_lowest_floor();
	int get_highest_floor();
    
    virtual ~Car();

};
#endif