#include "Robot.h"

Robot::Robot()
{

}

void Robot::create_comp()
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
        cout << "What is your part type? ";
        int part_type;
        cin >> part_type;
        cout << endl;

        if (part_type > 5)
        {
            cout << "Number out of bounds! Please pick a number between 0 and 5" << endl;
            continue;
        }

        if (part_type == 0)
        {
            Head obj_head;
            obj_head.set_comp(0);
            all_head.push_back(obj_head);
        }

        if (part_type == 1)
        {
            Torso obj_torso;
            obj_torso.set_comp(1);
            obj_torso.set_torso();
            all_torso.push_back(obj_torso);
        }

        if (part_type == 2)
        {
            Arm obj_arm;
            obj_arm.set_comp(2);
            obj_arm.set_arm();
            all_arm.push_back(obj_arm);
        }

        if(part_type == 3)
        {
            Locomotor obj_loco;
            obj_loco.set_comp(3);
            obj_loco.set_loco();
            all_loco.push_back(obj_loco);
        }

        if(part_type == 4)
        {
            Battery obj_bat;
            obj_bat.set_comp(4);
            obj_bat.set_bat();
            all_bat.push_back(obj_bat);
        }

        if(part_type == 5)
        {
            flag = 0;
        }
    }
}
void Robot::set_robot()
{
    int counter = 5;
    int user_choice[5];
    user_choice[0] = 0;
    user_choice[1] = 0;
    user_choice[2] = 0;
    user_choice[3] = 0;
    user_choice[4] = 0;

    while (counter > 0)
    {
        cout << "### CREATE ROBOT MENU ###" << endl;
        cout << endl;

        cout << "Enter type of component you wish to add" << endl;
        cout << "Press 0 for HEAD" << endl;
        cout << "Press 1 for TORSO" << endl;
        cout << "Press 2 for ARM" << endl;
        cout << "Press 3 for LOCOMOTOR" << endl;
        cout << "Press 4 for BATTERY" << endl;
        cout << "Press 5 to stop adding more components" << endl;
        cout << "What is your part type? ";
        int part_type;
        cin >> part_type;
        cout << endl;
        int j = 0;

        if (part_type > 5)
        {
            cout << "Number out of bounds! Please pick a number between 0 and 5" << endl;
            continue;
        }

        if (part_type == 0)
        {
            if (user_choice[0] == 0)
            {
                j = all_head.size();
                for(int i = 0; i < j; i++)
                {
                    cout << endl;
                    cout << "HEAD NUMBER: " << i << endl;
                    cout << endl;
                    cout << "Head Name: " << all_head[i].ahoy.comp_name << endl;
                    cout << "Head Number: " << all_head[i].ahoy.comp_part_num << endl;
                    cout << "Head Weight: " << all_head[i].ahoy.comp_weight << endl;
                    cout << "Head Cost: " << all_head[i].ahoy.comp_cost << endl;
                    cout << endl;
                }
                cout << "Which HEAD model would you like? ";
                int user;
                cin >> user;
                robo_cop.noggin = all_head[user];
                user_choice[0] = 1;
                cout << endl;
                counter --;
            }

            else
            {
                cout << "Can't have more than one Head!" << endl;
                cout << endl;
                continue;
            }
        }

        if (part_type == 1)
        {
            if (user_choice[1] == 0)
            {
                j = all_torso.size();
                for(int i = 0; i < j ; i++)
                {
                    cout << endl;
                    cout << "TORSO NUMBER: " << i << endl;
                    cout << endl;
                    cout << "Torso Name: " << all_torso[i].ahoy.comp_name << endl;
                    cout << "Torso Number: " << all_torso[i].ahoy.comp_part_num << endl;
                    cout << "Torso Weight: " << all_torso[i].ahoy.comp_weight << endl;
                    cout << "Torso Cost: " << all_torso[i].ahoy.comp_cost << endl;
                    cout << "Torso Battery: " << all_torso[i].get_total_battery(all_torso[i]) << endl;
                    cout << endl;
                }
                cout << "Which TORSO model would you like? ";
                int user;
                cin >> user;
                robo_cop.robo_t = all_torso[user];
                user_choice[1] = 1;
                counter--;
            }
            else
            {
                cout << "Can't have more than one Torso!" << endl;
                cout << endl;
                continue;
            }

        }

        if (part_type == 2)
        {
            if (user_choice[2] == 0)
            {
                j = all_arm.size();
                for(int i = 0; i < j; i++)
                {
                    cout << endl;
                    cout << "ARM NUMBER: " << i << endl;
                    cout << endl;
                    cout << "Arm Name: " << all_arm[i].ahoy.comp_name << endl;
                    cout << "Arm Number: " << all_arm[i].ahoy.comp_part_num << endl;
                    cout << "Arm Weight: " << all_arm[i].ahoy.comp_weight << endl;
                    cout << "Arm Cost: " << all_arm[i].ahoy.comp_cost << endl;
                    cout << "Arm Power: " << all_arm[i].get_arm_power(all_arm[i]) << endl;
                    cout << endl;
                }
                cout << "Which ARM model would you like? ";
                int user;
                cin >> user;
                robo_cop.first_arm = all_arm[user];
                user_choice[2] = 1;
                continue;
            }

            else if (user_choice[2] == 1)
            {
                j = all_arm.size();
                for(int i = 0; i < j; i++)
                {
                    cout << endl;
                    cout << "ARM NUMBER: " << i << endl;
                    cout << endl;
                    cout << "Arm Name: " << all_arm[i].ahoy.comp_name << endl;
                    cout << "Arm Number: " << all_arm[i].ahoy.comp_part_num << endl;
                    cout << "Arm Weight: " << all_arm[i].ahoy.comp_weight << endl;
                    cout << "Arm Cost: " << all_arm[i].ahoy.comp_cost << endl;
                    cout << "Arm Power: " << all_arm[i].get_arm_power(all_arm[i]) << endl;
                    cout << endl;
                }
                cout << "Which ARM model would you like? ";
                int user;
                cin >> user;
                robo_cop.second_arm = all_arm[user];
                user_choice[2] = 2;
                counter--;
            }
            else
            {
                cout << "Can't have more than two Arms!" << endl;
                cout << endl;
                continue;
            }
        }

        else if(part_type == 3)
        {
            if (user_choice[3] == 0)
            {
                j = all_loco.size();
                for(int i = 0; i < j; i++)
                {
                    cout << endl;
                    cout << "LOCOMOTOR NUMBER: " << i << endl;
                    cout << endl;
                    cout << "Locomotor Name: " << all_loco[i].ahoy.comp_name << endl;
                    cout << "Locomotor Number: " << all_loco[i].ahoy.comp_part_num << endl;
                    cout << "Locomotor Weight: " << all_loco[i].ahoy.comp_weight << endl;
                    cout << "Locomotor Cost: " << all_loco[i].ahoy.comp_cost << endl;
                    cout << "Locomotor Max Speed: " << all_loco[i].get_max_speed(all_loco[i]) << endl;
                    cout << "Locomotor Power Consumption: " << all_loco[i].get_pow_eat(all_loco[i]) << endl;
                    cout << endl;
                }
                cout << "Which LOCOMOTOR model would you like? ";
                int user;
                cin >> user;
                robo_cop.loco_coco = all_loco[user];
                user_choice[3] = 1;
                counter--;
            }

            else
            {
                cout << "Can't have more than one Locomotor!" << endl;
                cout << endl;
                continue;
            }


        }

        else if(part_type == 4)
        {
            if (user_choice[4] == 0)
            {
                j = all_bat.size();
                for(int i = 0; i < j; i++)
                {
                    cout << endl;
                    cout << "BATTERY NUMBER: " << i << endl;
                    cout << endl;
                    cout << "Battery Name: " << all_bat[i].ahoy.comp_name << endl;
                    cout << "Battery Number: " << all_bat[i].ahoy.comp_part_num << endl;
                    cout << "Battery Weight: " << all_bat[i].ahoy.comp_weight << endl;
                    cout << "Battery Cost: " << all_bat[i].ahoy.comp_cost << endl;
                    cout << "Battery Power: " << all_bat[i].get_battery(all_bat[i]) << endl;
                    cout << endl;
                }
                cout << endl;
                cout << "The selected Torso model allows " << robo_cop.robo_t.get_total_battery(robo_cop.robo_t) << " battery(ies)." << endl;
                cout << "Which BATTERY model would you like? ";
                int user;
                cin >> user;
                robo_cop.power_af = all_bat[user];
                user_choice[4] = 1;
                counter --;
            }

            else
            {
                cout << "Can't have more than one battery type!" << endl;
                cout << endl;
                continue;
            }

        }

        else if(part_type == 5 || counter == 0)
        {
            int sum = 0;
            for(auto& num:user_choice)
            {
                sum += num;
            }

            if(sum == 0)
            {
                cout << "Did not add any parts!" << endl;
                cout << endl;
                break;
            }


            cout << "Done with Robot!" << endl;
            cout << endl;
            cout << "What is the robot's model name? ";
            cin >> robo_cop.model_name;
            cout << endl;

            cout << "What is the robot's model number? ";
            cin >> robo_cop.model_num;
            cout << endl;
            robo_cop.final_weight = 0;
            robo_cop.final_cost = 0;

            tot_weight_cost(user_choice);

            cout << "Total Cost Is: " << robo_cop.final_cost << endl;
            cout << "What is your retail price for this robot model? ";
            cin >> robo_cop.retail_price;

            hill.push_back(robo_cop);
            break;
        }

        if (counter == 0)
        {
            cout << "Done with Robot!" << endl;
            cout << endl;
            cout << "What is the robot's model name? ";
            cin >> robo_cop.model_name;
            cout << endl;

            cout << "What is the robot's model number? ";
            cin >> robo_cop.model_num;
            cout << endl;
            robo_cop.final_weight = 0;
            robo_cop.final_cost = 0;

            tot_weight_cost(user_choice);

            cout << "Total Cost Is: " << robo_cop.final_cost << endl;
            cout << "What is your retail price for this robot model? ";
            cin >> robo_cop.retail_price;

            hill.push_back(robo_cop);
            break;
        }

        //cout << "Counter: " << counter << endl;
    }

}

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
        cout << endl;
    }

    j = all_arm.size();
    for (i = 0; i < j; i++)
    {
        cout << endl;
        cout << "Arm Vector Size: " << all_arm.size() << endl;
        cout << "Arm Name: " << all_arm[i].ahoy.comp_name << endl;
        cout << "Arm Number: " << all_arm[i].ahoy.comp_part_num << endl;
        cout << "Arm Weight: " << all_arm[i].ahoy.comp_weight << endl;
        cout << "Arm Cost: " << all_arm[i].ahoy.comp_cost << endl;
        cout << "Arm Power: " << all_arm[i].get_arm_power(all_arm[i]) << endl;
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
        cout << endl;
    }



}

void Robot::print_all_models()
{
    cout << "### ROBOT LIST ###" << endl;
    cout << endl;

    int siz = hill.size();
    //cout << siz << endl;

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

void Robot::tot_weight_cost(int choice[])
{
    cout << endl;
    if(choice[0] == 0)
    {
        robo_cop.final_weight += 0;
        robo_cop.final_cost += 0;
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
        }
    }

    if(choice[3] == 0)
    {
        robo_cop.final_weight += 0;
        robo_cop.final_cost += 0;
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
