#include "Battery.h"

Battery::Battery()
{
    //ctor
}

void Battery::set_bat()
{
    cout << "How much energy in the battery? ";
    cin >>energy;
    cout << endl;
}

//double Battery::get_battery(Battery pow)
//{
//    return pow.energy;
//}
