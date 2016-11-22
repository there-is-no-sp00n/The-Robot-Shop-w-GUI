#include "Head_Window.h"

int size;
int pos;

Fl_Button *nxt;
Fl_Button *back;

vector <Head> nog;

Fl_Window *tab_win;

void show_heads();

void back_CB()
{
	if (pos == 0)
	{
		//tab_win->hide();
	}

	else if (pos <= size)
	{
		tab_win->hide();
		pos--;
		show_heads();
	}
}


void next_CB()
{
	if (pos == size)
	{
		//tab_win->hide();
	}

	else if (pos < size)
	{
		tab_win->hide();
		pos++;
		show_heads();
		
	}
}

void show_heads()
{
	cout << "Position for head: " << pos << endl;
	cout << "Size for head: " << size << endl;
	
	//FL_Output shit here
	Fl_Output *o_name, *o_number, *o_weight, *o_cost, *o_index;
	Fl_Multiline_Output *o_desc;
	

	//this goes to Fl_Output later
	char index[1024];
	char name[1024];
	char num[1024];
	char c_cost[1024];
	char c_weight[1024];
	char desc[1024];

	//this is from the vector
	string nombre,ss_cost,ss_weight, indi;
	string numero;
	double cost;
	double wght;
	string description;

	//set from the vector
	nombre = nog[pos].ahoy.comp_name;
	cout << nombre << endl;
	numero = nog[pos].ahoy.comp_part_num;
	cout << numero << endl;
	cost = nog[pos].ahoy.comp_cost;
	cout << cost << endl;
	wght = nog[pos].ahoy.comp_weight;
	cout << wght << endl;
	description = nog[pos].ahoy.comp_desc;
	cout << description << endl;
	indi = to_string(static_cast <long long>(pos+1));

	//convert from the vector to GUI
	ss_cost = to_string(static_cast <long long>(cost));
	ss_weight = to_string(static_cast < long long >(wght));

	strncpy(name, nombre.c_str(), sizeof(name));
	strncpy(num, numero.c_str(), sizeof(num));
	strncpy(desc, description.c_str(), sizeof(desc));
	strncpy(c_cost, ss_cost.c_str(), sizeof(c_cost));
	strncpy(c_weight, ss_weight.c_str(), sizeof(c_weight));
	strncpy(index, indi.c_str(), sizeof(index));

	//create window for display
	tab_win = new Fl_Window(500,500, "HEAD");
	
	//put the fields on the window
	o_index = new Fl_Output(100,50,50,30, "Head #");
	o_index->textsize(10);
	o_index->value(index);

	o_name = new Fl_Output(100,100,50,30, "Head Name:");
	o_name->textsize(10);
	o_name->value(name); 

	o_number = new Fl_Output(100,120,50,30, "Head Serial#:");
	o_number->textsize(10);
	o_number->value(num);

	o_weight = new Fl_Output(100,140,50,30, "Head Weight:");
	o_weight->textsize(10);
	o_weight->value(c_weight);
			
	o_cost = new Fl_Output(100,160,50,30, "Head Cost:");
	o_cost->textsize(10);
	o_cost->value(c_cost);

	o_desc = new Fl_Multiline_Output(100,180,50,100, "Desc:");
	o_desc->textsize(10);
	o_desc->value(desc);

	nxt = new Fl_Button(100, 300, 60, 25, "NEXT");
	back = new Fl_Button(200, 300, 60, 25, "BACK");

	nxt->callback((Fl_Callback *)next_CB,0);
	back->callback((Fl_Callback *)back_CB,0);

	//tab_win->redraw();
	tab_win->end();
	tab_win->show();

}



Head_Window::Head_Window()
{


}


void Head_Window::show_head_tab(vector <Head> noggin)
{
	size = noggin.size() -1;
	pos = 0;
	nog = noggin;
	
	if (size != -1)
	{
		show_heads();
	}
	


}