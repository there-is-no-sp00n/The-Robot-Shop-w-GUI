#include "Scroll_Window.h"

Fl_Scrollbar *bscroll;
Fl_Output *out;


void scrollbar_CB(Fl_Widget *w, void *p)
{
	char s[20];
	//bscroll->value();
	
	sprintf(s,"%d",bscroll->value());
	out->value(s);
	
}
Scroll_Window::Scroll_Window()
{

}
void Scroll_Window::show_scroll(string n, string num, char wei[1024], char cst[1024])
{
	char n_s[1024];
	strncpy(n_s, n.c_str(), sizeof(n_s));
	char num_s[1024];
	strncpy(num_s, num.c_str(), sizeof(num_s));
	//Fl_Scroll *scro = new Fl_Scroll(10,20,200,200,"t2");

	//Fl_Scrollbar *bscroll = new Fl_Scrollbar(10,20,200,200,"sb");

	//Fl_Double_Window *s_win = new Fl_Double_Window(0,0,500,500,"Test");
	Fl_Window *s_win = new Fl_Window(0,0,500,500,"Test");
	{
		Fl_Window *scroll_win = new Fl_Window(0,0,500,500, "inner");
		{
			bscroll = new Fl_Scrollbar(450,0,50,500,"sb");
			//Fl_Window *scroll_win = new Fl_Window(0,0,500,500, "inner");
			bscroll->type(FL_VERTICAL);
			bscroll->slider_size(.1);
			bscroll->bounds(0,500);
			bscroll->value(0);
			bscroll->step(2);
			bscroll->callback(scrollbar_CB, (void*)&out);


			Fl_Output *name, *number, *weight, *cost;
			name = new Fl_Output(100,100,20,20, "Head Name:");
			name->textsize(10);
			name->value(n_s);

			number = new Fl_Output(100,120,20,20, "Head Number:");
			number->textsize(10);
			number->value(num_s);

			weight = new Fl_Output(100,140,20,20, "Head Weight:");
			weight->textsize(10);
			weight->value(wei);
			
			cost = new Fl_Output(100,160,20,20, "Head Cost:");
			cost->textsize(10);
			cost->value(cst);

			out = new Fl_Output(200,300,100,40, "Scrollbar Value");
			out->textsize(24);
		}

		scroll_win->end();
		scroll_win->show();
		//Fl_Scroll *scro = new Fl_Scroll(0,0,200,200,"t2");

		//bscroll->type(FL_VERTICAL);
		//bscroll->slider_size(.1);
		//bscroll->bounds(0,500);
		//bscroll->value(0);
		//bscroll->step(2);
		//bscroll->callback(scrollbar_CB, (void*)&out);

		//out = new Fl_Output(200,150,100,40, "Scrollbar Value");
		//out->textsize(24);


		//scro->type(Fl_Scroll::VERTICAL);
		//scro->as_window();
		//scro->activate();
	
	}

	s_win->end();
	//s_win->resizable(s_win);
	
	s_win->show();
}