#ifndef BEHAVIOURS_HPP_
#define BEHAVIOURS_HPP_

#include "IBehaviours.hpp"
#include "attributes.hpp"
#include "registry_utils.hpp"
#include "angle.hpp"

#define AWACS_TOPSPEED 800
#define FIGHTER_TOPSPEED 1600
#define MISSILE_TOPSPEED 4000
#define WEZ 100
#define 

enum STATUS {ATTACK, DEFEND, LOITER};

class AIRCRAFT : public IBehaviours
{
    public:
        

    protected:
        registry *regis;
        double _speed;
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
        double _step_speed;
        double _step_orientation;
        int _step_alt;

        // cmd speed
        void change_speed(double newspeed);
        // cmd orientation
        void change_orientation(double neworientation);
        // cmd alt
        void change_alt(int newalt);

        // update
        void update_speed();
        void update_orientation();
        void update_alt();

        // writing the movement onto the registry
        void move();
};

class AWACS : public AIRCRAFT {
    public:
        AWACS(registry **regis);
        void update();
    private:
        //Datalink *dl // each team shared an instance of data link
        STATUS _status;
        void update_datalink();
};

class FIGHTER : public AIRCRAFT {
    public:
        FIGHTER(registry **regis, double fuel, int nb_missile, int def, int atk);
        void update(); 
};

class MISSILE : public AIRCRAFT {
    public:
        MISSILE(registry **regis);
        void update();
};

#endif