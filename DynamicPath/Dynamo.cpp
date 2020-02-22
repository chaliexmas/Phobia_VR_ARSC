/**
**Code by Carlos Natividad**
**ARSC Internship 2006**
**Mentor: Dr. Boris Bracio**
**Project: Dynamic Virtual Environment**
**/
#include <GL/glut.h>
#include <math.h>
#include "Dynamo.h"

/**Initiates GL requirements**/
Dynamo::Dynamo(void){
	//camera variables
	xPos = 0.0;
	yPos = 0.0;
	zPos = -300.0;

	y_Pos=0.0;
	x_Pos=0.0;

	//dynamic path variables
	counter1=40.1;
	counter2=40.1;
	pathsize = 1.0;
	rm_angle=(float)(pathsize + 4.0)* cos(counter1);
	rp_angle=(float)(pathsize + 4.0)* sin(counter1);
	lm_angle=rm_angle;
	lp_angle=rp_angle;
}

void Dynamo::Init(void){
	//start opengl
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glHint(GL_LINE_SMOOTH_HINT, GL_DONT_CARE);
	
	//problem: THE MORE TEXTURES ADDED THE HIGHER THE LAG

	//Texture creation
	image=new CTargaImage;
	
	//load texture image data
	image->Load("rock.tga");
	glGenTextures(2, texRock);
	glBindTexture(GL_TEXTURE_2D, texRock[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, image->GetWidth(), image->GetHeight(), GL_RGB, GL_UNSIGNED_BYTE, image->GetImage());
	image->Release();
	
	image->Load("sky.tga");
	glBindTexture(GL_TEXTURE_2D, texRock[1]);
	gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, image->GetWidth(), image->GetHeight(), GL_RGB, GL_UNSIGNED_BYTE, image->GetImage());
	image->Release();
	
	image->Load("roof.tga");
	glBindTexture(GL_TEXTURE_2D, texRock[2]);
	gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, image->GetWidth(), image->GetHeight(), GL_RGB, GL_UNSIGNED_BYTE, image->GetImage());
	image->Release();
	
	delete image;
}

/**Create fog**/
void Dynamo::Fog(){
	glEnable(GL_FOG);
	GLfloat fogColor[]= {1.0, 1.0, 1.0, 1.0};
	glFogi(GL_FOG_MODE, GL_LINEAR);
	glFogfv(GL_FOG_COLOR, fogColor);
	glFogi(GL_FOG_DENSITY, 10);
	glFogi(GL_FOG_HINT, GL_NICEST);    //pick the highest quality
	glPushMatrix();
	glFogi(GL_FOG_START, 22);          //where the fog starts in front of you
	glFogi(GL_FOG_END, 1);             //where it ends after it starts
	glPopMatrix();
}

/**Draws Main Path**/
void Dynamo::Path(){
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, texRock[0]);	
	glBegin(GL_QUADS);
	float i=0.0;
	while( i>=-400.0){
		//texture
		//set vertex and texture coordinates
		glTexCoord2f(0.0,1.0); glVertex3f(-(pathsize), -2.0f, i);
		glTexCoord2f(1.0,1.0); glVertex3f(pathsize, -2.0f, i);
		glTexCoord2f(1.0,0.0); glVertex3f(pathsize, -2.0f, (i-4.0));
		glTexCoord2f(0.0,0.0); glVertex3f(-(pathsize), -2.0f, (i-4.0));
		i-=4.0;
	}
	glEnd();
	glPopMatrix();
}

/**Build the walls**/
void Dynamo::Walls(){
	glPushMatrix();
	glDisable(GL_DEPTH_TEST);
	glBindTexture(GL_TEXTURE_2D, texRock[0]);
	glBegin(GL_QUADS);
	float i=0.0;
	while( i>=-400.0){
		//left wall
		glTexCoord2f(0.0,1.0); glVertex3f(-(pathsize), -2.0f, i);
		glTexCoord2f(1.0,1.0); glVertex3f((-lp_angle), lm_angle, i);
		glTexCoord2f(1.0,0.0); glVertex3f((-lp_angle), lm_angle, (i-4.0));
		glTexCoord2f(0.0,0.0); glVertex3f(-(pathsize), -2.0f, (i-4.0));
		//right wall
		glTexCoord2f(0.0,1.0); glVertex3f(pathsize, -2.0f, i);
		glTexCoord2f(1.0,1.0); glVertex3f((rp_angle), rm_angle, i);
		glTexCoord2f(1.0,0.0); glVertex3f((rp_angle), rm_angle, (i-4.0));
		glTexCoord2f(0.0,0.0); glVertex3f(pathsize, -2.0f, (i-4.0));
		//increase counter
		i-=4.0;
	}	
	glEnd();
	glPopMatrix();
}

