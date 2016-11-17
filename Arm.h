#ifndef ARM_H
#define ARM_H

#include "Components.h"

class Arm : virtual public Components
{
    public:
        Arm();

		Arm (string name, string part_num, string desc, double weight, double cost, double pow)
		{
			string comp_type_allowed[5] = {"HEAD", "TORSO", "ARM", "LOCOMOTOR", "BATTERY"};

			ahoy.comp_type = comp_type_allowed[2];
			ahoy.comp_name = name;
			ahoy.comp_part_num = part_num;
			ahoy.comp_desc = desc;
			ahoy.comp_weight = weight;
			ahoy.comp_cost = cost;
			power_con = pow;
		}
        void set_arm();

        double get_arm_power(Arm);

    protected:
        double power_con;

    private:
};

#endif
