#include <GL/freeglut.h>

void drawDot(GLint x, GLint y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

class GLintPoint {
public:
    GLint x, y;
};

int random(int m)
{
    return rand() % m;
}

void Sierpinski(void)
{
    GLintPoint T[3] = { {10, 10}, {300, 30}, {200, 300} };

    int index = random(3);  // 0, 1, or 2 equally likely
    GLintPoint point = T[index];  // initial point
    drawDot(point.x, point.y);  // draw initial point
    for (int i = 0; i < 1000; i++)  // draw 1000 points
    {
        index = random(3);
        point.x = (point.x + T[index].x) / 2;
        point.y = (point.y + T[index].y) / 2;
        drawDot(point.x, point.y);
    }
    glFlush();
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

    // register the callback functions
    glutDisplayFunc(Sierpinski);

    myInit();        // additional initializations as necessary
    glutMainLoop();  // go into a perpetual loop
}
