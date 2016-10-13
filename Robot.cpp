#include "Robot.h"

Robot::Robot()
{
    //ctor
}

void Robot::set_robot()
{
    //set_torso();
    int counter = 5;
    int user_choice[5];
    user_choice[0] = 0;
    user_choice[1] = 0;
    user_choice[2] = 0;
    user_choice[3] = 0;
    user_choice[4] = 0;
    while (counter > 0)
    {

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
            if (user_choice[0] == 0)
            {
                robo_cop.noggin.set_comp(0);
                user_choice[0] = 1;
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
                robo_cop.robo_t.set_comp(1);
                robo_cop.robo_t.set_torso();
                user_choice[1] = 1;
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
                robo_cop.first_arm.set_comp(2);
                robo_cop.first_arm.set_arm();
                user_choice[2]++;
            }

            else if (user_choice[2] == 1)
            {
                robo_cop.second_arm.set_comp(2);
                robo_cop.second_arm.set_arm();
                user_choice[2]++;
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
                robo_cop.loco_coco.set_comp(3);
                robo_cop.loco_coco.set_loco();
                user_choice[3] = 1;
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
                robo_cop.power_af.set_comp(4);
                robo_cop.power_af.set_bat();
                user_choice[4] = 1;
            }

            else
            {
                cout << "Can't have more than one Battery type!" << endl;
                cout << endl;
                continue;
            }

        }

        else if(part_type == 5 || counter == 1)
        {
            cout << "Done with Robot!" << endl;
            break;
        }

        counter--;
    }

    cout << "What is the robot's model name? ";
    cin >> robo_cop.model_name;
    cout << endl;

    cout << "What is the robot's model number? ";
    cin >> robo_cop.model_num;
    cout << endl;

    robo_cop.final_weight = (robo_cop.robo_t.ahoy.comp_weight) + (robo_cop.loco_coco.ahoy.comp_weight);
    robo_cop.final_weight += (robo_cop.robo_t.get_total_battery(robo_cop.robo_t))*(robo_cop.power_af.ahoy.comp_weight);
    robo_cop.final_weight += (robo_cop.first_arm.ahoy.comp_weight) + (robo_cop.second_arm.ahoy.comp_weight);

    robo_cop.final_cost = (robo_cop.robo_t.ahoy.comp_cost) + (robo_cop.loco_coco.ahoy.comp_cost);
    robo_cop.final_cost += (robo_cop.robo_t.get_total_battery(robo_cop.robo_t))*(robo_cop.power_af.ahoy.comp_cost);
    robo_cop.final_cost += (robo_cop.first_arm.ahoy.comp_cost) + (robo_cop.second_arm.ahoy.comp_cost);

    hill.push_back(robo_cop);
}

void Robot::print_all_models()
{
    int siz = hill.size();
    cout << siz << endl;

    for (int i = 0; i  < siz; i++)
    {
        //Torso obj;
        //int tot_bat = hill[i].robo_t.get_total_battery(hill[i].robo_t);
        cout << endl;

        cout << "Model Name: " << hill[i].model_name<<endl;
        cout << "Model Num: " << hill[i].model_num<<endl;

        cout << "T_Weight: " << hill[i].robo_t.ahoy.comp_weight<<endl;
        cout << "L_Weight: " << hill[i].loco_coco.ahoy.comp_weight<<endl;
        cout << "B_Weight: " << (hill[i].robo_t.get_total_battery(hill[i].robo_t))*(hill[i].power_af.ahoy.comp_weight)<<endl;

        cout << "Weight: " << hill[i].final_weight<<endl;

        cout << endl;
    }

}
