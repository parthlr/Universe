//
// Created by ParthSchool on 11/12/2019.
//

#include "System.h"
System::System(int system_id, int planet_number, float (&system_position)[2]) : position(system_position) {
    id = system_id;
    planet_count = planet_number;
}

std::string System::get_name() {
    return "S-" + std::to_string(id);
}

float* System::get_position() {
    return position;
}

void System::set_position(const float *new_position) {
    position[0] = new_position[0];
    position[1] = new_position[1];
}