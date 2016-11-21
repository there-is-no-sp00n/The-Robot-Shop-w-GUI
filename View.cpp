#include "View.h"

Robot rob;
Robot_Part_Dialog talk;

void head_CB (Fl_Widget *w, void *p)
{
	cout << "head callback" << endl;
		
	talk.r_dialog(0);
	rob = talk.get_robot();
	rob.view_comp();
	
}


void torso_CB (Fl_Widget *w, void *p)
{
	cout << "torso callback" << endl;

	talk.r_dialog(1);
	rob = talk.get_robot();
}

void arm_CB (Fl_Widget *w, void *p)
{
	cout << "arm callback" << endl;

	talk.r_dialog(2);
	rob = talk.get_robot();
}

void loco_CB (Fl_Widget *w, void *p)
{
	cout << "locomotor callback" << endl;

	talk.r_dialog(3);
	rob = talk.get_robot();
}

void battery_CB (Fl_Widget *w, void *p)
{
	cout << "battery callback" << endl;

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
	cout << "view head" << endl;

	Head_Window disp;
	rob = talk.get_robot();
	vector <Head> noggin = rob.get_hvec();
	disp.show_head_tab(noggin);
}

void view_torso_CB(Fl_Widget *w, void *p)
{
	cout << "view torso" << endl;

	Torso_Window disp_t;
	rob = talk.get_robot();
	vector <Torso> body = rob.get_tvec();
	disp_t.show_torso_tab(body);
}

void view_arm_CB(Fl_Widget *w, void *p)
{
	cout << "view arm" << endl;

	Arm_Window disp_a;
	rob = talk.get_robot();
	vector <Arm> aarm = rob.get_avec();
	disp_a.show_arm_tab(aarm);
}

void view_loco_CB(Fl_Widget *w, void *p)
{
	cout << "view locomotor" << endl;

	Locomotor_Window disp_l;
	rob = talk.get_robot();
	vector <Locomotor> moto = rob.get_lvec();
	disp_l.see_loco_tab(moto);
}

void view_bat_CB(Fl_Widget *w, void *p)
{
	cout << "view battery" << endl;

	Battery_Window disp_b;
	rob = talk.get_robot();
	vector <Battery> da_pow = rob.get_bvec();
	disp_b.show_battery_tab(da_pow);

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
			{"Torso", 0, (Fl_Callback *)view_torso_CB},
			{"Arm", 0, (Fl_Callback *)view_arm_CB},
			{"Locomotor", 0, (Fl_Callback *)view_loco_CB},
			{"Battery", 0, (Fl_Callback *)view_bat_CB},
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
