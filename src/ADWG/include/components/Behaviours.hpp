#ifndef BEHAVIOURS_HPP_
#define BEHAVIOURS_HPP_

#include "IBehaviours.hpp"
#include "attributes.hpp"

class Datalink;

class AWACS : public IBehaviours {
    public:
        AWACS(Datalink *dl);
        void update();
    private:
        int _speed;
        int _def;
        int _atk;
        double _fuel;

        flight_data_t *blackbox;
        Datalink *dl;
        
        void update_datalink();

};

class FIGHTER : public IBehaviours {
    public:
        FIGHTER(double fuel, int nb_missile, int def, int atk);
        void update();
    private:
        int _speed;
        int _nb_missile;
        int _def;
        int _atk;
        double _fuel;

        flight_data_t *blackbox;

        // timers during which the craft is changing to a new state
        int _changing_speed;
        int _changing_orientation;
        int _changing_alt;

        // value added after each "tick" down of the timer
        int _step_speed;
        int _step_orientation;
        int _step_alt;

        void change_speed(int newspeed);
        void change_orientation(int neworientation);
        void change_alt(int newalt);

        

};

class MISSILE : public IBehaviours {
    public:
        MISSILE();
        void update();
};

#endif