#include <iostream>
#include <GL/glut.h>
#include <cmath>

const GLfloat delta = 3;
const GLfloat angleDelta = .33;
const GLfloat angleMax = 36;
const GLfloat amplitude = 5;

void init()
{
    glClearColor(0, 0, 0, .5);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
}


void drawVeza()
{
    GLfloat x, y, xx, yy, xmed, ymed, z = 10, angle;
    bool test = false;

    //glRotatef(45, 0, 1, 1);
    glLineWidth(5);
    glBegin(GL_LINES);
        for(angle = 0; angle < angleMax; angle += angleDelta)
        {
            //Simple nacin da se svaka druga oboja drugacije
            if(!test)
            {
                glColor3f(.8, 0.0, 0.0);
            }
            else
            {
                glColor3f(.8, .8, 0.0);
            }

            x = amplitude * sin(angle);
            y = amplitude * cos(angle);
            xx = -amplitude * sin(angle);
            yy = -amplitude * cos(angle);
            //median?
            xmed = (x + xx)/2.0f;
            ymed = (y + yy)/2.0f;
            z -= delta;

            //crtaj linije
            glVertex3f(x, y, z);
            glVertex3f(xmed, ymed, z);
            if(!test)
            {
                glColor3f(0.0, .8, 0.0);
                test = true;
            }
            else
            {
                glColor3f(0.0, 0.0, .8);
                test = false;
            }

            glVertex3f(xmed, ymed, z);
            glVertex3f(xx, yy, z);
        }
    glEnd();
}

void drawOutline(bool state)
{
    GLfloat x, y, z = 10, angle;
    //glScalef(1.0, 1.0, 1);
    glLineWidth(10);
    glColor3f(1, 1, 0.8);
    glBegin(GL_LINE_STRIP);
    if(state == true)
    {
        for(angle = 0; angle < angleMax; angle += angleDelta)
        {
            //prva spirala
            x = amplitude * sin(angle);
            y = amplitude * cos(angle);
            z -= delta;
            glVertex3f(x, y, z);
        }
    }
    else
    {
//        glColor3f(.5, .5, 0.0);
    glBegin(GL_LINE_STRIP);
        for (angle = 0; angle < angleMax; angle += angleDelta)
        {
            x = - amplitude * sin(angle);
            y = - amplitude * cos(angle);
            z -= delta;
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
    gluPerspective(60, (GLfloat)w/(GLfloat)h, .1, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(10.0, 70.0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0);
    glRotatef(300, 0, 0, 1);
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
