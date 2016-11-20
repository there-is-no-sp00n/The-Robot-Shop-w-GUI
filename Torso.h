#ifndef TORSO_H
#define TORSO_H

#include "Components.h"

class Torso : virtual public Components
{
    public:
        Torso();

		Torso(string name, string part_num, string desc, double weight, double cost, int bat)
		{
			string comp_type_allowed[5] = {"HEAD", "TORSO", "ARM", "LOCOMOTOR", "BATTERY"};

			ahoy.comp_type = comp_type_allowed[1];
			ahoy.comp_name = name;
			ahoy.comp_part_num = part_num;
			ahoy.comp_desc = desc;
			ahoy.comp_weight = weight;
			ahoy.comp_cost = cost;
			torso_bat = bat;
		}

        void set_torso();

        int get_total_battery(Torso);

    protected:
        int torso_bat;

    private:
};

#endif
