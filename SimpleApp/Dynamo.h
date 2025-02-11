#ifndef DYNAMO
#define DYNAMO
#include "CTargaImage.h"
#include <vrj/Draw/OGL/GlContextData.h>

class ConData
{
public:
	ConData() { for(int ii=0;ii<4;++ii){ texRock[ii]=0; } }
	GLuint texRock[4];
};


class Dynamo{
	public:
	//textures
	vrj::GlContextData<ConData> texs;
	
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

	public:
	Dynamo(void);
	void Init(void);
	void Fog(void);
	void Display(void);
	void Path(void);
	void Walls(void);
	GLfloat GetzPos(void);
	void SkyBox(void);
	void Directional(int x);
	void roof(void);
	void setDir(float alpha, float omega, float beta);
};
#endif
