//
// Created by Parth on 11/18/2019.
//

#include <cmath>
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

bool Physics::collision(MassObject object1, MassObject object2) {
    float distance[2] = {object2.get_position()[0] - object1.get_position()[0], object2.get_position()[1] - object1.get_position()[1]};
    float radius_distance = object1.get_radius() / 1920 + object2.get_radius() / 1920;
    return pow(radius_distance, 2) >= pow(distance[0], 2) + pow(distance[1], 2);
}

void Physics::on_collide(MassObject object1, MassObject object2) {
    float distance[2] = {(object2.get_position()[0] - object1.get_position()[0]), (object2.get_position()[1] - object1.get_position()[1])};
    float collision_normal[2] = {distance[0] / vector_magnitude(distance), distance[1] / vector_magnitude(distance)};
    float relative_velocity[2] = {object2.get_velocity()[0] - object1.get_velocity()[0], object2.get_velocity()[1] - object1.get_velocity()[1]};

    float normal_velocity = (relative_velocity[0] * collision_normal[0]) + (relative_velocity[1] * collision_normal[1]);
    float elasticity = fminf(object1.get_elasticity(), object2.get_elasticity());
    float impulse_constant = (-(1 + elasticity) * normal_velocity) / ((1 / object1.get_mass()) + (1 / object2.get_mass()));

    float impulse[2] = {impulse_constant * collision_normal[0], impulse_constant * collision_normal[1]};
    float object1_new_v[2] = {object1.get_velocity()[0] - ((1 / object1.get_mass()) * impulse[0]), object1.get_velocity()[1] - ((1 / object1.get_mass()) * impulse[1])};
    float object2_new_v[2] = {object2.get_velocity()[0] + ((1 / object2.get_mass()) * impulse[0]), object2.get_velocity()[1] + ((1 / object2.get_mass()) * impulse[1])};

    object1.set_velocity(object1_new_v);
    object2.set_velocity(object2_new_v);
}

float Physics::vector_magnitude(float vector[2]) {
    return sqrt(pow(vector[0], 2) + pow(vector[1], 2));
}