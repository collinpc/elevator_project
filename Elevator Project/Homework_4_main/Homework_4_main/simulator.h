#pragma once
#ifndef SIMULATOR_H
#define SIMULATOR_H


#include "passenger.h"
#include <iostream>
#include <vector>

using namespace std;


class Simulator : private Passenger //inherited class to access protected functions of passenger.cpp
{
private:

	
	int total_passengers = 0;
	vector<int> trip_times; //holds the trip time for each passenger
	vector<int> arrival_times; //holds how long the elevator took to arrive for each passenger


public:



	void handle_data(Passenger passenger);








};

#endif // !SIMULATOR_H