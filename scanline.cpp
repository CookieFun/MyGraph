//
// Created by zig_zag on 2017/5/26.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include "base.h"

using namespace std;


namespace mygraph {
    class edge {
    public:
        float x, dx;
        int my;

        edge(float _x = 0, float _dx = 0, int _my = 0) {
            x = _x;
            dx = _dx;
            my = _my;
        };

        friend bool operator<(edge a, edge b) {
            return a.x < b.x;
        }
    };

    void fill(int lx, int rx, int y) {
        for (int i = lx; i <= rx; i++) {
            draw_point(i, y);
        }
    }

    void scanfill(vector<point> p) {
        int W = mygraph::window_width, H = mygraph::window_height;
        int n = p.size();
        if (n <= 2) return;
        vector<edge> *NET = new vector<edge>[H + 2];
        vector<edge> *AET = new vector<edge>[H + 2];
//        初始化活化边表
        for (int i = 0; i < n; i++) {
            point z = p[(i - 1 + n) % n];
            point a = p[i];
            point b = p[(i + 1) % n];
            point c = p[(i + 2) % n];
            if (a.y < b.y && b.y < c.y) {
                b.y -= 1;
            }
            if (z.y > a.y && a.y > b.y) {
                a.y -= 1;
            }
            float m = (float) (b.x - a.x) / (b.y - a.y);
            if (a.y > b.y) {
                swap(a, b);
            }
            NET[a.y].push_back(edge(a.x, m, b.y));
        }
        for (int i = 0; i <= H; i++) {
            for (int j = 0; j < NET[i].size(); j++) {
                AET[i].push_back(NET[i][j]);
            }
            int lf = W + 1, rt;
            sort(AET[i].begin(), AET[i].end());
            for (int j = 0; j < AET[i].size(); j++) {
                edge now = AET[i][j];
                if (lf > W) {
                    lf = (int) now.x;
                } else {
                    rt = (int) now.x;
                    fill(lf, rt, i);
                    lf = W + 1;
                }
                if (i + 1 <= AET[i][j].my) {
                    AET[i + 1].push_back(edge(now.x + now.dx, now.dx, now.my));
                }
            }
        }
        delete[] NET;
        delete[] AET;
    }

}

