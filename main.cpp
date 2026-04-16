#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <time.h>


GLfloat tx = 0.0f, ty = 0.0f;
GLfloat d  = 0.25f;

GLfloat angulo = 0.0f;
GLfloat escala = 1.0f;
GLfloat deslocX = 0.0f;
GLfloat deslocY = 0.0f;

float randomFloat(float min, float max) {
    return min + ((float)rand() / (float)RAND_MAX) * (max - min);
}

void desenhaTriangulo(void) {
    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(tx - d, ty - d, 0.0f);

        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(tx, ty + d, 0.0f);

        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(tx + d, ty - d, 0.0f);
    glEnd();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(deslocX, deslocY, 0.0f);
    glRotatef(angulo, 0.0f, 0.0f, 1.0f);
    glScalef(escala, escala, 1.0f);

    desenhaTriangulo();

    glFlush();
}

void teclado(unsigned char key, int x, int y) {
    (void)x;
    (void)y;

    switch (key) {
        case 27:
            exit(0);
            break;

        case 'r':
        case 'R':
            angulo += 180.0f;
            break;

        case 's':
        case 'S':
            escala *= 1.5f;
            break;

        case 't':
        case 'T':
            float limite;
            limite = 1.0f - (d * escala);

            if (limite < 0.0f) {
                limite = 0.0f;
            }

            deslocX = randomFloat(-limite, limite);
            deslocY = randomFloat(-limite, limite);
            break;


        case 'o':
        case 'O':
            angulo = 0.0f;
            escala = 1.0f;
            deslocX = 0.0f;
            deslocY = 0.0f;
            break;
    }

    glutPostRedisplay();
}

void inicializa(void) {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv) {
    srand((unsigned int)time(NULL));
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Pratica 3 - Transformacoes Geometricas");

    inicializa();

    glutDisplayFunc(display);
    glutKeyboardFunc(teclado);

    glutMainLoop();
    return 0;
}