//
// Created by Parth on 11/18/2019.
//

#ifndef UNIVERSE_PHYSICS_H
#define UNIVERSE_PHYSICS_H


#include "MassObject.h"

class Physics {

    private:
        static float vector_magnitude(float vector[2]);

    public:
        constexpr static float deltaTime = 0.0001f;
        static void add_force(MassObject massObject, const float force[2]);
        static void set_motion(MassObject massObject);
        static bool collision(MassObject object1, MassObject object2);
        static void on_collide(MassObject object1, MassObject object2);
};


#endif //UNIVERSE_PHYSICS_H
