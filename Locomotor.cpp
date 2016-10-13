#include "Locomotor.h"

using namespace std;

Locomotor::Locomotor()
{
    //ctor
}

void Locomotor::set_loco()
{
    cout << "What is the maximum speed of the robot? ";
    cin >> max_speed;
    cout << endl;

    cout << "What is the power consumption of the robot? ";
    cin >> pow_eaten;
    cout << endl;
}

double Locomotor::get_max_speed(Locomotor obj)
{
    return obj.max_speed;
}

double Locomotor::get_pow_eat(Locomotor obj)
{
    return obj.pow_eaten;
}
