//
// Created by zig_zag on 2017/5/26.
//
#include <iostream>
#include "base.h"
#include <GL/glut.h>

namespace mygraph {
    int window_width, window_height;

    color::color(float _r, float _g, float _b) {
        r = _r;
        g = _g;
        b = _b;
    }

    point::point(int _x, int _y) {
        x = _x;
        y = _y;
    }

    color default_color;

    void draw_point(int x, int y, color c) {
//        printf("draw at (%d, %d) with (%.1f, %.1f, %.1f)", x, y, c.r, c.g, c.b);
        glColor3f(c.r, c.g, c.b);
        glPointSize(2.0);
        glBegin(GL_POINTS);
        y = window_height / 2 - y;
        x = x - window_width / 2;
//        printf("(%d %d)\n", x, y);
        glVertex2i(x, y);
//        int k=0;
//        for (int i=1;i<=10;i++)
//        k+=1;
        glEnd();
        glFlush();
    }
}
