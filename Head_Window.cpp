#include "Tabbed_Window.h"

int size;
int pos;
Fl_Button *nxt;

vector <Head> nog;

Fl_Window *tab_win;
Fl_Hold_Browser *browser;
Fl_Group *da_info;
Fl_Tabs *tabs;


void next_CB()
{
	if (pos > size)
	{
		//show_head_tab(nog);
		cout << "pos1" << pos << endl;
		cout << "size" << size << endl;
		tab_win->hide();
	}

	else if (pos <= size)
	{
		pos++;
		cout << "pos2" << pos << endl;
		cout << "size" << size << endl;
		//pos++;
		//size--;

		//FL_Output shit here
		tab_win->hide();
		cout << "pos3" << pos << endl;
		cout << "size" << size << endl;
		Fl_Output *o_name, *o_number, *o_weight, *o_cost;
		Fl_Multiline_Output *o_desc;
	

		//this goes to Fl_Output later
		char name[1024];
		char num[1024];
		char c_cost[1024];
		char c_weight[1024];
		char desc[1024];

		//this is from the vector
		string nombre,ss_cost,ss_weight;
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

		//convert from the vector to GUI
		ss_cost = to_string(static_cast <long long>(cost));
		ss_weight = to_string(static_cast < long long >(wght));

		strncpy(name, nombre.c_str(), sizeof(name));
		strncpy(num, numero.c_str(), sizeof(num));
		strncpy(desc, description.c_str(), sizeof(desc));
		strncpy(c_cost, ss_cost.c_str(), sizeof(c_cost));
		strncpy(c_weight, ss_weight.c_str(), sizeof(c_weight));
		cout << "pos4" << pos << endl;
		cout << "size" << size << endl;
		tab_win = new Fl_Window(1000,1000, "HEAD");
							
		o_name = new Fl_Output(100,100,50,30, "Head Name:");
		o_name->textsize(10);
		o_name->value(name); 

		o_number = new Fl_Output(100,120,50,30, "Head Number:");
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

		nxt = new Fl_Button(500, 500, 60, 25, "NEXT");
		cout << "pos" << pos << endl;

		cout << pos << endl;
		nxt->callback((Fl_Callback *)next_CB,0);

		cout << "pos" << pos << endl;

		tab_win->redraw();
		tab_win->end();
		tab_win->show();
		
	}
}
Tabbed_Window::Tabbed_Window()
{


}


void Tabbed_Window::show_head_tab(vector <Head> noggin)
{
	size = noggin.size() -1;
	nog = noggin;
	pos=-1;
	pos++;

	cout << pos << endl;

	//FL_Output shit here
	Fl_Output *o_name, *o_number, *o_weight, *o_cost;
	Fl_Multiline_Output *o_desc;
	

	//this goes to Fl_Output later
	char name[1024];
	char num[1024];
	char c_cost[1024];
	char c_weight[1024];
	char desc[1024];

	//this is from the vector
	string nombre;
	string numero;
	string s_weight, s_cost;
	double cost;
	double wght;
	string description;


		//set from the vector
		nombre = noggin[pos].ahoy.comp_name;
		cout << nombre << endl;
		numero = noggin[pos].ahoy.comp_part_num;
		cout << numero << endl;
		cost = noggin[pos].ahoy.comp_cost;
		cout << cost << endl;
		wght = noggin[pos].ahoy.comp_weight;
		cout << wght << endl;
		description = noggin[pos].ahoy.comp_desc;
		cout << description << endl;

		//convert from the vector to GUI
		s_cost = to_string(static_cast <long long>(cost));
		s_weight = to_string(static_cast < long long >(wght));

		strncpy(name, nombre.c_str(), sizeof(name));
		strncpy(num, numero.c_str(), sizeof(num));
		strncpy(desc, description.c_str(), sizeof(desc));
		strncpy(c_cost, s_cost.c_str(), sizeof(c_cost));
		strncpy(c_weight, s_weight.c_str(), sizeof(c_weight));
		

		//itoa(cost, c_cost, 1024);
		//itoa(wght, c_wight, 1024);

		tab_win = new Fl_Window(1000,1000, "HEAD");
							
		o_name = new Fl_Output(100,100,50,30, "Head Name:");
		o_name->textsize(10);
		o_name->value(name); 

		o_number = new Fl_Output(100,120,50,30, "Head Number:");
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

		next = new Fl_Button(500, 500, 60, 25, "NEXT");
		cout << "pos" << pos << endl;

		cout << pos << endl;
		next->callback((Fl_Callback *)next_CB,0);

		cout << "pos" << pos << endl;

		tab_win->end();
		tab_win->show();


}

