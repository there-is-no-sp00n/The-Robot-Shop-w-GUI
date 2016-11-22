#include "Robot.h"

Robot::Robot()
{

}

void Robot::create_comp(int type, string name, string num, string desc, double weight, double cost, double pow_con, double max_spd, double pow_eat, int num_bat)
{
    int flag = 1;
    while (flag)
    {
        cout << "### COMPONENTS MENU ###" << endl;
        cout << endl;

        cout << "Enter type of component" << endl;
        cout << "Press 0 for HEAD" << endl;
        cout << "Press 1 for TORSO" << endl;
        cout << "Press 2 for ARM" << endl;
        cout << "Press 3 for LOCOMOTOR" << endl;
        cout << "Press 4 for BATTERY" << endl;
        cout << "Press 5 to stop adding more components" << endl;
        //cout << "What is your part type? ";
        int part_type;
        //cin >> part_type;
        //cout << endl;

		part_type = type;

        if (part_type > 5)
        {
            cout << "Number out of bounds! Please pick a number between 0 and 5" << endl;
            continue;
        }

        if (part_type == 0)
        {
            Head obj_head(name, num, desc, weight, cost);
            all_head.push_back(obj_head);
			break;
        }

        if (part_type == 1)
        {
            Torso obj_torso(name,num,desc,weight,cost,num_bat);
            all_torso.push_back(obj_torso);
			break;
        }

        if (part_type == 2)
        {
            Arm obj_arm(name, num, desc, weight, cost, pow_con);
            all_arm.push_back(obj_arm);
			break;
        }

        if(part_type == 3)
        {
            Locomotor obj_loco(name, num, desc, weight, cost, max_spd, pow_eat); 
            //obj_loco.set_comp(3);
            //obj_loco.set_loco();
            all_loco.push_back(obj_loco);
			break;
        }

        if(part_type == 4)
        {
            Battery obj_bat(name, num, desc, weight, cost, pow_con);
            //obj_bat.set_comp(4);
			//obj_bat.set_bat();
            all_bat.push_back(obj_bat);
			break;
        }

        if(part_type == 5)
        {
            flag = 0;
        }
    }
}
void Robot::set_robot(Head nog, Torso slam, Arm punch, Locomotor vel, Battery pow, string name, string num, string desc, double retail, double weight, double cost)
{
	//cout << "We're in set_robot" << endl; 
	//add the parts to it
	robo_cop.noggin = nog;
	robo_cop.robo_t = slam;
	robo_cop.first_arm = punch;
	robo_cop.second_arm = punch;
	robo_cop.loco_coco = vel;
	robo_cop.power_af = pow;

	//set the robot variables
	robo_cop.model_name = name;
	robo_cop.model_num = num;
	robo_cop.desc = desc;

	robo_cop.retail_price = retail;
	robo_cop.final_cost = cost;
	robo_cop.final_weight = weight;


	//calculate the
	//robo_cop.final_cost = nog.ahoy.comp_cost;
	//robo_cop.final_cost += slam.ahoy.comp_cost;
	//robo_cop.final_cost += (2*punch.ahoy.comp_cost);
	//robo_cop.final_cost += vel.ahoy.comp_cost;
	//robo_cop.final_cost += pow.ahoy.comp_cost*slam.get_total_battery(slam);

	//robo_cop.final_weight = nog.ahoy.comp_weight;
	//robo_cop.final_weight = slam.ahoy.comp_weight;
	//robo_cop.final_weight = (2*punch.ahoy.comp_weight);
	//robo_cop.final_weight = vel.ahoy.comp_weight;
	//robo_cop.final_weight = pow.ahoy.comp_weight * slam.get_total_battery(slam);

	hill.push_back(robo_cop);

	//print_all_models();



}

int Robot::ret_r_vec_size()
{
	
	int j = hill.size();
	cout << "vec_siz " << j << endl;
	return j;
	
}

vector <Head> Robot::get_hvec()
{
	return all_head;
}

vector <Torso> Robot::get_tvec()
{
	return all_torso;
}

vector <Arm> Robot::get_avec()
{
	return all_arm;
}

vector <Locomotor> Robot::get_lvec()
{
	return all_loco;
}

vector <Battery> Robot::get_bvec()
{
	return all_bat;
}

