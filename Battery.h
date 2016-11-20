#ifndef BATTERY_H
#define BATTERY_H

#include "Components.h"

class Battery : virtual public Components
{
    public:
        Battery();

		Battery(string name, string part_num, string desc, double weight, double cost, double pow)
		{
			string comp_type_allowed[5] = {"HEAD", "TORSO", "ARM", "LOCOMOTOR", "BATTERY"};

			ahoy.comp_type = comp_type_allowed[4];
			ahoy.comp_name = name;
			ahoy.comp_part_num = part_num;
			ahoy.comp_desc = desc;
			ahoy.comp_weight = weight;
			ahoy.comp_cost = cost;
			energy = pow;
		}

        void set_bat();
        double get_battery(Battery);

    protected:
        double energy;

    private:
};

#endif
