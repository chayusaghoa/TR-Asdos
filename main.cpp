#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include<windows.h>
#include<gl/glut.h>

void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void mouse(int, int, int, int);
void mouseMotion(int, int);
void ukuran(int, int);

int is_depth;

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;

float xmov = 0.0f;
float ymov = 0.0f;
float zmov = 0.0f;


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(250, 80);
    glutCreateWindow("INSTITUT TEKNOLOGI SURABAYA");
    init();
    glutDisplayFunc(tampil);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);

    glutReshapeFunc(ukuran);
    glutMainLoop();
    return 0;
}
void init(void)
{
    glClearColor(0.0, 1.0, 1.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

void tampil(void)
{
    if (is_depth) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
    else {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);

    glTranslatef(xmov, ymov, zmov);
    glPushMatrix();
     //alas
    glBegin(GL_QUADS);
    glColor3ub(33,89,11);
    glVertex3f(480.0, -20.0, 220.0); //kanan
    glVertex3f(-400.0, -20.0,220.0);//kiri
    glVertex3f(-400.0, -20.0, -480.0);//kiri
    glVertex3f(480.0, -20.0, -480.0);//kanan
    glEnd();
    //bagunan panjang tengah
     //lantai1 bagunan panjang tengah
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(140.0, -20.0, 20.0); //kanan
    glVertex3f(-70.0, -20.0, 20.0);//kiri
    glVertex3f(-70.0, -20.0, -80.0);//kiri
    glVertex3f(140.0, -20.0, -80.0);//kanan
    glEnd();
     //lantai2 bagunan panjang tengah
        glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(140.0, 17.0, 20.0); //kanan
    glVertex3f(-70.0, 17.0, 20.0);//kiri
    glVertex3f(-70.0, 17.0, -80.0);//kiri
    glVertex3f(140.0, 17.0, -80.0);//kanan
    glEnd();
         //lantai3 bagunan panjang tengah
        glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(140.0, 57.0, 20.0); //kanan
    glVertex3f(-70.0, 57.0, 20.0);//kiri
    glVertex3f(-70.0, 57.0, -80.0);//kiri
    glVertex3f(140.0, 57.0, -80.0);//kanan
    glEnd();
     //dinding Kanan bagunan panjang tengah
    glBegin(GL_QUADS);
    glColor3ub(171, 149, 99);
    glVertex3f(-70.0, -20.0, 20.0); //kanan
    glVertex3f(-70.0, 100.0, 20.0);//kiri
    glVertex3f(-70.0, 100.0, -80.0);//kiri
    glVertex3f(-70.0, -20.0, -80.0);//kanan
    glEnd();
    //dinding dalam 1 bagunan panjang tengah
    glBegin(GL_QUADS);
    glColor3ub(171, 149, 99);
    glVertex3f(140.0, -20.0, 20.0); //kanan
    glVertex3f(140.0, 100.0, 20.0);//kiri
    glVertex3f(140.0, 100.0, -80.0);//kiri
    glVertex3f(140.0, -20.0, -80.0);//kanan
    glEnd();
        //dinding dalam 2 bagunan panjang tengah
    glBegin(GL_QUADS);
    glColor3ub(171, 149, 99);
    glVertex3f(113.0, -20.0, 20.0); //kanan
    glVertex3f(113.0, 100.0, 20.0);//kiri
    glVertex3f(113.0, 100.0, -80.0);//kiri
    glVertex3f(113.0, -20.0, -80.0);//kanan
    glEnd();
            //dinding dalam 3 bagunan panjang tengah
    glBegin(GL_QUADS);
    glColor3ub(171, 149, 99);
    glVertex3f(43.0, -20.0, 20.0); //kanan
    glVertex3f(43.0, 100.0, 20.0);//kiri
    glVertex3f(43.0, 100.0, -80.0);//kiri
    glVertex3f(43.0, -20.0, -80.0);//kanan
    glEnd();
                //dinding dalam 4 bagunan panjang tengah
    glBegin(GL_QUADS);
    glColor3ub(171, 149, 99);
    glVertex3f(-24.0, -20.0, 20.0); //kanan
    glVertex3f(-24.0, 100.0, 20.0);//kiri
    glVertex3f(-24.0, 100.0, -80.0);//kiri
    glVertex3f(-24.0, -20.0, -80.0);//kanan
    glEnd();
    //dinding depan bagunan panjang tengah
    glBegin(GL_QUADS);
    glColor3ub(171,149,99);
    glVertex3f(-70.0, -20.0, 20.0); //kanan
    glVertex3f(-70.0, 100.0, 20.0);//kiri
    glVertex3f(140.0, 100.0, 20.0);//kiri
    glVertex3f(140.0, -20.0, 20.0);//kanan
    glEnd();
    //dinding depan kecil 1 bagunan panjang tengah
        glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(-73.0, 12.0, 20.3); //kanan
    glVertex3f(-73.0, 23.0, 20.3);//kiri
    glVertex3f(143.0, 23.0, 20.3);//kiri
    glVertex3f(143.0, 12.0, 20.3);//kanan
    glEnd();
    glBegin(GL_QUADS);//jendela1 dinding depan kecil 1 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(-68.0, -10.0, 20.2); //kanan
    glVertex3f(-68.0, 05.0, 20.2);//kiri
    glVertex3f(-50.0, 05.0, 20.2);//kiri
    glVertex3f(-50.0, -10.0, 20.2);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela2 dinding depan kecil 1 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(-45.0, -10.0, 20.2); //kanan
    glVertex3f(-45.0, 05.0, 20.2);//kiri
    glVertex3f(-27.0, 05.0, 20.2);//kiri
    glVertex3f(-27.0, -10.0, 20.2);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela3 dinding depan kecil 1 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(-22.0, -10.0, 20.2); //kanan
    glVertex3f(-22.0, 05.0, 20.2);//kiri
    glVertex3f(-4.0, 05.0, 20.2);//kiri
    glVertex3f(-4.0, -10.0, 20.2);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela4 dinding depan kecil 1 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(1.0, -10.0, 20.2); //kanan
    glVertex3f(1.0, 05.0, 20.2);//kiri
    glVertex3f(19.0, 05.0, 20.2);//kiri
    glVertex3f(19.0, -10.0, 20.2);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela5 dinding depan kecil 1 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(24.0, -10.0, 20.2); //kanan
    glVertex3f(24.0, 05.0, 20.2);//kiri
    glVertex3f(42.0, 05.0, 20.2);//kiri
    glVertex3f(42.0, -10.0, 20.2);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela6 dinding depan kecil 1 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(47.0, -10.0, 20.2); //kanan
    glVertex3f(47.0, 05.0, 20.2);//kiri
    glVertex3f(65.0, 05.0, 20.2);//kiri
    glVertex3f(65.0, -10.0, 20.2);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela7 dinding depan kecil 1 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(70.0, -10.0, 20.2); //kanan
    glVertex3f(70.0, 05.0, 20.2);//kiri
    glVertex3f(88.0, 05.0, 20.2);//kiri
    glVertex3f(88.0, -10.0, 20.2);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela8 dinding depan kecil 1 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(93.0, -10.0, 20.2); //kanan
    glVertex3f(93.0, 05.0, 20.2);//kiri
    glVertex3f(111.0, 05.0, 20.2);//kiri
    glVertex3f(111.0, -10.0, 20.2);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela9 dinding depan kecil 1 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(116.0, -10.0, 20.2); //kanan
    glVertex3f(116.0, 05.0, 20.2);//kiri
    glVertex3f(134.0, 05.0, 20.2);//kiri
    glVertex3f(134.0, -10.0, 20.2);//kanan
    glEnd();
        //dinding depan kecil 2
        glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(-73.0, 52.0, 20.3); //kanan
    glVertex3f(-73.0, 63.0, 20.3);//kiri
    glVertex3f(143.0, 63.0, 20.3);//kiri
    glVertex3f(143.0, 52.0, 20.3);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela1 dinding depan kecil 2 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(-68.0, 30.0, 20.2); //kanan
    glVertex3f(-68.0, 45.0, 20.2);//kiri
    glVertex3f(-50.0, 45.0, 20.2);//kiri
    glVertex3f(-50.0, 30.0, 20.2);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela2 dinding depan kecil 2 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(-45.0, 30.0, 20.2); //kanan
    glVertex3f(-45.0, 45.0, 20.2);//kiri
    glVertex3f(-27.0, 45.0, 20.2);//kiri
    glVertex3f(-27.0, 30.0, 20.2);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela3 dinding depan kecil 2 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(-22.0, 30.0, 20.2); //kanan
    glVertex3f(-22.0, 45.0, 20.2);//kiri
    glVertex3f(-4.0, 45.0, 20.2);//kiri
    glVertex3f(-4.0, 30.0, 20.2);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela4 dinding depan kecil 2 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(1.0, 30.0, 20.2); //kanan
    glVertex3f(1.0, 45.0, 20.2);//kiri
    glVertex3f(19.0,45.0, 20.2);//kiri
    glVertex3f(19.0, 30.0, 20.2);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela5 dinding depan kecil 2 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(24.0, 30.0, 20.2); //kanan
    glVertex3f(24.0, 45.0, 20.2);//kiri
    glVertex3f(42.0, 45.0, 20.2);//kiri
    glVertex3f(42.0, 30.0, 20.2);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela6 dinding depan kecil 2 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(47.0, 30.0, 20.2); //kanan
    glVertex3f(47.0, 45.0, 20.2);//kiri
    glVertex3f(65.0, 45.0, 20.2);//kiri
    glVertex3f(65.0, 30.0, 20.2);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela7 dinding depan kecil 2 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(70.0, 30.0, 20.2); //kanan
    glVertex3f(70.0, 45.0, 20.2);//kiri
    glVertex3f(88.0, 45.0, 20.2);//kiri
    glVertex3f(88.0, 30.0, 20.2);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela8 dinding depan kecil 2 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(93.0, 30.0, 20.2); //kanan
    glVertex3f(93.0, 45.0, 20.2);//kiri
    glVertex3f(111.0,45.0, 20.2);//kiri
    glVertex3f(111.0,30.0, 20.2);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela9 dinding depan kecil 2 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(116.0, 30.0, 20.2); //kanan
    glVertex3f(116.0, 45.0, 20.2);//kiri
    glVertex3f(134.0, 45.0, 20.2);//kiri
    glVertex3f(134.0, 30.0, 20.2);//kanan
    glEnd();
        //dinding depan kecil 3
        glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(-73.0, 89.0, 20.3); //kanan
    glVertex3f(-73.0, 102.0, 20.3);//kiri
    glVertex3f(143.0, 102.0, 20.3);//kiri
    glVertex3f(143.0, 89.0, 20.3);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela1 dinding depan kecil 3 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(-68.0, 68.0, 20.2); //kanan
    glVertex3f(-68.0, 83.0, 20.2);//kiri
    glVertex3f(-50.0, 83.0, 20.2);//kiri
    glVertex3f(-50.0, 68.0, 20.2);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela2 dinding depan kecil 3 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(-45.0, 68.0, 20.2); //kanan
    glVertex3f(-45.0, 83.0, 20.2);//kiri
    glVertex3f(-27.0, 83.0, 20.2);//kiri
    glVertex3f(-27.0, 68.0, 20.2);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela3 dinding depan kecil 3 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(-22.0, 68.0, 20.2); //kanan
    glVertex3f(-22.0, 83.0, 20.2);//kiri
    glVertex3f(-4.0, 83.0, 20.2);//kiri
    glVertex3f(-4.0, 68.0, 20.2);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela4 dinding depan kecil 3 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(1.0, 68.0, 20.2); //kanan
    glVertex3f(1.0, 83.0, 20.2);//kiri
    glVertex3f(19.0,83.0, 20.2);//kiri
    glVertex3f(19.0, 68.0, 20.2);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela5 dinding depan kecil 3 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(24.0, 68.0, 20.2); //kanan
    glVertex3f(24.0, 83.0, 20.2);//kiri
    glVertex3f(42.0, 83.0, 20.2);//kiri
    glVertex3f(42.0, 68.0, 20.2);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela6 dinding depan kecil 3 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(47.0, 68.0, 20.2); //kanan
    glVertex3f(47.0, 83.0, 20.2);//kiri
    glVertex3f(65.0, 83.0, 20.2);//kiri
    glVertex3f(65.0, 68.0, 20.2);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela7 dinding depan kecil 3 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(70.0, 68.0, 20.2); //kanan
    glVertex3f(70.0, 83.0, 20.2);//kiri
    glVertex3f(88.0, 83.0, 20.2);//kiri
    glVertex3f(88.0, 68.0, 20.2);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela8 dinding depan kecil 3 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(93.0, 68.0, 20.2); //kanan
    glVertex3f(93.0, 83.0, 20.2);//kiri
    glVertex3f(111.0,83.0, 20.2);//kiri
    glVertex3f(111.0,68.0, 20.2);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela9 dinding depan kecil 3 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(116.0, 68.0, 20.2); //kanan
    glVertex3f(116.0, 83.0, 20.2);//kiri
    glVertex3f(134.0, 83.0, 20.2);//kiri
    glVertex3f(134.0, 68.0, 20.2);//kanan
    glEnd();
    //dinding belakang
    glBegin(GL_QUADS);
    glColor3ub(171,149,99);
    glVertex3f(-70.0, -20.0, -80.0); //kanan
    glVertex3f(-70.0, 100.0, -80.0);//kiri
    glVertex3f(140.0, 100.0, -80.0);//kiri
    glVertex3f(140.0, -20.0, -80.0);//kanan
    glEnd();
        //dinding belakang kecil 1
        glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(-73.0, 12.0, -80.3); //kanan
    glVertex3f(-73.0, 23.0, -80.3);//kiri
    glVertex3f(143.0, 23.0, -80.3);//kiri
    glVertex3f(143.0, 12.0, -80.3);//kanan
    glEnd();
      glBegin(GL_QUADS);//jendela1 dinding belakang kecil 1 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(-68.0, -10.0, -80.2); //kanan
    glVertex3f(-68.0, 05.0, -80.2);//kiri
    glVertex3f(-50.0, 05.0, -80.2);//kiri
    glVertex3f(-50.0, -10.0, -80.2);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela2 dinding belakang kecil 1 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(-45.0, -10.0, -80.2); //kanan
    glVertex3f(-45.0, 05.0, -80.2);//kiri
    glVertex3f(-27.0, 05.0, -80.2);//kiri
    glVertex3f(-27.0, -10.0, -80.2);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela3 dinding belakang kecil 1 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(-22.0, -10.0, -80.2); //kanan
    glVertex3f(-22.0, 05.0, -80.2);//kiri
    glVertex3f(-4.0, 05.0, -80.2);//kiri
    glVertex3f(-4.0, -10.0, -80.2);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela4 dinding belakang kecil 1 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(1.0, -10.0, -80.2); //kanan
    glVertex3f(1.0, 05.0, -80.2);//kiri
    glVertex3f(19.0, 05.0, -80.2);//kiri
    glVertex3f(19.0, -10.0, -80.2);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela5 dinding belakang kecil 1 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(24.0, -10.0, -80.2); //kanan
    glVertex3f(24.0, 05.0, -80.2);//kiri
    glVertex3f(42.0, 05.0, -80.2);//kiri
    glVertex3f(42.0, -10.0, -80.2);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela6 dinding belakang kecil 1 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(47.0, -10.0, -80.2); //kanan
    glVertex3f(47.0, 05.0, -80.2);//kiri
    glVertex3f(65.0, 05.0, -80.2);//kiri
    glVertex3f(65.0, -10.0, -80.2);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela7 dinding belakang kecil 1 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(70.0, -10.0, -80.2); //kanan
    glVertex3f(70.0, 05.0, -80.2);//kiri
    glVertex3f(88.0, 05.0, -80.2);//kiri
    glVertex3f(88.0, -10.0, -80.2);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela8 dinding belakang kecil 1 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(93.0, -10.0, -80.2); //kanan
    glVertex3f(93.0, 05.0, -80.2);//kiri
    glVertex3f(111.0, 05.0, -80.2);//kiri
    glVertex3f(111.0, -10.0, -80.2);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela9 dinding belakang kecil 1 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(116.0, -10.0, -80.2); //kanan
    glVertex3f(116.0, 05.0, -80.2);//kiri
    glVertex3f(134.0, 05.0, -80.2);//kiri
    glVertex3f(134.0, -10.0, -80.2);//kanan
    glEnd();
        //dinding belakang kecil 2 dinding belakang kecil 2 bagunan panjang tengah
        glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(-73.0, 52.0, -80.3); //kanan
    glVertex3f(-73.0, 63.0, -80.3);//kiri
    glVertex3f(143.0, 63.0, -80.3);//kiri
    glVertex3f(143.0, 52.0, -80.3);//kanan
    glEnd();
     glBegin(GL_QUADS);//jendela1 dinding belakang kecil 2 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(-68.0, 30.0, -80.2); //kanan
    glVertex3f(-68.0, 45.0, -80.2);//kiri
    glVertex3f(-50.0, 45.0, -80.2);//kiri
    glVertex3f(-50.0, 30.0, -80.2);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela2 dinding belakang kecil 2 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(-45.0, 30.0, -80.2); //kanan
    glVertex3f(-45.0, 45.0, -80.2);//kiri
    glVertex3f(-27.0, 45.0, -80.2);//kiri
    glVertex3f(-27.0, 30.0, -80.2);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela3 dinding belakang kecil 2 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(-22.0, 30.0, -80.2); //kanan
    glVertex3f(-22.0, 45.0, -80.2);//kiri
    glVertex3f(-4.0, 45.0, -80.2);//kiri
    glVertex3f(-4.0, 30.0, -80.2);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela4 dinding belakang kecil 2 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(1.0, 30.0, -80.2); //kanan
    glVertex3f(1.0, 45.0, -80.2);//kiri
    glVertex3f(19.0,45.0, -80.2);//kiri
    glVertex3f(19.0, 30.0, -80.2);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela5 dinding belakang kecil 2 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(24.0, 30.0, -80.2); //kanan
    glVertex3f(24.0, 45.0, -80.2);//kiri
    glVertex3f(42.0, 45.0, -80.2);//kiri
    glVertex3f(42.0, 30.0, -80.2);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela6 dinding belakang kecil 2 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(47.0, 30.0, -80.2); //kanan
    glVertex3f(47.0, 45.0, -80.2);//kiri
    glVertex3f(65.0, 45.0, -80.2);//kiri
    glVertex3f(65.0, 30.0, -80.2);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela7 dinding belakang kecil 2 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(70.0, 30.0, -80.2); //kanan
    glVertex3f(70.0, 45.0, -80.2);//kiri
    glVertex3f(88.0, 45.0, -80.2);//kiri
    glVertex3f(88.0, 30.0, -80.2);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela8 dinding belakang kecil 2 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(93.0, 30.0, -80.2); //kanan
    glVertex3f(93.0, 45.0, -80.2);//kiri
    glVertex3f(111.0,45.0, -80.2);//kiri
    glVertex3f(111.0,30.0, -80.2);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela9 dinding belakang kecil 2 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(116.0, 30.0, -80.2); //kanan
    glVertex3f(116.0, 45.0, -80.2);//kiri
    glVertex3f(134.0, 45.0, -80.2);//kiri
    glVertex3f(134.0, 30.0, -80.2);//kanan
    glEnd();
        //dinding belakang kecil 3
        glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(-73.0, 89.0, -80.3); //kanan
    glVertex3f(-73.0, 102.0, -80.3);//kiri
    glVertex3f(143.0, 102.0, -80.3);//kiri
    glVertex3f(143.0, 89.0, -80.3);//kanan
    glEnd();
    glBegin(GL_QUADS);//jendela1 dinding belakang kecil 3 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(-68.0, 68.0, -80.2); //kanan
    glVertex3f(-68.0, 83.0, -80.2);//kiri
    glVertex3f(-50.0, 83.0, -80.2);//kiri
    glVertex3f(-50.0, 68.0, -80.2);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela2 dinding belakang kecil 3 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(-45.0, 68.0, -80.2); //kanan
    glVertex3f(-45.0, 83.0, -80.2);//kiri
    glVertex3f(-27.0, 83.0, -80.2);//kiri
    glVertex3f(-27.0, 68.0, -80.2);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela3 dinding belakang kecil 3 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(-22.0, 68.0, -80.2); //kanan
    glVertex3f(-22.0, 83.0, -80.2);//kiri
    glVertex3f(-4.0, 83.0, -80.2);//kiri
    glVertex3f(-4.0, 68.0, -80.2);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela4 dinding belakang kecil 3 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(1.0, 68.0, -80.2); //kanan
    glVertex3f(1.0, 83.0, -80.2);//kiri
    glVertex3f(19.0,83.0, -80.2);//kiri
    glVertex3f(19.0, 68.0, -80.2);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela5 dinding belakang kecil 3 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(24.0, 68.0, -80.2); //kanan
    glVertex3f(24.0, 83.0, -80.2);//kiri
    glVertex3f(42.0, 83.0, -80.2);//kiri
    glVertex3f(42.0, 68.0, -80.2);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela6 dinding belakang kecil 3 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(47.0, 68.0, -80.2); //kanan
    glVertex3f(47.0, 83.0, -80.2);//kiri
    glVertex3f(65.0, 83.0, -80.2);//kiri
    glVertex3f(65.0, 68.0, -80.2);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela7 dinding belakang kecil 3 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(70.0, 68.0, -80.2); //kanan
    glVertex3f(70.0, 83.0, -80.2);//kiri
    glVertex3f(88.0, 83.0, -80.2);//kiri
    glVertex3f(88.0, 68.0, -80.2);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela8
    glColor3ub(128,236,255);
    glVertex3f(93.0, 68.0, -80.2); //kanan
    glVertex3f(93.0, 83.0, -80.2);//kiri
    glVertex3f(111.0,83.0, -80.2);//kiri
    glVertex3f(111.0,68.0, -80.2);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela9 dinding belakang kecil 3 bagunan panjang tengah
    glColor3ub(128,236,255);
    glVertex3f(116.0, 68.0, -80.2); //kanan
    glVertex3f(116.0, 83.0, -80.2);//kiri
    glVertex3f(134.0, 83.0, -80.2);//kiri
    glVertex3f(134.0, 68.0, -80.2);//kanan
    glEnd();
    //genteng depan
    glBegin(GL_QUADS);
    glColor3ub(133,0,0);
    glVertex3f(-73.0, 120.0, -25.0); //kanan
    glVertex3f(143.0, 120.0, -25.0);//kiri
    glVertex3f(143.0, 100.0, 23.0);//kiri
    glVertex3f(-73.0, 100.0, 23.0);//kanan
    glEnd();
    //genteng belakang
    glBegin(GL_QUADS);
    glColor3ub(133,0,0);
    glVertex3f(-73.0, 120.0, -25.0); //kanan
    glVertex3f(143.0, 120.0, -25.0);//kiri
    glVertex3f(143.0, 100.0, -83.0);//kiri
    glVertex3f(-73.0, 100.0, -83.0);//kanan
    glEnd();


    //bagunan panjang kiri
        //lantai1 bagunan panjang kiri
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(-120.0, -20.0, -120.0); //kanan
    glVertex3f(-200.0, -20.0, -120.0);//kiri
    glVertex3f(-200.0, -20.0, -340.0);//kiri
    glVertex3f(-120.0, -20.0, -340.0);//kanan
    glEnd();
    //lantai1 bagunan panjang kiri
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(-120.0, -20.0, -120.0); //kanan
    glVertex3f(-200.0, -20.0, -120.0);//kiri
    glVertex3f(-200.0, -20.0, -340.0);//kiri
    glVertex3f(-120.0, -20.0, -340.0);//kanan
    glEnd();
     //lantai2 bagunan panjang tengah
        glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(-120.0, 17.0, -120.0); //kanan
    glVertex3f(-200.0, 17.0, -120.0);//kiri
    glVertex3f(-200.0, 17.0, -340.0);//kiri
    glVertex3f(-120.0, 17.0, -340.0);//kanan
    glEnd();
         //lantai3 bagunan panjang tengah
        glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(-120.0, 57.0, -120.0); //kanan
    glVertex3f(-200.0, 57.0, -120.0);//kiri
    glVertex3f(-200.0, 57.0, -340.0);//kiri
    glVertex3f(-120.0, 57.0, -340.0);//kanan
    glEnd();
            //dinding kiri bagunan panjang kiri
    glBegin(GL_QUADS);
    glColor3ub(171, 149, 99);
    glVertex3f(-120.0, -20.0, -120.0); //kanan
    glVertex3f(-120.0, 100.0, -120.0);//kiri
    glVertex3f(-120.0, 100.0, -340.0);//kiri
    glVertex3f(-120.0, -20.0, -340.0);//kanan
    glEnd();
        //dinding kiri kecil 1 bagunan panjang kiri
        glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(-119.7, 12.0, -117.0); //kanan
    glVertex3f(-119.7, 23.0, -117.0);//kiri
    glVertex3f(-119.7, 23.0, -343.0);//kiri
    glVertex3f(-119.7, 12.0, -343.0);//kanan
    glEnd();
      glBegin(GL_QUADS);//jendela1 dinding kiri kecil 1 bagunan panjang kiri
    glColor3ub(128,236,255);
    glVertex3f(-119.8, -10.0, -142.0); //kanan
    glVertex3f(-119.8, 05.0, -142.0);//kiri
    glVertex3f(-119.8, 05.0, -124.0);//kiri
    glVertex3f(-119.8, -10.0, -124.0);//kanan
    glEnd();
    glBegin(GL_QUADS);//jendela2 dinding kiri kecil 1 bagunan panjang kiri
    glColor3ub(128,236,255);
    glVertex3f(-119.8, -10.0, -147.0); //kanan
    glVertex3f(-119.8, 05.0, -147.0);//kiri
    glVertex3f(-119.8, 05.0, -165.0);//kiri
    glVertex3f(-119.8, -10.0, -165.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela3 dinding kiri kecil 1 bagunan panjang kiri
    glColor3ub(128,236,255);
    glVertex3f(-119.8, -10.0, -170.0); //kanan
    glVertex3f(-119.8, 05.0, -170.0);//kiri
    glVertex3f(-119.8, 05.0, -188.0);//kiri
    glVertex3f(-119.8, -10.0, -188.0);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela4 dinding kiri kecil 1 bagunan panjang kiri
    glColor3ub(128,236,255);
    glVertex3f(-119.8, -10.0, -193.0); //kanan
    glVertex3f(-119.8, 05.0, -193.0);//kiri
    glVertex3f(-119.8, 05.0, -211.0);//kiri
    glVertex3f(-119.8, -10.0, -211.0);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela5 dinding kiri kecil 1 bagunan panjang kiri
    glColor3ub(128,236,255);
    glVertex3f(-119.8, -10.0, -216.0); //kanan
    glVertex3f(-119.8, 05.0, -216.0);//kiri
    glVertex3f(-119.8, 05.0, -234.0);//kiri
    glVertex3f(-119.8, -10.0, -234.0);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela6 dinding kiri kecil 1 bagunan panjang kiri
    glColor3ub(128,236,255);
    glVertex3f(-119.8, -10.0, -239.0); //kanan
    glVertex3f(-119.8, 05.0, -239.0);//kiri
    glVertex3f(-119.8, 05.0, -257.0);//kiri
    glVertex3f(-119.8, -10.0, -257.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela7 dinding kiri kecil 1 bagunan panjang kiri
    glColor3ub(128,236,255);
    glVertex3f(-119.8, -10.0, -262.0); //kanan
    glVertex3f(-119.8, 05.0, -262.0);//kiri
    glVertex3f(-119.8, 05.0, -280.0);//kiri
    glVertex3f(-119.8, -10.0, -280.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela8 dinding kiri kecil 1 bagunan panjang kiri
    glColor3ub(128,236,255);
    glVertex3f(-119.8, -10.0, -285.0); //kanan
    glVertex3f(-119.8, 05.0, -285.0);//kiri
    glVertex3f(-119.8, 05.0, -303.0);//kiri
    glVertex3f(-119.8, -10.0, -303.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela9 dinding kiri kecil 1 bagunan panjang kiri
    glColor3ub(128,236,255);
    glVertex3f(-119.8, -10.0, -308.0); //kanan
    glVertex3f(-119.8, 05.0, -308.0);//kiri
    glVertex3f(-119.8, 05.0, -326.0);//kiri
    glVertex3f(-119.8, -10.0, -326.0);//kanan
    glEnd();
        //dinding kiri kecil 2 bagunan panjang kiri
        glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(-119.7, 52.0, -117.0); //kanan
    glVertex3f(-119.7, 63.0, -117.0);//kiri
    glVertex3f(-119.7, 63.0, -343.0);//kiri
    glVertex3f(-119.7, 52.0, -343.0);//kanan
    glEnd();
     glBegin(GL_QUADS);//jendela1 dinding kiri kecil 2 bagunan panjang kiri
    glColor3ub(128,236,255);
    glVertex3f(-119.8, 30.0, -142.0); //kanan
    glVertex3f(-119.8, 45.0, -142.0);//kiri
    glVertex3f(-119.8, 45.0, -124.0);//kiri
    glVertex3f(-119.8, 30.0, -124.0);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela2 dinding kiri kecil 2 bagunan panjang kiri
    glColor3ub(128,236,255);
    glVertex3f(-119.8, 30.0, -147.0); //kanan
    glVertex3f(-119.8, 45.0, -147.0);//kiri
    glVertex3f(-119.8, 45.0, -165.0);//kiri
    glVertex3f(-119.8, 30.0, -165.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela3 dinding kiri kecil 2 bagunan panjang kiri
    glColor3ub(128,236,255);
    glVertex3f(-119.8, 30.0, -170.0); //kanan
    glVertex3f(-119.8, 45.0, -170.0);//kiri
    glVertex3f(-119.8, 45.0, -188.0);//kiri
    glVertex3f(-119.8, 30.0, -188.0);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela4 dinding kiri kecil 2 bagunan panjang kiri
    glColor3ub(128,236,255);
    glVertex3f(-119.8, 30.0, -193.0); //kanan
    glVertex3f(-119.8, 45.0, -193.0);//kiri
    glVertex3f(-119.8, 45.0, -211.0);//kiri
    glVertex3f(-119.8, 30.0, -211.0);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela5 dinding kiri kecil 2 bagunan panjang kiri
    glColor3ub(128,236,255);
    glVertex3f(-119.8, 30.0, -216.0); //kanan
    glVertex3f(-119.8, 45.0, -216.0);//kiri
    glVertex3f(-119.8, 45.0, -234.0);//kiri
    glVertex3f(-119.8, 30.0, -234.0);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela6 dinding kiri kecil 2 bagunan panjang kiri
    glColor3ub(128,236,255);
    glVertex3f(-119.8, 30.0, -239.0); //kanan
    glVertex3f(-119.8, 45.0, -239.0);//kiri
    glVertex3f(-119.8, 45.0, -257.0);//kiri
    glVertex3f(-119.8, 30.0, -257.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela7 dinding kiri kecil 2 bagunan panjang kiri
    glColor3ub(128,236,255);
    glVertex3f(-119.8, 30.0, -262.0); //kanan
    glVertex3f(-119.8, 45.0, -262.0);//kiri
    glVertex3f(-119.8, 45.0, -280.0);//kiri
    glVertex3f(-119.8, 30.0, -280.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela8 dinding kiri kecil 2 bagunan panjang kiri
    glColor3ub(128,236,255);
    glVertex3f(-119.8, 30.0, -285.0); //kanan
    glVertex3f(-119.8, 45.0, -285.0);//kiri
    glVertex3f(-119.8, 45.0, -303.0);//kiri
    glVertex3f(-119.8, 30.0, -303.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela9 dinding kiri kecil 2 bagunan panjang kiri
    glColor3ub(128,236,255);
    glVertex3f(-119.8, 30.0, -308.0); //kanan
    glVertex3f(-119.8, 45.0, -308.0);//kiri
    glVertex3f(-119.8, 45.0, -326.0);//kiri
    glVertex3f(-119.8, 30.0, -326.0);//kanan
    glEnd();
        //dinding kiri kecil 3 bagunan panjang kiri
        glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(-119.7, 89.0, -117.0); //kanan
    glVertex3f(-119.7, 102.0, -117.0);//kiri
    glVertex3f(-119.7, 102.0, -343.0);//kiri
    glVertex3f(-119.7, 89.0, -343.0);//kanan
    glEnd();
           glBegin(GL_QUADS);//jendela1 dinding kiri kecil 3 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(-119.8, 68.0, -142.0); //kanan
    glVertex3f(-119.8, 83.0, -142.0);//kiri
    glVertex3f(-119.8, 83.0, -124.0);//kiri
    glVertex3f(-119.8, 68.0, -124.0);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela2 dinding kiri kecil 3 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(-119.8, 68.0, -147.0); //kanan
    glVertex3f(-119.8, 83.0, -147.0);//kiri
    glVertex3f(-119.8, 83.0, -165.0);//kiri
    glVertex3f(-119.8, 68.0, -165.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela3 dinding kiri kecil 3 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(-119.8, 68.0, -170.0); //kanan
    glVertex3f(-119.8, 83.0, -170.0);//kiri
    glVertex3f(-119.8, 83.0, -188.0);//kiri
    glVertex3f(-119.8, 68.0, -188.0);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela4 dinding kiri kecil 3 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(-119.8, 68.0, -193.0); //kanan
    glVertex3f(-119.8, 83.0, -193.0);//kiri
    glVertex3f(-119.8, 83.0, -211.0);//kiri
    glVertex3f(-119.8, 68.0, -211.0);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela5 dinding kiri kecil 3 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(-119.8, 68.0, -216.0); //kanan
    glVertex3f(-119.8, 83.0, -216.0);//kiri
    glVertex3f(-119.8, 83.0, -234.0);//kiri
    glVertex3f(-119.8, 68.0, -234.0);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela6 dinding kiri kecil 3 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(-119.8, 68.0, -239.0); //kanan
    glVertex3f(-119.8,83.0, -239.0);//kiri
    glVertex3f(-119.8, 83.0, -257.0);//kiri
    glVertex3f(-119.8, 68.0, -257.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela7 dinding kiri kecil 3 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(-119.8, 68.0, -262.0); //kanan
    glVertex3f(-119.8, 83.0, -262.0);//kiri
    glVertex3f(-119.8, 83.0, -280.0);//kiri
    glVertex3f(-119.8, 68.0, -280.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela8 dinding kiri kecil 3 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(-119.8, 68.0, -285.0); //kanan
    glVertex3f(-119.8, 83.0, -285.0);//kiri
    glVertex3f(-119.8, 83.0, -303.0);//kiri
    glVertex3f(-119.8, 68.0, -303.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela9 dinding kiri kecil 3 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(-119.8, 68.0, -308.0); //kanan
    glVertex3f(-119.8, 83.0, -308.0);//kiri
    glVertex3f(-119.8, 83.0, -326.0);//kiri
    glVertex3f(-119.8, 68.0, -326.0);//kanan
    glEnd();
     //dinding Kanan bagunan panjang kiri
    glBegin(GL_QUADS);
    glColor3ub(171, 149, 99);
    glVertex3f(-200.0, -20.0, -120.0); //kanan
    glVertex3f(-200.0, 100.0, -120.0);//kiri
    glVertex3f(-200.0, 100.0, -340.0);//kiri
    glVertex3f(-200.0, -20.0, -340.0);//kanan
    glEnd();
        //dinding kanan kecil 1 bagunan panjang kiri
        glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(-200.3, 12.0, -117.0); //kanan
    glVertex3f(-200.3, 23.0, -117.0);//kiri
    glVertex3f(-200.3, 23.0, -343.0);//kiri
    glVertex3f(-200.3, 12.0, -343.0);//kanan
    glEnd();
    glBegin(GL_QUADS);//jendela1 dinding kanan kecil 1 Bangunan Panjang kiri
    glColor3ub(128,236,255);
    glVertex3f(-200.2, -10.0, -142.0); //kanan
    glVertex3f(-200.2, 05.0, -142.0);//kiri
    glVertex3f(-200.2, 05.0, -124.0);//kiri
    glVertex3f(-200.2, -10.0, -124.0);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela2 dinding kanan kecil 1 Bangunan Panjang kiri
    glColor3ub(128,236,255);
    glVertex3f(-200.2, -10.0, -147.0); //kanan
    glVertex3f(-200.2, 05.0, -147.0);//kiri
    glVertex3f(-200.2, 05.0, -165.0);//kiri
    glVertex3f(-200.2, -10.0, -165.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela3 dinding kanan kecil 1 Bangunan Panjang kiri
    glColor3ub(128,236,255);
    glVertex3f(-200.2, -10.0, -170.0); //kanan
    glVertex3f(-200.2, 05.0, -170.0);//kiri
    glVertex3f(-200.2, 05.0, -188.0);//kiri
    glVertex3f(-200.2, -10.0, -188.0);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela4 dinding kanan kecil 1 Bangunan Panjang kiri
    glColor3ub(128,236,255);
    glVertex3f(-200.2, -10.0, -193.0); //kanan
    glVertex3f(-200.2, 05.0, -193.0);//kiri
    glVertex3f(-200.2, 05.0, -211.0);//kiri
    glVertex3f(-200.2, -10.0, -211.0);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela5 dinding kanan kecil 1 Bangunan Panjang kiri
    glColor3ub(128,236,255);
    glVertex3f(-200.2, -10.0, -216.0); //kanan
    glVertex3f(-200.2, 05.0, -216.0);//kiri
    glVertex3f(-200.2, 05.0, -234.0);//kiri
    glVertex3f(-200.2, -10.0, -234.0);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela6 dinding kanan kecil 1 Bangunan Panjang kiri
    glColor3ub(128,236,255);
    glVertex3f(-200.2, -10.0, -239.0); //kanan
    glVertex3f(-200.2, 05.0, -239.0);//kiri
    glVertex3f(-200.2, 05.0, -257.0);//kiri
    glVertex3f(-200.2, -10.0, -257.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela7 dinding kanan kecil 1 Bangunan Panjang kiri
    glColor3ub(128,236,255);
    glVertex3f(-200.2, -10.0, -262.0); //kanan
    glVertex3f(-200.2, 05.0, -262.0);//kiri
    glVertex3f(-200.2, 05.0, -280.0);//kiri
    glVertex3f(-200.2, -10.0, -280.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela8 dinding kanan kecil 1 Bangunan Panjang kiri
    glColor3ub(128,236,255);
    glVertex3f(-200.2, -10.0, -285.0); //kanan
    glVertex3f(-200.2, 05.0, -285.0);//kiri
    glVertex3f(-200.2, 05.0, -303.0);//kiri
    glVertex3f(-200.2, -10.0, -303.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela 9 dinding kanan kecil 1 Bangunan Panjang kiri
    glColor3ub(128,236,255);
    glVertex3f(-200.2, -10.0, -308.0); //kanan
    glVertex3f(-200.2, 05.0, -308.0);//kiri
    glVertex3f(-200.2, 05.0, -326.0);//kiri
    glVertex3f(-200.2, -10.0, -326.0);//kanan
    glEnd();
        //dinding kanan kecil 2 bagunan panjang kiri
        glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(-200.3, 52.0, -117.0); //kanan
    glVertex3f(-200.3, 63.0, -117.0);//kiri
    glVertex3f(-200.3, 63.0, -343.0);//kiri
    glVertex3f(-200.3, 52.0, -343.0);//kanan
    glEnd();
     glBegin(GL_QUADS);//jendela1 dinding kanan kecil 2 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(-200.2, 30.0, -142.0); //kanan
    glVertex3f(-200.2, 45.0, -142.0);//kiri
    glVertex3f(-200.2, 45.0, -124.0);//kiri
    glVertex3f(-200.2, 30.0, -124.0);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela2 dinding kanan kecil 2 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(-200.2, 30.0, -147.0); //kanan
    glVertex3f(-200.2, 45.0, -147.0);//kiri
    glVertex3f(-200.2, 45.0, -165.0);//kiri
    glVertex3f(-200.2, 30.0, -165.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela3 dinding kanan kecil 2 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(-200.2, 30, -170.0); //kanan
    glVertex3f(-200.2, 45.0, -170.0);//kiri
    glVertex3f(-200.2, 45.0, -188.0);//kiri
    glVertex3f(-200.2, 30.0, -188.0);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela4 dinding kanan kecil 2 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(-200.2, 30.0, -193.0); //kanan
    glVertex3f(-200.2, 45.0, -193.0);//kiri
    glVertex3f(-200.2, 45.0, -211.0);//kiri
    glVertex3f(-200.2, 30.0, -211.0);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela5 dinding kanan kecil 2 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(-200.2, 30.0, -216.0); //kanan
    glVertex3f(-200.2, 45.0, -216.0);//kiri
    glVertex3f(-200.2, 45.0, -234.0);//kiri
    glVertex3f(-200.2, 30.0, -234.0);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela6 dinding kanan kecil 2 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(-200.2, 30.0, -239.0); //kanan
    glVertex3f(-200.2, 45.0, -239.0);//kiri
    glVertex3f(-200.2, 45.0, -257.0);//kiri
    glVertex3f(-200.2, 30.0, -257.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela7 dinding kanan kecil 2 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(-200.2, 30.0, -262.0); //kanan
    glVertex3f(-200.2, 45.0, -262.0);//kiri
    glVertex3f(-200.2, 45.0, -280.0);//kiri
    glVertex3f(-200.2, 30.0, -280.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela8 dinding kanan kecil 2 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(-200.2, 30.0, -285.0); //kanan
    glVertex3f(-200.2, 45.0, -285.0);//kiri
    glVertex3f(-200.2, 45.0, -303.0);//kiri
    glVertex3f(-200.2, 30.0, -303.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela9 dinding kanan kecil 2 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(-200.2, 30.0, -308.0); //kanan
    glVertex3f(-200.2, 45.0, -308.0);//kiri
    glVertex3f(-200.2, 45.0, -326.0);//kiri
    glVertex3f(-200.2, 30.0, -326.0);//kanan
    glEnd();
        //dinding kanan kecil 3 bagunan panjang kiri
        glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(-200.3, 89.0, -117.0); //kanan
    glVertex3f(-200.3, 102.0, -117.0);//kiri
    glVertex3f(-200.3, 102.0, -343.0);//kiri
    glVertex3f(-200.3, 89.0, -343.0);//kanan
    glEnd();
           glBegin(GL_QUADS);//jendela1 dinding kanan kecil 3 Bangunan Panjang kiri
    glColor3ub(128,236,255);
    glVertex3f(-200.2, 68.0, -142.0); //kanan
    glVertex3f(-200.2, 83.0, -142.0);//kiri
    glVertex3f(-200.2, 83.0, -124.0);//kiri
    glVertex3f(-200.2, 68.0, -124.0);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela2 dinding kiri kecil 3 Bangunan Panjang kiri
    glColor3ub(128,236,255);
    glVertex3f(-200.2, 68.0, -147.0); //kanan
    glVertex3f(-200.2, 83.0, -147.0);//kiri
    glVertex3f(-200.2, 83.0, -165.0);//kiri
    glVertex3f(-200.2, 68.0, -165.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela3 dinding kiri kecil 3 Bangunan Panjang kiri
    glColor3ub(128,236,255);
    glVertex3f(-200.2, 68.0, -170.0); //kanan
    glVertex3f(-200.2, 83.0, -170.0);//kiri
    glVertex3f(-200.2, 83.0, -188.0);//kiri
    glVertex3f(-200.2, 68.0, -188.0);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela4 dinding kiri kecil 3 Bangunan Panjang kiri
    glColor3ub(128,236,255);
    glVertex3f(-200.2, 68.0, -193.0); //kanan
    glVertex3f(-200.2, 83.0, -193.0);//kiri
    glVertex3f(-200.2, 83.0, -211.0);//kiri
    glVertex3f(-200.2, 68.0, -211.0);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela5 dinding kiri kecil 3 Bangunan Panjang kiri
    glColor3ub(128,236,255);
    glVertex3f(-200.2, 68.0, -216.0); //kanan
    glVertex3f(-200.2, 83.0, -216.0);//kiri
    glVertex3f(-200.2, 83.0, -234.0);//kiri
    glVertex3f(-200.2, 68.0, -234.0);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela6 dinding kiri kecil 3 Bangunan Panjang kiri
    glColor3ub(128,236,255);
    glVertex3f(-200.2, 68.0, -239.0); //kanan
    glVertex3f(-200.2,83.0, -239.0);//kiri
    glVertex3f(-200.2, 83.0, -257.0);//kiri
    glVertex3f(-200.2, 68.0, -257.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela7 dinding kiri kecil 3 Bangunan Panjang kiri
    glColor3ub(128,236,255);
    glVertex3f(-200.2, 68.0, -262.0); //kanan
    glVertex3f(-200.2, 83.0, -262.0);//kiri
    glVertex3f(-200.2, 83.0, -280.0);//kiri
    glVertex3f(-200.2, 68.0, -280.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela8 dinding kiri kecil 3 Bangunan Panjang kiri
    glColor3ub(128,236,255);
    glVertex3f(-200.2, 68.0, -285.0); //kanan
    glVertex3f(-200.2, 83.0, -285.0);//kiri
    glVertex3f(-200.2, 83.0, -303.0);//kiri
    glVertex3f(-200.2, 68.0, -303.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela9 dinding kiri kecil 3 Bangunan Panjang kiri
    glColor3ub(128,236,255);
    glVertex3f(-200.2, 68.0, -308.0); //kanan
    glVertex3f(-200.2, 83.0, -308.0);//kiri
    glVertex3f(-200.2, 83.0, -326.0);//kiri
    glVertex3f(-200.2, 68.0, -326.0);//kanan
    //dinding depan bagunan panjang kiri
    glBegin(GL_QUADS);
    glColor3ub(171,149,99);
    glVertex3f(-120.0, -20.0, -120.0); //kanan
    glVertex3f(-120.0, 100.0, -120.0);//kiri
    glVertex3f(-200.0, 100.0, -120.0);//kiri
    glVertex3f(-200.0, -20.0, -120.0);//kanan
    glEnd();

        //dinding dalam 1 bagunan panjang kiri
    glBegin(GL_QUADS);
    glColor3ub(171,149,99);
    glVertex3f(-120.0, -20.0, -305.0); //kanan
    glVertex3f(-120.0, 100.0, -305.0);//kiri
    glVertex3f(-200.0, 100.0, -305.0);//kiri
    glVertex3f(-200.0, -20.0, -305.0);//kanan
    glEnd();
            //dinding dalam 2 bagunan panjang kiri
    glBegin(GL_QUADS);
    glColor3ub(171,149,99);
    glVertex3f(-120.0, -20.0, -236.0); //kanan
    glVertex3f(-120.0, 100.0, -236.0);//kiri
    glVertex3f(-200.0, 100.0, -236.0);//kiri
    glVertex3f(-200.0, -20.0, -236.0);//kanan
    glEnd();
            //dinding dalam 3 bagunan panjang kiri
    glBegin(GL_QUADS);
    glColor3ub(171,149,99);
    glVertex3f(-120.0, -20.0, -166.0); //kanan
    glVertex3f(-120.0, 100.0, -166.0);//kiri
    glVertex3f(-200.0, 100.0, -166.0);//kiri
    glVertex3f(-200.0, -20.0, -166.0);//kanan
    glEnd();
        //dinding belakang bagunan panjang kiri
    glBegin(GL_QUADS);
    glColor3ub(171,149,99);
    glVertex3f(-120.0, -20.0, -340.0); //kanan
    glVertex3f(-120.0, 100.0, -340.0);//kiri
    glVertex3f(-200.0, 100.0, -340.0);//kiri
    glVertex3f(-200.0, -20.0, -340.0);//kanan
    glEnd();
            //dinding belakang bagunan panjang kiri
    glBegin(GL_QUADS);
    glColor3ub(255,154,54);
    glVertex3f(-120.0, -20.0, -343.0); //kanan
    glVertex3f(-120.0, 100.0, -343.0);//kiri
    glVertex3f(-200.0, 100.0, -343.0);//kiri
    glVertex3f(-200.0, -20.0, -343.0);//kanan
    glEnd();
                //dinding belakang bagunan panjang kiri
    glBegin(GL_QUADS);
    glColor3ub(255,154,54);
    glVertex3f(-120.0, -20.0, -353.0); //kanan
    glVertex3f(-120.0, 100.0, -353.0);//kiri
    glVertex3f(-200.0, 100.0, -353.0);//kiri
    glVertex3f(-200.0, -20.0, -353.0);//kanan
    glEnd();
         //dinding Kanan bagunan panjang kiri
    glBegin(GL_QUADS);
    glColor3ub(255,154,54);
    glVertex3f(-200.3, -20.0, -343.0); //kanan
    glVertex3f(-200.3, 100.0, -343.0);//kiri
    glVertex3f(-200.3, 100.0, -353.0);//kiri
    glVertex3f(-200.3, -20.0, -353.0);//kanan
    glEnd();
             //dinding Kanan bagunan panjang kiri
    glBegin(GL_QUADS);
    glColor3ub(255,154,54);
    glVertex3f(-119.7, -20.0, -343.0); //kanan
    glVertex3f(-119.7, 100.0, -343.0);//kiri
    glVertex3f(-119.7, 100.0, -353.0);//kiri
    glVertex3f(-119.7, -20.0, -353.0);//kanan
    glEnd();

    //genteng bagunan panjang kiri
    glBegin(GL_QUADS);
    glColor3ub(133, 0, 0);
    glVertex3f(-117.0, 100.0, -120.0); //kanan
    glVertex3f(-160.0, 120.0, -120.0);//kiri
    glVertex3f(-160.0, 120.0, -340.0);//kiri
    glVertex3f(-117.0, 100.0, -340.0);//kanan
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(133,0,0);
    glVertex3f(-203.0, 100.0, -120.0); //kanan
    glVertex3f(-160.0, 120.0, -120.0);//kiri
    glVertex3f(-160.0, 120.0, -340.0);//kiri
    glVertex3f(-203.0, 100.0, -340.0);//kanan
    glEnd();

    //Bangunan Panjang kanan
    //lantai 1 Bangunan Panjang kanan
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(200.0, -20.0, -120.0); //kanan
    glVertex3f(280.0, -20.0, -120.0);//kiri
    glVertex3f(280.0, -20.0, -340.0);//kiri
    glVertex3f(200.0, -20.0, -340.0);//kanan
    glEnd();
        //lantai 2 Bangunan Panjang kanan
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(200.0, 17.0, -120.0); //kanan
    glVertex3f(280.0, 17.0, -120.0);//kiri
    glVertex3f(280.0, 17.0, -340.0);//kiri
    glVertex3f(200.0, 17.0, -340.0);//kanan
    glEnd();
            //lantai 3 Bangunan Panjang kanan
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(200.0, 57.0, -120.0); //kanan
    glVertex3f(280.0, 57.0, -120.0);//kiri
    glVertex3f(280.0, 57.0, -340.0);//kiri
    glVertex3f(200.0, 57.0, -340.0);//kanan
    glEnd();
    //Tembok kanan Bangunan Panjang kanan
    glBegin(GL_QUADS);
    glColor3ub(171, 149, 99);
    glVertex3f(280.0, -20.0, -120.0); //kanan
    glVertex3f(280.0, 100.0, -120.0);//kiri
    glVertex3f(280.0, 100.0, -340.0);//kiri
    glVertex3f(280.0, -20.0, -340.0);//kanan
    glEnd();
    //dinding kanan kecil 1 Bangunan Panjang kanan
        glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(280.3, 12.0, -117.0); //kanan
    glVertex3f(280.3, 23.0, -117.0);//kiri
    glVertex3f(280.3, 23.0, -343.0);//kiri
    glVertex3f(280.3, 12.0, -343.0);//kanan
    glEnd();
    glBegin(GL_QUADS);//jendela1 dinding kanan kecil 1 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(280.2, -10.0, -142.0); //kanan
    glVertex3f(280.2, 05.0, -142.0);//kiri
    glVertex3f(280.2, 05.0, -124.0);//kiri
    glVertex3f(280.2, -10.0, -124.0);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela2 dinding kanan kecil 1 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(280.2, -10.0, -147.0); //kanan
    glVertex3f(280.2, 05.0, -147.0);//kiri
    glVertex3f(280.2, 05.0, -165.0);//kiri
    glVertex3f(280.2, -10.0, -165.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela3 dinding kanan kecil 1 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(280.2, -10.0, -170.0); //kanan
    glVertex3f(280.2, 05.0, -170.0);//kiri
    glVertex3f(280.2, 05.0, -188.0);//kiri
    glVertex3f(280.2, -10.0, -188.0);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela4 dinding kanan kecil 1 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(280.2, -10.0, -193.0); //kanan
    glVertex3f(280.2, 05.0, -193.0);//kiri
    glVertex3f(280.2, 05.0, -211.0);//kiri
    glVertex3f(280.2, -10.0, -211.0);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela5 dinding kanan kecil 1 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(280.2, -10.0, -216.0); //kanan
    glVertex3f(280.2, 05.0, -216.0);//kiri
    glVertex3f(280.2, 05.0, -234.0);//kiri
    glVertex3f(280.2, -10.0, -234.0);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela6 dinding kanan kecil 1 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(280.2, -10.0, -239.0); //kanan
    glVertex3f(280.2, 05.0, -239.0);//kiri
    glVertex3f(280.2, 05.0, -257.0);//kiri
    glVertex3f(280.2, -10.0, -257.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela7 dinding kanan kecil 1 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(280.2, -10.0, -262.0); //kanan
    glVertex3f(280.2, 05.0, -262.0);//kiri
    glVertex3f(280.2, 05.0, -280.0);//kiri
    glVertex3f(280.2, -10.0, -280.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela8 dinding kanan kecil 1 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(280.2, -10.0, -285.0); //kanan
    glVertex3f(280.2, 05.0, -285.0);//kiri
    glVertex3f(280.2, 05.0, -303.0);//kiri
    glVertex3f(280.2, -10.0, -303.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela 9 dinding kanan kecil 1 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(280.2, -10.0, -308.0); //kanan
    glVertex3f(280.2, 05.0, -308.0);//kiri
    glVertex3f(280.2, 05.0, -326.0);//kiri
    glVertex3f(280.2, -10.0, -326.0);//kanan
    glEnd();
    //dinding kanan kecil 2 dinding kanan kecil 2 Bangunan Panjang kanan
        glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(280.3, 52.0, -117.0); //kanan
    glVertex3f(280.3, 63.0, -117.0);//kiri
    glVertex3f(280.3, 63.0, -343.0);//kiri
    glVertex3f(280.3, 52.0, -343.0);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela1 dinding kanan kecil 2 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(280.2, 30.0, -142.0); //kanan
    glVertex3f(280.2, 45.0, -142.0);//kiri
    glVertex3f(280.2, 45.0, -124.0);//kiri
    glVertex3f(280.2, 30.0, -124.0);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela2 dinding kanan kecil 2 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(280.2, 30.0, -147.0); //kanan
    glVertex3f(280.2, 45.0, -147.0);//kiri
    glVertex3f(280.2, 45.0, -165.0);//kiri
    glVertex3f(280.2, 30.0, -165.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela3 dinding kanan kecil 2 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(280.2, 30, -170.0); //kanan
    glVertex3f(280.2, 45.0, -170.0);//kiri
    glVertex3f(280.2, 45.0, -188.0);//kiri
    glVertex3f(280.2, 30.0, -188.0);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela4 dinding kanan kecil 2 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(280.2, 30.0, -193.0); //kanan
    glVertex3f(280.2, 45.0, -193.0);//kiri
    glVertex3f(280.2, 45.0, -211.0);//kiri
    glVertex3f(280.2, 30.0, -211.0);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela5 dinding kanan kecil 2 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(280.2, 30.0, -216.0); //kanan
    glVertex3f(280.2, 45.0, -216.0);//kiri
    glVertex3f(280.2, 45.0, -234.0);//kiri
    glVertex3f(280.2, 30.0, -234.0);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela6 dinding kanan kecil 2 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(280.2, 30.0, -239.0); //kanan
    glVertex3f(280.2, 45.0, -239.0);//kiri
    glVertex3f(280.2, 45.0, -257.0);//kiri
    glVertex3f(280.2, 30.0, -257.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela7 dinding kanan kecil 2 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(280.2, 30.0, -262.0); //kanan
    glVertex3f(280.2, 45.0, -262.0);//kiri
    glVertex3f(280.2, 45.0, -280.0);//kiri
    glVertex3f(280.2, 30.0, -280.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela8 dinding kanan kecil 2 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(280.2, 30.0, -285.0); //kanan
    glVertex3f(280.2, 45.0, -285.0);//kiri
    glVertex3f(280.2, 45.0, -303.0);//kiri
    glVertex3f(280.2, 30.0, -303.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela9 dinding kanan kecil 2 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(280.2, 30.0, -308.0); //kanan
    glVertex3f(280.2, 45.0, -308.0);//kiri
    glVertex3f(280.2, 45.0, -326.0);//kiri
    glVertex3f(280.2, 30.0, -326.0);//kanan
    glEnd();
    //dinding kanan kecil 3 Bangunan Panjang kanan
        glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(280.3, 89.0, -117.0); //kanan
    glVertex3f(280.3, 102.0, -117.0);//kiri
    glVertex3f(280.3, 102.0, -343.0);//kiri
    glVertex3f(280.3, 89.0, -343.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela1 dinding kanan kecil 3 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(280.2, 68.0, -142.0); //kanan
    glVertex3f(280.2, 83.0, -142.0);//kiri
    glVertex3f(280.2, 83.0, -124.0);//kiri
    glVertex3f(280.2, 68.0, -124.0);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela2 dinding kanan kecil 3 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(280.2, 68.0, -147.0); //kanan
    glVertex3f(280.2, 83.0, -147.0);//kiri
    glVertex3f(280.2, 83.0, -165.0);//kiri
    glVertex3f(280.2, 68.0, -165.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela3 dinding kanan kecil 3 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(280.2, 68.0, -170.0); //kanan
    glVertex3f(280.2, 83.0, -170.0);//kiri
    glVertex3f(280.2, 83.0, -188.0);//kiri
    glVertex3f(280.2, 68.0, -188.0);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela4 dinding kanan kecil 3 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(280.2, 68.0, -193.0); //kanan
    glVertex3f(280.2, 83.0, -193.0);//kiri
    glVertex3f(280.2, 83.0, -211.0);//kiri
    glVertex3f(280.2, 68.0, -211.0);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela5 dinding kanan kecil 3 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(280.2, 68.0, -216.0); //kanan
    glVertex3f(280.2, 83.0, -216.0);//kiri
    glVertex3f(280.2, 83.0, -234.0);//kiri
    glVertex3f(280.2, 68.0, -234.0);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela6 dinding kanan kecil 3 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(280.2, 68.0, -239.0); //kanan
    glVertex3f(280.2, 83.0, -239.0);//kiri
    glVertex3f(280.2, 83.0, -257.0);//kiri
    glVertex3f(280.2, 68.0, -257.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela7 dinding kanan kecil 3 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(280.2, 68.0, -262.0); //kanan
    glVertex3f(280.2, 83.0, -262.0);//kiri
    glVertex3f(280.2, 83.0, -280.0);//kiri
    glVertex3f(280.2, 68.0, -280.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela8 dinding kanan kecil 3 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(280.2, 68.0, -285.0); //kanan
    glVertex3f(280.2, 83.0, -285.0);//kiri
    glVertex3f(280.2, 83.0, -303.0);//kiri
    glVertex3f(280.2, 68.0, -303.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela9 dinding kanan kecil 3 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(280.2, 68.0, -308.0); //kanan
    glVertex3f(280.2, 83.0, -308.0);//kiri
    glVertex3f(280.2, 83.0, -326.0);//kiri
    glVertex3f(280.2, 68.0, -326.0);//kanan
    glEnd();
    //dinding kiri Bangunan Panjang kanan
    glBegin(GL_QUADS);
    glColor3ub(171, 149, 99);
    glVertex3f(200.0, -20.0, -120.0); //kanan
    glVertex3f(200.0, 100.0, -120.0);//kiri
    glVertex3f(200.0, 100.0, -340.0);//kiri
    glVertex3f(200.0, -20.0, -340.0);//kanan
    glEnd();
            //dinding kiri kecil 1 Bangunan Panjang kanan
        glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(199.7, 12.0, -117.0); //kanan
    glVertex3f(199.7, 23.0, -117.0);//kiri
    glVertex3f(199.7, 23.0, -343.0);//kiri
    glVertex3f(199.7, 12.0, -343.0);//kanan
    glEnd();
    glBegin(GL_QUADS);//jendela1 dinding kiri kecil 1 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(199.8, -10.0, -142.0); //kanan
    glVertex3f(199.8, 05.0, -142.0);//kiri
    glVertex3f(199.8, 05.0, -124.0);//kiri
    glVertex3f(199.8, -10.0, -124.0);//kanan
    glEnd();
    glBegin(GL_QUADS);//jendela2 dinding kiri kecil 1 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(199.8, -10.0, -147.0); //kanan
    glVertex3f(199.8, 05.0, -147.0);//kiri
    glVertex3f(199.8, 05.0, -165.0);//kiri
    glVertex3f(199.8, -10.0, -165.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela3 dinding kiri kecil 1 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(199.8, -10.0, -170.0); //kanan
    glVertex3f(199.8, 05.0, -170.0);//kiri
    glVertex3f(199.8, 05.0, -188.0);//kiri
    glVertex3f(199.8, -10.0, -188.0);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela4 dinding kiri kecil 1 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(199.8, -10.0, -193.0); //kanan
    glVertex3f(199.8, 05.0, -193.0);//kiri
    glVertex3f(199.8, 05.0, -211.0);//kiri
    glVertex3f(199.8, -10.0, -211.0);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela5 dinding kiri kecil 1 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(199.8, -10.0, -216.0); //kanan
    glVertex3f(199.8, 05.0, -216.0);//kiri
    glVertex3f(199.8, 05.0, -234.0);//kiri
    glVertex3f(199.8, -10.0, -234.0);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela6 dinding kiri kecil 1 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(199.8, -10.0, -239.0); //kanan
    glVertex3f(199.8, 05.0, -239.0);//kiri
    glVertex3f(199.8, 05.0, -257.0);//kiri
    glVertex3f(199.8, -10.0, -257.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela7 dinding kiri kecil 1 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(199.8, -10.0, -262.0); //kanan
    glVertex3f(199.8, 05.0, -262.0);//kiri
    glVertex3f(199.8, 05.0, -280.0);//kiri
    glVertex3f(199.8, -10.0, -280.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela8 dinding kiri kecil 1 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(199.8, -10.0, -285.0); //kanan
    glVertex3f(199.8, 05.0, -285.0);//kiri
    glVertex3f(199.8, 05.0, -303.0);//kiri
    glVertex3f(199.8, -10.0, -303.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela9 dinding kiri kecil 1 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(199.8, -10.0, -308.0); //kanan
    glVertex3f(199.8, 05.0, -308.0);//kiri
    glVertex3f(199.8, 05.0, -326.0);//kiri
    glVertex3f(199.8, -10.0, -326.0);//kanan
    glEnd();
        //dinding kiri kecil 2
        glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(199.7, 89.0, -117.0); //kanan
    glVertex3f(199.7, 102.0, -117.0);//kiri
    glVertex3f(199.7, 102.0, -343.0);//kiri
    glVertex3f(199.7, 89.0, -343.0);//kanan
    glEnd();
    glBegin(GL_QUADS);//jendela1 dinding kiri kecil 2 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(199.8, 30.0, -142.0); //kanan
    glVertex3f(199.8, 45.0, -142.0);//kiri
    glVertex3f(199.8, 45.0, -124.0);//kiri
    glVertex3f(199.8, 30.0, -124.0);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela2 dinding kiri kecil 2 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(199.8, 30.0, -147.0); //kanan
    glVertex3f(199.8, 45.0, -147.0);//kiri
    glVertex3f(199.8, 45.0, -165.0);//kiri
    glVertex3f(199.8, 30.0, -165.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela3 dinding kiri kecil 2 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(199.8, 30.0, -170.0); //kanan
    glVertex3f(199.8, 45.0, -170.0);//kiri
    glVertex3f(199.8, 45.0, -188.0);//kiri
    glVertex3f(199.8, 30.0, -188.0);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela4 dinding kiri kecil 2 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(199.8, 30.0, -193.0); //kanan
    glVertex3f(199.8, 45.0, -193.0);//kiri
    glVertex3f(199.8, 45.0, -211.0);//kiri
    glVertex3f(199.8, 30.0, -211.0);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela5 dinding kiri kecil 2 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(199.8, 30.0, -216.0); //kanan
    glVertex3f(199.8, 45.0, -216.0);//kiri
    glVertex3f(199.8, 45.0, -234.0);//kiri
    glVertex3f(199.8, 30.0, -234.0);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela6 dinding kiri kecil 2 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(199.8, 30.0, -239.0); //kanan
    glVertex3f(199.8, 45.0, -239.0);//kiri
    glVertex3f(199.8, 45.0, -257.0);//kiri
    glVertex3f(199.8, 30.0, -257.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela7 dinding kiri kecil 2 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(199.8, 30.0, -262.0); //kanan
    glVertex3f(199.8, 45.0, -262.0);//kiri
    glVertex3f(199.8, 45.0, -280.0);//kiri
    glVertex3f(199.8, 30.0, -280.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela8 dinding kiri kecil 2 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(199.8, 30.0, -285.0); //kanan
    glVertex3f(199.8, 45.0, -285.0);//kiri
    glVertex3f(199.8, 45.0, -303.0);//kiri
    glVertex3f(199.8, 30.0, -303.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela9 dinding kiri kecil 2 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(199.8, 30.0, -308.0); //kanan
    glVertex3f(199.8, 45.0, -308.0);//kiri
    glVertex3f(199.8, 45.0, -326.0);//kiri
    glVertex3f(199.8, 30.0, -326.0);//kanan
    glEnd();
        //dinding kiri kecil 3 Bangunan Panjang kanan
        glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(199.7, 52.0, -117.0); //kanan
    glVertex3f(199.7, 63.0, -117.0);//kiri
    glVertex3f(199.7, 63.0, -343.0);//kiri
    glVertex3f(199.7, 52.0, -343.0);//kanan
    glEnd();
       glBegin(GL_QUADS);//jendela1 dinding kiri kecil 3 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(199.8, 68.0, -142.0); //kanan
    glVertex3f(199.8, 83.0, -142.0);//kiri
    glVertex3f(199.8, 83.0, -124.0);//kiri
    glVertex3f(199.8, 68.0, -124.0);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela2 dinding kiri kecil 3 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(199.8, 68.0, -147.0); //kanan
    glVertex3f(199.8, 83.0, -147.0);//kiri
    glVertex3f(199.8, 83.0, -165.0);//kiri
    glVertex3f(199.8, 68.0, -165.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela3 dinding kiri kecil 3 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(199.8, 68.0, -170.0); //kanan
    glVertex3f(199.8, 83.0, -170.0);//kiri
    glVertex3f(199.8, 83.0, -188.0);//kiri
    glVertex3f(199.8, 68.0, -188.0);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela4 dinding kiri kecil 3 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(199.8, 68.0, -193.0); //kanan
    glVertex3f(199.8, 83.0, -193.0);//kiri
    glVertex3f(199.8, 83.0, -211.0);//kiri
    glVertex3f(199.8, 68.0, -211.0);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela5 dinding kiri kecil 3 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(199.8, 68.0, -216.0); //kanan
    glVertex3f(199.8, 83.0, -216.0);//kiri
    glVertex3f(199.8, 83.0, -234.0);//kiri
    glVertex3f(199.8, 68.0, -234.0);//kanan
    glEnd();
        glBegin(GL_QUADS);//jendela6 dinding kiri kecil 3 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(199.8, 68.0, -239.0); //kanan
    glVertex3f(199.8,83.0, -239.0);//kiri
    glVertex3f(199.8, 83.0, -257.0);//kiri
    glVertex3f(199.8, 68.0, -257.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela7 dinding kiri kecil 3 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(199.8, 68.0, -262.0); //kanan
    glVertex3f(199.8, 83.0, -262.0);//kiri
    glVertex3f(199.8, 83.0, -280.0);//kiri
    glVertex3f(199.8, 68.0, -280.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela8 dinding kiri kecil 3 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(199.8, 68.0, -285.0); //kanan
    glVertex3f(199.8, 83.0, -285.0);//kiri
    glVertex3f(199.8, 83.0, -303.0);//kiri
    glVertex3f(199.8, 68.0, -303.0);//kanan
    glEnd();
            glBegin(GL_QUADS);//jendela9 dinding kiri kecil 3 Bangunan Panjang kanan
    glColor3ub(128,236,255);
    glVertex3f(199.8, 68.0, -308.0); //kanan
    glVertex3f(199.8, 83.0, -308.0);//kiri
    glVertex3f(199.8, 83.0, -326.0);//kiri
    glVertex3f(199.8, 68.0, -326.0);//kanan
    glEnd();
    //dinding depan Bangunan Panjang kanan
    glBegin(GL_QUADS);
    glColor3ub(171,149,99);
    glVertex3f(200.0, -20.0, -120.0); //kanan
    glVertex3f(200.0, 100.0, -120.0);//kiri
    glVertex3f(280.0, 100.0, -120.0);//kiri
    glVertex3f(280.0, -20.0, -120.0);//kanan
    glEnd();

        //dinding dalam 1 Bangunan Panjang kanan
    glBegin(GL_QUADS);
    glColor3ub(171,149,99);
    glVertex3f(200.0, -20.0, -305.0); //kanan
    glVertex3f(200.0, 100.0, -305.0);//kiri
    glVertex3f(280.0, 100.0, -305.0);//kiri
    glVertex3f(280.0, -20.0, -305.0);//kanan
    glEnd();
            //dinding dalam 2 Bangunan Panjang kanan
    glBegin(GL_QUADS);
    glColor3ub(171,149,99);
    glVertex3f(200.0, -20.0, -236.0); //kanan
    glVertex3f(200.0, 100.0, -236.0);//kiri
    glVertex3f(280.0, 100.0, -236.0);//kiri
    glVertex3f(280.0, -20.0, -236.0);//kanan
    glEnd();        //dinding dalam 3 Bangunan Panjang kanan
    glBegin(GL_QUADS);
    glColor3ub(171,149,99);
    glVertex3f(200.0, -20.0, -166.0); //kanan
    glVertex3f(200.0, 100.0, -166.0);//kiri
    glVertex3f(280.0, 100.0, -166.0);//kiri
    glVertex3f(280.0, -20.0, -166.0);//kanan
    glEnd();
        //dinding belakang Bangunan Panjang kanan
    glBegin(GL_QUADS);
    glColor3ub(171,149,99);
    glVertex3f(200.0, -20.0, -340.0); //kanan
    glVertex3f(200.0, 100.0, -340.0);//kiri
    glVertex3f(280.0, 100.0, -340.0);//kiri
    glVertex3f(280.0, -20.0, -340.0);//kanan
    glEnd();
                //Tembok kecil belakang
    glBegin(GL_QUADS);
    glColor3ub(255,154,54);
    glVertex3f(200.0, -20.0, -343.0); //kanan
    glVertex3f(200.0, 100.0, -343.0);//kiri
    glVertex3f(280.0, 100.0, -343.0);//kiri
    glVertex3f(280.0, -20.0, -343.0);//kanan
    glEnd();
    //Tembok kecil belakang
    glBegin(GL_QUADS);
    glColor3ub(255,154,54);
    glVertex3f(200.0, -20.0, -353.0); //kanan
    glVertex3f(200.0, 100.0, -353.0);//kiri
    glVertex3f(280.0, 100.0, -353.0);//kiri
    glVertex3f(280.0, -20.0, -353.0);//kanan
    glEnd();
    //Tembok kecil belakang
    glBegin(GL_QUADS);
    glColor3ub(255,154,54);
    glVertex3f(280.3, -20.0, -343.0); //kanan
    glVertex3f(280.3, 100.0, -343.0);//kiri
    glVertex3f(280.3, 100.0, -353.0);//kiri
    glVertex3f(280.3, -20.0, -353.0);//kanan
    glEnd();
    //Tembok kecil belakang
    glBegin(GL_QUADS);
    glColor3ub(255,154,54);
    glVertex3f(199.7, -20.0, -343.0); //kanan
    glVertex3f(199.7, 100.0, -343.0);//kiri
    glVertex3f(199.7, 100.0, -353.0);//kiri
    glVertex3f(199.7, -20.0, -353.0);//kanan
    glEnd();

    //genteng
    glBegin(GL_QUADS);
    glColor3ub(133, 0, 0);
    glVertex3f(197.0, 100.0, -120.0); //kanan
    glVertex3f(240.0, 120.0, -120.0);//kiri
    glVertex3f(240.0, 120.0, -340.0);//kiri
    glVertex3f(197.0, 100.0, -340.0);//kanan
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(133, 0, 0);
    glVertex3f(283.0, 100.0, -120.0); //kanan
    glVertex3f(240.0, 120.0, -120.0);//kiri
    glVertex3f(240.0, 120.0, -340.0);//kiri
    glVertex3f(283.0, 100.0, -340.0);//kanan
    glEnd();

    //dinding serong kiri
    glBegin(GL_QUADS);
    glColor3ub(255,154,54);
    glVertex3f(-202.0, -20.0, -120.0); //kanan
    glVertex3f(-202.0, 103.0, -120.0);//kiri
    glVertex3f(-72.0, 103.0, 20.0);//kiri
    glVertex3f(-72.0, -20.0, 20.0);//kanan
    glEnd();
    //dinding serong kiri kecil 1
    glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(-200.0, 65.0, -116.2); //kanan
    glVertex3f(-200.0, 88.0, -116.2);//kiri
    glVertex3f(-78.0, 88.0, 22.8);//kiri
    glVertex3f(-78.0, 65.0, 22.8);//kanan
    glEnd();
    //dinding serong kiri kecil 2
    glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(-200.0, 28.0, -116.2); //kanan
    glVertex3f(-200.0, 50.0, -116.2);//kiri
    glVertex3f(-78.0, 50.0, 22.8);//kiri
    glVertex3f(-78.0, 28.0, 22.8);//kanan
    glEnd();
                  //dinding serong kiri kecil 3
    glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(-200.0, -10.0, -116.2); //kanan
    glVertex3f(-200.0, 13.0, -116.2);//kiri
    glVertex3f(-78.0, 13.0, 22.8);//kiri
    glVertex3f(-78.0, -10.0, 22.8);//kanan
    glEnd();
    //dinding serong kiri belakang

    glBegin(GL_QUADS);
    glColor3ub(255,154,54);
    glVertex3f(-117.0, -20.0, -120.0); //kanan
    glVertex3f(-117.0, 100.0, -120.0);//kiri
    glVertex3f(-72.0, 100.0, -80.0);//kiri
    glVertex3f(-72.0, -20.0, -80.0);//kanan
    glEnd();

    //dinding serong kanan
    glBegin(GL_QUADS);
    glColor3ub(255,154,54);
    glVertex3f(282.0, -20.0, -120.0); //kanan
    glVertex3f(282.0, 100.0, -120.0);//kiri
    glVertex3f(142.0, 100.0, 20.0);//kiri
    glVertex3f(142.0, -20.0, 20.0);//kanan
    glEnd();
        //dinding serong kanan kecil 1
    glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(284.5, 65.0, -112.2); //kanan
    glVertex3f(284.5, 88.0, -112.2);//kiri
    glVertex3f(144.0, 88.0, 18.8);//kiri
    glVertex3f(144.0, 65.0, 18.8);//kanan
    glEnd();
    //dinding serong kanan kecil 2
    glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(284.5, 28.0, -112.2); //kanan
    glVertex3f(284.5, 50.0, -112.2);//kiri
    glVertex3f(144.0, 50.0, 18.8);//kiri
    glVertex3f(144.0, 28.0, 18.8);//kanan
    glEnd();
    //dinding serong kiri kecil 3
    glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(284.5, -10.0, -112.2); //kanan
    glVertex3f(284.5, 13.0, -112.2);//kiri
    glVertex3f(144.0, 13.0, 18.8);//kiri
    glVertex3f(144.0, -10.0, 18.8);//kanan
    glEnd();

        //dinding serong kanan belakang
    glBegin(GL_QUADS);
    glColor3ub(255,154,54);
    glVertex3f(198.0, -20.0, -120.0); //kanan
    glVertex3f(198.0, 100.0, -120.0);//kiri
    glVertex3f(142.0, 100.0, -81.0);//kiri
    glVertex3f(142.0, -20.0, -81.0);//kanan
    glEnd();

    //bangunan Kotak Kecil kiri
              //lantaiatas
                  glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(-110.0, 120.0, -5.0); //kanan
    glVertex3f(-180.0, 120.0, -5.0);//kiri
    glVertex3f(-180.0, 120.0, -80.0);//kiri
    glVertex3f(-110.0, 120.0, -80.0);//kanan
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(-110.0, -19.8, -5.0); //kanan
    glVertex3f(-180.0, -19.8, -5.0);//kiri
    glVertex3f(-180.0, -19.8, -80.0);//kiri
    glVertex3f(-110.0, -19.8, -80.0);//kanan
    glEnd();
           //lantaibawah
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(-110.0, 0.0, -5.0); //kanan
    glVertex3f(-180.0, 0.0, -5.0);//kiri
    glVertex3f(-180.0, 0.0, -80.0);//kiri
    glVertex3f(-110.0, 0.0, -80.0);//kanan
    glEnd();
         //Tembok kiri
    glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(-180.0, 0.0, -5.0); //kanan
    glVertex3f(-180.0, 120.0, -5.0);//kiri
    glVertex3f(-180.0, 120.0, -80.0);//kiri
    glVertex3f(-180.0, 0.0, -80.0);//kanan
    glEnd();
        glBegin(GL_QUADS);
    glColor3ub(242, 192,102); //warnah tengah
    glVertex3f(-180.3, 15.0, -7.0); //kanan
    glVertex3f(-180.3, 105.0, -7.0);//kiri
    glVertex3f(-180.3, 105.0, -78.0);//kiri
    glVertex3f(-180.3, 15.0, -78.0);//kanan
    glEnd();
            glBegin(GL_QUADS);
    glColor3ub(128, 236,255);//jendela
    glVertex3f(-180.5, 15.0, -30.0); //kanan
    glVertex3f(-180.5, 105.0, -30.0);//kiri
    glVertex3f(-180.5, 105.0, -55.0);//kiri
    glVertex3f(-180.5, 15.0, -55.0);//kanan
    glEnd();

      //dinding Kanan
    glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(-110.0, 0.0, -5.0); //kanan
    glVertex3f(-110.0, 120.0, -5.0);//kiri
    glVertex3f(-110.0, 120.0, -80.0);//kiri
    glVertex3f(-110.0, 0.0, -80.0);//kanan
    glEnd();
    //dinding depan
        glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(-110.0, 0.0, -05.0); //kanan
    glVertex3f(-110.0, 120.0, -05.0);//kiri
    glVertex3f(-180.0, 120.0, -05.0);//kiri
    glVertex3f(-180.0, 0.0, -05.0);//kanan
    glEnd();
        //dinding belakang
            glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(-110.0, 0.0, -80.0); //kanan
    glVertex3f(-110.0, 120.0, -80.0);//kiri
    glVertex3f(-180.0, 120.0, -80.0);//kiri
    glVertex3f(-180.0, 0.0, -80.0);//kanan
    glEnd();
            glBegin(GL_QUADS);
    glColor3ub(242, 192,102);//warna tengah
    glVertex3f(-113.0, 15.0, -04.7); //kanan
    glVertex3f(-113.0, 105.0, -04.7);//kiri
    glVertex3f(-177.0, 105.0, -04.7);//kiri
    glVertex3f(-177.0, 15.0, -04.7);//kanan
    glEnd();
     glBegin(GL_QUADS);
        glColor3ub(128, 236,255);//jendela
    glVertex3f(-135.0, 15.0, -04.5); //kanan
    glVertex3f(-135.0, 105.0, -04.5);//kiri
    glVertex3f(-155.0, 105.0, -04.5);//kiri
    glVertex3f(-155.0, 15.0, -04.5);//kanan
    glEnd();
            glBegin(GL_QUADS);
    glColor3ub(255,234,171); //tiang teras
    glVertex3f(-110.0, -20.0, -13.0); //kanan
    glVertex3f(-110.0, -20.0,-5.0);//kiri
    glVertex3f(-110.0, 0.2, -5.0);//kiri
    glVertex3f(-110.0, 0.2, -13.0);//kanan
    glEnd();
                glBegin(GL_QUADS);
    glColor3ub(255,234,171); //tiang teras
    glVertex3f(-180.0, -20.0, -13.0); //kanan
    glVertex3f(-180.0, -20.0,-5.0);//kiri
    glVertex3f(-180.0, 0.2, -5.0);//kiri
    glVertex3f(-180.0, 0.2, -13.0);//kanan
    glEnd();
                    glBegin(GL_QUADS);
    glColor3ub(255,234,171); //tiang teras
    glVertex3f(-180.0, -20.0, -80.0); //kanan
    glVertex3f(-180.0, -20.0,-70.0);//kiri
    glVertex3f(-180.0, 0.2, -70.0);//kiri
    glVertex3f(-180.0, 0.2, -80.0);//kanan
    glEnd();

    //Bangunan Kotak Kecil kanan
             glColor3ub(255, 255, 255);
    glVertex3f(-110.0, 120.0, -5.0); //kanan
    glVertex3f(-180.0, 120.0, -5.0);//kiri
    glVertex3f(-180.0, 120.0, -80.0);//kiri
    glVertex3f(-110.0, 120.0, -80.0);//kanan
    glEnd();
          //lantaibawah
    glBegin(GL_QUADS);
    glColor3ub(128, 236,255);
    glVertex3f(190.0, 5.0, 15.0); //kanan
    glVertex3f(280.0, 5.0, 15.0);//kiri
    glVertex3f(280.0, 5.0, -80.0);//kiri
    glVertex3f(190.0, 5.0, -80.0);//kanan
    glEnd();
              //lantaibawah
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(190.0, 19.8, -5.0); //kanan
    glVertex3f(260.0, 19.8, -5.0);//kiri
    glVertex3f(260.0, 19.8, -80.0);//kiri
    glVertex3f(190.0, 19.8, -80.0);//kanan
    glEnd();
             //Tembok kiri
    glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(190.0, 5.0, -5.0); //kanan
    glVertex3f(190.0, 120.0, -5.0);//kiri
    glVertex3f(190.0, 120.0, -80.0);//kiri
    glVertex3f(190.0, 05.0, -80.0);//kanan
    glEnd();
      //dinding Kanan
    glBegin(GL_QUADS);
    glColor3ub(171,149,99);
    glVertex3f(260.0, 5.0, -5.0); //kanan
    glVertex3f(260.0, 120.0, -5.0);//kiri
    glVertex3f(260.0, 120.0, -80.0);//kiri
    glVertex3f(260.0, 5.0, -80.0);//kanan
    glEnd();
        glBegin(GL_QUADS);
    glColor3ub(242, 192,102); //warnah tengah
    glVertex3f(260.3, 15.0, -7.0); //kanan
    glVertex3f(260.3, 105.0, -7.0);//kiri
    glVertex3f(260.3, 105.0, -78.0);//kiri
    glVertex3f(260.3, 15.0, -78.0);//kanan
    glEnd();
            glBegin(GL_QUADS);
    glColor3ub(128, 236,255);//jendela
    glVertex3f(260.5, 15.0, -30.0); //kanan
    glVertex3f(260.5, 105.0, -30.0);//kiri
    glVertex3f(260.5, 105.0, -55.0);//kiri
    glVertex3f(260.5, 15.0, -55.0);//kanan
    glEnd();
    //dinding depan
        glBegin(GL_QUADS);
    glColor3ub(171,149,99);
    glVertex3f(190.0, 5.0, -05.0); //kanan
    glVertex3f(190.0, 120.0, -05.0);//kiri
    glVertex3f(260.0, 120.0, -05.0);//kiri
    glVertex3f(260.0, 5.0, -05.0);//kanan
    glEnd();
                glBegin(GL_QUADS);
    glColor3ub(242, 192,102);//warna tengah
    glVertex3f(193.0, 15.0, -04.7); //kanan
    glVertex3f(193.0, 105.0, -04.7);//kiri
    glVertex3f(257.0, 105.0, -04.7);//kiri
    glVertex3f(257.0, 15.0, -04.7);//kanan
    glEnd();
     glBegin(GL_QUADS);
        glColor3ub(128, 236,255);//jendela
    glVertex3f(215.0, 15.0, -04.5); //kanan
    glVertex3f(215.0, 105.0, -04.5);//kiri
    glVertex3f(235.0, 105.0, -04.5);//kiri
    glVertex3f(235.0, 15.0, -04.5);//kanan
    glEnd();
    //dinding belakang
            glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(190.0, 5.0, -80.0); //kanan
    glVertex3f(190.0, 120.0, -80.0);//kiri
    glVertex3f(260.0, 120.0, -80.0);//kiri
    glVertex3f(260.0, 5.0, -80.0);//kanan
    glEnd();
     //Tembok kiri
    glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(190.0, 5.0, -5.0); //kanan
    glVertex3f(190.0, -20.0, -5.0);//kiri
    glVertex3f(190.0, -20.0, -80.0);//kiri
    glVertex3f(190.0, 05.0, -80.0);//kanan
    glEnd();
      //dinding Kanan
    glBegin(GL_QUADS);
    glColor3ub(171,149,99);
    glVertex3f(260.0, 5.0, -5.0); //kanan
    glVertex3f(260.0, -20.0, -5.0);//kiri
    glVertex3f(260.0, -20.0, -80.0);//kiri
    glVertex3f(260.0, 5.0, -80.0);//kanan
    glEnd();
        glBegin(GL_QUADS);
    glColor3ub(242, 192,102); //warnah tengah
    glVertex3f(260.3, 5.0, -7.0); //kanan
    glVertex3f(260.3, -17.0, -7.0);//kiri
    glVertex3f(260.3, -17.0, -78.0);//kiri
    glVertex3f(260.3, 5.0, -78.0);//kanan
    glEnd();
            glBegin(GL_QUADS);
    glColor3ub(0, 0,0); //pintu
    glVertex3f(260.5, 3.0, -67.0); //kanan
    glVertex3f(260.5, -17.0, -67.0);//kiri
    glVertex3f(260.5, -17.0, -78.0);//kiri
    glVertex3f(260.5, 3.0, -78.0);//kanan
    glEnd();

            glBegin(GL_QUADS);
    glColor3ub(128, 236,255);//jendela
    glVertex3f(260.5, 3.0, -45.0); //kanan
    glVertex3f(260.5, -12.0, -45.0);//kiri
    glVertex3f(260.5, -12.0, -60.0);//kiri
    glVertex3f(260.5, 3.0, -60.0);//kanan
    glEnd();
                glBegin(GL_QUADS);
    glColor3ub(128, 236,255);//jendela
    glVertex3f(260.5, 3.0, -25.0); //kanan
    glVertex3f(260.5, -12.0, -25.0);//kiri
    glVertex3f(260.5, -12.0, -40.0);//kiri
    glVertex3f(260.5, 3.0, -40.0);//kanan
    glEnd();
        //dinding depan
        glBegin(GL_QUADS);
    glColor3ub(171,149,99);
    glVertex3f(190.0, 5.0, -05.0); //kanan
    glVertex3f(190.0, -20.0, -05.0);//kiri
    glVertex3f(260.0, -20.0, -05.0);//kiri
    glVertex3f(260.0, 5.0, -05.0);//kanan
    glEnd();
                    glBegin(GL_QUADS);
    glColor3ub(242, 192,102);//warna tengah
    glVertex3f(193.0, 5.0, -04.7); //kanan
    glVertex3f(193.0, -17.0, -04.7);//kiri
    glVertex3f(257.0, -17.0, -04.7);//kiri
    glVertex3f(257.0, 5.0, -04.7);//kanan
    glEnd();
         glBegin(GL_QUADS);
        glColor3ub(128, 236,255);//jendela
    glVertex3f(205.0, 3.0, -04.5); //kanan
    glVertex3f(205.0, -12.0, -04.5);//kiri
    glVertex3f(220.0, -12.0, -04.5);//kiri
    glVertex3f(220.0, 3.0, -04.5);//kanan
    glEnd();
             glBegin(GL_QUADS);
        glColor3ub(128, 236,255);//jendela
    glVertex3f(230.0, 3.0, -04.5); //kanan
    glVertex3f(230.0, -12.0, -04.5);//kiri
    glVertex3f(245.0, -12.0, -04.5);//kiri
    glVertex3f(245.0, 3.0, -04.5);//kanan
    glEnd();

    //dinding belakang
            glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(190.0, 5.0, -80.0); //kanan
    glVertex3f(190.0, -20.0, -80.0);//kiri
    glVertex3f(260.0, -20.0, -80.0);//kiri
    glVertex3f(260.0, 5.0, -80.0);//kanan
    glEnd();

         //Jalan
    glBegin(GL_QUADS);
    glColor3ub(32,44,59);
    glVertex3f(140.0, -19.7, 120.0); //kanan
    glVertex3f(-70.0, -19.7, 120.0);//kiri
    glVertex3f(-70.0, -19.7, 80.0);//kiri
    glVertex3f(140.0, -19.7, 80.0);//kanan
    glEnd();


       glPopMatrix();
    glutSwapBuffers();


}

void idle() {
    if (!mouseDown) {
        xrot += 0.3f;
        yrot += 0.4f;
    }

    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
        mouseDown = false;
}

void mouseMotion(int x, int y) {
    if (mouseDown) {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}


void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
    case 'W':
        zmov += 3.0;
        break;
    case 'd':
    case 'D':
        xmov += 3.0;
        break;
    case 's':
    case 'S':
        zmov -= 3.0;
        break;
    case 'a':
    case 'A':
        xmov -= 3.0;
        break;
    case '7':
        ymov += 3.0;
        break;
    case '9':
        ymov -= 3.0;
        break;
    case '2':
        glRotatef(2.0, 1.0, 0.0, 0.0);
        break;
    case '8':
        glRotatef(-2.0, 1.0, 0.0, 0.0);
        break;
    case '6':
        glRotatef(2.0, 0.0, 1.0, 0.0);
        break;
    case '4':
        glRotatef(-2.0, 0.0, 1.0, 0.0);
        break;
    case '1':
        glRotatef(2.0, 0.0, 0.0, 1.0);
        break;
    case '3':
        glRotatef(-2.0, 0.0, 0.0, 1.0);
        break;
    case '5':
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    tampil();
}

void ukuran(int lebar, int tinggi)
{
    if (tinggi == 0) tinggi = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(80.0, lebar / tinggi, 5.0, 600.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}
