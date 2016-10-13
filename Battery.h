#ifndef BATTERY_H
#define BATTERY_H

#include "Components.h"

class Battery : virtual public Components
{
    public:
        Battery();

        void set_bat();
        double get_battery(Battery);

    protected:
        double energy;

    private:
};

#endif
