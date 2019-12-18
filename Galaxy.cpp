//
// Created by Parth on 11/11/2019.
//

#include <string>
#include "Galaxy.h"
Galaxy::Galaxy(int galaxy_id, int system_number, float (&galaxy_position)[2]) : position(galaxy_position) {
    id = galaxy_id;
    system_count = system_number;
}

void Galaxy::create_galaxy() {
    for (int i = 0; i < system_count; i++) {
        float galaxy_position[2] = {1.0f, 1.0f};
        System system(i, rand() % 10, galaxy_position);
        systems.push_back(system);
    }
}

std::string Galaxy::get_name() {
    return "G-" + std::to_string(id);
}

float* Galaxy::get_position() {
    return position;
}

void Galaxy::set_position(const float *new_position) {
    position[0] = new_position[0];
    position[1] = new_position[1];
}