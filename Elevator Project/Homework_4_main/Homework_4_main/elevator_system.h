#pragma once
// Controls

#include "bst.h"//
#include <string>
#ifndef ELEVATOR_SYSTEM
#define ELEVATOR_SYSTEM

using namespace std;

//Controls interactions between the Floors and Cars
class Elevator_System
{
public:
    Elevator_System();
    void call_elevator(int floor, string directions);

private:
    static const int number_of_floors = 12;
    BinarySearchTree<int, bool>*up_list = new BinarySearchTree<int, bool>; // up binary search tree
    BinarySearchTree<int, bool>*down_list = new BinarySearchTree<int, bool>; // down binary search tree
    //friend class Car;
};
#endif