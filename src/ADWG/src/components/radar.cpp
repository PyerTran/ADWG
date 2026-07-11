#include "radar.hpp"


RADAR::RADAR(double field_of_view, double range, int n_DL, registry *regis)
{ 
    this->fov = field_of_view;
    this->range=range;
    this->n_DL=n_DL;
    this->enemy_ids.clear();
}

void RADAR::IFF()
{
    sparse_array<Team> tags = regis->get_components<Team>();
    sparse_array<RADAR> radars = regis->get_components<RADAR>();
    size_t id = radars.get_index(this);
    
    TEAM myteam = tags.at(id).value().get_team();

    for (size_t i = 0; i < tags.size(); i += 1)
    {
        std::optional<Team> tag = tags.at(i);
        if (tag.has_value()) {
            if (tag.value().get_team() != myteam) {
                this->enemy_ids.push_back(i);
            }
        }
    }
}

std::vector<flight_data_t> RADAR::run()
{
    detections.clear();
    int distance;
    double absolute_angle;
    // relative angle to the orientation
    double relative_angle;
    bool lookover = true;
    sparse_array<RADAR> radars = regis->get_components<RADAR>();
    size_t id = radars.get_index(this);
    
    // relative postion detection
    sparse_array<flight_data_t> positions = regis->get_components<flight_data_t>();
    flight_data_t selfpos = positions.at(id).value();

    // if the radar sight is looking under the circle
    if (selfpos.orientation > 90 && selfpos.orientation < 270) {
        lookover = false;
    }

    for (int i = 0; i < this->enemy_ids.size(); i += 1) {
        distance = 0;
        absolute_angle = 0;
        relative_angle = 0;
    
        flight_data_t pos = positions.at(this->enemy_ids[i]).value();
        distance = selfpos.position.get_distance(pos.position);
        if (distance < this->range) {
            absolute_angle = selfpos.position.get_angle(pos.position); // between -180° and 180°
            //relative_angle = Normalize(absolute_angle) - Normalize(selfpos.orientation);
            if (lookover) {
                relative_angle = absolute_angle - Utils::DeNormalize(selfpos.orientation); 
            } else {
                relative_angle = Utils::Normalize(absolute_angle) - selfpos.orientation;
            }
            if (relative_angle > -this->fov && relative_angle < this->fov) {
                this->detections.push_back(pos);
            }
        }
    }

    return this->detections;
}

const int RADAR::get_nb_DL(){
    return this->n_DL;
}