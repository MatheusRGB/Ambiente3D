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
float a = 0.0f;
void atualizaRotacao(int valor) {
    a += 1.0f;
    
    if(a > 360.0f) {
        a -= 360.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(25, atualizaRotacao, 0);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // PRIMEIRO VIEWPORT
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0, //POSIÇÃO DA CÂMERA
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
    gluLookAt(5.0, 0.0, 0.0, //POSIÇÃO DA CÂMERA
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
    gluLookAt(0.0, 5.0, 0.0, //POSIÇÃO DA CÂMERA
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
    gluLookAt(3.0, 2.0, 5.0, //POSIÇÃO DA CÂMERA
              0.0, 0.0, 0.0, //PARA ONDE A CAMERA APONTA
              0.0, 1.0, 0.0);//VETOR VIEW-UP
    glPushMatrix();
        glViewport(310, 10, 300, 300);
        glRotated(a,0,1,0);
        desenharBule();
    glPopMatrix();
    
    glutSwapBuffers();
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowPosition(200, 0);
   glutInitWindowSize(600, 600);
   glutCreateWindow("Viewport");
   init();

   glutDisplayFunc(display);
   glutTimerFunc(25, atualizaRotacao, 0);
   glutMainLoop();
   return 0;
}