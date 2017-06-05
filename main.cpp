#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
//#include <SOIL/SOIL.h>
//variable para rotar
double rotate_z=0;
int width, height;  //variables para el ancho y alto
void specialKeys( int key, int x, int y )
{
    if (key == GLUT_KEY_RIGHT){


            rotate_z += 10;
    }
    if (key == GLUT_KEY_LEFT)
    {
            rotate_z -= 10;
    }  
    glutPostRedisplay();

}
void display(void)
{
    //  Borrar pantalla y Z-buffer
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    // Resetear transformaciones
    glLoadIdentity();
    //gira para en z para mover todo
    glRotatef( rotate_z, 0.0, 0.0, 1.0 );
   //lineas de orientación
    glBegin(GL_LINES);
    glColor3f(0,0,1);
    glVertex3f(1.f,0.0f,.0f);
    glVertex3f(-1.0f,0.f,-.0f);
    glColor3f(0,1,0);
    glVertex3f(0.f,-1.00f,0.0f);
    glVertex3f(-0.0f,1.f,0.0f);
    glColor3f(0,0,1);
    glVertex3f(0.f,-0.0f,-1.0f);
    glColor3f(1,0,0);
    glVertex3f(-0.0f,0.f,2.0f);
    glEnd();
    //Dibujando lineas

    glBegin(GL_POLYGON);
    glVertex3f(-6,0,0);
    glVertex3f(6,0,0);
    glVertex3f(6,-0,30);
    glVertex3f(-6,-0,30);
    glEnd();

    
       //esfera
    glPushMatrix();
    glColor3f(0.0, 1.0, 0.0);
    glScalef(0.08,0.08,0.08);
    glTranslatef(-27,5,10);
    glutSolidSphere(20,20,20);
    glPopMatrix();

     //cubo
    glPushMatrix();
    glColor3f(0.0, 1.0, 0.0);
    //glScalef(0.08,0.08,0.08);
    glTranslatef(2,0,0);
    glutSolidCube(2);
    glPopMatrix();

     //cono
    glPushMatrix();
    glColor3f(0.0, 1.0, 0.0);
    glScalef(0.08,0.08,0.08);
    glRotatef(270,1,0,0);
    glTranslatef(-30,-300,0);
    glutSolidCone(15,15,15,15);
    glPopMatrix();
    
    //torus
    glPushMatrix();
    glColor3f(0.0, 1.0, 0.0);
    glScalef(1,1,1);
    glTranslatef(2,0,10);
    glutSolidTorus(0.3, 0.6, 10, 20);
    glPopMatrix();
    
    //tetera
    glPushMatrix();
    glColor3f(0.0, 1.0, 0.0);
   glScalef(1,1,1);
    glTranslatef(2,0,17);
    glutSolidTeapot(1);
    glPopMatrix();

	//tetraedron
    glPushMatrix();
    glColor3f(0.0, 0.0, 1.0);
    glScalef(1,1,1);
    glTranslatef(-5,0,22);
    glutSolidTetrahedron();
    glPopMatrix();

	 //octahedron
    glPushMatrix();
    glColor3f(0.0, 1.0, 1.0);
   glScalef(1,1,1);
    glTranslatef(0,0,22);
    glutSolidOctahedron();
    glPopMatrix();
    
     //icosahedron
    glPushMatrix();
    glColor3f(0.0, 1.0, 0.0);
   glScalef(1,1,1);
    glTranslatef(3,0,22);
    glutSolidIcosahedron();
    glPopMatrix();
    

    //dodecaedro
    glPushMatrix();
    glColor3f(0.0, 1.0, 0.0);
    glScalef(0.8,0.8,0.8);
    glTranslatef(-2.5,0,20);
    glutSolidDodecahedron();
    glPopMatrix();
   
    glFlush();
    glutPostRedisplay();
}

void init(void)
{
	glShadeModel(GL_SMOOTH);
    //GLfloat light_position[] = { -0.50, -0.50,-1.0,0 };
   //GLfloat light_position[] = { 7, 1,40.0,1 };
    //GLfloat light_position[] = { 1, 1,1,1 };
    //GLfloat luz_ambiental[] = { 0.2, 0.2, 0.2, 10.0 };
    //glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);
  // glLightfv(GL_LIGHT0,GL_POSITION,light_position);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glPushMatrix();

}

void reshape(int w, int h)
{
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
  //por el uso de la perspectiva z positivo se encuentra para abajo
  //y a -y hacia la pantalla
	gluPerspective(40.0f, (GLfloat)h/(GLfloat)w, 0.0f, 1.0f);
    gluLookAt(0.0,5.0,40.0,0.0,2.50,5.0,0.0,1.0,0.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   
    glutInitWindowSize (800, 800);//tamaño de la ventana
    glutInitWindowPosition (300, 100);//posicion de la ventana en la pantalla
    glutCreateWindow ("Figuras");//nombre de la ventana
    init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(specialKeys);
    glutMainLoop();
    return 0;
}
