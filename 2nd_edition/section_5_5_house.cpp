#include "Canvas.h"

#include <GL/freeglut.h>

#include <fstream>
#include <iostream>

Canvas cvs(640, 480, "House");

void drawDot(GLint x, GLint y)
{
    std::cout << "x = " << x << ", y = " << y << std::endl;

    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();  // apparently, we must flush here...
}

void house()
{
    // TODO
    cvs.moveTo(50, 50);
    cvs.lineRel(10, 0);
    cvs.lineRel(0, 20);
    cvs.lineRel(-10, 0);
    cvs.lineRel(0, -20);
}

void myDisplay()
{
    cvs.setWindow(0, 200, 0, 100);
    cvs.setViewport(10, 190, 10, 90);
    cvs.initCT();

    // TODO: this does not work as expected yet!
    house();
    cvs.translate2D(32, 25);
    cvs.rotate2D(-30.0);
    house();
}

void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);  // set white background color
    glColor3f(0.0f, 0.0f, 0.0f);  // set the drawing color
    glPointSize(4.0);  // a 'dot' is 4 by 4 pixels
}

void main(int argc, char** argv)
{
    glutDisplayFunc(myDisplay);

    myInit();        // additional initializations as necessary
    glutMainLoop();  // go into a perpetual loop
}
