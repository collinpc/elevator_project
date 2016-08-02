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
	Simulator * sim1 = new Simulator(1,12);
	
	sim1->run_simulation(12);
	system("PAUSE");

}