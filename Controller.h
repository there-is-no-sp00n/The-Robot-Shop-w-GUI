#ifndef CONTROLLER_H
#define CONTROLLER_H

//#include "Components.h"
#include "Robot.h"
#include "Order.h"

class Controller
{
    public:
        Controller();

        void run_prog(Robot obj, int choice, int type, string name, string num, double weight, double cost, double pow_con, double max_spd, double pow_eat, int num_bat);
		
		Robot get_robo_c();
	protected:
    private:
		Robot robo_ret;
};

#endif
