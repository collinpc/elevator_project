
// Knows where elevator is going from/to, records time for events

#pragma once
#ifndef PASSENGER.H
#define PASSENGER.H
using namespace std;


class Passenger
{
private:

	int floor_from; 
	int floor_to;
	int wait_total; 
	int wait_arrival;

	int arrive_time;
	int call_time;
	int exit_time;

	int calculate_trip_time();
	int calculate_arrival_time(); //when the elevator gets to the person




public:


	//setters


	void set_wait_total(int time)
	{
		wait_total = time;
	}

	void set_wait_arrival(int time)
	{
		wait_arrival = time;
	}


	//Getters

	int get_wait_total()
	{
		return wait_total;
	}

	int get_wait_arrival()
	{
		return wait_arrival;
	}

	



};

#endif
