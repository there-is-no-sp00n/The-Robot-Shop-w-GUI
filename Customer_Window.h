#ifndef CUSTOMER_WINDOW_H
#define CUSTOMER_WINDOW_H

#include "View.h"
#include "Customer.h"

using namespace std;

class Customer_Window
{
public:
	Customer_Window();

	void show_customer_tab(vector <Customer>);
};


#endif