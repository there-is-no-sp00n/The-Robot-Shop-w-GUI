#include "Sales_Associate_Window.h"

int size_sa;
int pos_sa;

Fl_Button *nxt_sa;
Fl_Button *back_sa;

vector <Sales_Associate> association;

Fl_Window *tab_win_sa;

void show_associates();

void back_CB_sa()
{
	if (pos_sa == 0)
	{
		//tab_win->hide();
	}

	else if (pos_sa <= size_sa)
	{
		tab_win_sa->hide();
		pos_sa--;
		show_associates();
	}
}


void next_CB_sa()
{
	if (pos_sa == size_sa)
	{
		//tab_win->hide();
	}

	else if (pos_sa < size_sa)
	{
		tab_win_sa->hide();
		pos_sa++;
		show_associates();
		
	}
}

void show_associates()
{
	cout << "Position for Customer: " << pos_sa << endl;
	cout << "Size for Customer: " << size_sa << endl;
	
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
	nombre = association[pos_sa].get_sa_name();
	cout << nombre << endl;
	numero = association[pos_sa].get_sa_id();
	cout << numero << endl;
	
	indi = to_string(static_cast <long long>(pos_sa+1));

	//convert from the vector to GUI

	strncpy(name, nombre.c_str(), sizeof(name));
	strncpy(num, numero.c_str(), sizeof(num));
	strncpy(index, indi.c_str(), sizeof(index));

	//create window for display
	tab_win_sa = new Fl_Window(500,500, "SALES ASSOCIATE");
	
	//put the fields on the window
	o_index = new Fl_Output(100,50,50,30, "Associate #");
	o_index->textsize(10);
	o_index->value(index);

	o_name = new Fl_Output(100,100,50,30, "Name:");
	o_name->textsize(10);
	o_name->value(name); 

	o_number = new Fl_Output(100,120,50,30, "ID #:");
	o_number->textsize(10);
	o_number->value(num);

	

	nxt_sa = new Fl_Button(100, 300, 60, 25, "NEXT");
	back_sa = new Fl_Button(200, 300, 60, 25, "BACK");

	nxt_sa->callback((Fl_Callback *)next_CB_sa,0);
	back_sa->callback((Fl_Callback *)back_CB_sa,0);

	//tab_win->redraw();
	tab_win_sa->end();
	tab_win_sa->show();

}


Sales_Associate_Window::Sales_Associate_Window()
{

}

void Sales_Associate_Window::show_asso_tab(vector <Sales_Associate> unio)
{
	association = unio;
	pos_sa = 0;
	size_sa = unio.size() -1;

	if (size_sa != -1)
	{
		show_associates();
	}
}