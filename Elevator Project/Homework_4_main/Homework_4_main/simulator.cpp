#include "passenger.h"
#include <iostream>
#include "simulator.h"
#include "elevator_system.h"
#include <time.h>
//#include <windows.h>

Simulator::Simulator(int cars, int people)
{
	passenger_num = people;
	num_cars = cars;

	elevator_system_ptr = new Elevator_System(cars, this);
}


void Simulator::handle_data(Passenger passenger)
{
	cout << "Average Time---------------------------------------------------------------";
	
	total_passengers++; // adds 1 to the number of passengers served
	
	trip_times.push_back(calculate_trip_time()); //adds the wait total for the current passenger?
	arrival_times.push_back(calculate_arrival_wait_time()); // adds the arrival wait time for the current passenger?

	total_times = calculate_trip_time() + total_times;
	average_time = total_times / total_passengers; //calculates the average trip time	
	
}

void Simulator::print_data()
{
	passenger_info();
	cout << "\n\nTotal passengers " << total_passengers << endl;
	cout << "Average_time: " << average_time << endl;


}

void Simulator::run_simulation(int time)
{
	srand(time);
	int interval = get_interval(time);

	for (int i = 0; i < time; i++)
	{
        elevator_system_ptr->tick();
		if (i%interval ==0)
		{
			int from = rand() % 12;
			int to = rand() % 12;

			while (from == to)
			{
				from = rand() % 12 + 1;
				to = rand() % 12 + 1;
			}
            cout << "Making new passenger, floor: " << from << " to " << to << endl;
			Passenger * temp_passenger = new Passenger(from, to);
				//randomly generate floor from, floor to
            elevator_system_ptr->call_elevator(temp_passenger);

		}
	}
}

int Simulator::get_interval(int time)
{
	int interval = time / passenger_num;
	cout << "\n\n" << interval << endl;
	return interval;

}

