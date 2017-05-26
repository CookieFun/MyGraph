//
// Created by zig_zag on 2017/5/26.
//

#ifndef MYGRAPH_BASE_H
#define MYGRAPH_BASE_H

namespace mygraph {
    extern int window_width, window_height;

    class color {
    public:
        float r, g, b;

        color(float _r = 0, float _g = 0, float _b = 0);
    };

    class point {
    public:
        int x, y;

        point(int _x = 0, int _y = 0);

    };

    extern color default_color;

    void draw_point(int x, int y, color c = default_color);
}


#endif //MYGRAPH_BASE_H
