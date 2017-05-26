//
// Created by zig_zag on 2017/5/26.
//

#include "base.h"

namespace mygraph {
    void bresenham(point p, point q) {
        int x1, y1, x2, y2;
        if (p.x < q.x) {
            x1 = p.x, y1 = p.y;
            x2 = q.x, y2 = q.y;
        } else {
            x1 = q.x, y1 = q.y;
            x2 = p.x, y2 = p.y;
        }
        float dx = x2 - x1;
        float dy = y2 - y1;
        float k = dy / dx;
        float m, e;
        int i;
        float x = x1, y = y1;
        if (k >= 0 && k < 1) {
            //斜率为0到1
            m = dy / dx;
            e = m - 0.5;
//        e=(2dy-dx)/2dx
            for (i = 0; i < dx; i++) {
                draw_point(x, y);
                if (e >= 0) {
                    y += 1;
                    e -= 1;
                }
                x += 1;
                e += m;
            }
        } else if (k >= 1) {
            //x换为y,y换为x
            m = dx / dy;
            e = m - 0.5;
            for (i = 0; i < dy; i++) {
                draw_point(x, y);
                if (e >= 0) {
                    x += 1;
                    e -= 1;
                }
                y += 1;
                e += m;
            }
        } else if (k < 0 && k >= -1) {
            //x不变，y换为-y
            m = -dy / dx;
            e = m + 0.5;
            for (i = 0; i < dx; i++) {
                draw_point(x, y);
                if (e <= 0) {
                    y -= 1;
                    e += 1;
                }
                x += 1;
                e -= m;
            }
        } else {
            //将x换为-y,y换为x
            m = -dx / dy;
            e = m + 0.5;
            for (i = 0; i < -dy; i++) {
                draw_point(x, y);
                if (e <= 0) {
                    x += 1;
                    e += 1;
                }
                y -= 1;
                e -= m;
            }
        }
    }
}