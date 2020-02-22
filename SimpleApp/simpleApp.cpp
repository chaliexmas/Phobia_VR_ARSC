#include <vrj/vrjConfig.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <gmtl/Matrix.h>
#include <gmtl/Generate.h>
#include <gmtl/Vec.h>
#include <simpleApp.h>

//using namespace gmtl;
//using namespace vrj;

/*Get Opengl Ready*/
void simpleApp::bufferPreDraw(){
   glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
   glClear(GL_COLOR_BUFFER_BIT); //exclusive to this function
}

/*Complete the Scene*/
void simpleApp::draw(){
   glClear(GL_DEPTH_BUFFER_BIT); // exclusive to this function
   glMatrixMode(GL_MODELVIEW);
   
   //Joystick
   joyY->updateData();
   data = joyY->getData();
   if(data>0){
   	DY->Directional(1);
   }
   if(data<0){
   	DY->Directional(2);
   }
   
   //Scene draw
   glPushMatrix();
   
   	//set initial view position
   	glTranslated(-4.0, 20.0, DY->GetzPos());
   	glRotated(180.0, 0.0, 1.0, 0.0);
   
   	//Render scene
   	DY->Fog();
   	DY->SkyBox();
   	DY->Walls();
   	DY->Path();

   glPopMatrix();
}
