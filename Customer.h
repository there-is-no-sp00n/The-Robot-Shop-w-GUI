#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>

using namespace std;

class Customer
{
public:
	Customer();

	Customer(string name, string num)
	{
		name = name;
		cell_num = num;
	}

	void cust_input();



private:
	string name;
	string cell_num;
};


#endif