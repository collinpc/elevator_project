#pragma once
// Controls

#include "bst.h";
#ifndef ELEVATOR_SYSTEM
#define ELEVATOR_SYSTEM



//Controls interactions between the Floors and Cars
class Elevator_System
{
public:
    Elevator_System();
    void call_elevator(int floor);

private:
    BinarySearchTree<int, bool>*up_list = new BinarySearchTree<int, bool>; // up binary search tree
    BinarySearchTree<int, bool>*down_list = new BinarySearchTree<int, bool>; // down binary search tree
}
#endif