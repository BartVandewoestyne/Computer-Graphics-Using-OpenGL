#include "graphics2d.h"

class Canvas {
public:
    Canvas(int width, int height, char* windowTitle);
    void setWindow(float l, float r, float b, float t);
    void setViewport(int l, int r, int b, int t);
    IntRect getViewport();
    RealRect getWindow();
    float getWindowAspectRatio();
    void clearScreen();
    void setBackgroundColor(float r, float g, float b);
    void setColor(float r, float g, float b);
    void lineTo(float x, float y);
    void lineTo(Point2 p);
    void moveTo(float x, float y);
    void moveTo(Point2 p);
    void moveRel(float dx, float dy);
    void lineRel(float dx, float dy);

    // Turtle movement.
    void turnTo(float angle);
    void turn(float angle);
    void forward(float dist, int isVisible);

    void initCT();
    void scale2D(double sx, double sy);
    void translate2D(double dx, double dy);
    void rotate2D(double angle);

    void pushCT();
    void popCT();

private:
    Point2 CP;  // current position in the world
    float CD;  // current direction
    IntRect viewport;
    RealRect window;
    // others later
};