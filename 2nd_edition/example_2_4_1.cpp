// TODO: this is not completely working yet!
// The dot does not appear without the glFlush call in drawDot.
// And even then, it does not stay on screen.

#include <GL/freeglut.h>
#include <fstream>
#include <iostream>

const int screenWidth = 640;  // width of screen window in pixels
const int screenHeight = 480;  // height of screen window in pixels

void drawDot(GLint x, GLint y)
{
    std::cout << "x = " << x << ", y = " << y << std::endl;

    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();  // apparently, we must flush here...
}

void myMouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        drawDot(x, screenHeight - y);
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        exit(-1);
    }
}

void myDisplay()
{
    // Do not clear, so dots stay on screen.
    //glClear(GL_COLOR_BUFFER_BIT);
}

void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);  // set white background color
    glColor3f(0.0f, 0.0f, 0.0f);  // set the drawing color
    glPointSize(4.0);  // a 'dot' is 4 by 4 pixels
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void main(int argc, char** argv)
{
    glutInit(&argc, argv);  // initialize the toolkit
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // set the display mode
    glutInitWindowSize(640, 480);  // set window size
    glutInitWindowPosition(100, 150);  // set the window position on screen
    glutCreateWindow("my first attempt");  // open the screen window

    glutDisplayFunc(myDisplay);
    glutMouseFunc(myMouse);

    myInit();        // additional initializations as necessary
    glutMainLoop();  // go into a perpetual loop
}
