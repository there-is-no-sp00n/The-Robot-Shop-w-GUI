#ifndef LOCOMOTOR_H
#define LOCOMOTOR_H

#include "Components.h"

class Locomotor : virtual public Components
{
    public:
        Locomotor();

		Locomotor(string name, string part_num, string desc, double weight, double cost, double m_spd, double pow_con)
		{
			string comp_type_allowed[5] = {"HEAD", "TORSO", "ARM", "LOCOMOTOR", "BATTERY"};

			ahoy.comp_type = comp_type_allowed[3];
			ahoy.comp_name = name;
			ahoy.comp_part_num = part_num;
			ahoy.comp_desc = desc;
			ahoy.comp_weight = weight;
			ahoy.comp_cost = cost;
			max_speed = m_spd;
			pow_eaten = pow_con;
		}
        void set_loco();
        void total_energy();

        double get_max_speed(Locomotor);
        double get_pow_eat(Locomotor);

    protected:
        double max_speed;
        double pow_eaten;

    private:
};

#endif
