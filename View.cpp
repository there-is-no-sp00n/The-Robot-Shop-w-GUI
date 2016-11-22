#include "View.h"

Robot rob, rob_2;
Robot_Part_Dialog talk;
Make_Robot_Window lets_go;

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

void view_robo_CB (Fl_Widget *w, void *p)
{
	cout << "view robot calllback" << endl;
	
	rob = lets_go.get_robo_m_r();
	rob.print_all_models();	

	Robot_View_Window modelo;
	modelo.show_robot_tab(rob);

	
}

void create_robo_CB(Fl_Widget *w, void *p)
{
	cout << "Create robo CB print" << endl;

	int counter = 1;

	//if (counter == 0)
	//{
	//	rob = lets_go.get_robo_m_r();
	//}

	//else
	//{
	//	rob = talk.get_robot();
	//}

	rob_2 = lets_go.get_robo_m_r();
	rob = talk.get_robot();
	
	cout << "SHOULD PRINT MODELS" << endl;
	rob_2.print_all_models();
	lets_go.make_window(rob, rob_2);
	//rob = lets_go.get_robo_m_r();

	//rob = rob_2;

	//talk.set_robo(rob);
	//talk.f_set();
	
	//cout << "ROB OUT" << endl;
	//rob.print_all_models();

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
			{"Robot Model", 0, (Fl_Callback *)create_robo_CB,0, FL_MENU_DIVIDER},
			{"&Order"},
		{0},
		{"&View", 0,0,0, FL_SUBMENU},
			//{"Comp",0, (Fl_Callback*)view_comp_CB},
			{"Components", 0,0,0,FL_SUBMENU}, //(Fl_Callback*)view_comp_CB},
			{"Head", 0, (Fl_Callback *)view_head_CB},
			{"Torso", 0, (Fl_Callback *)view_torso_CB},
			{"Arm", 0, (Fl_Callback *)view_arm_CB},
			{"Locomotor", 0, (Fl_Callback *)view_loco_CB},
			{"Battery", 0, (Fl_Callback *)view_bat_CB},
			{0},
			{"Robot Model", 0, (Fl_Callback *)view_robo_CB, 0, FL_MENU_DIVIDER},
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
