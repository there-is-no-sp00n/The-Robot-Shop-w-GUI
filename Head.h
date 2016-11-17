#ifndef HEAD_H
#define HEAD_H

#include "Components.h"

class Head : virtual public Components
{
    public:
        Head();

		Head (string name, string part_num, string desc, double weight, double cost)
		{
			string comp_type_allowed[5] = {"HEAD", "TORSO", "ARM", "LOCOMOTOR", "BATTERY"};

			ahoy.comp_type = comp_type_allowed[0];
			ahoy.comp_name = name;
			ahoy.comp_part_num = part_num;
			ahoy.comp_desc = desc;
			ahoy.comp_weight = weight;
			ahoy.comp_cost = cost;
		}
    protected:
    private:
};

#endif
