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

		Robot(Head skull, Torso bod, Arm fist, Locomotor moto, Battery ene, string name, string num)
		{
			robo_cop.noggin = skull;
			robo_cop.robo_t = bod;
			robo_cop.first_arm = robo_cop.second_arm = fist;
			robo_cop.loco_coco = moto;
			robo_cop.power_af = ene;

			robo_cop.final_cost = skull.ahoy.comp_cost;
			robo_cop.final_cost += bod.ahoy.comp_cost;
			robo_cop.final_cost += (2*fist.ahoy.comp_cost);
			robo_cop.final_cost += moto.ahoy.comp_cost;
			robo_cop.final_cost += ene.ahoy.comp_cost;

			robo_cop.final_weight = skull.ahoy.comp_weight;
			robo_cop.final_weight = bod.ahoy.comp_weight;
			robo_cop.final_weight = (2*fist.ahoy.comp_weight);
			robo_cop.final_weight = moto.ahoy.comp_weight;
			robo_cop.final_weight = ene.ahoy.comp_weight;
			robo_cop.model_name = name;
			robo_cop.model_num = num;


		}

        void set_robot(Head, Torso, Arm, Locomotor, Battery, string, string, string, double, double, double);

        void print_all_models();

        void detail_robot_view();

        void create_comp(int type, string name, string num, string desc, double weight, double cost, double pow_con, double max_spd, double pow_eat, int num_bat);

        void view_comp();

        void tot_weight_cost( int []);

        double get_retail(Robot, int);
        double get_weight(Robot, int);

		vector <Head> get_hvec();
		vector <Torso> get_tvec();
		vector <Arm> get_avec();
		vector <Locomotor> get_lvec();
		vector <Battery> get_bvec();

		vector <struct robo_bobo> get_rvec();

		string ret_name(int i)
		{
			return hill[i].model_name;
		}

		string ret_num(int i)
		{
			return hill[i].model_num;
		}
		string ret_desc(int i)
		{
			return hill[i].desc;
		}
		double ret_retail(int i)
		{
			return hill[i].retail_price;
		}
		double ret_weight(int i)
		{
			return hill[i].final_weight;
		}

		int ret_r_vec_size();

    private:
        struct robo_bobo
        {
            double final_weight;
            double final_cost;
            double retail_price;

            string model_name;
            string model_num;
			string desc;

            Torso robo_t;
            Locomotor loco_coco;
            Battery power_af;
            Arm first_arm;
            Arm second_arm;
            Head noggin;

			int parts[6];
        };

		//int size_r;

        robo_bobo robo_cop;

        vector <Head> all_head;
        vector <Torso> all_torso;
        vector <Arm> all_arm;
        vector <Locomotor> all_loco;
        vector <Battery> all_bat;

        vector <struct robo_bobo> hill;
};

#endif