/**Build the sky bounding box**/
void Dynamo::SkyBox(){
	glPushMatrix();
	float back_edge=-900.0;//z distance in the rear
	float X_edge=1100.0;//x edge size
	float Y_edge=1100.0;//y edge size
	float dist_edge=700.0;//z distance from the front
	glBindTexture(GL_TEXTURE_2D, texRock[1]);
	glBegin(GL_QUADS);
		//right wall
		glTexCoord2f(1.0,0.0); glVertex3f(-X_edge, -Y_edge, back_edge);
		glTexCoord2f(0.66,0.0); glVertex3f(-X_edge, -Y_edge, dist_edge);
		glTexCoord2f(0.66,1.0); glVertex3f(-X_edge, Y_edge, dist_edge);
		glTexCoord2f(1.0,1.0); glVertex3f(-X_edge, Y_edge, back_edge);
		//center wall
		glTexCoord2f(0.66,0.0); glVertex3f(-X_edge, -Y_edge, dist_edge);
		glTexCoord2f(0.33,0.0); glVertex3f(X_edge, -Y_edge, dist_edge);
		glTexCoord2f(0.33,1.0); glVertex3f(X_edge, Y_edge, dist_edge);
		glTexCoord2f(0.66,1.0); glVertex3f(-X_edge, Y_edge, dist_edge);
		//left wall
		glTexCoord2f(0.33,0.0); glVertex3f(X_edge, -Y_edge, dist_edge);
		glTexCoord2f(0.0,0.0); glVertex3f(X_edge, -Y_edge, back_edge);
		glTexCoord2f(0.0,1.0); glVertex3f(X_edge, Y_edge, back_edge);
		glTexCoord2f(0.33,1.0); glVertex3f(X_edge, Y_edge, dist_edge);
		//roof
		glTexCoord2f(0.5,0.7); glVertex3f(X_edge, 1090.0, dist_edge);
		glTexCoord2f(0.85,0.7); glVertex3f(-X_edge, 1090.0, dist_edge);
		glTexCoord2f(0.85,1.0); glVertex3f(-X_edge, 1090.0, back_edge);
		glTexCoord2f(0.5,1.0); glVertex3f(X_edge, 1090.0, back_edge);
		//floor
		glTexCoord2f(0.5,0.7); glVertex3f(X_edge, -1090.0, dist_edge);
		glTexCoord2f(0.85,0.7); glVertex3f(-X_edge, -1090.0, dist_edge);
		glTexCoord2f(0.85,1.0); glVertex3f(-X_edge, -1090.0, back_edge);
		glTexCoord2f(0.5,1.0); glVertex3f(X_edge, -1090.0, back_edge);
	glEnd();
	glPopMatrix();
}

/**Creates the roof**/
void Dynamo::roof(){
	glPushMatrix();
	float back_edge=-900.0;//z distance in the rear
	float dist_edge=700.0;//z distance from the front
	glBindTexture(GL_TEXTURE_2D, texRock[3]);
	glBegin(GL_QUADS);
	//floor
		glTexCoord2f(0.0,0.0); glVertex3f(1100.0, 1090.0, dist_edge);
		glTexCoord2f(1.0,0.0); glVertex3f(-1100.0, 1090.0, dist_edge);
		glTexCoord2f(1.0,1.0); glVertex3f(-1100.0, 1090.0, back_edge);
		glTexCoord2f(0.0,1.0); glVertex3f(1100.0, 1090.0, back_edge);
	glEnd();
	glPopMatrix();
}

/**Handles Camera Changes: Foward, Back, Strafes left/right, looks up/down left/right**/
void Dynamo::Camera(){
	if(zPos>-200.0){
		zPos=-300.0;
	}
	if(zPos<-400.0){
		zPos=-300.0;
	}
	gluLookAt(xPos, -0.6, zPos, x_Pos, y_Pos, 0.0, 0.0, 1.0, 0.0);
	
}

/**Directional Controls for the camera**/
void Dynamo::Directional(int x){
	switch(x){
		case 1://move foward
			zPos+=0.25;
			break;
		case 2://move backward
			zPos-=0.25;
			break;
		case 3://strafe left
			if(xPos<pathsize){ //do not get of path
				xPos+=0.5;
			}
			break;
		case 4://strafe right
			if(xPos>(-pathsize)){ //do not get of path
				xPos-=0.5;
			}
			break;
		case 5://lift right wall
			counter2+=0.1;
  			rm_angle = (float)(pathsize+4.0)* cosf(counter2);
			rp_angle = (float)(pathsize+4.0)* sinf(counter2);
			break;
		case 6://lift left wall
			counter1+=0.1;
			lm_angle = (float)(pathsize+4.0)* cosf(counter1);
			lp_angle = (float)(pathsize+4.0)* sinf(counter1);
			break;
		case 7://lower right wall
			counter2-=0.1;
			rm_angle = (float)(pathsize+4.0)* cosf(counter2);
			rp_angle = (float)(pathsize+4.0)* sinf(counter2);
			break;
		case 8://lower left wall
			counter1-=0.1;
			lm_angle = (float)(pathsize+4.0)* cosf(counter1);
			lp_angle = (float)(pathsize+4.0)* sinf(counter1);
			break;
		case 9://widen path
			if(pathsize<=8.0){ //protect against overwiddening
				pathsize+=0.1;
			}
			break;
		case 10://narrow path 
			if(pathsize>=0.3){//make sure path doesnt disapear nor inverse
				pathsize-=0.1;
			}
			break;
	}
}

/**Used to get the window size**/
void Dynamo::setWinSize(int x, int y){
	win_sizex=x;
	win_sizey=y;
}

/**Used to set mouse to camera coordinates**/
void Dynamo::setDir(int x, int y){
	y_Pos=-y+(win_sizey/2.0);
	x_Pos=-x+(win_sizex/2.0);
}
