#include "Robot_Part_Dialog.h"

Fl_Input *name, *number, *weight, *cost, *pow_con, *max_speed, *num_of_bat, *bat_pow;
Fl_Multiline_Input *description;
Fl_Window *dialog;
int type, mode;

Robot robbie;

void show()
{
	dialog->show();
}

void hide()
{
	dialog->hide();
}

//input for head
void input_head()
{
	string nombre, num, wght, cst, desc;
	double d_wght, d_cst;

	nombre = name->value();
	num = number->value();
	wght = weight->value();
	cst = cost->value();
	desc = description->value();

	d_wght = atof(wght.c_str());
	d_cst = atof(cst.c_str());

	cout << nombre << endl;
	cout << type << endl;
	cout << num << endl;
	cout << d_wght << endl;
	cout << d_cst << endl;
	cout << desc << endl;

	robbie.create_comp (0, nombre, num, desc, d_wght, d_cst, 0, 0, 0, 0);
}

//input for torso
void input_torso()
{
	string nombre, num, wght, cst, n_of_bat, desc;
	double d_wght, d_cst;
	int i_bat;

	nombre = name->value();
	num = number->value();
	wght = weight->value();
	cst = cost->value();
	n_of_bat = num_of_bat->value();
	desc = description->value();

	d_wght = atof(wght.c_str());
	d_cst = atof(cst.c_str());
	i_bat = stoi(n_of_bat);

	cout << nombre << endl;
	cout << type << endl;
	cout << num << endl;
	cout << d_wght << endl;
	cout << d_cst << endl;
	cout << i_bat << endl;
	cout << desc << endl;

	robbie.create_comp(1, nombre, num, desc, d_wght, d_cst, 0, 0, 0, i_bat);
}

//input for arm
void input_arm()
{
	string nombre, num, wght, cst, pow, desc;
	double d_wght, d_cst, d_pow_con;

	nombre = name->value();
	num = number->value();
	wght = weight->value();
	cst = cost->value();
	pow = pow_con->value();
	desc = description->value();

	d_wght = atof(wght.c_str());
	d_cst = atof(cst.c_str());
	d_pow_con = atof(pow.c_str());

	cout << nombre << endl;
	cout << type << endl;
	cout << num << endl;
	cout << d_wght << endl;
	cout << d_cst << endl;
	cout << d_pow_con << endl;
	cout << desc << endl;

	robbie.create_comp(2, nombre, num, desc, d_wght, d_cst, d_pow_con, 0, 0, 0);
}

//input locomotor
void input_loco()
{
	//cout << "ola1" << endl;
	string nombre, num, wght, cst, desc, m_spd, b_pow;
	double d_wght, d_cst, d_pow, dm_spd;

	//cout << "ola2" << endl;
	nombre = name->value();
	num = number->value();
	wght = weight->value();
	cst = cost->value();
	b_pow = pow_con->value();
	m_spd = max_speed->value();
	desc = description->value();

	//cout << "ola3" << endl;
	d_wght = atof(wght.c_str());
	d_cst = atof(cst.c_str());
	d_pow = atof(b_pow.c_str());
	dm_spd = atof(m_spd.c_str());

	cout << nombre << endl;
	cout << type << endl;
	cout << num << endl;
	cout << d_wght << endl;
	cout << d_cst << endl;
	cout << d_pow << endl;
	cout << desc << endl;

	robbie.create_comp(3, nombre, num, desc, d_wght, d_cst, 0, dm_spd, d_pow, 0);
}

//input battery
void input_battery()
{
	string nombre, num, wght, cst, pow, desc;
	double d_wght, d_cst, d_pow_con;

	nombre = name->value();
	num = number->value();
	wght = weight->value();
	cst = cost->value();
	pow = bat_pow->value();
	desc = description->value();

	d_wght = atof(wght.c_str());
	d_cst = atof(cst.c_str());
	d_pow_con = atof(pow.c_str());

	cout << nombre << endl;
	cout << type << endl;
	cout << num << endl;
	cout << d_wght << endl;
	cout << d_cst << endl;
	cout << d_pow_con << endl;
	cout << desc << endl;

	robbie.create_comp(4, nombre, num, desc, d_wght, d_cst, d_pow_con, 0, 0, 0);
}


void create_CB (Fl_Widget* w, void* p)
{
	if (type == 0)
	{
		input_head();
	}

	if (type == 1)
	{
		input_torso();
	}

	if (type == 2)
	{
		input_arm();
	}

	if (type == 3)
	{
		input_loco();
	}

	if (type == 4)
	{
		input_battery();
	}
	
	hide();
}

void cancel_CB (Fl_Widget *w, void *p)
{
	hide();
}

Robot_Part_Dialog::Robot_Part_Dialog()
{

}

void Robot_Part_Dialog::r_dialog(int x)
{
	dialog = new Fl_Window(340, 270, "Robot Part");
	
	

	type = x;
	name = new Fl_Input(120, 10, 210, 25, "Name:");
	number = new Fl_Input(120, 40, 210, 25, "Number:");
	weight = new Fl_Input(120, 70, 210, 25, "Weight:");
	cost = new Fl_Input(120, 100, 210, 25, "Cost:");
	
	if (type == 0)
	{
		description = new Fl_Multiline_Input(120, 130, 210, 50, "Description:");
	}

	if (type == 1)
	{
		num_of_bat = new Fl_Input(120,130,210,25, "Num of Battery:");
		description = new Fl_Multiline_Input(120, 160, 210, 50, "Description:");
	}

	if (type == 2)
	{
		pow_con = new Fl_Input(120, 130, 210, 25, "Power Consumed:");
		description = new Fl_Multiline_Input(120, 160, 210, 50, "Description:");
	}

	if (type == 3)
	{
		max_speed = new Fl_Input(120,130,210,25, "Max Speed:");
		pow_con = new Fl_Input(120,160,210,25, "Power Consumed: ");
		description = new Fl_Multiline_Input(120, 190, 210, 50, "Description:");
	}

	if (type == 4)
	{
		bat_pow = new Fl_Input(120,130,210,25, "Battery Power:");
		description = new Fl_Multiline_Input(120, 160, 210, 50, "Description:");
	}

	create = new Fl_Return_Button(145, 240, 120, 25, "Create");
	create->callback((Fl_Callback *)create_CB,0);
	cancel = new Fl_Button(270, 240, 60, 25, "Cancel");
	cancel->callback((Fl_Callback *)cancel_CB,0);


	dialog->end();
	dialog->set_non_modal();	
	show();
	
}

Robot Robot_Part_Dialog::get_robot()
{
	return robbie;
}