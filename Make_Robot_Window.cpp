#include "Make_Robot_Window.h"

Robot roro;

//robot input from the user
Fl_Input *retail, *robo_name, *robo_num;
Fl_Output *tot_cost;
Fl_Button *build;
string r_name, r_num, r_retail;

Fl_Window *r_win;
Fl_Window *r_n_win;

double cst;

Head h_f_r;
Torso t_f_r;
Arm a_f_r;
Locomotor l_f_r;
Battery b_f_r;

vector <Head> h_r;
vector <Torso> t_r;
vector <Arm> a_r;
vector <Locomotor> l_r;
vector <Battery> b_r;

//user choosing the the components
Fl_Scrollbar *h_scroll, *t_scroll, *a_scroll,  *l_scroll, *b_scroll;

Fl_Output *h_val, *t_val, *a_val, *l_val, *b_val;

Fl_Button *make;

void input_robot_name();

void before_set_rob()
{
	r_retail = retail->value();
	r_name = robo_name->value();
	r_num = robo_num->value();
	
	cout << "retail price: " << r_retail << endl;
	cout << "robot name: " << r_name << endl;
	cout << "robot serial: " << r_num << endl;

	roro.set_robot(h_f_r, t_f_r, a_f_r, l_f_r, b_f_r, r_name, r_num);
}

void build_CB(Fl_Widget *w, void *p)
{
	r_n_win->hide();
	
	before_set_rob();
}



void h_scroll_CB(Fl_Widget *w, void *p)
{
	char s[20];
	
	sprintf(s,"%d",h_scroll->value());
	h_val->value(s);
}

void t_scroll_CB(Fl_Widget *w, void *p)
{
	char s[20];
	
	sprintf(s,"%d",t_scroll->value());
	//t_val->value(0);
	t_val->value(s);
}

void a_scroll_CB(Fl_Widget *w, void *p)
{
	char s[20];
	
	sprintf(s,"%d",a_scroll->value());
	a_val->value(s);
}

void l_scroll_CB(Fl_Widget *w, void *p)
{
	char s[20];
	
	sprintf(s,"%d",l_scroll->value());
	l_val->value(s);
}

void b_scroll_CB(Fl_Widget *w, void *p)
{
	char s[20];
	
	sprintf(s,"%d",b_scroll->value());
	b_val->value(s);
}

void make_CB(Fl_Widget *w, void *p)
{
	input_robot_name();
}

void input_robot_name()
{
	r_win->hide();
	cout << "input robot name" << endl;

	double t_cost = 0;
	string s_t_cost;
	char o_t_cost[1024];

	//string s_head, s_torso, s_arm, s_loco, s_bat;
	int c_head, c_tor, c_arm, c_loco, c_bat;

	//load the choices for each
	c_head = h_scroll->value()-1;
	c_tor = t_scroll->value()-1;
	c_arm = a_scroll->value()-1;
	c_loco = l_scroll->value()-1;
	c_bat = b_scroll->value()-1;
		

	//output to commandline
	cout << c_head << endl;
	cout << c_tor << endl; 
	cout << c_arm << endl; 
	cout << c_loco << endl; 
	cout << c_bat << endl;

	if (c_head != -1)
	{
		t_cost += h_r[c_head].ahoy.comp_cost;
		h_f_r = h_r[c_head];
	}
	if (c_tor != -1)
	{
		t_cost += t_r[c_tor].ahoy.comp_cost;
		t_f_r = t_r[c_tor];
	}

	if (c_arm != -1)
	{
		t_cost += a_r[c_arm].ahoy.comp_cost;
		a_f_r = a_r[c_arm];
	}

	if (c_loco != -1)
	{
		t_cost += l_r[c_loco].ahoy.comp_cost;
		l_f_r = l_r[c_loco];
	}

	if (c_bat != -1)
	{
		t_cost += b_r[c_bat].ahoy.comp_cost;
		b_f_r = b_r[c_bat];
	}

	cout << "Total Cost: " << t_cost <<  endl;




	////////////

	r_n_win = new Fl_Window(0,0,300,300, "ROBOT INPUT");

	tot_cost = new Fl_Output(50,50,50,50, "Total Cost");
	s_t_cost = to_string(static_cast <long long>(t_cost));

	strncpy(o_t_cost, s_t_cost.c_str(), sizeof(o_t_cost));
	tot_cost->value(o_t_cost);

	retail = new Fl_Input(50, 100, 50,50, "Retail Price:");
	robo_name = new Fl_Input(50, 150, 50, 50, "Name:");
	robo_num = new Fl_Input(50, 200, 50, 50, "Serial:");
	build = new Fl_Button(100, 250, 30,30, "BUILD");
	build->callback((Fl_Callback *)build_CB,0);

	r_retail = retail->value();
	r_name = robo_name->value();
	r_num = robo_num->value();
	
	cout << "retail price: " << r_retail << endl;
	cout << "robot name: " << r_name << endl;
	cout << "robot serial: " << r_num << endl;

	r_n_win->end();
	r_n_win->show();



}

