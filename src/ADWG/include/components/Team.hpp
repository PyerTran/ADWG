#ifndef TEAM_HPP_
#define TEAM_HPP_

enum TEAM {RED, BLUE};

class Team
{
    public:
        Team(TEAM team, double forward);
        const double get_forward_as_angle();
        const TEAM get_team();
    private:
        double _forward;
        TEAM _team;
};

#endif