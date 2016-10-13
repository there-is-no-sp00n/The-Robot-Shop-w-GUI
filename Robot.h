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
    ///protected:
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
        };

        robo_bobo robo_cop;

        vector <struct robo_bobo> hill;
};

#endif
