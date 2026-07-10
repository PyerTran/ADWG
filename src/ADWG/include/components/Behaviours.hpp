#ifndef BEHAVIOURS_HPP_
#define BEHAVIOURS_HPP_

#include "IBehaviours.hpp"
#include "attributes.hpp"
#include "registry_utils.hpp"
#include "angle.hpp"

#define AWACS_TOPSPEED 800/60/60
#define FIGHTER_TOPSPEED 1600/60/60
#define MISSILE_TOPSPEED 4000/60/60
#define WEZ 100
#define WEZ_WARNING 150



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

        // new value of each attribut
        double _newspeed;
        double _neworientation;
        double _newalt;

        // value added after each "tick" down of the timer
        double _step_speed;
        double _step_orientation;
        double _step_alt;

        // cmd speed
        void change_speed(double newspeed);
        // cmd orientation [0°, 360°[
        void change_orientation(double neworientation);
        // cmd alt
        void change_alt(double newalt);

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
        
        // locate your allies, closest to farthest
        std::vector<flight_data_t> find_my_allies();
        
        /**
         * @brief finds a coords where the AWACS should push
         * 
         * gather the average of the coords of its three closest allies
         * theoreticaly this is where the AWACS is the safest
         * altho the AWACS should stay slightly "behind" coords for safety reasons
         * 
         * @return adwg::Vector3<double> 
         */
        adwg::Vector3<double> where_to_push();
        
        // find a coords where the AWACS should be to overlook, without being in danger.
        adwg::Vector3<double> safezone();
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