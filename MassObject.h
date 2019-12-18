//
// Created by Parth on 11/13/2019.
//

#ifndef UNIVERSE_MASSOBJECT_H
#define UNIVERSE_MASSOBJECT_H

#include "Shader.h"

class MassObject {

    float mass;         // In kg
    float radius;       // In meters
    float elasticity;

    float (&position)[2];
    float (&velocity)[2];
    float (&acceleration)[2];

    Shader shader;

    public:
        MassObject(float object_mass, float object_radius, float object_elasticity, float (&object_position)[2], float (&object_velocity)[2], float (&object_acceleration)[2], Shader object_shader);
        float get_mass();
        float get_radius();
        float get_elasticity();
        float* get_position();
        void set_position(const float new_position[2]);
        float* get_velocity();
        void set_velocity(const float new_velocity[2]);
        float* get_acceleration();
        void set_acceleration(const float new_acceleration[2]);
        void set_vertices(float x, float y, int triangles, float radius);
        void initialize_polygon();
        void set_graphical_position(float x, float y);

        unsigned int VAO;
        unsigned int VBO;
};


#endif //UNIVERSE_MASSOBJECT_H
