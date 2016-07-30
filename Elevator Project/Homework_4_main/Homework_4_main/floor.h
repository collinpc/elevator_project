#pragma once

#include <queue>
// Controls
#ifndef FLOOR
#define FLOOR


//Controls interactions between the Floors and Cars
class Floor
{
public:
    Floor();
    Floor(int number);
protected:
    queue<Passenger>* up_queue = new queue<Passenger>;
    queue<Passenger>* down_queue = new queue<Passenger>;
};
#endif