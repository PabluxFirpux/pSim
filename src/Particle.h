//
// Created by pabluxfirpux on 17/05/24.
//

#ifndef PSIM_PARTICLE_H
#define PSIM_PARTICLE_H

enum Color {
    RED,
    GREEN,
    BLUE,
    YELLOW
};

class Particle {
public:
    Particle(int maxX, int maxY, Color color);
    float getX();
    float getY();
    void calcNextPosition();
    Color getColor();
    void bounce();
    void setMaxX(int maxX);
    void setMaxY(int maxY);
    float float_rand( float min, float max );
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
