//
// Created by Parth on 11/11/2019.
//

#include "Universe.h"
#include <iostream>

Universe::Universe(int universe_id, int galaxy_number) {
    id = universe_id;
    galaxy_count = galaxy_number;
}

void Universe::create_universe() {
    for (int i = 0; i < galaxy_count; i++) {
        float galaxy_position[2] = {1.0f, 1.0f};
        Galaxy galaxy(i, rand() % 10, galaxy_position);
        galaxy.create_galaxy();
        galaxies.push_back(galaxy);
        std::cout << "Creating galaxy: " << galaxy.get_name() << "\n";
    }
}

std::string Universe::get_name() {
    return "U-" + std::to_string(id);
}