#ifndef VIEW_H
#define VIEW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Scrollbar.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Output.H>

#include "Robot_Part_Dialog.h"
#include "Controller.h"
#include "Scroll_Window.h"

#include <iostream>

using namespace std;



class View
{
	public:
		View();		
		


		int show_the_goods();
	protected:
	private:
};


#endif