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
    Elevator_System * sys1 = new Elevator_System(12, 1);
    Passenger * pass1 = new Passenger(1, 2);
    sys1->call_elevator(pass1);
    sys1->tick();
    sys1->tick();
    sys1->tick();
    sys1->tick();
    Passenger * pass2 = new Passenger(5, 2);
    sys1->call_elevator(pass2);
    sys1->tick();
    sys1->tick();
    sys1->tick();
    sys1->tick();
    sys1->tick();
    sys1->tick();
    sys1->tick();
    sys1->tick();
    sys1->tick();
    sys1->tick();
    sys1->tick();
    sys1->tick();
    sys1->tick();
    sys1->tick();
    sys1->tick();
    sys1->tick();
    sys1->tick();
    sys1->tick();
    sys1->tick();
    
}