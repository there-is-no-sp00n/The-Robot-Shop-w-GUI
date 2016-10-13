#include "Controller.h"

Controller::Controller()
{
    
}

void Controller::create_new_comp()
{
        cout << "Enter type of component" << endl;
        cout << "Press 0 for HEAD" << endl;
        cout << "Press 1 for TORSO" << endl;
        cout << "Press 2 for ARM" << endl;
        cout << "Press 3 for LOCOMOTOR" << endl;
        cout << "Press 4 for BATTERY" << endl;
        cout << "Press 5 to stop adding more components" << endl;
        cout << "What is your part type? ";
        int part_type;
        cin >> part_type;
        cout << endl;    
}
