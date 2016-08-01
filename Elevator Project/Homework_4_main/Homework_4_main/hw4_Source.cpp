#include <iostream>
#include "passenger.h"
#include "bst.h"
#include "floor.h"
#include <queue>
#include <vector>
#include "car.h"
#include <cstdlib>
#include <string>

#define NUM_OF_FLOORS 12

using namespace std;

void get_some(vector<Floor>* floor_ptr, int floor) {
    Floor one = (*floor_ptr)[2];
}

int main()
{
    Passenger * pas1 = new Passenger();
	pas1->passenger_info();
    
//    vector<Floor>* floors = new vector<Floor>(10);
//    
//    vector<Floor>* floor_ptr = floors;
//    
//    floors[3].add_to_que();
    
    
    //queue<Passenger>* passengers = new queue<Passenger>;
    
    //passengers->push(*pas1);
    
    //Car * car1 = new Car();
    //car1->load_car(passengers);

	//cout << Passenger::passenger_info();



	//system("PAUSE");
}