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
