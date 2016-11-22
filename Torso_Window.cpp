#include "Torso_Window.h"

int siz_t;
int pos_t;

Fl_Button *nxt_t;
Fl_Button *back_t;

vector <Torso> body;

Fl_Window *tab_win_t;

void show_torsos();

void back_CB_t()
{
	if (pos_t == 0)
	{
		//tab_win->hide();
	}

	else if (pos_t <= siz_t)
	{
		tab_win_t->hide();
		pos_t--;
		show_torsos();
	}
}


void next_CB_t()
{
	if (pos_t == siz_t)
	{
		//tab_win->hide();
	}

	else if (pos_t < siz_t)
	{
		tab_win_t->hide();
		pos_t++;
		show_torsos();
		
	}
}

void show_torsos()
{
	cout << "Position for torso: " << pos_t << endl;
	cout << "Size for torso: " << siz_t << endl;
	
	//FL_Output shit here
	Fl_Output *o_name, *o_number, *o_weight, *o_cost, *o_index, *o_num_of_bat;
	Fl_Multiline_Output *o_desc;
	

	//this goes to Fl_Output later
	char index[1024];
	char name[1024];
	char num[1024];
	char c_cost[1024];
	char c_weight[1024];
	char desc[1024];
	char num_of_bat[1024];

	//this is from the vector
	string nombre,ss_cost,ss_weight, indi, bat_num_s;
	string numero;
	double cost;
	double wght;
	int bat_num;
	string description;

	//set from the vector
	nombre = body[pos_t].ahoy.comp_name;
	cout << nombre << endl;
	numero = body[pos_t].ahoy.comp_part_num;
	cout << numero << endl;
	cost = body[pos_t].ahoy.comp_cost;
	cout << cost << endl;
	wght = body[pos_t].ahoy.comp_weight;
	cout << wght << endl;
	description = body[pos_t].ahoy.comp_desc;
	cout << description << endl;
	bat_num = body[pos_t].get_total_battery(body[pos_t]);

	indi = to_string(static_cast <long long>(pos_t+1));

	//convert from the vector to GUI
	ss_cost = to_string(static_cast <long long>(cost));
	ss_weight = to_string(static_cast < long long >(wght));
	bat_num_s = to_string(static_cast <long long>(bat_num));

	strncpy(name, nombre.c_str(), sizeof(name));
	strncpy(num, numero.c_str(), sizeof(num));
	strncpy(desc, description.c_str(), sizeof(desc));
	strncpy(c_cost, ss_cost.c_str(), sizeof(c_cost));
	strncpy(c_weight, ss_weight.c_str(), sizeof(c_weight));
	strncpy(index, indi.c_str(), sizeof(index));
	strncpy(num_of_bat, bat_num_s.c_str(), sizeof(num_of_bat));

	//create window for display
	tab_win_t = new Fl_Window(500,500, "TORSO");
	
	//put the fields on the window
	o_index = new Fl_Output(100,50,50,30, "Torso #");
	o_index->textsize(10);
	o_index->value(index);

	o_name = new Fl_Output(100,100,50,30, "Torso Name:");
	o_name->textsize(10);
	o_name->value(name); 

	o_number = new Fl_Output(100,120,50,30, "Torso Serial#:");
	o_number->textsize(10);
	o_number->value(num);

	o_weight = new Fl_Output(100,140,50,30, "Torso Weight:");
	o_weight->textsize(10);
	o_weight->value(c_weight);
			
	o_cost = new Fl_Output(100,160,50,30, "Torso Cost:");
	o_cost->textsize(10);
	o_cost->value(c_cost);

	o_num_of_bat = new Fl_Output(100, 180, 50, 30, "Battery Slot(s):");
	o_num_of_bat->textsize(10);
	o_num_of_bat->value(num_of_bat);

	o_desc = new Fl_Multiline_Output(100,200,50,100, "Desc:");
	o_desc->textsize(10);
	o_desc->value(desc);

	nxt_t = new Fl_Button(100, 300, 60, 25, "NEXT");
	back_t = new Fl_Button(200, 300, 60, 25, "BACK");

	nxt_t->callback((Fl_Callback *)next_CB_t,0);
	back_t->callback((Fl_Callback *)back_CB_t,0);

	//tab_win->redraw();
	tab_win_t->end();
	tab_win_t->show();

}



Torso_Window::Torso_Window()
{


}


void Torso_Window::show_torso_tab(vector <Torso> belly)
{
	siz_t = belly.size() -1;
	pos_t = 0;
	body = belly;
	
	if (siz_t != -1)
	{
		show_torsos();
	}


}

