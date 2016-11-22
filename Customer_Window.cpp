#include "Customer_Window.h"

int size_cust;
int pos_cust;

Fl_Button *nxt_cust;
Fl_Button *back_cust;

vector <Customer> custom;

Fl_Window *tab_win_cust;

void show_customers();

void back_CB_cust()
{
	if (pos_cust == 0)
	{
		//tab_win->hide();
	}

	else if (pos_cust <= size_cust)
	{
		tab_win_cust->hide();
		pos_cust--;
		show_customers();
	}
}


void next_CB_cust()
{
	if (pos_cust == size_cust)
	{
		//tab_win->hide();
	}

	else if (pos_cust < size_cust)
	{
		tab_win_cust->hide();
		pos_cust++;
		show_customers();
		
	}
}

void show_customers()
{
	cout << "Position for Customer: " << pos_cust << endl;
	cout << "Size for Customer: " << size_cust << endl;
	
	//FL_Output shit here
	Fl_Output *o_name, *o_number, *o_weight, *o_cost, *o_index;
	Fl_Multiline_Output *o_desc;
	

	//this goes to Fl_Output later
	char index[1024];
	char name[1024];
	char num[1024];


	//this is from the vector
	string nombre,indi;
	string numero;
	

	//set from the vector
	nombre = custom[pos_cust].get_name();
	cout << nombre << endl;
	numero = custom[pos_cust].get_cell();
	cout << numero << endl;
	
	indi = to_string(static_cast <long long>(pos_cust+1));

	//convert from the vector to GUI

	strncpy(name, nombre.c_str(), sizeof(name));
	strncpy(num, numero.c_str(), sizeof(num));
	strncpy(index, indi.c_str(), sizeof(index));

	//create window for display
	tab_win_cust = new Fl_Window(500,500, "CUSTOMER");
	
	//put the fields on the window
	o_index = new Fl_Output(100,50,50,30, "Customer #");
	o_index->textsize(10);
	o_index->value(index);

	o_name = new Fl_Output(100,100,50,30, "Name:");
	o_name->textsize(10);
	o_name->value(name); 

	o_number = new Fl_Output(100,120,50,30, "Cell #:");
	o_number->textsize(10);
	o_number->value(num);

	

	nxt_cust = new Fl_Button(100, 300, 60, 25, "NEXT");
	back_cust = new Fl_Button(200, 300, 60, 25, "BACK");

	nxt_cust->callback((Fl_Callback *)next_CB_cust,0);
	back_cust->callback((Fl_Callback *)back_CB_cust,0);

	//tab_win->redraw();
	tab_win_cust->end();
	tab_win_cust->show();

}


Customer_Window::Customer_Window()
{

}

void Customer_Window::show_customer_tab(vector <Customer> cust)
{
	custom = cust;
	pos_cust = 0;
	size_cust = cust.size() -1;

	if (size_cust != -1)
	{
		show_customers();
	}
}