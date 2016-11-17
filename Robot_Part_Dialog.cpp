#include "Robot_Part_Dialog.h"

Fl_Input *name, *number, *weight, *cost, *description, *pow_con;
Fl_Window *dialog;
int type, mode;

Controller boss;

void show()
{
	dialog->show();
}

void hide()
{
	dialog->hide();
}

void input()
{
	string nombre, num, wght, cst;
	double d_wght, d_cst;

	nombre = name->value();
	num = number->value();
	wght = weight->value();
	cst = cost->value();

	d_wght = atof(wght.c_str());
	d_cst = atof(cst.c_str());

	cout << nombre << endl;
	cout << type << endl;
	cout << num << endl;
	cout << d_wght << endl;
	cout << d_cst << endl;

	boss.run_prog(1, type, nombre, num, d_wght, d_cst, 0, 0, 0, 0);
}

void input_arm()
{
	string nombre, num, wght, cst, pow;
	double d_wght, d_cst, d_pow_con;

	nombre = name->value();
	num = number->value();
	wght = weight->value();
	cst = cost->value();
	pow = pow_con->value();

	d_wght = atof(wght.c_str());
	d_cst = atof(cst.c_str());
	d_pow_con = atof(pow.c_str());

	cout << nombre << endl;
	cout << type << endl;
	cout << num << endl;
	cout << d_wght << endl;
	cout << d_cst << endl;
	cout << d_pow_con << endl;

	boss.run_prog(1, type, nombre, num, d_wght, d_cst, d_pow_con, 0, 0, 0);
}

void Robot_Part_Dialog::show_comp(int x, Controller obj)
{
	boss = obj;
	//boss.run_prog(x,0,0,0,0,0);
}

void create_CB (Fl_Widget* w, void* p)
{
	if (type == 0)
	{
		input();
	}

	if (type == 2)
	{
		input_arm();
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

void Robot_Part_Dialog::r_dialog(int x, Controller obj_1)
{
	boss = obj_1;
	dialog = new Fl_Window(340, 270, "Robot Part");
	
	

	type = x;
	//mode = y;
	name = new Fl_Input(120, 10, 210, 25, "Name:");
	number = new Fl_Input(120, 40, 210, 25, "Number:");
	weight = new Fl_Input(120, 70, 210, 25, "Weight:");
	cost = new Fl_Input(120, 100, 210, 25, "Cost:");
	if (type == 2)
	{
		pow_con = new Fl_Input(120, 130, 210, 25, "Power Consumed:");
	}
	create = new Fl_Return_Button(145, 240, 120, 25, "Create");
	create->callback((Fl_Callback *)create_CB,0);
	cancel = new Fl_Button(270, 240, 60, 25, "Cancel");
	cancel->callback((Fl_Callback *)cancel_CB,0);


	dialog->end();
	dialog->set_non_modal();	
	show();
	
}