#include "Locomotor_Window.h"

int siz_l;
int pos_l;

Fl_Button *nxt_l;
Fl_Button *back_l;

vector <Locomotor> hello_moto;

Fl_Window *tab_win_l;

void show_locos();

void back_CB_l()
{
	if (pos_l == 0)
	{
		//tab_win->hide();
	}

	else if (pos_l <= siz_l)
	{
		tab_win_l->hide();
		pos_l--;
		show_locos();
	}
}


void next_CB_l()
{
	if (pos_l == siz_l)
	{
		//tab_win->hide();
	}

	else if (pos_l < siz_l)
	{
		tab_win_l->hide();
		pos_l++;
		show_locos();
		
	}
}

void show_locos()
{
	cout << "Position for locomotor: " << pos_l << endl;
	cout << "Size for locomotor: " << siz_l << endl;
	
	//FL_Output shit here
	Fl_Output *o_name, *o_number, *o_weight, *o_cost, *o_index, *o_pow_eat, *o_max_speed;
	Fl_Multiline_Output *o_desc;
	

	//this goes to Fl_Output later
	char index[1024];
	char name[1024];
	char num[1024];
	char c_cost[1024];
	char c_weight[1024];
	char desc[1024];
	char pow_eat[1024];
	char max_speed[1024];

	//this is from the vector
	string nombre,ss_cost,ss_weight, indi, pow_eat_s, max_spd_s;
	string numero;
	double cost;
	double wght;
	double pow_num, spd_m;
	string description;

	//set from the vector
	nombre = hello_moto[pos_l].ahoy.comp_name;
	cout << nombre << endl;
	numero = hello_moto[pos_l].ahoy.comp_part_num;
	cout << numero << endl;
	cost = hello_moto[pos_l].ahoy.comp_cost;
	cout << cost << endl;
	wght = hello_moto[pos_l].ahoy.comp_weight;
	cout << wght << endl;
	description = hello_moto[pos_l].ahoy.comp_desc;
	cout << description << endl;
	pow_num = hello_moto[pos_l].get_pow_eat(hello_moto[pos_l]);
	spd_m = hello_moto[pos_l].get_max_speed(hello_moto[pos_l]);

	indi = to_string(static_cast <long long>(pos_l+1));

	//convert from the vector to GUI
	ss_cost = to_string(static_cast <long long>(cost));
	ss_weight = to_string(static_cast < long long >(wght));
	pow_eat_s = to_string(static_cast <long long>(pow_num));
	max_spd_s = to_string(static_cast <long long>(spd_m));

	strncpy(name, nombre.c_str(), sizeof(name));
	strncpy(num, numero.c_str(), sizeof(num));
	strncpy(desc, description.c_str(), sizeof(desc));
	strncpy(c_cost, ss_cost.c_str(), sizeof(c_cost));
	strncpy(c_weight, ss_weight.c_str(), sizeof(c_weight));
	strncpy(index, indi.c_str(), sizeof(index));
	strncpy(pow_eat, pow_eat_s.c_str(), sizeof(pow_eat));
	strncpy(max_speed, max_spd_s.c_str(), sizeof(max_speed));

	//create window for display
	tab_win_l = new Fl_Window(500,500, "ARM");
	
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

	o_max_speed = new Fl_Output(100, 180, 50, 30, "Max Speed:");
	o_max_speed->textsize(10);
	o_max_speed->value(max_speed);

	o_pow_eat = new Fl_Output(100, 200, 50, 30, "Power Consumed:");
	o_pow_eat->textsize(10);
	o_pow_eat->value(pow_eat);

	o_desc = new Fl_Multiline_Output(100,220,50,100, "Desc:");
	o_desc->textsize(10);
	o_desc->value(desc);

	nxt_l = new Fl_Button(100, 300, 60, 25, "NEXT");
	back_l = new Fl_Button(200, 300, 60, 25, "BACK");

	nxt_l->callback((Fl_Callback *)next_CB_l,0);
	back_l->callback((Fl_Callback *)back_CB_l,0);

	//tab_win->redraw();
	tab_win_l->end();
	tab_win_l->show();

}



Locomotor_Window::Locomotor_Window()
{

}

void Locomotor_Window::see_loco_tab(vector <Locomotor> moto)
{
	siz_l = moto.size() - 1;
	hello_moto = moto;
	pos_l = 0;

	if (siz_l != -1)
	{
		show_locos();
	}

}