#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "src/Particle.h"
#include <vector>

int WIDTH = 1800;
int HEIGHT = 900;
float CELLSIZE = 5;
std::vector<Particle*> particles = std::vector<Particle*>();
void display();

void reshape(int w, int h);

void drawParticle(float x, float y);

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
    calcPositions();
    glBegin(GL_QUADS);

    drawParticles();

    glEnd();

    glFlush();

}
void drawParticle(float x, float y) {
    glColor3f(1, 1, 1);
    glVertex2f(x, y);
    glVertex2f(x + CELLSIZE, y);
    glVertex2f(x + CELLSIZE, y + CELLSIZE);
    glVertex2f(x, y + CELLSIZE);
}

void drawParticles() {
    for(Particle* part: particles) {
        drawParticle(part->getX(), part->getY());
    }
}

void calcPositions() {
    for(Particle* part: particles) {
        part->calcNextPosition();
    }
}

void populate() {
    for (int i = 0; i<3; i++) {
        Particle *perttt = new Particle(WIDTH, HEIGHT);
        particles.push_back(perttt);
    }
}

void pressKey(unsigned char key, int x, int y) {
    //TODO
}
