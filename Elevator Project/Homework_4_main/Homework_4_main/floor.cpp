#include "floor.h"
#include <iostream>
using namespace std;



void Floor::add_to_queue(Passenger *passenger, string direction)
{
	

	if (direction == "down")
	{
		down_queue->push(*passenger);
	}

	else if (direction == "up")
	{
		up_queue->push(*passenger);
	}

	else
	{
		cout << "Something got fucked up";
	}
}

queue<Passenger> * Floor::get_passengers(string direction) {
    if (direction == "down") {
        return down_queue;
    } else if (direction == "up") {
        return up_queue;
    }
    return NULL;
}
