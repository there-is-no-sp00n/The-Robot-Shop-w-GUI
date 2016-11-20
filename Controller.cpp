#include "Controller.h"

Controller::Controller()
{

}

Robot Controller::get_robo_c()
{
	return robo_ret;
}

void Controller::run_prog(Robot r_obj, int choice, int type, string name, string num, double weight, double cost, double pow_con, double max_spd, double pow_eat, int num_bat)
{
    int flag = 1;
	
    Order obj_1;

    while (flag)
    {
        cout << "*** MAIN MENU ***" << endl;
        cout << endl;

        cout << "Press 1 to make robot components" << endl;
        cout << "Press 2 to view components" << endl;
        cout << "Press 3 to create robot" << endl;
        cout << "Press 4 to view robot" << endl;
        cout << "Press 5 to order an robot" << endl;
        cout << "Press 6 to view bill of sale" << endl;
        cout << "Press 7 view order per SA" << endl;
        cout << "Press 8 to view all orders" << endl;
        cout << "Press 9 to view sales report of SA" << endl;
        cout << "Press 0 to exit"<< endl;
        cout << "What is your choice? ";
        int user_choice;
        //cin >> user_choice;
        //cout << endl;

		user_choice = choice;
        if (user_choice == 1)
        {
			cout << "lklklkl" << endl;
			robo_ret.create_comp(type, name, num, weight, cost, pow_con, max_spd, pow_eat, num_bat);
			robo_ret.view_comp();
			break;
        }

        if (user_choice == 2)
        {
            robo_ret.view_comp();
			break;
        }

        if (user_choice == 3)
        {
            robo_ret.set_robot();
        }

        if (user_choice == 4)
        {
            robo_ret.print_all_models();
        }

        if (user_choice == 5)
        {
            obj_1.order_robot(robo_ret);
        }

        if (user_choice == 6)
        {
            obj_1.view_bill_of_sale(robo_ret);
        }

        if (user_choice == 7)
        {
            obj_1.view_order_by_sa();
        }

        if (user_choice == 8)
        {
            obj_1.view_all_orders();
        }

        if (user_choice == 9)
        {
            obj_1.get_sales_report();
        }



        if(user_choice == 0)
        {
            flag = 0;
        }
    }
}
