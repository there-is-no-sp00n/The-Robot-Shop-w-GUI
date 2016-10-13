#include "Arm.h"

Arm::Arm()
{
    //ctor
}

void Arm::set_arm()
{
    cout << "How much power does the arm consume? ";
    cin >> power_con;
    cout << endl;
}

double Arm::get_arm_power(Arm obj)
{
    return obj.power_con;
}
