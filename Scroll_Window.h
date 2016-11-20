#ifndef SCROLL_WINDOW_H
#define SCROLL_WINDOW_H

#include <FL/Fl_Double_Window.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Scrollbar.H>
#include <FL/Fl_Scroll.H>

#include "View.h"

using namespace std;


class Scroll_Window
{
	public:
		Scroll_Window();

		void show_scroll(string, string, char[1024],char[1024]);
	protected:
		

};

#endif