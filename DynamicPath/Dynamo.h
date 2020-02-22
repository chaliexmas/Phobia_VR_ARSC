/**
**Code by Carlos Natividad**
**ARSC Internship 2006**
**Mentor: Dr. Boris Bracio**
**Project: Dynamic Virtual Environment**
**/

#ifndef DYNAMO
#define DYNAMO
#include "CTargaImage.h"

class Dynamo{
	private:
	//textures
	GLuint texRock[3];
	unsigned int texSky;
	CTargaImage *image;
	
	//camera variables
	GLfloat xPos;
	GLfloat yPos;
	GLfloat zPos;

	GLfloat y_Pos;
	GLfloat x_Pos;

	//Dynamic path variables
	float counter1;
	float counter2;
	GLfloat rm_angle;
	GLfloat rp_angle;
	GLfloat lm_angle;
	GLfloat lp_angle;
	GLfloat pathsize;

	//Mouse Directional
	int win_sizex;
	int win_sizey;

	public:
	Dynamo(void);
	void Init(void);
	void Fog(void);
	void Display(void);
	void Path(void);
	void Walls(void);
	void Camera(void);
	void SkyBox(void);
	void Directional(int x);
	void setWinSize(int x, int y);
	void setDir(int x, int y);
	void roof(void);
};
#endif
