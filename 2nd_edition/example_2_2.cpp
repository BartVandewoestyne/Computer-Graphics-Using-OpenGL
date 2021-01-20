#include <GL/freeglut.h>



void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);  // set white background color
    glColor3f(0.0f, 0.0f, 0.0f);  // set the drawing color
    glPointSize(4.0);  // a 'dot' is 4 by 4 pixels
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);  // clear the screen
    glBegin(GL_POINTS);
    glVertex2i(100, 50);  // draw three points
    glVertex2i(100, 130);
    glVertex2i(150, 130);
    glEnd();
    glFlush();  // send all output to display
}

void main(int argc, char** argv)
{
    glutInit(&argc, argv);  // initialize the toolkit
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // set the display mode
    glutInitWindowSize(640, 480);  // set window size
    glutInitWindowPosition(100, 150);  // set the window position on screen
    glutCreateWindow("my first attempt");  // open the screen window

    // register the callback functions
    glutDisplayFunc(myDisplay);

    myInit();        // additional initializations as necessary
    glutMainLoop();  // go into a perpetual loop
}
