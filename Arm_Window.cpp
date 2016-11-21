#include "Arm_Window.h"

int siz_a;
int pos_a;

Fl_Button *nxt_a;
Fl_Button *back_a;

vector <Arm> knuckle;

Fl_Window *tab_win_a;

void show_arms();

void back_CB_a()
{
	if (pos_a == 0)
	{
		//tab_win->hide();
	}

	else if (pos_a <= siz_a)
	{
		tab_win_a->hide();
		pos_a--;
		show_arms();
	}
}


void next_CB_a()
{
	if (pos_a == siz_a)
	{
		//tab_win->hide();
	}

	else if (pos_a < siz_a)
	{
		tab_win_a->hide();
		pos_a++;
		show_arms();
		
	}
}

void show_arms()
{
	cout << "Position for arm: " << pos_a << endl;
	cout << "Size for arm: " << siz_a << endl;
	
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
	double pow_con;
	string description;

	//set from the vector
	nombre = knuckle[pos_a].ahoy.comp_name;
	cout << nombre << endl;
	numero = knuckle[pos_a].ahoy.comp_part_num;
	cout << numero << endl;
	cost = knuckle[pos_a].ahoy.comp_cost;
	cout << cost << endl;
	wght = knuckle[pos_a].ahoy.comp_weight;
	cout << wght << endl;
	description = knuckle[pos_a].ahoy.comp_desc;
	cout << description << endl;
	pow_con = knuckle[pos_a].get_arm_power(knuckle[pos_a]);

	indi = to_string(static_cast <long long>(pos_a+1));

	//convert from the vector to GUI
	ss_cost = to_string(static_cast <long long>(cost));
	ss_weight = to_string(static_cast < long long >(wght));
	pow_s = to_string(static_cast <long long>(pow_con));

	strncpy(name, nombre.c_str(), sizeof(name));
	strncpy(num, numero.c_str(), sizeof(num));
	strncpy(desc, description.c_str(), sizeof(desc));
	strncpy(c_cost, ss_cost.c_str(), sizeof(c_cost));
	strncpy(c_weight, ss_weight.c_str(), sizeof(c_weight));
	strncpy(index, indi.c_str(), sizeof(index));
	strncpy(pow, pow_s.c_str(), sizeof(pow));

	//create window for display
	tab_win_a = new Fl_Window(500,500, "ARM");
	
	//put the fields on the window
	o_index = new Fl_Output(100,50,50,30, "Arm #");
	o_index->textsize(10);
	o_index->value(index);

	o_name = new Fl_Output(100,100,50,30, "Arm Name:");
	o_name->textsize(10);
	o_name->value(name); 

	o_number = new Fl_Output(100,120,50,30, "Arm Serial#:");
	o_number->textsize(10);
	o_number->value(num);

	o_weight = new Fl_Output(100,140,50,30, "Arm Weight:");
	o_weight->textsize(10);
	o_weight->value(c_weight);
			
	o_cost = new Fl_Output(100,160,50,30, "Arm Cost:");
	o_cost->textsize(10);
	o_cost->value(c_cost);

	o_pow = new Fl_Output(100, 180, 50, 30, "Power Consumed:");
	o_pow->textsize(10);
	o_pow->value(pow);

	o_desc = new Fl_Multiline_Output(100,200,50,100, "Desc:");
	o_desc->textsize(10);
	o_desc->value(desc);

	nxt_a = new Fl_Button(100, 300, 60, 25, "NEXT");
	back_a = new Fl_Button(200, 300, 60, 25, "BACK");

	nxt_a->callback((Fl_Callback *)next_CB_a,0);
	back_a->callback((Fl_Callback *)back_CB_a,0);

	//tab_win->redraw();
	tab_win_a->end();
	tab_win_a->show();

}


Arm_Window::Arm_Window()
{

}

void Arm_Window::show_arm_tab(vector <Arm> aarm)
{
	siz_a = aarm.size() - 1;
	knuckle = aarm;
	pos_a = 0;

	show_arms();
}