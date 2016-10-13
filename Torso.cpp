#include "Torso.h"

Torso::Torso()
{
    //ctor
}

void Torso::set_torso()
{
    cout << "How many batteries does your robot have? ";
    cin >> torso_bat;
    cout << endl;
}

int Torso::get_total_battery(Torso body)
{
    return body.torso_bat;
}
