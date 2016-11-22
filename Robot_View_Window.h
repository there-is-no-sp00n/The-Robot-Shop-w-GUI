#ifndef ROBOT_VIEW_WINDOW_H
#define ROBOT_VIEW_WINDOW_H

#include "View.h"
#include "Robot.h"

using namespace std;

class Robot_View_Window
{
	public:
		Robot_View_Window();

		void show_robot_tab(Robot);

		vector <struct robo_bobo> get_r_vec(Robot);

		string ret_name(Robot);


};



#endif