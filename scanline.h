//
// Created by zig_zag on 2017/5/26.
//

#ifndef MYGRAPH_SCANLINE_H
#define MYGRAPH_SCANLINE_H

#include <vector>
#include "base.h"
using namespace std;

namespace mygraph {
    class edge {
    public:
        float x, dx;
        int my;

        edge(float _x = 0, float _dx = 0, int _my = 0);

        friend bool operator<(edge a, edge b);
    };

    void fill(int lx, int rx, int y);

    void scanfill(vector <point> p);
}


#endif //MYGRAPH_SCANLINE_H
