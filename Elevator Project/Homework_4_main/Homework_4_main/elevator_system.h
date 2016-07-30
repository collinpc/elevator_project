#pragma once
// Controls

// The cars will run on their own and pick up passengers from floors that are on the way and the same direction
// When a car is finished serving floors it is assigned or picking up people along the way, it will not be busy
// and the elevator system can assign it a floor to go to if there is a passenger.

#include "bst.h"//
#include "car.h"
#include "floor.h"
#include <string>
#include <vector>
#include <forward_list>
#include <queue>
#ifndef ELEVATOR_SYSTEM
#define ELEVATOR_SYSTEM

using namespace std;

//Controls interactions between the Floors and Cars
class Elevator_System
{
public:
    Elevator_System(int number_of_floors, int number_of_cars);
    
    // See if any cars can services the requsts in the queue ... Possiblt make protected **
    void service_requests();
    
    // Address a call.. Possibly make protected
    void call_elevator(int floor, string direction, Passenger* passenger); //**

private:
    int number_of_floors;
    int number_of_cars;
	void add_request(int floor, string passenger);
    // Inplementing as vector because specific floors will have to be accessed.
    vector<Floor> floors;
    
    // Implementing Cars as single linked list (front list) because there is no need to access a specific car
    forward_list<Car> cars;
    
    // Cars check these to see if they can pick up a passengers traveling in the same direction,
    // similar to a real elevator.
    BinarySearchTree<int, bool>*up_list = new BinarySearchTree<int, bool>; // up binary search tree
    BinarySearchTree<int, bool>*down_list = new BinarySearchTree<int, bool>; // down binary search tree
    
    // To keep program modular, we will not keep a que of passengers, as that's the floors job
    // instead there the elevator will have a queue of requests for particlular floors as a real eleators do
    struct Request {
        int floor;
        string direction;
    };
	struct Request r = { 3, "down" };

    queue<Request> * requests = new queue<Request>;
    
    // Add passenger to FLOOR que
    void add_to_que(int floor, Passenger * passenger, string direction);
    
    // Add floor to BST
    void add_floor(int floor, string direction);
    
    // Check to see if a car is alreay going to pass the floor **
    bool car_in_route();
    
    // Pick a car that isn't busy **
    // If no car is picked, add request to the request queue
    Car * pick_car();
};
#endif