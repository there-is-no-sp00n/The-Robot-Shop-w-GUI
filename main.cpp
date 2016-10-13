#include <iostream>
#include "Robot.h"

using namespace std;

int main()
{
    int flag = 1;

    Robot obj;

    while (flag)
    {
        cout << "Press 1 to make robot model" << endl;
        cout << "Press 2 to view all robot models" << endl;
        cout << "Press 0 to exit"<< endl;
        cout << "What is your choice? ";
        int user_choice;
        cin >> user_choice;
        cout << endl;

        if (user_choice == 1)
        {
            obj.set_robot();
        }

        else if (user_choice == 2)
        {
            obj.print_all_models();
        }

        else if (user_choice == 0)
        {
            cout << "You have exited the program" << endl;
            flag = 0;
        }
    }


    return 0;
}
