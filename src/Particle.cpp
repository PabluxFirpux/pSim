//
// Created by pabluxfirpux on 17/05/24.
//

#include <cstdlib>
#include "Particle.h"
int MAX_SPEED = 10;
Particle::Particle(int maxX, int maxY, Color color) {
    this->x = float_rand(0, maxX);
    this->y = float_rand(0, maxY);
    this->speedX = 0;
    this->speedY = 0;
    this->maxX = maxX;
    this->maxY = maxY;
    this->color = color;
}

Color Particle::getColor() {
    return this->color;
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
    if (this->x < 0) {
        this->x *= -1;
        return;
    }
    if (this->x > this->maxX) {
        this->x -= 50;
    }
    if (this->y< 0) {
        this->y *= -1;
        return;
    }
    if (this->y > this->maxX) {
        this->y -= 50;
    }
    this->x += this->speedX;
    this->y += this->speedY;
   // this->speedX = 0;
   // this->speedY = 0;
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

void Particle::addToSpeedX(float x) {
    if (this->speedX > MAX_SPEED || this->speedX < -MAX_SPEED) {this->speedX *= 0.5;return;}
    this->speedX += x;
}

void Particle::addToSpeedY(float y) {
    if (this->speedY > MAX_SPEED || this->speedY < -MAX_SPEED) {this->speedY*=0.5;return;}
    this->speedY += y;
}

float Particle::setX(float x) {
   this->x = x;
}

float Particle::setY(float y) {
    this->y = y;
}

