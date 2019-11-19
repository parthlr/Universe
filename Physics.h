//
// Created by ParthSchool on 11/18/2019.
//

#ifndef UNIVERSE_PHYSICS_H
#define UNIVERSE_PHYSICS_H


#include "MassObject.h"

class Physics {

    public:
        constexpr static float deltaTime = 0.1f;
        void add_force(MassObject massObject, const float force[2]);
        void set_motion(MassObject massObject);
};


#endif //UNIVERSE_PHYSICS_H
