#include "pch.h"
#include <gl/glut.h>
#include <gl/GLAUX.H>
#include <gl/GLU.h>
#include <math.h>

GLfloat xRotated, yRotated, zRotated;
GLdouble size = 1.0;
GLuint g_box;                          
GLuint texture;                       
char texture_name[100] = { "dice.bmp" };

void display();
//AUX_RGBImageRec *LoadBMP(char *Filename)
//{
//	FILE *File = NULL;
//	if (!Filename)
//		return NULL;
//	fopen_s(&File, Filename, "r");
//	if (File)
//	{
//		fclose(File);
//		return auxDIBImageLoadA((LPCSTR)Filename);
//	}
//	return NULL;
//}
//
//bool LoadGLTextures()
//{
//	int ret = false;
//	AUX_RGBImageRec *texture_image = NULL;
//	if (texture_image = LoadBMP(texture_name))
//	{
//		glGenTextures(1, &texture);
//		glBindTexture(GL_TEXTURE_2D, texture);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//		glTexImage2D(GL_TEXTURE_2D, 0, 3, texture_image->sizeX,
//			texture_image->sizeY, 0, GL_RGB,
//			GL_UNSIGNED_BYTE, texture_image->data);
//	}
//	else
//	{
//		ret = false;
//		if (texture_image)
//		{
//			if (texture_image->data)
//				free(texture_image->data);
//			free(texture_image);
//		}
//	}
//	return ret;
//}


void idle()
{
	xRotated = xRotated + 0.01;
	yRotated += 0.01;
	zRotated += 0.01;
	display();
}

void myinit()
{
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	//LoadGLTextures();
}

void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);
	glColor3f(0.9, 0.3, 0.2);
	glRotatef(xRotated, 1.0, 0.0, 0.0);
	glRotatef(yRotated, 0.0, 1.0, 0.0);
	glRotatef(zRotated, 0.0, 0.0, 1.0);
	glScalef(1.0, 1.0, 1.0);
	glutSolidCube(size);
	glFlush();
}

void myReshape(GLsizei w, GLsizei h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-1.5, 1.5, -1.5*(GLfloat)480 / (GLfloat)640,
		1.5*(GLfloat)480 / (GLfloat)640, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(200, 200);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	xRotated = yRotated = zRotated = 30.0;
	xRotated = 43;
	yRotated = 50;
	glutCreateWindow("CUBE_LIGHT");
	glutDisplayFunc(display);
	glutReshapeFunc(myReshape);
	myinit();
	glutIdleFunc(idle);
	glutMainLoop();
	return 1;
}