//vector <struct robo_bobo> Robot::get_rvec(Robot rotten)
//{
//	return rotten.hill;
//}
void Robot::view_comp()
{
    cout << "### LIST OF COMPONENTS ###" << endl;
    //cout << endl;

    int i;
    int j = all_head.size();
    for (i = 0; i < j; i++)
    {
        cout << endl;
        cout << "Head Name: " << all_head[i].ahoy.comp_name << endl;
        cout << "Head Number: " << all_head[i].ahoy.comp_part_num << endl;
        cout << "Head Weight: " << all_head[i].ahoy.comp_weight << endl;
        cout << "Head Cost: " << all_head[i].ahoy.comp_cost << endl;
		cout << "Head Desc: " << all_head[i].ahoy.comp_desc << endl;
        cout << endl;
    }

    j = all_torso.size();
    for (i = 0; i < j; i++)
    {
        cout << endl;
        cout << "Torso Name: " << all_torso[i].ahoy.comp_name << endl;
        cout << "Torso Number: " << all_torso[i].ahoy.comp_part_num << endl;
        cout << "Torso Weight: " << all_torso[i].ahoy.comp_weight << endl;
        cout << "Torso Cost: " << all_torso[i].ahoy.comp_cost << endl;
        cout << "Torso Battery: " << all_torso[i].get_total_battery(all_torso[i]) << endl;
		cout << "Torso Desc: " << all_torso[i].ahoy.comp_desc << endl;
        cout << endl;
    }

    j = all_arm.size();
    for (i = 0; i < j; i++)
    {
        cout << endl;
        //cout << "Arm Vector Size: " << all_arm.size() << endl;
        cout << "Arm Name: " << all_arm[i].ahoy.comp_name << endl;
        cout << "Arm Number: " << all_arm[i].ahoy.comp_part_num << endl;
        cout << "Arm Weight: " << all_arm[i].ahoy.comp_weight << endl;
        cout << "Arm Cost: " << all_arm[i].ahoy.comp_cost << endl;
        cout << "Arm Power: " << all_arm[i].get_arm_power(all_arm[i]) << endl;
		cout << "Arm Desc: " << all_arm[i].ahoy.comp_desc << endl;
        cout << endl;
    }

    j = all_loco.size();
    for (i = 0; i < j; i++)
    {
        cout << endl;
        cout << "Locomotor Name: " << all_loco[i].ahoy.comp_name << endl;
        cout << "Locomotor Number: " << all_loco[i].ahoy.comp_part_num << endl;
        cout << "Locomotor Weight: " << all_loco[i].ahoy.comp_weight << endl;
        cout << "Locomotor Cost: " << all_loco[i].ahoy.comp_cost << endl;
        cout << "Locomotor Max Speed: " << all_loco[i].get_max_speed(all_loco[i]) << endl;
        cout << "Locomotor Power Consumption: " << all_loco[i].get_pow_eat(all_loco[i]) << endl;
		cout << "Locomotor Desc: " << all_loco[i].ahoy.comp_desc << endl;
        cout << endl;
    }

    j = all_bat.size();
    for (i = 0; i < j; i++)
    {
        cout << endl;
        cout << "Battery Name: " << all_bat[i].ahoy.comp_name << endl;
        cout << "Battery Number: " << all_bat[i].ahoy.comp_part_num << endl;
        cout << "Battery Weight: " << all_bat[i].ahoy.comp_weight << endl;
        cout << "Battery Cost: " << all_bat[i].ahoy.comp_cost << endl;
        cout << "Battery Power: " << all_bat[i].get_battery(all_bat[i]) << endl;
		cout << "Battery Desc: " << all_bat[i].ahoy.comp_desc << endl;
        cout << endl;
    }



}

void Robot::print_all_models()
{
    cout << "### ROBOT VIEW MENU ###" << endl;
    cout << endl;
    cout << "Press 1 for detailed view" << endl;
    cout << "Press 0 for regular view" << endl;
    int choice = 0;
    cout << "What is your choice? ";
    //cin >> choice;
    //cout << endl;
    int siz = hill.size();

    if (choice == 0)
    {
        cout << "### ROBOT LIST ###" << endl;
        cout << endl;

        for (int i = 0; i  < siz; i++)
        {
            cout << endl;

            cout << "Robot # " << i << endl;
            cout << "Model Name: " << hill[i].model_name << endl;
            cout << "Model Num: " << hill[i].model_num << endl;
            cout << "Weight: " << hill[i].final_weight << endl;
            cout << "Cost: " << hill[i].final_cost << endl;
            cout << "Retail Price: " << hill[i].retail_price << endl;

            cout << endl;
        }
    }

    else if (choice == 1)
    {
        for (int i = 0; i < siz; i++)
        {
            detail_robot_view();
        }
    }
}

