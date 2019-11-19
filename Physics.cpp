//
// Created by ParthSchool on 11/18/2019.
//

#include "Physics.h"

void Physics::add_force(MassObject massObject, const float force[2]) {
    float x_accel = ((massObject.get_mass() * massObject.get_acceleration()[0]) + force[0]) / massObject.get_mass();
    float y_accel = ((massObject.get_mass() * massObject.get_acceleration()[1]) + force[1]) / massObject.get_mass();
    float new_acceleration[2] = {x_accel, y_accel};
    massObject.set_acceleration(new_acceleration);
}

void Physics::set_motion(MassObject massObject) {
    float x_velocity = massObject.get_velocity()[0] + (massObject.get_acceleration()[0] * deltaTime);
    float y_velocity = massObject.get_velocity()[1] + (massObject.get_acceleration()[1] * deltaTime);
    float new_velocity[2] = {x_velocity, y_velocity};

    float x_pos = massObject.get_position()[0] + (massObject.get_velocity()[0] * deltaTime);
    float y_pos = massObject.get_position()[1] + (massObject.get_velocity()[1] * deltaTime);
    float new_position[2] = {x_pos, y_pos};

    massObject.set_velocity(new_velocity);
    massObject.set_position(new_position);
}