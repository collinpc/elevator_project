#include <iostream>
#include "passenger.h"
#include "bst.h"
#include "car.h"
#include <cstdlib>

using namespace std;


int main()
{
    Passenger* pass1 = new Passenger();
    pass1->calculate_trip_time();
	//cout << pass1->get_wait_total() << endl << endl;
	//i changed thisewwe
    Car* car1 = new Car();


	return 0;




	system("PAUSE");
    return 0;

}