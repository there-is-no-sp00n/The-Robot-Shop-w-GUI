#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Components
{
    public:
        Components();

        void set_comp(int);

    //protected:
        struct comp
        {
            string comp_type;
            string comp_name;
            string comp_part_num;
            string comp_desc;

            double comp_weight = 0;
            double comp_cost = 0;
        };

        comp ahoy;

    //private:
};

#endif
