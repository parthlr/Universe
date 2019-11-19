//
// Created by ParthSchool on 11/12/2019.
//

#ifndef UNIVERSE_SYSTEM_H
#define UNIVERSE_SYSTEM_H


#include <string>

class System {

    int id;
    int planet_count;

    float (&position)[2];

    public:
        System(int system_id, int planet_number, float (&system_position)[2]);
        std::string get_name();
        float* get_position();
        void set_position(const float new_position[2]);
};


#endif //UNIVERSE_SYSTEM_H
