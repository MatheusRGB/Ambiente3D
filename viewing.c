#include <GL/glut.h>

void desenharBule() {
    float kd[4] = {0.2f, 0.4f, 1.0f, 1.0f};
    float ks[4] = {0.9f, 0.9f, 0.9f, 1.0f};
    float ns = 100.0f;

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, kd);
    glMaterialfv(GL_FRONT, GL_SPECULAR, ks);
    glMaterialf(GL_FRONT, GL_SHININESS, ns);

    //glColor3f(0.0, 0.0, 1.0);
    glutSolidTeapot(0.7);
}
void desenharBola() {
    float kd[4] = {1.0f, 0.6f, 0.0f, 1.0f};
    float ks[4] = {0.1f, 0.1f, 0.1f, 0.1f};
    float ns = 90.0f;

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, kd);
    glMaterialfv(GL_FRONT, GL_SPECULAR, ks);
    glMaterialf(GL_FRONT, GL_SHININESS, ns);

    //glColor3f(1.0, 0.7, 0.0);
    glutSolidSphere(0.9, 100, 100);
}
void desenharToro() {
    float kd[4] = {0.0f, 1.0f, 0.2f, 1.0f};
    float ks[4] = {0.9f, 0.9f, 0.9f, 1.0f};
    float ns = 70.0f;

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, kd);
    glMaterialfv(GL_FRONT, GL_SPECULAR, ks);
    glMaterialf(GL_FRONT, GL_SHININESS, ns);

    //glColor3f(0.0, 1.0, 0.5);
    glutSolidTorus(0.2, 1.0, 30, 30);
}
void desenhaChao() {
    float kd[4] = {1.0f, 0.0f, 0.0f, 1.0f};
    float ks[4] = {0.0f, 0.0f, 0.0f, 1.0f};
    float ns = 70.0f;

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, kd);
    glMaterialfv(GL_FRONT, GL_SPECULAR, ks);
    glMaterialf(GL_FRONT, GL_SHININESS, ns);

    glScalef(5.5, 0.3, 5.5);
    glutSolidCube(1.0f);
}
void desenhaParEsq() {
    float kd[4] = {2.0f, 0.0f, 0.0f, 1.0f};
    float ks[4] = {0.7f, 0.7f, 0.7f, 1.0f};
    float ns = 70.0f;

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, kd);
    glMaterialfv(GL_FRONT, GL_SPECULAR, ks);
    glMaterialf(GL_FRONT, GL_SHININESS, ns);

    glScalef(3.5, 0.1, 10.0);
    glutSolidCube(0.5f);
}
void desenhaParDir() {
    float kd[4] = {2.0f, 0.0f, 0.0f, 1.0f};
    float ks[4] = {0.7f, 0.7f, 0.7f, 1.0f};
    float ns = 70.0f;

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, kd);
    glMaterialfv(GL_FRONT, GL_SPECULAR, ks);
    glMaterialf(GL_FRONT, GL_SHININESS, ns);

    glScalef(6.5, 0.1, 1.6);
    glutSolidCube(0.9f);
}
void lighting() {
    //FONTE DE LUZ LOCAL
    float position[4] = {5.0, 15, -3, 1.0f};
    float white[4] = {1.0f, 1.0f, 1.0f, 1.0f};
    float black[4] = {0.0f, 0.0f, 0.0f, 1.0f};

    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, black);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
    glLightfv(GL_LIGHT0, GL_SPECULAR, white);

    //ATIVA A ILUMINAÇÃO
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

// Função de exibição
int init() {
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(-5, 2, 5.0,
            0.0, 0.0, 0.0,
            0.0, 1.0, 0.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
    gluPerspective(60.0, 1.0, 1.5, 100.0);
    lighting();
    glFlush();

}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    //OBJETOS
    //BULE
    glPushMatrix();
    glTranslatef(-1.9, -0.5, 0.5);
    desenharBule();
    glPopMatrix();

    //BOLA
    glPushMatrix();
    glTranslatef(1.0, -0.9, -1.0);
    desenharBola();
    glPopMatrix();

    //TORO
    glPushMatrix();
    glTranslatef(-0.2, -1.5, 1.6);
    glRotatef(90.0,1.0, 0.0, 0.0);
    //glTranslatef(-2.5, 1.5, -1.0);
    desenharToro();
    glPopMatrix();

    //AMBIENTE
    //CHAO
    glPushMatrix();
    glTranslatef(0.0, -2.0, 0.0);
    //glRotatef(90.0,1.0, 0.1, 0.0);
    //glTranslatef(5.0, 2.0, 0.5);
    desenhaChao();
    glPopMatrix();

    //PAREDE_ESQ
    glPushMatrix();
    glTranslatef(-0.28, -1.18, -2.7);
    glRotatef(90.0,0.0, 1.0, 0.0);
    glRotatef(90.0,0.0, 0.0, 1.0);
    //glTranslatef(1.6, 0.0, -1.0);
    desenhaParEsq();
    glPopMatrix();

    //PAREDE_DIR
    glPushMatrix();
    glTranslatef(2.4, -1.1, -0.1);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glRotatef(90.0,0.0, 0.0, 1.0);
    //glRotatef(90.0,0.0, 0.0, 1.0);
    desenhaParDir();
    glPopMatrix();

    glFlush();
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowPosition(200, 0);
   glutInitWindowSize(600, 600);
   glutCreateWindow("Formas 3D");
   init();

   glutDisplayFunc(display);
   glutMainLoop();
   return 0;
}
