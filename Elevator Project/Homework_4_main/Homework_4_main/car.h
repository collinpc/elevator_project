#pragma once

// knows wait times, knows how long at each floor, knows passengers

#ifndef CAR
#define CAR
#include <iostream>
#include <queue>
#include <map>
#include "bst.h"
using namespace std;



class Car
{
private:

	int travel_time_total;
	int const time_between_floors = 3; // seconds
	int const min_floor_time = 5; // seconds
	int const pass_load_time = 1; // Time for each passenger to load
	int const home_floor = 3; // home floor
	int const floor_current = 3;
	
	static BinarySearchTree<int, bool>*up_list = new BinarySearchTree<int, bool>; // up binary search treee
	static BinarySearchTree<int, bool>*down_list = new BinarySearchTree<int, bool>; // down binary search tree



	
	

	






public:

	void go_up(); 
	void go_down();




};












#endif