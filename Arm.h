#ifndef ARM_H
#define ARM_H

#include "Components.h"

class Arm : virtual public Components
{
    public:
        Arm();
        void set_arm();

    protected:
        double power_con;

        vector <Arm> all_arm;

    private:
};

#endif
