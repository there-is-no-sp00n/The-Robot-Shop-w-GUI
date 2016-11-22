#ifndef ORDER_WINDOW_H
#define ORDER_WINDOW_H

#include <iostream>
#include <vector>

#include "Customer.h"
#include "Sales_Associate.h"
#include "View.h"


class Order_Window
{
public:
	Order_Window();

	Order_Window(string cust_n, string sa_nomb, string num, string date_3, double price, double weight)
	{
		o_c_name = cust_n;
		o_sa_name = sa_nomb;
		o_number = num;
		o_date = date_3;
		total_price = price;
		total_weight = weight;
	}

	void make_my_money(vector <Customer>, vector <Sales_Associate>, Robot);

	vector <Order_Window> get_ordersss();

	string get_c_name()
	{
		return o_c_name;
	}

	string get_sa_name()
	{
		return o_sa_name;
	}

	string get_o_number()
	{
		return o_number;
	}

	string get_o_date()
	{
		return o_date;
	}

	double get_da_f_price()
	{
		return total_price;
	}

	double get_da_f_weight()
	{
		return total_weight;
	}
private:
	string o_c_name;
	string o_sa_name;
	string o_number;
	string o_date;
	double total_price;
	double total_weight;

};


#endif