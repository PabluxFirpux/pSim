#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "src/Particle.h"
#include <vector>
#include "src/PhysicsEngine.h"

int WIDTH = 1800;
int HEIGHT = 900;
float CELLSIZE = 5;
std::vector<Particle*> particles = std::vector<Particle*>();
PhysicsEngine pengine = PhysicsEngine(0,4,4,0,1,1,0,4,0,1);
void display();

void reshape(int w, int h);

void applyForces();

void drawParticle(float x, float y, Color color);

void calcPositions();

void drawParticles();

void reMarginParticles( int maxX, int maxY);

void pressKey(unsigned char key, int x, int y);

void populate();

void init() {
    glClearColor(0, 0, 0, 255);
}

int main(int argc, char **argv) {
    populate();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(200, 100);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("pSim");

    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(pressKey);
    init();
    glutMainLoop();

    return 0;
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
    glMatrixMode(GL_MODELVIEW);
    WIDTH = w;
    HEIGHT = h;
    reMarginParticles(WIDTH, HEIGHT);
}

void reMarginParticles(int maxX, int maxY) {
    for(Particle* part: particles) {
        part->setMaxX(maxX);
        part->setMaxY(maxY);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    applyForces();
    calcPositions();
    glBegin(GL_QUADS);

    drawParticles();

    glEnd();

    glFlush();

}

void applyForces() {
    for (Particle* p1: particles) {
        for (Particle* p2: particles) {
            if (p1 == p2) {continue;}

            Force f = pengine.getForce(p1, p2);
            p1->addToSpeedX(f.x);
            p1->addToSpeedY(f.y);
        }
    }
}

void drawParticle(float x, float y, Color color) {
    switch (color) {
        case Color::RED:
            glColor3f(1, 0, 0);
            break;
            case Color::BLUE:
            glColor3f(0, 0, 1);
            break;
        case Color::GREEN:
            glColor3f(0, 1, 0);
            break;
        case Color::YELLOW:
            glColor3f(1,1,0);
            break;
    }
    glVertex2f(x, y);
    glVertex2f(x + CELLSIZE, y);
    glVertex2f(x + CELLSIZE, y + CELLSIZE);
    glVertex2f(x, y + CELLSIZE);
}

void drawParticles() {
    for(Particle* part: particles) {
        drawParticle(part->getX(), part->getY(), part->getColor());
    }
}

void calcPositions() {
    for(Particle* part: particles) {
        part->calcNextPosition();
    }
}

void populate() {
    const int PARTICLE_AMOUNT = 10;
    for (int i = 0; i<PARTICLE_AMOUNT; i++) {
        Particle *perttt = new Particle(WIDTH, HEIGHT, Color::BLUE);
        particles.push_back(perttt);
    }
    for (int i = 0; i<PARTICLE_AMOUNT; i++) {
        Particle *perttt = new Particle(WIDTH, HEIGHT, Color::RED);
        particles.push_back(perttt);
    }
    for (int i = 0; i<PARTICLE_AMOUNT; i++) {
        Particle *perttt = new Particle(WIDTH, HEIGHT, Color::GREEN);
        particles.push_back(perttt);
    }
    for (int i = 0; i<PARTICLE_AMOUNT; i++) {
        Particle *perttt = new Particle(WIDTH, HEIGHT, Color::YELLOW);
        particles.push_back(perttt);
    }
}

void pressKey(unsigned char key, int x, int y) {
    //TODO
}
