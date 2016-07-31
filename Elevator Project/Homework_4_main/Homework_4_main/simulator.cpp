#include "passenger.h"
#include <iostream>
#include "simulator.h"


void Simulator::handle_data(Passenger passenger)
{
	
	int total_times = 0;
	total_passengers++; // adds 1 to the number of passengers served
	
	trip_times.push_back(calculate_trip_time()); //adds the wait total for the current passenger?
	arrival_times.push_back(calculate_arrival_wait_time()); // adds the arrival wait time for the current passenger?
	passenger_info(); // prints the passenger info
	cout << "\n\nTotal passengers " << total_passengers << endl;

	for (int i = 0; i < trip_times.size();)//adds the times in array to get total trip time
	{
		total_times = trip_times[i] + total_times;
		i++;
	}

	int average_time = total_times / total_passengers; //calculates the average trip time


	cout << "Average_time: " << average_time << endl;

	
	

}
