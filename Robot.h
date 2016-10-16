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

        void create_comp();

        void view_comp();

        void tot_weight_cost( int []);

    private:
        struct robo_bobo
        {
            double final_weight = 0;
            double final_cost = 0;
            double retail_price = 0;

            string model_name;
            string model_num;

            Torso robo_t;
            Locomotor loco_coco;
            Battery power_af;
            Arm first_arm;
            Arm second_arm;
            Head noggin;
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
