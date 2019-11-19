#include <iostream>
#include "Universe.h"
#include "MassObject.h"
#include "Physics.h"

int main() {
    float position[2] = {0.0f, 0.0f};
    float velocity[2] = {2.0f, 2.0f};
    float acceleration[2] = {0.0f, 0.0f};
    MassObject massObject(100, 0, position, velocity, acceleration);
    massObject.set_velocity(velocity);
    Physics physics;
    float force[2] = {1000.0f, 1000.0f};
    physics.add_force(massObject, force);
    int iterations = 0;
    while(iterations < 10) {
        physics.set_motion(massObject);
        std::cout << "X: " << massObject.get_position()[0] << " Y: " << massObject.get_position()[1] << "\n";
        iterations++;
    }
    return 0;
}
