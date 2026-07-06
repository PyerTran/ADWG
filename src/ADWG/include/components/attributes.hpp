#ifndef ATTRIBUTES_HPP_
#define ATTRIBUTES_HPP_

typedef struct has_radar_s
{

} has_radar_t;

typedef struct flight_data_s
{
    int altitude;
    int pos_x;
    int pos_y;
    short int orientation; // modulo 360°
} flight_data_t;

typedef struct blue_team_s
{

}blue_team_t;

typedef struct red_team_s
{

}red_team_t;

typedef struct shotdown_s
{

} shotdown_t;

#endif