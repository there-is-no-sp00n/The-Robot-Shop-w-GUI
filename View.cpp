#include "View.h"

Robot rob, rob_2;
Robot_Part_Dialog talk;
Make_Robot_Window lets_go;

vector <Customer> cust_list;
vector <Sales_Associate> sa_list;


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

//**
//customer and sales associate input

Fl_Window *cust_win;
Fl_Input *cust_name, *cust_id;
string names, cell_nums;

void enter_cust_CB(Fl_Widget *w, void *p)
{

	cust_win->hide();

	names = cust_name->value();
	cell_nums = cust_id->value();
	
	cout << "Name: " << names << endl;
	cout << "Cell: " << cell_nums << endl;

	Customer beloved(names, cell_nums);
	cust_list.push_back(beloved);

	cout << "Customer Size:" << cust_list.size() << endl;
}

void create_cust_CB(Fl_Widget *w, void *p)
{
	cout << "create customer callback" << endl;	
	
	Fl_Button *create_cust;

	cust_win = new Fl_Window(400,400, "Customer Input");
	cust_name = new Fl_Input(150,100, 100,60, "Customer Name:");
	cust_id = new Fl_Input(150,200, 100,60, "Customer Cell:");

	create_cust = new Fl_Button(300,300, 70,50, "CREATE");
	create_cust->callback((Fl_Callback*)enter_cust_CB,0);

	cust_win->end();
	cust_win->show();

}

void enter_sa_CB(Fl_Widget *w, void *p)
{
	cust_win->hide();

	names = cust_name->value();
	cell_nums = cust_id->value();
	
	cout << "Name: " << names << endl;
	cout << "ID: " << cell_nums << endl;

	Sales_Associate dinero(names, cell_nums);
	sa_list.push_back(dinero);

	cout << "Sales Associate Size:" << sa_list.size() << endl;
}

void create_sa_CB(Fl_Widget *w, void *p)
{
	cout << "create sales associate callback" << endl;	
	
	Fl_Button *create_sa;

	cust_win = new Fl_Window(400,400, "Sales Associate Input");
	cust_name = new Fl_Input(150,100, 100,60, "Associate Name:");
	cust_id = new Fl_Input(150,200, 100,60, "Associate ID:");

	create_sa = new Fl_Button(300,300, 70,50, "CREATE");
	create_sa->callback((Fl_Callback*)enter_sa_CB,0);

	cust_win->end();
	cust_win->show();
}

//**

Order_Window da_orders;
vector <Order_Window> all_da_info;

void create_order_CB(Fl_Widget *w, void *p)
{
	all_da_info = da_orders.get_ordersss();
	rob_2 = lets_go.get_robo_m_r();
	cout << "create order CB" << endl;
	cout << cust_list.size() << endl;
	da_orders.make_my_money(cust_list, sa_list, rob_2);
	cout << "size of order in view " << all_da_info.size() << endl;
	
	//cout << "size of order in view " << all_da_info.size() << endl;

}

void view_customer_CB(Fl_Widget *w, void *p)
{
	cout << "view customer callback" << endl;
	Customer_Window coco;
	coco.show_customer_tab(cust_list);

}

void view_sa_CB(Fl_Widget *w, void *p)
{
	cout << "view sa callback" << endl;
	Sales_Associate_Window polo;
	polo.show_asso_tab(sa_list);
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
			{"&Order",0 ,(Fl_Callback *)create_order_CB,0, FL_MENU_DIVIDER},
			{"Customer",0, (Fl_Callback *)create_cust_CB},
			{"Sales Associate", 0, (Fl_Callback *)create_sa_CB},
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
			{"Customer",0, (Fl_Callback *)view_customer_CB},
			{"Associate", 0, (Fl_Callback *)view_sa_CB},
			//{"All Orders"},
			//{"Sales Report"},
		{0},
		{0}
	};

	menubar->menu(menuitems);

	//Robot_Part_Dialog obj;

	win->end();
	win->show();

	return Fl::run();
}
