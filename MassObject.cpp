//
// Created by ParthSchool on 11/13/2019.
//

#include "MassObject.h"

MassObject::MassObject(float object_mass, float object_radius, float object_elasticity, float (&object_position)[2], float (&object_velocity)[2], float (&object_acceleration)[2]) : position(object_position), velocity(object_velocity), acceleration(object_acceleration) {
    mass = object_mass;
    radius = object_radius;
    elasticity = object_elasticity;
}

float MassObject::get_mass() {
    return mass;
}

float MassObject::get_radius() {
    return radius;
}

float MassObject::get_elasticity() {
    return elasticity;
}

float* MassObject::get_position() {
    return position;
}

void MassObject::set_position(const float *new_position) {
    position[0] = new_position[0];
    position[1] = new_position[1];
}

float* MassObject::get_velocity() {
    return velocity;
}

void MassObject::set_velocity(const float *new_velocity) {
    velocity[0] = new_velocity[0];
    velocity[1] = new_velocity[1];
}

float* MassObject::get_acceleration() {
    return acceleration;
}

void MassObject::set_acceleration(const float *new_acceleration) {
    acceleration[0] = new_acceleration[0];
    acceleration[1] = new_acceleration[1];
}