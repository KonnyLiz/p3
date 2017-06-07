//parcial3

#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <SOIL/SOIL.h>   
int width, height;  //variables para el ancho y alto

GLfloat plano_s[4] = {1, 0, 0, 0};// s=x
GLfloat plano_v[4] = {0, 1, 0, 0};// v=y
GLuint texture[0];

void tex(void){
 texture[0] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
      (
          "6.bmp", //se carga la imagen
          SOIL_LOAD_AUTO,
          SOIL_CREATE_NEW_ID,
          SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
      );
      glEnable(GL_TEXTURE_2D);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
      // allocate a texture name
      glBindTexture(GL_TEXTURE_2D, texture[0]);
    
    glBegin(GL_POLYGON);
    //glColor4f(0.77, 0.78, 0.78, 0.5); //iron
    glTexCoord2f(10,10);
    glVertex3f(-6,0,0);
    glTexCoord2f(0,10);
    glVertex3f(6,0,0);
    glTexCoord2f(10,0);
    glVertex3f(6,-0,30);
    glTexCoord2f(0,0);
    glVertex3f(-6,-0,30);
    glEnd();
      
}

void display(void)
{
    //  Borrar pantalla y Z-buffer
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    // Resetear transformaciones
    glLoadIdentity();

    //Dibujando piso
   tex();
   
    //esfera 
    glPushMatrix();
    glColor4f(0,0,0,1);
    glScalef(0.08,0.08,0.08);
    glTranslatef(-30,5,10);
    glutSolidSphere(20,20,20);
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(1.0, 0.86, 0.57);//gold
    glScalef(0.08,0.08,0.08);
    glTranslatef(-27,5,10);
    glutSolidSphere(20,20,20);
    glPopMatrix();

     //cubo
    glPushMatrix();
    glColor4f(0,0,0,0.5);
    glTranslatef(1.5,0,0);
    glutSolidCube(2);
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0.98, 0.82, 0.76); //cooper
    glTranslatef(2,0,0);
    glutSolidCube(2);
    glPopMatrix();

     //cono
    glPushMatrix();
    glColor4f(0.0, 0.0, 0,0.5);
    glScalef(0.08,0.08,0.08);
    glRotatef(270,1,0,0);
    glTranslatef(-33,-300,0);
    glutSolidCone(15,15,15,15);
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0.0, 1.0, 1.0); //blue
    glScalef(0.08,0.08,0.08);
    glRotatef(270,1,0,0);
    glTranslatef(-30,-300,0);
    glutSolidCone(15,15,15,15);
    glPopMatrix();
    
    //torus
    glPushMatrix();
    glColor4f(0,0,0,0.5);
    glScalef(1,1,1);
    glTranslatef(1.7,0,10);
    glutSolidTorus(0.3, 0.6, 10, 20);
    glPopMatrix();
    
    glPushMatrix();
    glColor4f(0,1,0,1);//green
    glScalef(1,1,1);
    glTranslatef(2,0,10);
    glutSolidTorus(0.3, 0.6, 10, 20);
    glPopMatrix();
    
    //tetera
    glPushMatrix();
    glColor4f(0,0,0,0.5);
    glScalef(1,1,1);
    glTranslatef(1.7,0,17);
    glutSolidTeapot(1);
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(1,0,0);//rojo
    glScalef(1,1,1);
    glTranslatef(2,0,17);
    glutSolidTeapot(1);
    glPopMatrix();

	//tetraedron
    glPushMatrix();
    glColor4f(0,0,0,0.5);
    glScalef(0,0,0);
    glTranslatef(-5.5,0,22);
    glutSolidTetrahedron();
    glPopMatrix();
    
    glPushMatrix();
    glColor4f(1,1,0,1);//yellow
    glScalef(1,1,1);
    glTranslatef(-5,0,22);
    glutSolidTetrahedron();
    glPopMatrix();

	 //octahedron
    glPushMatrix();
    glColor4f(0,0,0,0.5);
    glScalef(1,1,1);
    glTranslatef(-0.3,0,22);
    glutSolidOctahedron();
    glPopMatrix();
    
    glPushMatrix();
    glColor4f(0,1,1,1);//cyan
    glScalef(1,1,1);
    glTranslatef(0,0,22);
    glutSolidOctahedron();
    glPopMatrix();
    
     //icosahedron
    glPushMatrix();
    glColor4f(0,0,0,0.5);
   glScalef(1,1,1);
    glTranslatef(2.8,0,22);
    glutSolidIcosahedron();
    glPopMatrix();
    
glPushMatrix();
    glColor4f(1,0,1,1);//magenta
   glScalef(1,1,1);
    glTranslatef(3,0,22);
    glutSolidIcosahedron();
    glPopMatrix();
    
    //dodecaedro
    glPushMatrix();
    glColor4f(0,0,0,0.5);
    glScalef(0.8,0.8,0.8);
    glTranslatef(-3,0,20);
    glutSolidDodecahedron();
    glPopMatrix();
    
    glPushMatrix();
    glColor4f(1,1,1,1);//white
    glScalef(0.8,0.8,0.8);
    glTranslatef(-2.5,0,20);
    glutSolidDodecahedron();
    glPopMatrix();
   
    glFlush();
    glutPostRedisplay();
}

void init(void)
{
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);
    glPushMatrix();
}

void reshape(int w, int h)
{
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
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
    glutCreateWindow ("Figuras parcial3");//nombre de la ventana
    init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
