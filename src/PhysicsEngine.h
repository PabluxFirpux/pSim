//
// Created by pabluxfirpux on 18/05/24.
//

#ifndef PSIM_PHYSICSENGINE_H
#define PSIM_PHYSICSENGINE_H
#include "Particle.h"

struct Force {
    float x;
    float y;
};

class PhysicsEngine {
public:
    PhysicsEngine(float bg, float br, float bb, float by, float gg, float gr, float gy, float rr, float ry, float yy);
    Force getForce(Particle* target, Particle* reference);
    void setForces(float *bg, float *br, float *bb, float *by, float *gg, float *gr, float *gy, float *rr, float *ry, float *yy);
private:
    float bg;
    float br;
    float bb;
    float by;
    float gg;
    float gr;
    float gy;
    float rr;
    float ry;
    float yy;
    float getRelation(Particle* p1, Particle* p2);
    float getSquare(float x);
};


#endif //PSIM_PHYSICSENGINE_H
