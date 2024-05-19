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
PhysicsEngine pengine = PhysicsEngine(0,2,3,0,0,3,0,0,1,0);
void display();

void reshape(int w, int h);

void applyForces();

void drawParticle(float x, float y, Color color);

void drawControls();

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
    drawControls();
    glEnd();

    glFlush();

}

void drawControls() {
    //Draw controls background
    glColor3f(0.7,0.7,0.7);
    int x = 20;
    int y = HEIGHT-20;
    int menuW = 280;
    int menuH = 110;
    glVertex2f(x, y);
    glVertex2f(x + menuW, y);
    glVertex2f(x + menuW, y - menuH);
    glVertex2f(x, y - menuH);

   //Draw options
    for (int i = 0; i < 10; i++) {
        Color color1 = Color::BLUE;
        Color color2 = Color::BLUE;
        switch (i) {
            case 0:
                color2 = Color::GREEN;
                break;
            case 1:
                color2 = Color::RED;
                break;
            case 2:
                break;
            case 3:
                color2 = Color::YELLOW;
                break;
            case 4:
                color1 = Color::GREEN;
                color2 = Color::GREEN;
                break;
            case 5:
                color1 = Color::GREEN;
                color2 = Color::RED;
                break;
            case 6:
                color1 = Color::GREEN;
                color2 = Color::YELLOW;
                break;
            case 7:
                color1 = Color::RED;
                color2 = Color::RED;
                break;
            case 8:
                color1 = Color::RED;
                color2 = Color::YELLOW;
                break;
            case 9:
                color1 = Color::YELLOW;
                color2 = Color::YELLOW;
                break;
            default:
                break;
        }
        drawParticle(x+10,y-10-(i*10), color1);
        drawParticle(x+15,y-10-(i*10), color2);

        //Draw sliders
        int sliderLength = 250;
        glColor3f(0,0,0);
        glVertex2f(x+25, y-10-(i*10));
        glVertex2f(x+25+sliderLength, y-10-(i*10));
        glVertex2f(x+25+sliderLength, y-10-(i*10)+CELLSIZE);
        glVertex2f(x+25, y-10-(i*10)+CELLSIZE);

        drawParticle(x+25+(sliderLength/2),y-10-(i*10), Color::WHITE);

    }

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
        case Color::WHITE:
            glColor3f(1,1,1);
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
    const int PARTICLE_AMOUNT = 100;
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
