
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

	int arrive_time; //when the elevator gets to the person
	int call_time;
	int exit_time;
	int calculate_arrival_weight_time();




public:

    //Constructors
    
    Passenger();
    
    
	//setters


	void set_call_time(int time)
	{
		call_time = time;
	}

	void set_arival_time(int time)
	{
		arrive_time = time;
	}
    
    void set_exit_time(int time)
    {
        exit_time = time;
    }
    
    void set_floor_from(int floor);
    
    void set_floor_to(int floor);


	//Getters

	int get_wait_total()
	{
		return wait_total;
	}

	int get_wait_arrival()
	{
		return wait_arrival;
	}
    int get_floor_to() {
        return floor_to;
    }
    
    void calculate_trip_time();

	

};

#endif
