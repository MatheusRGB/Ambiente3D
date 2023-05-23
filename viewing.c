#include <GL/glut.h>

void desenharBule() {
    float kd[4] = {0.0f, 0.0f, 1.0f, 1.0f}; 
    float ks[4] = {0.9f, 0.9f, 0.9f, 1.0f};
    float ns = 100.0f;

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, kd);
    glMaterialfv(GL_FRONT, GL_SPECULAR, ks);
    glMaterialf(GL_FRONT, GL_SHININESS, ns);

    //glColor3f(0.0, 0.0, 1.0);
    glutSolidTeapot(0.8);
}
void desenharBola() {
    float kd[4] = {1.0f, 0.7f, 0.0f, 1.0f}; 
    float ks[4] = {0.9f, 0.9f, 0.9f, 1.0f};
    float ns = 70.0f;

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, kd);
    glMaterialfv(GL_FRONT, GL_SPECULAR, ks);
    glMaterialf(GL_FRONT, GL_SHININESS, ns);

    //glColor3f(1.0, 0.7, 0.0);
    glutSolidSphere(1.5, 40, 40);
}
void desenharToroide() {
    float kd[4] = {0.0f, 1.0f, 0.5f, 1.0f}; 
    float ks[4] = {0.9f, 0.9f, 0.9f, 1.0f};
    float ns = 70.0f;

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, kd);
    glMaterialfv(GL_FRONT, GL_SPECULAR, ks);
    glMaterialf(GL_FRONT, GL_SHININESS, ns);

    //glColor3f(0.0, 1.0, 0.5);
    glutSolidTorus(0.3, 1.0, 30, 30);
}

void lighting() {
    float position[4] = {2.0f, 2.0f, 2.0f, 1.0f};
    float white[4] = {1.0f, 1.0f, 1.0f, 1.0f};
    float black[4] = {0.0f, 0.0f, 0.0f, 1.0f};

    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, black);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
    glLightfv(GL_LIGHT0, GL_SPECULAR, white);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

// Função de exibição
int init() {
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.7, 0.65, 1.0,
            0.0, 0.0, 0.0,
            0.0, 1.0, 0.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
    //gluPerspective(100.0, 1.0, 1.1, 3.0);
    lighting();
    glFlush();
    
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    desenharBule();
    //desenharBola();
    //desenharToroide();

    glFlush();
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowPosition(200, 0);
   glutInitWindowSize(500, 500);
   glutCreateWindow("Formas 3D");
   init();

   glutDisplayFunc(display);
   glutMainLoop();
   return 0;
}
