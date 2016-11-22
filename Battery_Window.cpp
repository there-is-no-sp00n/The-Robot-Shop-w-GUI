#include "Battery_Window.h"


int siz_b;
int pos_b;

Fl_Button *nxt_b;
Fl_Button *back_b;

vector <Battery> farad;

Fl_Window *tab_win_b;

void show_batteries();

void back_CB_b()
{
	if (pos_b == 0)
	{
		//tab_win->hide();
	}

	else if (pos_b <= siz_b)
	{
		tab_win_b->hide();
		pos_b--;
		show_batteries();
	}
}


void next_CB_b()
{
	if (pos_b == siz_b)
	{
		//tab_win->hide();
	}

	else if (pos_b < siz_b)
	{
		tab_win_b->hide();
		pos_b++;
		show_batteries();
		
	}
}

void show_batteries()
{
	cout << "Position for torso: " << pos_b << endl;
	cout << "Size for torso: " << siz_b << endl;
	
	//FL_Output shit here
	Fl_Output *o_name, *o_number, *o_weight, *o_cost, *o_index, *o_pow;
	Fl_Multiline_Output *o_desc;
	

	//this goes to Fl_Output later
	char index[1024];
	char name[1024];
	char num[1024];
	char c_cost[1024];
	char c_weight[1024];
	char desc[1024];
	char pow[1024];

	//this is from the vector
	string nombre,ss_cost,ss_weight, indi, pow_s;
	string numero;
	double cost;
	double wght;
	double pow_v;
	string description;

	//set from the vector
	nombre = farad[pos_b].ahoy.comp_name;
	cout << nombre << endl;
	numero = farad[pos_b].ahoy.comp_part_num;
	cout << numero << endl;
	cost = farad[pos_b].ahoy.comp_cost;
	cout << cost << endl;
	wght = farad[pos_b].ahoy.comp_weight;
	cout << wght << endl;
	description = farad[pos_b].ahoy.comp_desc;
	cout << description << endl;
	pow_v = farad[pos_b].get_battery(farad[pos_b]);

	indi = to_string(static_cast <long long>(pos_b+1));

	//convert from the vector to GUI
	ss_cost = to_string(static_cast <long long>(cost));
	ss_weight = to_string(static_cast < long long >(wght));
	pow_s = to_string(static_cast <long long>(pow_v));

	strncpy(name, nombre.c_str(), sizeof(name));
	strncpy(num, numero.c_str(), sizeof(num));
	strncpy(desc, description.c_str(), sizeof(desc));
	strncpy(c_cost, ss_cost.c_str(), sizeof(c_cost));
	strncpy(c_weight, ss_weight.c_str(), sizeof(c_weight));
	strncpy(index, indi.c_str(), sizeof(index));
	strncpy(pow, pow_s.c_str(), sizeof(pow));

	//create window for display
	tab_win_b = new Fl_Window(500,500, "BATTERY");
	
	//put the fields on the window
	o_index = new Fl_Output(100,50,50,30, "Battery #");
	o_index->textsize(10);
	o_index->value(index);

	o_name = new Fl_Output(100,100,50,30, "Battery Name:");
	o_name->textsize(10);
	o_name->value(name); 

	o_number = new Fl_Output(100,120,50,30, "Battery Serial#:");
	o_number->textsize(10);
	o_number->value(num);

	o_weight = new Fl_Output(100,140,50,30, "Battery Weight:");
	o_weight->textsize(10);
	o_weight->value(c_weight);
			
	o_cost = new Fl_Output(100,160,50,30, "Battery Cost:");
	o_cost->textsize(10);
	o_cost->value(c_cost);

	o_pow = new Fl_Output(100, 180, 50, 30, "Power:");
	o_pow->textsize(10);
	o_pow->value(pow);

	o_desc = new Fl_Multiline_Output(100,200,50,100, "Desc:");
	o_desc->textsize(10);
	o_desc->value(desc);

	nxt_b = new Fl_Button(100, 300, 60, 25, "NEXT");
	back_b = new Fl_Button(200, 300, 60, 25, "BACK");

	nxt_b->callback((Fl_Callback *)next_CB_b,0);
	back_b->callback((Fl_Callback *)back_CB_b,0);

	//tab_win->redraw();
	tab_win_b->end();
	tab_win_b->show();

}



Battery_Window::Battery_Window()
{

}

void Battery_Window::show_battery_tab(vector <Battery> da_pow)
{
	pos_b = 0;
	farad = da_pow;
	siz_b = da_pow.size() - 1;

	if (siz_b != -1)
	{
		show_batteries();
	}

	


}