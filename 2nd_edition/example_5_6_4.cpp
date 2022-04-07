#include <GL/freeglut.h>

#include "SDL.h"

Scene scn;  // construct the scene object

void displaySDL()
{
    glMatrixMode(GL_PROJECTION);  // set the camera
    glLoadIdentity();
    double winHt = 1.0;  // half-height of the window
    glOrtho(-winHt * 64 / 48.0, winHt * 64 / 48.0, -winHt, winHt, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(2.3, 1.3, 2, 0, 0.25, 0, 0.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // clear screen
    scn.drawSceneOpenGL();
}

void main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("read and draw an SDL scene");
    glutDisplayFunc(displaySDL);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glViewport(0, 0, 640, 480);
    scn.read("myScene1.dat");  // read the SDL file and build the objects
    glEnable(GL_LIGHTING);
    scn.makeLightsOpenGL();  // scan the lights list and make OpenGL lights
    glutMainLoop();
}