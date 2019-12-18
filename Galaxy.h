//
// Created by Parth on 11/11/2019.
//

#ifndef UNIVERSE_GALAXY_H
#define UNIVERSE_GALAXY_H

#include <string>
#include <vector>
#include "System.h"

class Galaxy {

    int id;
    int system_count;

    std::vector<System> systems;

    float (&position)[2];

    public:
        Galaxy(int galaxy_id, int system_number, float (&galaxy_position)[2]);
        void create_galaxy();
        std::string get_name();
        float* get_position();
        void set_position(const float new_position[2]);
};


#endif //UNIVERSE_GALAXY_H
