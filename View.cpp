#include "View.h"

Robot rob;
Robot_Part_Dialog talk;

void head_CB (Fl_Widget *w, void *p)
{
	cout << "aloha" << endl;
		
	talk.r_dialog(0);
	rob = talk.get_robot();
	rob.view_comp();
	
}


void torso_CB (Fl_Widget *w, void *p)
{
	cout << "hola" << endl;

	talk.r_dialog(1);
	rob = talk.get_robot();
}

void arm_CB (Fl_Widget *w, void *p)
{
	cout << "hi" << endl;

	talk.r_dialog(2);
	rob = talk.get_robot();
}

void loco_CB (Fl_Widget *w, void *p)
{
	cout << "ola" << endl;

	talk.r_dialog(3);
	rob = talk.get_robot();
}

void battery_CB (Fl_Widget *w, void *p)
{
	cout << "nihao" << endl;
	talk.r_dialog(4);
	rob = talk.get_robot();
}

void view_comp_CB (Fl_Widget *w, void *p)
{
	cout << "marimba" << endl;
	
	rob = talk.get_robot();
	rob.view_comp();

	string nombre, number, s_wght, s_cst;
	char s_w[1024];
	char c_w[1024];
	double weight,cost;

	vector <Head> noggin = rob.get_hvec();
	int j = noggin.size();
	cout << j << endl;
	for (int i = 0; i < j; i++)
    {
        nombre = noggin[i].ahoy.comp_name;
        number = noggin[i].ahoy.comp_part_num;
        weight = noggin[i].ahoy.comp_weight;
		itoa(weight, s_w,1024);
        cost = noggin[i].ahoy.comp_cost;
		itoa(cost, c_w, 1024);

    }




	
	Scroll_Window obj7;
	obj7.show_scroll(nombre, number, s_w, c_w);

	
}

void view_head_CB(Fl_Widget *w, void *p)
{
	cout << "manana" << endl;

	Tabbed_Window disp;
	rob = talk.get_robot();
	vector <Head> noggin = rob.get_hvec();
	disp.show_head_tab(noggin);
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
			{"Torso", 0, (Fl_Callback*)torso_CB},
			{"Arm", 0, (Fl_Callback*)arm_CB},
			{"Locomotor",0, (Fl_Callback*)loco_CB},
			{"Battery",0, (Fl_Callback*)battery_CB},
			{0},
			{"Robot Model", 0, 0, 0, FL_MENU_DIVIDER},
			{"&Order"},
		{0},
		{"&View", 0,0,0, FL_SUBMENU},
			{"Comp",0, (Fl_Callback*)view_comp_CB},
			{"Components", 0,0,0,FL_SUBMENU}, //(Fl_Callback*)view_comp_CB},
			{"Head", 0, (Fl_Callback *)view_head_CB},
			{"Torso"},
			{"Arm"},
			{"Locomotor"},
			{"Battery"},
			{0},
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
