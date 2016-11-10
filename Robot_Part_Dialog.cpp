#include "Robot_Part_Dialog.h"

Robot_Part_Dialog::Robot_Part_Dialog()
{
	Fl_Window *dialog = new Fl_Window(340, 270, "Robot Part");

	Fl_Input *name, *number, *weight, *cost, *description;

	name = new Fl_Input(120, 10, 210, 25, "Name:");
	number = new Fl_Input(120, 40, 210, 25, "Type:");
	weight = new Fl_Input(120, 70, 210, 25, "Weight:");
	cost = new Fl_Input(120, 100, 210, 25, "Cost:");

	dialog->end();
	dialog->set_non_modal();

	dialog->show();
	dialog->hide();
}