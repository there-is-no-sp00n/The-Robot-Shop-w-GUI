#ifndef TABBED_WINDOW_H
#define TABBED_WINDOW_H

#include <FL/Fl_Hold_Browser.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Button.H>

#include "View.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Tabbed_Window
{
	public:
		Tabbed_Window();

		void show_head_tab(vector <Head>);

	private:
		Fl_Button *next;
};


#endif