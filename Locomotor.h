#ifndef LOCOMOTOR_H
#define LOCOMOTOR_H

#include "Components.h"

class Locomotor : virtual public Components
{
    public:
        Locomotor();
        void set_loco();
        void total_energy();

        double get_max_speed(Locomotor);
        double get_pow_eat(Locomotor);

    protected:
        double max_speed;
        double pow_eaten;

    private:
};

#endif
