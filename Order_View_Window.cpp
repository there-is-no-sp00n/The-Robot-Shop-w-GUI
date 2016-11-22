#include "Order_View_Window.h"

int siz_o_v;
int pos_o_v;

Fl_Button *nxt_o_v;
Fl_Button *back_o_v;

vector <Order_Window> right_order;

Fl_Window *tab_win_o_v;

void show_orders();

void back_CB_o_v()
{
	if (pos_o_v == 0)
	{
		//tab_win->hide();
	}

	else if (pos_o_v <= siz_o_v)
	{
		tab_win_o_v->hide();
		pos_o_v--;
		show_orders();
	}
}


void next_CB_o_v()
{
	if (pos_o_v == siz_o_v)
	{
		//tab_win->hide();
	}

	else if (pos_o_v < siz_o_v)
	{
		tab_win_o_v->hide();
		pos_o_v++;
		show_orders();
		
	}
}

void show_orders()
{
	cout << "Position for order: " << pos_o_v << endl;
	cout << "Size for order: " << siz_o_v << endl;
	
	//FL_Output shit here
	Fl_Output *o_name, *o_number, *o_weight, *o_cost, *o_index, *o_pow, *o_desc;
	

	//this goes to Fl_Output later
	char index[1024];
	char name[1024];
	char num[1024];
	char c_cost[1024];
	char c_weight[1024];
	char o_date[1024];
	char o_worker[1024];

	//this is from the vector
	string nombre,ss_weight, indi, retail_s;
	string numero, date_33, work_name;
	double wght;
	double retail;

	//set from the vector
	nombre = right_order[pos_o_v].get_c_name();
	cout << nombre << endl;
	numero = right_order[pos_o_v].get_o_number();
	cout << numero << endl;
	retail = right_order[pos_o_v].get_da_f_price();
	cout << retail << endl;
	wght = right_order[pos_o_v].get_da_f_weight();
	cout << wght << endl;
	date_33 = right_order[pos_o_v].get_o_date();
	cout << date_33 << endl;
	work_name = right_order[pos_o_v].get_sa_name();
	cout << work_name << endl;

	indi = to_string(static_cast <long long>(pos_o_v+1));

	//convert from the vector to GUI
	retail_s = to_string(static_cast <long long>(retail));
	ss_weight = to_string(static_cast < long long >(wght));

	strncpy(name, nombre.c_str(), sizeof(name));
	strncpy(num, numero.c_str(), sizeof(num));
	strncpy(o_worker, work_name.c_str(), sizeof(o_worker));
	strncpy(c_cost, retail_s.c_str(), sizeof(c_cost));
	strncpy(c_weight, ss_weight.c_str(), sizeof(c_weight));
	strncpy(index, indi.c_str(), sizeof(index));
	strncpy(o_date, date_33.c_str(), sizeof(o_date));

	Fl_Output *o_shipping, *o_after_tax, *o_grand_tot;
	double ship, mf_tax, finally_tot;
	string ship_s, mf_tax_s, fin_tot_s;
	char shipping [1024];
	char after_tax[1024];
	char grand_tot[1024];

	ship = 5 * wght;
	mf_tax = 1.0825 * retail;
	finally_tot = ship + mf_tax;

	ship_s = to_string(static_cast <long long>(ship));
	mf_tax_s = to_string(static_cast <long long>(mf_tax));
	fin_tot_s = to_string(static_cast <long long>(finally_tot));

	strncpy(shipping, ship_s.c_str(), sizeof(shipping));
	strncpy(after_tax, mf_tax_s.c_str(), sizeof(after_tax));
	strncpy(grand_tot, fin_tot_s.c_str(), sizeof(grand_tot));



	//create window for display
	tab_win_o_v = new Fl_Window(500,500, "ORDER");
	
	//put the fields on the window
	o_index = new Fl_Output(120,50,50,30, "Order #");
	o_index->textsize(10);
	o_index->value(index);

	o_name = new Fl_Output(120,140,50,30, "Customer:");
	o_name->textsize(10);
	o_name->value(name); 

	o_number = new Fl_Output(120,220,50,30, "Order Serial#:");
	o_number->textsize(10);
	o_number->value(num);

	o_weight = new Fl_Output(120,300,50,30, "Order Weight:");
	o_weight->textsize(10);
	o_weight->value(c_weight);

	o_shipping = new Fl_Output(300, 300, 50,30, "Shipping $5/KG");
	o_shipping->textsize(10);
	o_shipping->value(shipping);
			
	o_cost = new Fl_Output(120,260,50,30, "Retail Price:");
	o_cost->textsize(10);
	o_cost->value(c_cost);

	o_grand_tot = new Fl_Output(400, 280, 50, 30, "Grand Total:");
	o_grand_tot->textsize(10);
	o_grand_tot->value(grand_tot);

	o_after_tax = new Fl_Output(300, 260, 50, 30, "After 8.25% tax");
	o_after_tax->textsize(10);
	o_after_tax->value(after_tax);

	o_pow = new Fl_Output(120, 180, 50, 30, "Sales Associate:");
	o_pow->textsize(10);
	o_pow->value(o_worker);

	o_desc = new Fl_Output(120,100,50,30, "Date:");
	o_desc->textsize(10);
	o_desc->value(o_date);

	nxt_o_v = new Fl_Button(100, 400, 60, 25, "NEXT");
	back_o_v = new Fl_Button(200, 400, 60, 25, "BACK");

	nxt_o_v->callback((Fl_Callback *)next_CB_o_v,0);
	back_o_v->callback((Fl_Callback *)back_CB_o_v,0);

	//tab_win->redraw();
	tab_win_o_v->end();
	tab_win_o_v->show();

}




Order_View_Window::Order_View_Window()
{

}


void Order_View_Window::show_order_tab(vector <Order_Window> gimme)
{
	siz_o_v = gimme.size() - 1;
	right_order = gimme;
	pos_o_v = 0;

	if (siz_o_v != -1)
	{
		show_orders();
	}
}