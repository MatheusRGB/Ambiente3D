#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <GL/glut.h>

//OBJETOS
void desenharBule() {
    float kd[4] = {0.2f, 0.4f, 1.0f, 1.0f};
    float ks[4] = {0.9f, 0.9f, 0.9f, 1.0f};
    float ns = 100.0f;

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, kd);
    glMaterialfv(GL_FRONT, GL_SPECULAR, ks);
    glMaterialf(GL_FRONT, GL_SHININESS, ns);

    glutSolidTeapot(0.7);
}
void desenharBola() {
    float kd[4] = {1.0f, 0.6f, 0.0f, 1.0f};
    float ks[4] = {0.1f, 0.1f, 0.1f, 0.1f};
    float ns = 90.0f;

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, kd);
    glMaterialfv(GL_FRONT, GL_SPECULAR, ks);
    glMaterialf(GL_FRONT, GL_SHININESS, ns);

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

//ILUMINAÇÃO
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


float cam_x = -5.0;
float cam_z = 5.0;
// FUNÇÃO DE CAMERA
int init() {
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

    glEnable(GL_DEPTH_TEST);

    //SUPERFICIE OCULTA (Z-BUFFER)
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //DEFINIÇÃO DA CAMERA
    gluLookAt(cam_x, 2.0, cam_z,
            0.0, 0.0, 0.0,
            0.0, 1.0, 0.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //PERSPECTIVA
    gluPerspective(60.0, 1.0, 1.0, 50.0);

    lighting();

    glFlush();
    glutPostRedisplay();

}

void zoom_up(){
    cam_x = cam_x + 0.1;
    cam_z = cam_z - 0.1;

    glLoadIdentity();
    gluLookAt(cam_x, 2.0, cam_z,
            0.0, 0.0, 0.0,
            0.0, 1.0, 0.0);

    glutPostRedisplay();
}

void zoom_down(){
    cam_x = cam_x - 0.1;
    cam_z = cam_z + 0.1;

    glLoadIdentity();
    gluLookAt(cam_x, 2.0, cam_z,
            0.0, 0.0, 0.0,
            0.0, 1.0, 0.0);

    glutPostRedisplay();
}

void zoom(int key, int x, int y){
    switch(key){
        case GLUT_KEY_UP:
            zoom_up();
            break;

        case GLUT_KEY_DOWN:
            zoom_down();
            break;

        default:
            break;
    }
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    //OBJETOS

    //BULE
    glDisable(GL_CULL_FACE);
    glPushMatrix();
    glTranslatef(-1.9, -1.0, 0.5);
    desenharBule();
    glPopMatrix();
    glEnable(GL_CULL_FACE);

    //BOLA
    glPushMatrix();
    glTranslatef(1.0, -0.9, -1.0);
    desenharBola();
    glPopMatrix();

    //TORO
    glPushMatrix();
    glTranslatef(-0.2, -1.5, 1.6);
    glRotatef(90.0,1.0, 0.0, 0.0);
    desenharToro();
    glPopMatrix();

    //AMBIENTE

    //CHAO
    glPushMatrix();
    glTranslatef(0.0, -2.0, 0.0);
    desenhaChao();
    glPopMatrix();

    //PAREDE_ESQ
    glPushMatrix();
    glTranslatef(-0.28, -1.18, -2.7);
    glRotatef(90.0,0.0, 1.0, 0.0);
    glRotatef(90.0,0.0, 0.0, 1.0);
    desenhaParEsq();
    glPopMatrix();

    //PAREDE_DIR
    glPushMatrix();
    glTranslatef(2.4, -1.1, -0.1);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glRotatef(90.0,0.0, 0.0, 1.0);
    desenhaParDir();
    glPopMatrix();

    glFlush();
}


int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowPosition(200, 0);
   glutInitWindowSize(600, 600);
   glutCreateWindow("Formas 3D");
   init();

   glutSpecialFunc(zoom);
   glutDisplayFunc(display);

   glutMainLoop();
   return 0;
}
