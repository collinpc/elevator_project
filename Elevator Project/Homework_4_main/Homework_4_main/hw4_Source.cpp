#include <iostream>
#include "passenger.h"
#include "bst.h"
#include <cstdlib>

using namespace std;


int main()
{
    Passenger* pass1 = new Passenger();
    pass1->calculate_trip_time();
	cout << pass1->get_wait_total() << endl << endl;
	//i changed thisewwe


	BinarySearchTree<int, bool>*bst = new BinarySearchTree<int, bool>;

	bst->Add(5, false);
	bst->Add(6, true);

	cout << bst->Get(5);


	system("PAUSE");

	return 0;




	system("PAUSE");
    return 0;

}