#include <iostream>
#include "passenger.h"
#include "bst.h"
#include "floor.h"
#include <queue>
#include "car.h"
#include <cstdlib>
#include <string>
#include "simulator.h"


#define NUM_OF_FLOORS 12

using namespace std;


int main()
{
    
    Passenger * pas1 = new Passenger();
	//
	//Simulator::handle_data(*pas1);


    queue<Passenger>* passengers = new queue<Passenger>;
    
    passengers->push(*pas1);
	Simulator passenger1;
	
    Car * car1 = new Car();
    car1->load_car(passengers);

	passenger1.handle_data(*pas1);
	


	Passenger * pas2 = new Passenger();
	//
	//Simulator::handle_data(*pas1);


	queue<Passenger>* passengers2 = new queue<Passenger>;

	passengers->push(*pas2);
	Simulator passenger2;

	Car * car12 = new Car();
	car12->load_car(passengers2);
	passenger1.handle_data(*pas2);

	system("PAUSE");
}