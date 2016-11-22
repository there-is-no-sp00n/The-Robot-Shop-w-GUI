#include "Order_Window.h"

Fl_Input *order_num, *date_1, *num_of_robo;

Fl_Output *pri_price, *tot_wght, *tax, *shipping, *fin_price;

Fl_Window *o_win;

Fl_Button *oorder;

vector <Order_Window> list_or;

Robot randal;
vector <Customer> cust_6;
vector <Sales_Associate> worker;

int randal_siz;


//for choosing SA and Customer
Fl_Scrollbar *c_scroll, *sa_scroll, *robo_scroll;
Fl_Output *c_name, *sa_name, *r_num;

void final_order()
{

}






Order_Window::Order_Window()
{

}

void c_scroll_CB(Fl_Widget *w, void *p)
{
	char s[20];
	sprintf(s, "%d", c_scroll->value());
	c_name->value(s);	
}

void sa_scroll_CB(Fl_Widget *w, void *p)
{
	char s[20];
	sprintf(s, "%d", sa_scroll->value());
	sa_name->value(s);	
}

void robo_scroll_CB(Fl_Widget *w, void *p)
{
	char s[20];
	sprintf(s, "%d", robo_scroll->value());
	r_num->value(s);	
}

void done_CB(Fl_Widget *w, void *p)
{
	cout << "done callback" << endl;
	o_win->hide();
	string serial_numb = order_num->value();
	string t_date = date_1->value();
	string custo, worko;

	int c_indx, sa_indx, r_indx;

	c_indx = c_scroll->value()-1;
	sa_indx = sa_scroll->value()-1;
	r_indx = robo_scroll->value()-1; 

	cout << "Cust " << cust_6.size() << endl;
	cout << "SA " << worker.size() << endl;

	cout << c_indx << endl;
	cout << sa_indx << endl;
	cout << r_indx << endl;

	cout << serial_numb << endl;
	cout << t_date << endl;
	cout << randal.ret_retail(r_indx) << endl;
	cout << randal.ret_weight(r_indx) << endl;

	cout << "B" << cust_6.size() << endl;
	cout << "C" << worker.size() << endl;

	custo = cust_6[c_indx].get_name();
	worko = worker[sa_indx].get_sa_name();
	double market = randal.ret_retail(r_indx);
	double rob_wgt = randal.ret_weight(r_indx);

	//Order_Window okok(cust_1[c_scroll->value()-1], worker[sa_scroll->value()-1],serial_numb, t_date, randal.ret_retail(robo_scroll->value()-1),randal.ret_weight(robo_scroll->value()-1));
	Order_Window okok(custo, worko, serial_numb, t_date, market, rob_wgt);

	list_or.push_back(okok);

	cout << "order list size " << list_or.size() << endl;
}


void Order_Window::make_my_money(vector <Customer> cust, vector <Sales_Associate> worker_1, Robot bob)
{
	randal = bob;
	cust_6 = cust;
	worker = worker_1;
	randal_siz = bob.ret_r_vec_size();

	cout << "vector robot size" << randal_siz << endl;


	o_win = new Fl_Window(800,800, "Make Order");
	{
		oorder = new Fl_Button(500,500, 50,50, "DONE");
		oorder->callback((Fl_Callback *)done_CB,0);

		c_name = new Fl_Output(400, 100, 200,50, "Customer #:");
		sa_name = new Fl_Output(400, 200, 200, 50, "Associate #:");
		r_num = new Fl_Output(400, 300, 200,50, "Robot #");

		c_scroll = new Fl_Scrollbar(100,100, 100, 50, "Customer");
		sa_scroll = new Fl_Scrollbar(100,200, 100,50, "Associate");
		robo_scroll = new Fl_Scrollbar(100,300, 100,50, "Robot");

		order_num = new Fl_Input(100, 400, 50,50, "Order #");
		date_1 = new Fl_Input(100,500, 50,50, "Date:");



		c_scroll->type(FL_HORIZONTAL);
		sa_scroll->type(FL_HORIZONTAL);
		robo_scroll->type(FL_HORIZONTAL);

		c_scroll->slider_size(.1);
		sa_scroll->slider_size(.1);
		robo_scroll->slider_size(.1);

		c_scroll->bounds(0, cust.size());
		sa_scroll->bounds(0, worker.size());
		robo_scroll->bounds(0, bob.ret_r_vec_size());


		c_scroll->value(0);
		sa_scroll->value(0);
		robo_scroll->value(0);

		c_scroll->step(1);
		sa_scroll->step(1);
		robo_scroll->step(1);

		c_scroll->callback(c_scroll_CB);
		sa_scroll->callback(sa_scroll_CB);
		robo_scroll->callback(robo_scroll_CB);


	}

	o_win->end();
	o_win->show();
}

vector <Order_Window> Order_Window::get_ordersss()
{
	return list_or;
}
