#include "View.h"

Controller obj;
Robot_Part_Dialog talk;

void head_CB (Fl_Widget *w, void *p)
{
	cout << "aloha" << endl;
	talk.r_dialog(0, obj);
	//obj.run_prog(1, 0);
}

void arm_CB (Fl_Widget *w, void *p)
{
	cout << "hi" << endl;
	talk.r_dialog(2, obj);
}

void view_comp_CB (Fl_Widget *w, void *p)
{
	cout << "marimba" << endl;
	talk.show_comp(2, obj);
}
View::View()
{

}


int View::show_the_goods()
{	
	const int X = 360;
	const int Y = 220;

	Fl_Window *win = new Fl_Window(X, Y, "Robot Shop Manager");

	//Fl_Box *box = new Fl_Box(20, 30, 300, 100, "Hello");
	

	Fl_Menu_Bar *menubar = new Fl_Menu_Bar(0,0,X,30);

	Fl_Menu_Item menuitems[] = {
		{"&Create", 0, 0, 0, FL_SUBMENU},
			{"&Robot Parts", 0, 0, 0, FL_SUBMENU},
			{"Head", 0, (Fl_Callback*)head_CB},
			{"Torso"},
			{"Arm", 0, (Fl_Callback*)arm_CB},
			{"Locomotor"},
			{"Battery"},
			{0},
			{"Robot Model", 0, 0, 0, FL_MENU_DIVIDER},
			{"&Order"},
		{0},
		{"&View", 0,0,0, FL_SUBMENU},
			{"Components", 0, (Fl_Callback*)view_comp_CB},
			{"Robot Model", 0, 0, 0, FL_MENU_DIVIDER},
			{"Bill of Sale"},
			{"Order by SA"},
			{"All Orders"},
			{"Sales Report"},
		{0},
		{0}
	};

	menubar->menu(menuitems);

	//Robot_Part_Dialog obj;

	win->end();
	win->show();

	return Fl::run();
}
