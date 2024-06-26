//
// Created by pabluxfirpux on 17/05/24.
//

#ifndef PSIM_PARTICLE_H
#define PSIM_PARTICLE_H

enum Color {
    RED,
    GREEN,
    BLUE,
    YELLOW,
    WHITE
};

class Particle {
public:
    Particle(int maxX, int maxY, Color color);
    float getX();
    float getY();
    float setX(float x);
    float setY(float y);
    void calcNextPosition();
    Color getColor();
    void bounce();
    void setMaxX(int maxX);
    void setMaxY(int maxY);
    float float_rand( float min, float max );
    void addToSpeedX(float x);
    void addToSpeedY(float y);
private:
    float x;
    float y;
    float speedX;
    float speedY;
    int maxX;
    int maxY;
    Color color;
};


#endif //PSIM_PARTICLE_H
