#pragma once

#include <queue>
#include "passenger.h"
#include <string>
// Controls
#ifndef FLOOR
#define FLOOR


//Controls interactions between the Floors and Cars
class Floor
{
public:
    Floor();
    Floor(int number);
	void add_to_queue(Passenger *passenger, string direction);
    queue<Passenger>* get_passengers(string direction);
    //friend class Car;

private:
    queue<Passenger>* up_queue = new queue<Passenger>; //* somhow make these friends
    queue<Passenger>* down_queue = new queue<Passenger>;
};
#endif