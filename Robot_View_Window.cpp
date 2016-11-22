#include "Robot_View_Window.h"

int siz_r_v;
int pos_r_v;

Fl_Button *nxt_r_v;
Fl_Button *back_r_v;

Robot r_modelo;

Fl_Window *tab_win_r_v;

void show_robots();

void back_CB_r_v()
{
	if (pos_r_v == 0)
	{
		//tab_win->hide();
	}

	else if (pos_r_v <= siz_r_v)
	{
		tab_win_r_v->hide();
		pos_r_v--;
		show_robots();
	}
}


void next_CB_r_v()
{
	if (pos_r_v == siz_r_v)
	{
		//tab_win->hide();
	}

	else if (pos_r_v < siz_r_v)
	{
		tab_win_r_v->hide();
		pos_r_v++;
		show_robots();
		
	}
}

void show_robots()
{
	cout << "Position for robot_vec: " << pos_r_v << endl;
	cout << "Size for robot_vec: " << siz_r_v << endl;
	
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
	string nombre,ss_retail,ss_weight, indi;
	string numero;
	double retail;
	double wght;
	string description;

	//set from the vector
	nombre = r_modelo.ret_name(pos_r_v);
	cout << nombre << endl;
	numero = r_modelo.ret_num(pos_r_v);
	cout << numero << endl;
	retail = r_modelo.ret_retail(pos_r_v);
	cout << retail << endl;
	wght = r_modelo.ret_weight(pos_r_v);
	cout << wght << endl;
	description = r_modelo.ret_desc(pos_r_v);
	cout << description << endl;

	indi = to_string(static_cast <long long>(pos_r_v+1));

	//convert from the vector to GUI
	ss_retail = to_string(static_cast <long long>(retail));
	ss_weight = to_string(static_cast < long long >(wght));
	//pow_s = to_string(static_cast <long long>(pow_con));

	strncpy(name, nombre.c_str(), sizeof(name));
	strncpy(num, numero.c_str(), sizeof(num));
	strncpy(desc, description.c_str(), sizeof(desc));
	strncpy(c_cost, ss_retail.c_str(), sizeof(c_cost));
	strncpy(c_weight, ss_weight.c_str(), sizeof(c_weight));
	strncpy(index, indi.c_str(), sizeof(index));
	//strncpy(pow, pow_s.c_str(), sizeof(pow));

	//create window for display
	tab_win_r_v = new Fl_Window(500,500, "ROBOT");
	
	//put the fields on the window
	o_index = new Fl_Output(100,50,50,30, "Robot #");
	o_index->textsize(10);
	o_index->value(index);

	o_name = new Fl_Output(100,100,50,30, "Robot Name:");
	o_name->textsize(10);
	o_name->value(name); 

	o_number = new Fl_Output(100,120,50,30, "Robot Serial#:");
	o_number->textsize(10);
	o_number->value(num);

	o_weight = new Fl_Output(100,140,50,30, "Robot Weight:");
	o_weight->textsize(10);
	o_weight->value(c_weight);
			
	o_cost = new Fl_Output(100,160,50,30, "Robot Price:");
	o_cost->textsize(10);
	o_cost->value(c_cost);

	o_desc = new Fl_Multiline_Output(100,200,50,100, "Desc:");
	o_desc->textsize(10);
	o_desc->value(desc);

	nxt_r_v = new Fl_Button(100, 300, 60, 25, "NEXT");
	back_r_v = new Fl_Button(200, 300, 60, 25, "BACK");

	nxt_r_v->callback((Fl_Callback *)next_CB_r_v,0);
	back_r_v->callback((Fl_Callback *)back_CB_r_v,0);

	//tab_win->redraw();
	tab_win_r_v->end();
	tab_win_r_v->show();

}

Robot_View_Window::Robot_View_Window()
{

}


void Robot_View_Window::show_robot_tab(Robot rot)
{
	cout << "robot vector size" << rot.ret_r_vec_size() << endl;
	siz_r_v = rot.ret_r_vec_size()-1;
	r_modelo = rot;
	pos_r_v = 0;

	if (siz_r_v != -1)
	{
		show_robots();
	}
}