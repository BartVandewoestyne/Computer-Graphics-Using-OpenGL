#ifndef GRAPHICS2D
#define GRAPHICS2D

class Point2
{
public:
    Point2() { x = y = 0.0f; }
    Point2(float xx, float yy) { x = xx; y = yy; }
    void set(float xx, float yy) { x = xx; y = yy; }
    float getX() { return x; }
    float getY() { return y; }
    void draw(void) {
        glBegin(GL_POINTS);
        glVertex2f((GLFloat)x, (GLFloat)y);
        glEnd();
    }

private:
    float x, y;
};

class IntRect
{
public:
    IntRect() { l = 0; r = 100; b = 0; t = 100; }
    IntRect(int left, int right, int bottom, int top)
    {
        l = left; r = right; b = bottom; t = top;
    }
    void set(int left, int right, int bottom, int top)
    {
        l = left; r = right; b = bottom; t = top;
    }
    void draw(void);

private:
    int l, r, b, t;
};

class RealRect
{
public:
    RealRect() { l = 0; r = 100; b = 0; t = 100; }
    RealRect(float left, float right, float bottom, float top)
    {
        l = left; r = right; b = bottom; t = top;
    }
    void set(float left, float right, float bottom, float top)
    {
        l = left; r = right; b = bottom; t = top;
    }
    void draw(void);

private:
    float l, r, b, t;
};

#endif  // GRAPHICS2D