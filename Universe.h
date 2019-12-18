//
// Created by Parth on 11/11/2019.
//

#ifndef UNIVERSE_UNIVERSE_H
#define UNIVERSE_UNIVERSE_H


#include <string>
#include <vector>
#include "Galaxy.h"

class Universe {
    int id;
    int galaxy_count;

    std::vector<Galaxy> galaxies;

    public:
        Universe(int universe_id, int galaxy_number);
        void create_universe();
        std::string get_name();
};


#endif //UNIVERSE_UNIVERSE_H
