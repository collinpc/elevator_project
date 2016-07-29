#include <iostream>
#include "passenger.h"
#include "bst.h"
#include "floor.h"
#include <queue>
#include "car.h"
#include <cstdlib>
#include <string>

#define NUM_OF_FLOORS 12

using namespace std;


int main()
{
    
    Passenger * pas1 = new Passenger();
    
    queue<Passenger>* passengers = new queue<Passenger>;
    
    passengers->push(*pas1);
    
    Car * car1 = new Car();
    car1->load_car(passengers);
}