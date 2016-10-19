#include "Controller.h"

Controller::Controller()
{

}

void Controller::run_prog()
{
    int flag = 1;

    Robot obj;
    Order obj_1;

    while (flag)
    {
        //cout << "Press 1 if PRODUCTION MANAGER" << endl;
        //cout << "Press 2 if CUSTOMER" << endl;
        //cout << "Press 3 if SALES ASSOCIATE" << endl;
        cout << "*** MAIN MENU ***" << endl;
        cout << endl;

        cout << "Press 1 to make robot components" << endl;
        cout << "Press 2 to view components" << endl;
        cout << "Press 3 to create robot" << endl;
        cout << "Press 4 to view robot" << endl;
        cout << "Press 5 to order an robot" << endl;
        cout << "Press 6 to view bill of sale" << endl;
        cout << "Press 0 to exit"<< endl;
        cout << "What is your choice? ";
        int user_choice;
        cin >> user_choice;
        cout << endl;

        if (user_choice == 1)
        {
            obj.create_comp();
        }

        if (user_choice == 2)
        {
            obj.view_comp();
        }

        if (user_choice == 3)
        {
            obj.set_robot();
        }

        if (user_choice == 4)
        {
            obj.print_all_models();
        }

        if (user_choice == 5)
        {
            obj_1.order_robot(obj);
        }

        if (user_choice == 6)
        {
            obj_1.view_bill_of_sale(obj);
        }



        if(user_choice == 0)
        {
            flag = 0;
        }
    }
}
