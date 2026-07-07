#ifndef BEHAVIOURS_HPP_
#define BEHAVIOURS_HPP_

#include "IBehaviours.hpp"
#include "attributes.hpp"
#include "angle.hpp"

class AIRCRAFT : public IBehaviours
{
    protected:
        registry *regis;
        int _speed;
        int _nb_missile;
        int _def;
        int _atk;
        double _fuel;
        // cinetic properties

        // timers during which the craft is changing to a new state
        int _changing_speed;
        int _changing_orientation;
        int _changing_alt;

        // value added after each "tick" down of the timer
        int _step_speed;
        double _step_orientation;
        int _step_alt;

        void change_speed(int newspeed);
        void change_orientation(double neworientation);
        void change_alt(int newalt);

        // update
        void update_speed();
        void update_orientation();
        void update_alt();
};

class AWACS : public AIRCRAFT {
    public:
        AWACS();
        void update();
    private:
        //Datalink *dl // each team shared an instance of data link
        
        void update_datalink();

};

class FIGHTER : public AIRCRAFT {
    public:
        FIGHTER(double fuel, int nb_missile, int def, int atk);
        void update();
    private:
        

};

class MISSILE : public AIRCRAFT {
    public:
        MISSILE();
        void update();
};

#endif