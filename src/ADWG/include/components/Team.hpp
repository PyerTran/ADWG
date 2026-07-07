#ifndef TEAM_HPP_
#define TEAM_HPP_

enum TEAM {RED, BLUE};

class ITeam
{
    public:
        virtual const int get_forward_as_angle();
        virtual TEAM get_team();
};

class RED {
    public:
        RED();
        const int get_forward_as_angle();
        const TEAM get_team();
    private:
        int forward;
        TEAM red;

};

class BLUE {
    public:
        BLUE();
        const int get_forward_as_angle();
        const TEAM get_team();
    private:
        int forward;
        TEAM blue;
};

#endif