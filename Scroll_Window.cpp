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
void Scroll_Window::show_scroll()
{
	//Fl_Scroll *scro = new Fl_Scroll(10,20,200,200,"t2");

	//Fl_Scrollbar *bscroll = new Fl_Scrollbar(10,20,200,200,"sb");

	//Fl_Double_Window *s_win = new Fl_Double_Window(0,0,500,500,"Test");
	Fl_Window *s_win = new Fl_Window(0,0,500,500,"Test");
	{
		bscroll = new Fl_Scrollbar(450,0,50,500,"sb");
			//Fl_Window *scroll_win = new Fl_Window(0,0,500,500, "inner");
			bscroll->type(FL_VERTICAL);
			bscroll->slider_size(.1);
			bscroll->bounds(0,500);
			bscroll->value(0);
			bscroll->step(2);
			bscroll->callback(scrollbar_CB, (void*)&out);
			out = new Fl_Output(200,150,100,40, "Scrollbar Value");
			out->textsize(24);
		//Fl_Scroll *scro = new Fl_Scroll(0,0,200,200,"t2");

		bscroll->type(FL_VERTICAL);
		bscroll->slider_size(.1);
		bscroll->bounds(0,500);
		bscroll->value(0);
		bscroll->step(2);
		bscroll->callback(scrollbar_CB, (void*)&out);
		out = new Fl_Output(200,150,100,40, "Scrollbar Value");
		out->textsize(24);


		//scro->type(Fl_Scroll::VERTICAL);
		//scro->as_window();
		//scro->activate();
	
	}

	s_win->end();
	//s_win->resizable(s_win);
	
	s_win->show();
}