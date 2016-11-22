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
#include <FL/Fl_Output.H>
#include <FL/Fl_Multiline_Output.H>

#include "Robot_Part_Dialog.h"
#include "Robot.h"
#include "Scroll_Window.h"

#include "Head_Window.h"
#include "Torso_Window.h"
#include "Arm_Window.h"
#include "Locomotor_Window.h"
#include "Battery_Window.h"

#include "Robot_View_Window.h"
#include "Make_Robot_Window.h"

#include "Customer.h"
#include "Sales_Associate.h"

#include <string>

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