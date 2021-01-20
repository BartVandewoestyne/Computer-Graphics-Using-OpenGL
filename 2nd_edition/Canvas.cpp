#include "Canvas.h"

Canvas::Canvas(int width, int height, char* windowTitle)
{
    char* argv[1];  // dummy argument list for glutInit()
    char dummyString[8];
    argv[0] = dummyString;  // hook up the pointer
    int argc = 1;  // to satisfy glutInit()

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(20, 20);
    glutCreateWindow(windowTitle);  // open the screen window
    setWindow(0, (float)width, 0, (float)height);  // default world window
    setViewport(0, width, 0, height);  // default viewport
    CP.set(0.0f, 0.0f);  // initialize the CP to (0, 0)
}

void Canvas::moveTo(float x, float y)
{
    CP.set(x, y);
}

void Canvas::lineTo(float x, float y)
{
    glBegin(GL_LINES);
    glVertex2f((GLfloat)CP.x, (GLfloat)CP.y);
    glVertex2f((GLfloat)x, (GLfloat)y);  // draw the line
    glEnd();
    CP.set(x, y);  // update the CP
    glFlush();
}

void Canvas::setWindow(float l, float r, float b, float t)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D((GLdouble)l, (GLdouble)r, (GLdouble)b, (GLdouble)t);
    window.set(l, r, b, t);
}

void Canvas::moveRel(float dx, float dy)
{
    CP.set(CP.x + dx, CP.y + dy);
}

void Canvas::lineRel(float dx, float dy)
{
    float x = CP.x + dx;
    float y = CP.y + dy;
    lineTo(x, y);
    CP.set(x, y);
}

void Canvas::turnTo(float angle) { CD = angle; }

void Canvas::turnTo(float angle) { CD += angle; }

void Canvas::forward(float dist, int isVisible)
{
    const float RadPerDeg = 0.017453393;  // radians per degree
    float x = CP.x + dist * cos(RadPerDeg * CD);
    float y = CP.y + dist * sin(RadPerDeg * CD);
    if (isVisible)
        lineTo(x, y);
    else
        moveTo(x, y);
}

// TODO:
//  other functions (see exercise 3.4.2 page 104)