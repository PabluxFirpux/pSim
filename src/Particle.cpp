//
// Created by pabluxfirpux on 17/05/24.
//

#include <cstdlib>
#include "Particle.h"

Particle::Particle(int maxX, int maxY) {
    this->x = float_rand(0, maxX);
    this->y = float_rand(0, maxY);
    this->speedX = float_rand(0.3, 2);
    this->speedY = float_rand(0.3, 2);
    this->maxX = maxX;
    this->maxY = maxY;
}

float Particle::float_rand( float min, float max )
{
    float scale = rand() / (float) RAND_MAX; /* [0, 1.0] */
    return min + scale * ( max - min );      /* [min, max] */
}

float Particle::getX() {
    return this->x;
}

float Particle::getY() {
    return this->y;
}

void Particle::calcNextPosition() {
    this->bounce();
    this->x += this->speedX;
    this->y += this->speedY;
}

void Particle::bounce() {
    if (this->x < 2 && this->speedX < 0) {
        this->speedX *= -1;
        return;
    }

    if (this->y < 2 && this->speedY < 0) {
        this->speedY *= -1;
        return;
    }

    if (this->x > this->maxX && this->speedX > 0) {
        this->speedX *= -1;
        return;
    }

    if (this->y > this->maxY && this->speedY > 0) {
        this->speedY *= -1;
        return;
    }
}

void Particle::setMaxX(int maxX) {
    this->maxX = maxX;
}

void Particle::setMaxY(int maxY) {
    this->maxY = maxY;
}

