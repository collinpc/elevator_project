#include <iostream>
#include "passenger.h"

using namespace std;


int main()
{
    Passenger* pass1 = new Passenger();
    pass1->calculate_trip_time();
	cout << pass1->get_wait_total() << endl;
	//i changed thisew

	system("PAUSE");
    return 0;

}