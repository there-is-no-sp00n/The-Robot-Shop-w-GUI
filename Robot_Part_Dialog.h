#ifndef ROBOT_PART_DIALOG_H
#define ROBOT_PART_DIALOG_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>
#include <iostream>
#include <string>

//#include "Controller.h"
#include "View.h"
#include "Robot.h"

using namespace std;

//string nombre();

class Robot_Part_Dialog
{
	public:
		Robot_Part_Dialog();

		void show_comp(int);

		//void show();
		//void hide();
		void r_dialog(int);

		Robot get_robot();

		//string nombre();
		//{
		//	string nombre;
		//	nombre = name->value();
		//}
		//string number() {return number->value();}
		//string weight() {return weight->value();}
		//string cost() {return cost->value();}
		//string desc() {return description->value();}

	protected:
		//Fl_Window *dialog;
		//Fl_Input *name, *number, *weight, *cost, *description;
		Fl_Return_Button *create;
		Fl_Button *cancel;
		Robot robo_d_ret;
};







#endif