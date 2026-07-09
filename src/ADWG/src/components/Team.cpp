#include "Team.hpp"

Team::Team(TEAM team, double forward) {
    this->_forward = forward;
    this->_team = team;
}

const double Team::get_forward_as_angle() {
    return this->_forward;
}

const TEAM Team::get_team() {
    return this->_team;
}