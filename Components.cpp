#include "Components.h"

using namespace std;

Components::Components()
{

}

void Components::set_comp(int type)
{
    string comp_type_allowed[5] = {"HEAD", "TORSO", "ARM", "LOCOMOTOR", "BATTERY"};

    ahoy.comp_type = comp_type_allowed[type];

    cout << "What is the component name? ";
    cin.ignore();
    getline(cin, ahoy.comp_name);
    cout << endl;

    cout << "What is the component number? ";
    cin >> ahoy.comp_part_num;
    cout << endl;

    cout << "What is the weight of the component (in KG)? ";
    cin >> ahoy.comp_weight;
    cout << endl;

    cout << "What is the cost of the component? ";
    cin >> ahoy.comp_cost;
    cout << endl;

    cout << "Insert a brief description of the component? ";
    cin.ignore();
    getline(cin, ahoy.comp_desc);
    cout << endl;
}
