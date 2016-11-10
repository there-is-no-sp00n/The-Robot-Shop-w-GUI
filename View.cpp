#include "View.h"

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
		{"&Create", 0,0,0, FL_SUBMENU},
			{"&Robot Parts", 0, 0, 0, FL_SUBMENU},
			{"Head"},
			{"Torso"},
			{"Arm"},
			{"Locomotor"},
			{"Battery"},
			{0},
			{"Robot Model", 0, 0, 0, FL_MENU_DIVIDER},
			{"&Order"},
		{0},
		{"&View", 0,0,0, FL_SUBMENU},
			{"Components"},
			{"Robot Model", 0, 0, 0, FL_MENU_DIVIDER},
			{"Bill of Sale"},
			{"Order by SA"},
			{"All Orders"},
			{"Sales Report"},
		{0},
		{0}
	};

	menubar->menu(menuitems);

	win->end();
	win->show();

	return Fl::run();
}
