#include <iostream>
#include <GL/glut.h>
#include <vector>
#include "base.h"
#include "drawline.h"
#include "scanline.h"

using namespace std;
using namespace mygraph;

vector<point> pts;
void init();
void display();
void mouseclick(int button, int state, int x, int y);
void presskey(int key, int x, int y);


int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    mygraph::window_height = 400;
    mygraph::window_width = 400;
    mygraph::default_color=color(1.0, 1.0, 0.0);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(mygraph::window_width, mygraph::window_height);
    glutCreateWindow("cookifan");
//    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    init();
    glutDisplayFunc(&display);
    glutMouseFunc(mouseclick);
    glutSpecialFunc(presskey);
    glutMainLoop();
    return 0;
}

void init()
{
    /* set clear color to black */
    glClearColor(1.0, 1.0, 1.0, 1.0);
    // 设置投影
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // 左下角坐标(-300,-200)，右上角坐标(300,200)
    gluOrtho2D(-mygraph::window_width / 2, mygraph::window_width / 2, -mygraph::window_height / 2, mygraph::window_height / 2);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 0.0f);
    int n=pts.size();
    for (int i=0;i<n;i++)
        bresenham(pts[i], pts[(i+1)%n]);
    glFlush();
}

void mouseclick(int button, int state, int x, int y){
    if (button==GLUT_LEFT_BUTTON){
        if (state == GLUT_DOWN) {
            printf("%d %d\n", x, y);
            pts.push_back(point(x, y));
        }
    }
}

void presskey(int key, int x, int y){
    if (key==1){
        scanfill(pts);
        glFlush();
    }
}
