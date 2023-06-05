#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <GL/glut.h>

void desenharBule() {
    float kd[4] = {0.8f, 0.4f, 1.0f, 1.0f};
    float ks[4] = {0.9f, 0.9f, 0.9f, 1.0f};
    float ns = 100.0f;

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, kd);
    glMaterialfv(GL_FRONT, GL_SPECULAR, ks);
    glMaterialf(GL_FRONT, GL_SHININESS, ns);

    glutSolidTeapot(1.0);
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

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, 1.0, 1.5, 100.0);
    lighting();
    glFlush();

}

//ROTAÇÃO
float a = 0.0f;
void atualizaRotacao(int valor) {
    a += 1.0f;

    if(a > 360.0f) {
        a -= 360.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(25, atualizaRotacao, 0);
}

//1 View
float cam_zA = 5.0;

//2 View
float cam_xB = 5.0;

//3 View
float cam_yC = 5.0;

//4 View
float cam_xD = 3.0;
float cam_zD = 5.0;

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // PRIMEIRO VIEWPORT
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, cam_zA, //POSIÇÃO DA CÂMERA
              0.0, 0.0, 0.0, //PARA ONDE A CAMERA APONTA
              0.0, 1.0, 0.0);//VETOR VIEW-UP
    glPushMatrix();
        glViewport(10, 310, 300, 300);
        glRotated(a,0,1,0);
        desenharBule();
    glPopMatrix();

    // SEGUNDO VIEWPORT
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(cam_xB, 0.0, 0.0, //POSIÇÃO DA CÂMERA
              0.0, 0.0, 0.0, //PARA ONDE A CAMERA APONTA
              0.0, 1.0, 0.0);//VETOR VIEW-UP
    glPushMatrix();
        glViewport(310, 310, 300, 300);
        glRotated(a,0,1,0);
        desenharBule();
    glPopMatrix();

    // TERCEIRO VIEWPORT
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, cam_yC, 0.0, //POSIÇÃO DA CÂMERA
              0.0, 0.0, 0.0, //PARA ONDE A CAMERA APONTA
              0.0, 1.0, -1.0);//VETOR VIEW-UP
    glPushMatrix();
        glViewport(10, 10, 300, 300);
        glRotated(a,0,1,0);
        desenharBule();
    glPopMatrix();

    // QUARTO VIEWPORT
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(cam_xD, 2.0, cam_zD, //POSIÇÃO DA CÂMERA
              0.0, 0.0, 0.0, //PARA ONDE A CAMERA APONTA
              0.0, 1.0, 0.0);//VETOR VIEW-UP
    glPushMatrix();
        glViewport(310, 10, 300, 300);
        glRotated(a,0,1,0);
        desenharBule();
    glPopMatrix();

    glutSwapBuffers();
}

void zoom_up(){
    cam_zA = cam_zA - 0.1;
    cam_xB = cam_xB - 0.1;
    cam_yC = cam_yC - 0.1;

    cam_xD = cam_xD - 0.1;
    cam_zD = cam_zD - 0.1;

}

void zoom_down(){
    cam_zA = cam_zA + 0.1;
    cam_xB = cam_xB + 0.1;
    cam_yC = cam_yC + 0.1;

    cam_xD = cam_xD + 0.1;
    cam_zD = cam_zD + 0.1;

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

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowPosition(200, 0);
   glutInitWindowSize(600, 600);
   glutCreateWindow("Viewport");
   init();

   glutSpecialFunc(zoom);
   glutDisplayFunc(display);
   glutTimerFunc(25, atualizaRotacao, 0);
   glutMainLoop();
   return 0;
}
