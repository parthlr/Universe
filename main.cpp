#include <iostream>
#include "Universe.h"
#include "MassObject.h"
#include "Physics.h"

int main() {
    float position1[2] = {0.0f, 0.0f};
    float position2[2] = {10.0f, 0.0f};
    float velocity1[2] = {2.0f, 0.0f};
    float velocity2[2] = {-2.0f, 0.0f};
    float acceleration[2] = {0.0f, 0.0f};
    MassObject massObject1(12, 2, 2, position1, velocity1, acceleration);
    MassObject massObject2(10, 2, 2, position2, velocity2, acceleration);
    int iterations = 0;
    while(iterations < 1000) {
        Physics::set_motion(massObject1);
        Physics::set_motion(massObject2);
        std::cout << "X1: " << massObject1.get_position()[0] << " Y1: " << massObject1.get_position()[1] << "\n";
        std::cout << "X2: " << massObject2.get_position()[0] << " Y2: " << massObject2.get_position()[1] << "\n";
        if (Physics::collision(massObject1, massObject2)) {
            Physics::on_collide(massObject1, massObject2);
        }
        iterations++;
    }
    return 0;
}