void Robot::detail_robot_view()
{
    int siz = hill.size();
    //cout << siz << endl;

    cout << "### DETAILED ROBOT LIST ###" << endl;

    for (int i = 0; i  < siz; i++)
    {
        cout << endl;

        cout << "Robot # " << i << endl;
        cout << "Model Name: " << hill[i].model_name << endl;
        cout << "Model Num: " << hill[i].model_num << endl;
        cout << "Weight: " << hill[i].final_weight << endl;
        cout << "Cost: " << hill[i].final_cost << endl;
        cout << "Retail Price: " << hill[i].retail_price << endl;

        if (hill[i].parts[0] != 0)
        {
            cout << endl;
            cout << "Head Name: " << hill[i].noggin.ahoy.comp_name << endl;
            cout << "Head Number: " << hill[i].noggin.ahoy.comp_part_num << endl;
            cout << "Head Weight: " << hill[i].noggin.ahoy.comp_weight << endl;
            cout << "Head Cost: " << hill[i].noggin.ahoy.comp_cost << endl;
            cout << endl;
        }

        if (hill[i].parts[1] != 0)
        {
            cout << endl;
            cout << "Torso Name: " << hill[i].robo_t.ahoy.comp_name << endl;
            cout << "Torso Number: " << hill[i].robo_t.ahoy.comp_part_num << endl;
            cout << "Torso Weight: " << hill[i].robo_t.ahoy.comp_weight << endl;
            cout << "Torso Cost: " << hill[i].robo_t.ahoy.comp_cost << endl;
            cout << "Torso Battery: " << hill[i].robo_t.get_total_battery(hill[i].robo_t) << endl;
            cout << endl;
        }

        if (hill[i].parts[2] == 1 || hill[i].parts[2] == 2)
        {
            if (hill[i].parts[2] == 1)
            {
                cout << endl;
                //cout << "Arm Vector Size: " << all_arm.size() << endl;
                cout << "1st Arm Name: " << hill[i].first_arm.ahoy.comp_name << endl;
                cout << "1st Arm Number: " << hill[i].first_arm.ahoy.comp_part_num << endl;
                cout << "1st Arm Weight: " << hill[i].first_arm.ahoy.comp_weight << endl;
                cout << "1st Arm Cost: " << hill[i].first_arm.ahoy.comp_cost << endl;
                cout << "1st Arm Power: " << hill[i].first_arm.get_arm_power(hill[i].first_arm) << endl;
                cout << endl;
            }
            if (hill[i].parts[6] == 2)
            {
                cout << endl;
                //cout << "Arm Vector Size: " << all_arm.size() << endl;
                cout << "2nd Arm Name: " << hill[i].second_arm.ahoy.comp_name << endl;
                cout << "2nd Arm Number: " << hill[i].second_arm.ahoy.comp_part_num << endl;
                cout << "2nd Arm Weight: " << hill[i].second_arm.ahoy.comp_weight << endl;
                cout << "2nd Arm Cost: " << hill[i].second_arm.ahoy.comp_cost << endl;
                cout << "2nd Arm Power: " << hill[i].second_arm.get_arm_power(hill[i].second_arm) << endl;
                cout << endl;
                cout << endl;
                //cout << "Arm Vector Size: " << all_arm.size() << endl;
                cout << "1st Arm Name: " << hill[i].first_arm.ahoy.comp_name << endl;
                cout << "1st Arm Number: " << hill[i].first_arm.ahoy.comp_part_num << endl;
                cout << "1st Arm Weight: " << hill[i].first_arm.ahoy.comp_weight << endl;
                cout << "1st Arm Cost: " << hill[i].first_arm.ahoy.comp_cost << endl;
                cout << "1st Arm Power: " << hill[i].first_arm.get_arm_power(hill[i].first_arm) << endl;
                cout << endl;
            }

        }

        if (hill[i].parts[3] != 0)
        {
            cout << endl;
            cout << "Locomotor Name: " << hill[i].loco_coco.ahoy.comp_name << endl;
            cout << "Locomotor Number: " << hill[i].loco_coco.ahoy.comp_part_num << endl;
            cout << "Locomotor Weight: " << hill[i].loco_coco.ahoy.comp_weight << endl;
            cout << "Locomotor Cost: " << hill[i].loco_coco.ahoy.comp_cost << endl;
            cout << "Locomotor Max Speed: " << hill[i].loco_coco.get_max_speed(hill[i].loco_coco) << endl;
            cout << "Locomotor Power Consumption: " << hill[i].loco_coco.get_pow_eat(hill[i].loco_coco) << endl;
            cout << endl;
        }

        if (hill[i].parts[4] != 0)
        {
            cout << endl;
            cout << "Battery Name: " << hill[i].power_af.ahoy.comp_name << endl;
            cout << "Battery Number: " << hill[i].power_af.ahoy.comp_part_num << endl;
            cout << "Battery Weight: " << hill[i].power_af.ahoy.comp_weight << endl;
            cout << "Battery Cost: " << hill[i].power_af.ahoy.comp_cost << endl;
            cout << "Battery Power: " << hill[i].power_af.get_battery(hill[i].power_af) << endl;
            cout << endl;
        }


        //cout << endl;

        cout << "=============NEW ROBOT==============" << endl;


    }




}

