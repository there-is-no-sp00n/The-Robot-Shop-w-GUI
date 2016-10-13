#ifndef TORSO_H
#define TORSO_H

#include "Components.h"

class Torso : virtual public Components
{
    public:
        Torso();

        void set_torso();

        int get_total_battery(Torso);

    protected:
        int torso_bat;

        vector <Torso> all_torso;

    private:
};

#endif
