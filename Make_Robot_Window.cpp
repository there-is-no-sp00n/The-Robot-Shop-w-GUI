#include "Make_Robot_Window.h"

Robot roro;

Fl_Scrollbar *h_scroll, *t_scroll, *a_scroll,  *l_scroll, *b_scroll;

Fl_Output *h_val, *t_val, *a_val, *l_val, *b_val;

Fl_Button *make;

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
	string s_head, s_torso, s_arm, s_loco, s_bat;

	s_head = h_val->value();	
	s_torso = t_val->value();
	s_arm = a_val->value();
	s_loco = l_val->value();
	s_bat = b_val->value();

	cout << s_head << endl;
	cout << s_torso << endl; 
	cout << s_arm << endl; 
	cout << s_loco << endl; 
	cout << s_bat << endl; 
}

Make_Robot_Window::Make_Robot_Window()
{
	
}

void Make_Robot_Window::make_window(Robot robo)
{
	vector <Head> h_r = robo.get_hvec();
	vector <Torso> t_r = robo.get_tvec();
	vector <Arm> a_r = robo.get_avec();
	vector <Locomotor> l_r = robo.get_lvec();
	vector <Battery> b_r = robo.get_bvec();

	roro = robo;
	Fl_Window *r_win;

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