void Robot::tot_weight_cost(int choice[])
{
    cout << endl;
    if(choice[0] == 0)
    {
        robo_cop.final_weight += 0;
        robo_cop.final_cost += 0;
        robo_cop.parts[0] = 0;
    }

    else if (choice[0] == 1)
    {
        robo_cop.final_weight += robo_cop.noggin.ahoy.comp_weight;
        robo_cop.final_cost += robo_cop.noggin.ahoy.comp_cost;
    }

    if(choice[1] == 0)
    {
        robo_cop.final_weight += 0;
        robo_cop.final_cost += 0;
        robo_cop.parts[1] = 0;
    }

    else if (choice[1] == 1)
    {
        robo_cop.final_weight += robo_cop.robo_t.ahoy.comp_weight;
        robo_cop.final_cost += robo_cop.robo_t.ahoy.comp_cost;
    }

    if(choice[2] == 0)
    {
        robo_cop.final_weight += 0;
        robo_cop.final_cost += 0;
        robo_cop.parts[2] = 0;
    }

    else if ((choice[2] == 1) || (choice[2] == 2))
    {
        if (choice[2] == 2)
        {
            robo_cop.final_weight += robo_cop.first_arm.ahoy.comp_weight;
            robo_cop.final_cost += robo_cop.first_arm.ahoy.comp_cost;

            robo_cop.final_weight += robo_cop.second_arm.ahoy.comp_weight;
            robo_cop.final_cost += robo_cop.second_arm.ahoy.comp_cost;
        }

        else if(choice[2] == 1)
        {
            robo_cop.final_weight += robo_cop.first_arm.ahoy.comp_weight;
            robo_cop.final_cost += robo_cop.first_arm.ahoy.comp_cost;
            robo_cop.parts[6] = 0;
        }
    }

    if(choice[3] == 0)
    {
        robo_cop.final_weight += 0;
        robo_cop.final_cost += 0;
        robo_cop.parts[3] = 0;
    }

    else if (choice[3] == 1)
    {
        robo_cop.final_weight += robo_cop.loco_coco.ahoy.comp_weight;
        robo_cop.final_cost += robo_cop.loco_coco.ahoy.comp_cost;
    }

    if(choice[4] == 0)
    {
        robo_cop.final_weight += 0;
        robo_cop.final_cost += 0;
        robo_cop.parts[4] = 0;
    }

    else if (choice[4] == 1)
    {
        int num_bat;
        num_bat = robo_cop.robo_t.get_total_battery(robo_cop.robo_t);
        robo_cop.final_weight += (num_bat*robo_cop.power_af.ahoy.comp_weight);
        robo_cop.final_cost += (num_bat*robo_cop.power_af.ahoy.comp_cost);
    }

}

double Robot::get_retail(Robot obj, int i)
{
    return obj.hill[i].retail_price;
}

double Robot::get_weight(Robot obj, int i)
{
    return obj.hill[i].final_weight;
}
