#ifndef ROBOT_H
#define ROBOT_H

#include "Torso.h"
#include "Locomotor.h"
#include "Battery.h"
#include "Arm.h"
#include "Head.h"

class Robot : public Torso, public Locomotor, public Battery, public Arm, public Head
{
    public:
        Robot();

        void set_robot();

        void print_all_models();

        void detail_robot_view();

        void create_comp(int type, string name, string num, string desc, double weight, double cost, double pow_con, double max_spd, double pow_eat, int num_bat);

        void view_comp();

        void tot_weight_cost( int []);

        double get_retail(Robot, int);
        double get_weight(Robot, int);
		vector <Head> get_hvec();

    private:
        struct robo_bobo
        {
            double final_weight;
            double final_cost;
            double retail_price;

            string model_name;
            string model_num;

            Torso robo_t;
            Locomotor loco_coco;
            Battery power_af;
            Arm first_arm;
            Arm second_arm;
            Head noggin;

			int parts[6];
        };

        robo_bobo robo_cop;

        vector <Head> all_head;
        vector <Torso> all_torso;
        vector <Arm> all_arm;
        vector <Locomotor> all_loco;
        vector <Battery> all_bat;

        vector <struct robo_bobo> hill;
};

#endif