void input_robot(vector <Head> nog, vector <Torso> bod, vector <Arm> fist, vector <Locomotor> coco, vector <Battery> pow)
{
	//Fl_Window *r_n_win = new Fl_Window(300,300, "ROBOT");

	//roro.set_robot(nog, bod, fist, coco, pow, r_name, r_num);
}

Make_Robot_Window::Make_Robot_Window()
{
	
}

void Make_Robot_Window::make_window(Robot robo)
{
	h_r = robo.get_hvec();
	t_r = robo.get_tvec();
	a_r = robo.get_avec();
	l_r = robo.get_lvec();
	b_r = robo.get_bvec();





	roro = robo;

	r_win = new Fl_Window(600,600, "Make Robot");
	{
		make = new Fl_Button(500,500,50,50,"MAKE");
		make->callback((Fl_Callback *)make_CB,0);

		h_val = new Fl_Output(400,100, 50,50, "Head #");
		t_val = new Fl_Output(400,200, 50,50, "Torso #");
		a_val = new Fl_Output(400,300, 50,50, "Arm #");
		l_val = new Fl_Output(400,400, 50,50, "Locomotor #");
		b_val = new Fl_Output(400,500, 50,50, "Battery #");


		h_scroll = new Fl_Scrollbar(100, 100, 100,50, "Head");
		t_scroll = new Fl_Scrollbar(100, 200, 100,50, "Torso");
		a_scroll = new Fl_Scrollbar(100, 300, 100,50, "Arm");
		l_scroll = new Fl_Scrollbar(100, 400, 100,50, "Locomotor");
		b_scroll = new Fl_Scrollbar(100, 500, 100,50, "Battery");

		h_scroll->type(FL_HORIZONTAL);
		t_scroll->type(FL_HORIZONTAL);
		a_scroll->type(FL_HORIZONTAL);
		l_scroll->type(FL_HORIZONTAL);
		b_scroll->type(FL_HORIZONTAL);

		h_scroll->slider_size(.1);
		t_scroll->slider_size(.1);
		a_scroll->slider_size(.1);
		l_scroll->slider_size(.1);
		b_scroll->slider_size(.1);

		h_scroll->bounds(0,h_r.size());
		t_scroll->bounds(0,t_r.size());
		a_scroll->bounds(0,a_r.size());
		l_scroll->bounds(0,l_r.size());
		b_scroll->bounds(0,b_r.size());

		h_scroll->value(0);
		t_scroll->value(0);
		a_scroll->value(0);
		l_scroll->value(0);
		b_scroll->value(0);


		h_scroll->step(1);
		t_scroll->step(1);
		a_scroll->step(1);
		l_scroll->step(1);
		b_scroll->step(1);

		h_scroll->callback(h_scroll_CB, (void*)&h_val);
		t_scroll->callback(t_scroll_CB, (void*)&t_val);
		a_scroll->callback(a_scroll_CB, (void*)&a_val);
		l_scroll->callback(l_scroll_CB, (void*)&l_val);
		b_scroll->callback(b_scroll_CB, (void*)&b_val);
	}

	r_win->end();
	r_win->show();
}

Robot Make_Robot_Window::get_robo_m_r()
{
	return roro;
}