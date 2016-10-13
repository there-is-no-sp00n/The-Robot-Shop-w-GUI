#ifndef ARM_H
#define ARM_H

#include "Components.h"

class Arm : virtual public Components
{
    public:
        Arm();
        void set_arm();

        double get_arm_power(Arm);

    protected:
        double power_con;

    private:
};

#endif
