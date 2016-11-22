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
		name_3 = name;
		cell_num = num;
	}

	string get_name()
	{
		return name_3;
	}

	string get_cell()
	{
		return cell_num;
	}

	


private:
	string name_3;
	string cell_num;

};


#endif