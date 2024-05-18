//
// Created by pabluxfirpux on 18/05/24.
//

#include "PhysicsEngine.h"

PhysicsEngine::PhysicsEngine(float bg, float br, float bb, float by, float gg, float gr, float gy, float rr, float ry,
                             float yy) {
    this->bg = bg;
    this->br=br;
    this->bb=bb;
    this->by=by;
    this->gg=gg;
    this->gr=gr;
    this->gy=gy;
    this->rr=rr;
    this->ry=ry;
    this->yy=yy;
}

float PhysicsEngine::getRelation(Particle* p1, Particle* p2) {
    if (p1->getColor() == Color::BLUE) {
        if (p2->getColor() == Color::BLUE) {
            return this->bb;
        }
            if (p2->getColor() == Color::GREEN) {
                return this->bg;
            }
                if (p2->getColor() == Color::RED) {
                    return this->br;
                }
                    if (p2->getColor() == Color::YELLOW) {
                        return this->by;
                    }
    }



        if (p1->getColor() == Color::GREEN) {
            if (p2->getColor() == Color::BLUE) {
                return this->bg;
            }
            if (p2->getColor() == Color::GREEN) {
                return this->gg;
            }
            if (p2->getColor() == Color::RED) {
                return this->gr;
            }
            if (p2->getColor() == Color::YELLOW) {
                return this->gy;
            }
        }
            if (p1->getColor() == Color::RED) {
                if (p2->getColor() == Color::BLUE){
                    return this->br;
                }
                if (p2->getColor() == Color::GREEN){
                    return this-> gr;
                }
               if (p2->getColor() == Color::RED){
                    return this->rr;
                }
                if (p2->getColor() == Color::YELLOW) {
                    return this->ry;
                }
            }
                if (p1->getColor() == Color::YELLOW) {
                    if (p2->getColor() == Color::BLUE) {
                        return this->by;
                    }
                    if (p2->getColor() == Color::GREEN) {
                        return this-> gy;
                    }
                    if (p2->getColor() == Color::RED) {
                        return this->ry;
                    }
                    if (p2->getColor() == Color::YELLOW) {
                        return this->yy;
                    }
                }

                    return 0;
}

Force PhysicsEngine::getForce(Particle* target, Particle* reference) {
    float relation = getRelation(target, reference);
    float x = relation / (reference->getX()-target->getX());
    float y = relation / (reference->getY()-target->getY());
    Force f = {x/200,y/200};
    return f;
}
