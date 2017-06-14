#include <iostream>
#include <GL/glut.h>
#include <cmath>

void init()
{
    glClearColor(0, 0, 0, .5);
}


void drawVeza()
{
    GLfloat x, y, xx,yy, z = 10, angle;

    //glRotatef(45, 0, 1, 1);
    glScalef(1.0, 1.0, 1);
    glLineWidth(5);
    glBegin(GL_LINES);
        for(angle = 0; angle < 36; angle += .33)
        {
            //prva spirala
            glColor3f(1.0, 0.0, 0.0);
            x = 5 * sin(angle);
            y = 5 * cos(angle);
            //druga kontra spirala
            xx = -5 * sin(angle);
            yy = -5 * cos(angle);
            z -= 1.2;
            glVertex3f(x, y, z);
            glColor3f(0.0, 1.0, 0.0);
            glVertex3f(xx, yy, z);
        }
    glEnd();
}

void drawOutline(bool state)
{
    GLfloat x, y, z = 10, angle;
    //glScalef(1.0, 1.0, 1);
    glLineWidth(5);
    glColor3f(0.0, 0.5, 0.5);
    glBegin(GL_LINE_STRIP);
    if(state == true)
    {
        for(angle = 0; angle < 36; angle += .33)
        {
            //prva spirala
            x = 5 * sin(angle);
            y = 5 * cos(angle);
            z -= 1.2;
            glVertex3f(x, y, z);
        }
    }
    else
    {
    glBegin(GL_LINE_STRIP);
        for (angle = 0; angle < 36; angle += .33)
        {
            x = - 5 * sin(angle);
            y = - 5 * cos(angle);
            z -= 1.2;
            glVertex3f(x, y, z);
        }
    }
    glEnd();
}

void scene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f (1.0, 0.0, 1.0);
    //tu nacrtati
    drawVeza();
    drawOutline(true);
    drawOutline(false);
    glFlush();
}
void keyboard(unsigned char c, int /*x*/, int /*y*/)
{
    if (c == 27)
    {
        exit(1);
    }
    else if (c == 'q')
    {
        exit(1);
    }
    else if(c == 'a')
    {

    }
}
void resize(int w, int h)
{
    glViewport (0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, (GLfloat)w/(GLfloat)h, 1, 50.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(10.0, 30.0, 0, 0.0, 0.0, 0, 0.0, 0.0, -1.0);
    glRotatef(40, 0, 0, 1);
    glTranslatef(0.0, 0.0, 30.0);
}

int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 600);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(scene);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(resize);
    glutMainLoop();
    return 0;
}
