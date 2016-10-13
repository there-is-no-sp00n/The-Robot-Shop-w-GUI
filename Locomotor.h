#ifndef LOCOMOTOR_H
#define LOCOMOTOR_H

#include "Components.h"

class Locomotor : virtual public Components
{
    public:
        Locomotor();
        void set_loco();
        void total_energy();

    protected:
        double max_speed;
        double pow_eaten;

    private:
};

#endif
