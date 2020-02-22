/**
**Code by Carlos Natividad**
**ARSC Internship 2006**
**Mentor: Dr. Boris Bracio**
**Project: Dynamic Virtual Environment**
**/
#include <GL/glut.h>
#include <stdlib.h>
#include "Dynamo.h"

Dynamo *DY= new Dynamo;

/**Renders scene**/
void Display(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	DY->Fog();
	DY->Camera();
	DY->SkyBox();
	DY->roof();
	DY->Walls();
	DY->Path();
	
	glutSwapBuffers();
}

/**Handles window resize**/
void reshape(int w, int h){
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);			             //reset viewport to the new dimensions
	glMatrixMode(GL_PROJECTION);					                 //set projection matrix to current matrix
	glLoadIdentity();						                         //reset projection matrix
	gluPerspective(54.0f, (GLfloat)w/(GLfloat)h, 1.0f, 2000.0f);	 //calculate aspect ratio
	glMatrixMode(GL_MODELVIEW);					                     //set model view matrix
	glLoadIdentity();						                         //reset model view matrix
	DY->setWinSize(w,h);
}

/**Handles special key events**/
void SPkeydown(int key, int x, int y){
	switch(key){
		case GLUT_KEY_UP://go foward
			DY->Directional(1);
			break;
		case GLUT_KEY_DOWN://go backward
			DY->Directional(2);
			break;
		case GLUT_KEY_LEFT://strafe left
			DY->Directional(3);
			break;
		case GLUT_KEY_RIGHT://strafe right
			DY->Directional(4);
			break;
	}
	
	glutPostRedisplay();
}

/**Handles key events**/
void keydown(unsigned char key, int x, int y){
	switch(key){
		case 'A':
		case 'a'://lift right wall
			DY->Directional(5);
			break;
		case 'S':
		case 's'://lift left wall
			DY->Directional(6);
			break;
		case 'Z':
		case 'z'://lower right wall
			DY->Directional(7);
			break;
		case 'X':
		case 'x'://lower left wall
			DY->Directional(8);
			break;
		case 'D':
		case 'd'://widen path
			DY->Directional(9);
			break;
		case 'C':
		case 'c'://narrow path
			DY->Directional(10);
			break;
	}
	
	glutPostRedisplay();
}

/**Controls active mouse to camera movement**/
void processMousePassiveMotion(int x, int y) {
	DY->setDir(x, y);
	glutPostRedisplay();
}

/**Idle function**/
void idle(void){
    glutPostRedisplay();
}

/**Main Function**/
int main(int argc, char *argv[]){
    //note order matters!!
    //use this glut order, windows crashes other wise
	glutInit(&argc, argv);
	glutInitWindowSize(650, 500);
	glutInitWindowPosition(200, 100);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	
	glutCreateWindow("A Path Among the Clouds");
	
	DY->Init(); //initialize values here to avoid slow down
	
	glutReshapeFunc(reshape);
	glutDisplayFunc(Display);
	glutKeyboardFunc(keydown);
	glutIdleFunc(idle);
	
    glutSetCursor(GLUT_CURSOR_NONE);
    glutPassiveMotionFunc(processMousePassiveMotion);
	glutSpecialFunc(SPkeydown);
	
	glutMainLoop();
	
	return EXIT_SUCCESS;
}
