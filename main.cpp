#include "initShaders.h"
#include "paint.h"

using namespace std;
int mouse_down_x;
int mouse_down_y;
int score = 0;
double seconds;
int level = 0;
int selection = 0;
paint diamond;
paint diamondtwo;
paint cube;
paint diamondthree;
int animationover = 0;
bool levelover = false;
GLfloat normal=1.0f/sqrt(3.0f);

int num = 1;

//timer
time_t timer;

void diamond1(){

GLfloat vert[]={
	0.0f,20.0f,0.0f,
	0.0f,-20.0f,0.0f,
	0.0f,0.0f,6.0f,
	0.0f,0.0f,-6.0f,	
	4.0f,0.0f,0.0f,
	-4.0f,0.0f,0.0f
					};

GLfloat norms[]={
	0.0f,normal,0.0f,
	0.0f,-normal,0.0f,
	0.0f,0.0f,normal,
	0.0f,0.0f,-normal,
	normal,0.0f,0.0f,
	-normal,0.0f,0.0f
};

GLfloat color[]={
	1.0f,1.0f,1.0f,1.0f,
	1.0f,1.0f,1.0f,1.0f,
	1.0f,1.0f,1.0f,1.0f,
	1.0f,1.0f,1.0f,1.0f,
	1.0f,1.0f,1.0f,1.0f,
	1.0f,1.0f,1.0f,1.0f						
	              		};

GLfloat text[] = { 1.0f, 1.0f,
	1.0f, 0.0f,
	1.0f, 0.0f,
	1.0f, 0.0f,
	1.0f, 0.0f,
	1.0f, 0.0f };

											
 GLubyte elems[]={
	1,2,4,
	1,5,2,
	1,3,5,
	1,4,3,
	0,2,4,
	0,5,2,
	0,3,5,
	0,4,3
			};
	diamond.speed = 0.4;
	diamond.vertsize = sizeof(vert);
	diamond.colorsize = sizeof(color);
	diamond.elemssize = sizeof(elems);
	diamond.textsize = sizeof(text);
	diamond.normssize = sizeof(norms);
	diamond.move = 0;
	diamond.vertarray = (GLfloat*)malloc(sizeof(GLfloat)*diamond.vertsize);
	diamond.colorarray = (GLfloat*)malloc(sizeof(GLfloat)*diamond.colorsize);
	diamond.elemsarray = (GLubyte*)malloc(sizeof(GLfloat)*diamond.elemssize);
	diamond.textarray = (GLfloat*)malloc(sizeof(GLfloat)*diamond.textsize);
	diamond.norms = (GLfloat*)malloc(sizeof(GLfloat)*diamond.normssize);
	memcpy(diamond.vertarray, vert, 4*diamond.vertsize);
	memcpy(diamond.colorarray, color, 4*diamond.colorsize);
	memcpy(diamond.textarray, text, 4*diamond.textsize);
	memcpy(diamond.norms, norms, 4*diamond.normssize);
	memcpy(diamond.elemsarray, elems, diamond.elemssize);

	//buffers
	glGenBuffers(4, diamond.vboID);
	glGenBuffers(1, &diamond.eboID);
	glGenTextures(1, &diamond.texture_id[0]);
  	glGenBuffers(1, &diamond.vbo_cube_texcoords);
 
	

	diamond.objTran.y = 0.0;
	diamond.objTran.x = -20.0;
	diamond.objTran.z = 0.0;
}

void diamond2(){

GLfloat vert[]={
	0.0f,20.0f,0.0f,
	0.0f,-20.0f,0.0f,
	0.0f,0.0f,6.0f,
	0.0f,0.0f,-6.0f,	
	4.0f,0.0f,0.0f,
	-4.0f,0.0f,0.0f
					};


GLfloat norms[]={
	0.0f,normal,0.0f,
	0.0f,-normal,0.0f,
	0.0f,0.0f,normal,
	0.0f,0.0f,-normal,
	normal,0.0f,0.0f,
	-normal,0.0f,0.0f
};
GLfloat color[]={
	1.0f,1.0f,1.0f,1.0f,
	1.0f,1.0f,1.0f,1.0f,
	1.0f,1.0f,1.0f,1.0f,
	1.0f,1.0f,1.0f,1.0f,
	1.0f,1.0f,1.0f,1.0f,
	1.0f,1.0f,1.0f,1.0f						
	              		};

GLfloat text[] = { 1.0f, 1.0f,
	1.0f, 0.0f,
	1.0f, 0.0f,
	1.0f, 0.0f,
	1.0f, 0.0f,
	1.0f, 0.0f };

											
 GLubyte elems[]={
	1,2,4,
	1,5,2,
	1,3,5,
	1,4,3,
	0,2,4,
	0,5,2,
	0,3,5,
	0,4,3
			};
	diamondtwo.speed = 0.3;
	diamondtwo.vertsize = sizeof(vert);
	diamondtwo.colorsize = sizeof(color);
	diamondtwo.elemssize = sizeof(elems);
	diamondtwo.textsize = sizeof(text);
	diamondtwo.normssize = sizeof(norms);
	diamondtwo.move = 0;
	diamondtwo.vertarray = (GLfloat*)malloc(sizeof(GLfloat)*diamondtwo.vertsize);
	diamondtwo.colorarray = (GLfloat*)malloc(sizeof(GLfloat)*diamondtwo.colorsize);
	diamondtwo.elemsarray = (GLubyte*)malloc(sizeof(GLfloat)*diamondtwo.elemssize);
	diamondtwo.textarray = (GLfloat*)malloc(sizeof(GLfloat)*diamondtwo.textsize);
	diamondtwo.norms = (GLfloat*)malloc(sizeof(GLfloat)*diamondtwo.normssize);
	memcpy(diamondtwo.vertarray, vert, 4*diamondtwo.vertsize);
	memcpy(diamondtwo.colorarray, color, 4*diamondtwo.colorsize);
	memcpy(diamondtwo.textarray, text, 4*diamondtwo.textsize);
	memcpy(diamondtwo.norms, norms, 4*diamondtwo.normssize);
	memcpy(diamondtwo.elemsarray, elems, diamondtwo.elemssize);

	//buffers
	glGenBuffers(4, diamondtwo.vboID);
	glGenBuffers(1, &diamondtwo.eboID);
	glGenTextures(1, &diamondtwo.texture_id[1]);
  	glGenBuffers(1, &diamondtwo.vbo_cube_texcoords);

	diamondtwo.objTran.y = 0.0;
	diamondtwo.objTran.x = -5.0;
	diamondtwo.objTran.z = -10.0;
}

void diamond3(){

GLfloat vert[]={
	0.0f,20.0f,0.0f,
	0.0f,-20.0f,0.0f,
	0.0f,0.0f,6.0f,
	0.0f,0.0f,-6.0f,	
	4.0f,0.0f,0.0f,
	-4.0f,0.0f,0.0f
					};

GLfloat norms[]={
	0.0f,normal,0.0f,
	0.0f,-normal,0.0f,
	0.0f,0.0f,normal,
	0.0f,0.0f,-normal,
	normal,0.0f,0.0f,
	-normal,0.0f,0.0f
};

GLfloat color[]={
	1.0f,1.0f,1.0f,1.0f,
	1.0f,1.0f,1.0f,1.0f,
	1.0f,1.0f,1.0f,1.0f,
	1.0f,1.0f,1.0f,1.0f,
	1.0f,1.0f,1.0f,1.0f,
	1.0f,1.0f,1.0f,1.0f						
	              		};

GLfloat text[] = { 1.0f, 1.0f,
	1.0f, 0.0f,
	1.0f, 0.0f,
	1.0f, 0.0f,
	1.0f, 0.0f,
	1.0f, 0.0f };

											
 GLubyte elems[]={
	1,2,4,
	1,5,2,
	1,3,5,
	1,4,3,
	0,2,4,
	0,5,2,
	0,3,5,
	0,4,3
			};
	diamondthree.speed = 0.3;
	diamondthree.vertsize = sizeof(vert);
	diamondthree.colorsize = sizeof(color);
	diamondthree.elemssize = sizeof(elems);
	diamondthree.textsize = sizeof(text);
	diamondthree.normssize = sizeof(norms);
	diamondthree.move = 0;
	diamondthree.vertarray = (GLfloat*)malloc(sizeof(GLfloat)*diamondthree.vertsize);
	diamondthree.colorarray = (GLfloat*)malloc(sizeof(GLfloat)*diamondthree.colorsize);
	diamondthree.elemsarray = (GLubyte*)malloc(sizeof(GLfloat)*diamondthree.elemssize);
	diamondthree.textarray = (GLfloat*)malloc(sizeof(GLfloat)*diamondthree.textsize);
	diamondthree.norms = (GLfloat*)malloc(sizeof(GLfloat)*diamondthree.normssize);
	memcpy(diamondthree.vertarray, vert, 4*diamondthree.vertsize);
	memcpy(diamondthree.colorarray, color, 4*diamondthree.colorsize);
	memcpy(diamondthree.textarray, text, 4*diamondthree.textsize);
	memcpy(diamondthree.norms, norms, 4*diamondthree.normssize);
	memcpy(diamondthree.elemsarray, elems, diamondthree.elemssize);

	//buffers
	glGenBuffers(4, diamondthree.vboID);
	glGenBuffers(1, &diamondthree.eboID);
	glGenTextures(1, &diamondthree.texture_id[2]);
  	glGenBuffers(1, &diamondthree.vbo_cube_texcoords);
 

	diamondthree.objTran.y = 0.0;
	diamondthree.objTran.x = 10.0;
	diamondthree.objTran.z = 0.0;
}

void cube1(){
GLfloat vert[]={
	-1.5f,1.5f,1.5f,
	-1.5f,-1.5f,1.5f,
	1.5f,-1.5f,1.5f,
	1.5f,1.5f,1.5f,	
	-1.5f,1.5f,-1.5f,
	-1.5f,-1.5f,-1.5f,
	1.5f,-1.5f,-1.5f,
	1.5f,1.5f,-1.5f
					};

GLfloat norms[]={
	-normal,normal,normal,
	-normal,-normal,normal,
	normal,-normal,normal,
	normal,normal,normal,
	-normal,normal,-normal,
	-normal,-normal,-normal,
	normal,-normal,-normal,
	normal,normal,-normal
};

GLfloat color[]={
	1.0f,1.0f,1.0f,1.0f,
	1.0f,1.0f,1.0f,1.0f,
	1.0f,1.0f,1.0f,1.0f,
	1.0f,1.0f,1.0f,1.0f,
	1.0f,1.0f,1.0f,1.0f,
	1.0f,1.0f,1.0f,1.0f,
	1.0f,1.0f,1.0f,1.0f,
	1.0f,1.0f,1.0f,1.0f						
	              		};
GLfloat text[] = { 1.0f, 1.0f,
	1.0f, 0.0f,
	1.0f, 0.5f,
	1.0f, 0.5f,
	1.0f, 0.5f,
	1.0f, 0.5f };
											
GLubyte elems[]={
	7,6,5,4,
	7,3,0,4,
	7,6,2,3,
	7,4,0,1,
	5,4,5,2,
	1,5,6,2,
	1,5,6,2,
	3,0,1,3,
	2,1,0,3
			};
	
	cube.speed = 0.3;

	cube.vertsize = sizeof(vert);
	cube.colorsize = sizeof(color);
	cube.elemssize = sizeof(elems);
	cube.textsize = sizeof(text);
	cube.normssize = sizeof(norms);
	cube.move = 0;
	cube.vertarray = (GLfloat*)malloc(sizeof(GLfloat)*cube.vertsize);
	cube.colorarray = (GLfloat*)malloc(sizeof(GLfloat)*cube.colorsize);
	cube.elemsarray = (GLubyte*)malloc(sizeof(GLfloat)*cube.elemssize);
	cube.textarray = (GLfloat*)malloc(sizeof(GLfloat)*cube.textsize);
	cube.norms = (GLfloat*)malloc(sizeof(GLfloat)*cube.normssize);
	memcpy(cube.vertarray, vert, 4*cube.vertsize);
	memcpy(cube.colorarray, color, 4*cube.colorsize);
	memcpy(cube.textarray, text, 4*cube.textsize);
	memcpy(cube.norms, norms, 4*cube.normssize);
	memcpy(cube.elemsarray, elems, cube.elemssize);
	
	//buffers
	glGenBuffers(4, cube.vboID);
	glGenBuffers(1, &cube.eboID);

	glGenTextures(1, &cube.texture_id[3]);
  	glGenBuffers(1, &cube.vbo_cube_texcoords);
	
	cube.objTran.y = -20.0;
	cube.objTran.x = -5.0;
	cube.objTran.z = 10.0;
}

void animation1(){
	if(num == 1){
		if(diamond.objTran.x <= 20.0){
			diamond.objTran.x += diamond.speed;
		}
		else{
			num = 2;
		}
		if(diamond.objTran.z >= -10.0){
			diamond.objTran.z -= diamond.speed;

		}
		if(diamondtwo.objTran.z <= 3.0){
			diamondtwo.objTran.z += diamond.speed;
		}
		if(diamondthree.objTran.x >= -10.0){
			diamondthree.objTran.x -= diamond.speed;
		}
	}
	if(num == 2){
		if(diamond.objTran.x >= -6.0){
			diamond.objTran.x -= diamond.speed;
		}
		if(diamond.objTran.z <= 2.0){
			diamond.objTran.z += diamond.speed;
		}
		if(diamondtwo.objTran.x <= 12.0){
			diamondtwo.objTran.x += diamond.speed;
		}
		else{
			num = 3;
		}
		if(diamondtwo.objTran.z <= 2.0){
			diamondtwo.objTran.z += diamond.speed;
		}
		if(diamondthree.objTran.x <= -7.0){
			diamondthree.objTran.x += diamond.speed;
		}
		if(diamondthree.objTran.z <= 4.0){
			diamondthree.objTran.z += diamond.speed;
		}
	}
	if(num == 3){
		if(diamond.objTran.x >= -20.0){
			diamond.objTran.x -= diamond.speed;
		}
		if(diamondtwo.objTran.x >= -5.0){
			diamondtwo.objTran.x -= diamond.speed;
		}
		if(diamondtwo.objTran.z >= -15.0){
			diamondtwo.objTran.z -= diamond.speed;
		}
		else{
			num = 4;
		}		
		if(diamondthree.objTran.x <= 0.0){
			diamondthree.objTran.x += diamond.speed;
		}
		if(diamondthree.objTran.z <= -3.0){
			diamondthree.objTran.z += diamond.speed;
		}
	}
	if(num == 4){
		if(diamond.objTran.x <= 15.0){
			diamond.objTran.x += diamond.speed;
		}
		else{
			num = 5;
		}
		if(diamond.objTran.z <= 7.0){
			diamond.objTran.z += diamond.speed;
		}
		if(diamondtwo.objTran.x <= 2.0){
			diamondtwo.objTran.x += diamond.speed;
		}
		if(diamondtwo.objTran.z >= -20.0){
			diamondtwo.objTran.z -= diamond.speed;
		}		
		if(diamondthree.objTran.x >= -16.0){
			diamondthree.objTran.x -= diamond.speed;
		}
		if(diamondthree.objTran.z <= 10.0){
			diamondthree.objTran.z += diamond.speed;
		}
	}
	if(num == 5){
		if(diamond.objTran.x >= 6.0){
			diamond.objTran.x -= diamond.speed;
		}
		if(diamond.objTran.z >= -12.0){
			diamond.objTran.z -= diamond.speed;
		}
		if(diamondtwo.objTran.x <= 20.0){
			diamondtwo.objTran.x += diamond.speed;
		}
		else{
			num = 6;
		}
		if(diamondtwo.objTran.z <= -3.0){
			diamondtwo.objTran.z += diamond.speed;
		}
		if(diamondthree.objTran.x >= -23.0){
			diamondthree.objTran.x -= diamond.speed;
		}
		if(diamondthree.objTran.z >= 0.0){
			diamondthree.objTran.z -= diamond.speed;
		}
	}
	if(num == 6){
		if(diamond.objTran.x >= -3.0){
			diamond.objTran.x -= diamond.speed;
		}
		if(diamond.objTran.z <= -4.0){
			diamond.objTran.z += diamond.speed;
		}
		if(diamondtwo.objTran.x >= -7.0){
			diamondtwo.objTran.x -= diamond.speed;
		}
		if(diamondtwo.objTran.z <= 0.0){
			diamondtwo.objTran.z += diamond.speed;
		}
		if(diamondthree.objTran.x <= 18.0){
			diamondthree.objTran.x += diamond.speed;
		}
		else{
			num = 7;
		}
	}
	if(num == 7){
		if(diamond.objTran.x >= -35.0){
			diamond.objTran.x -= diamond.speed;
		}
		else{
			num = 8;
		}
		if(diamond.objTran.z <= 7.0){
			diamond.objTran.z += diamond.speed;
		}
		if(diamondtwo.objTran.x >= -10.0){
			diamondtwo.objTran.x -= diamond.speed;
		}
		if(diamondtwo.objTran.z <= 3.0){
			diamondtwo.objTran.z += diamond.speed;
		}
		if(diamondthree.objTran.x >= -5.0){
			diamondthree.objTran.x -= diamond.speed;
		}
		if(diamondthree.objTran.z <= 3.0){
			diamondthree.objTran.z += diamond.speed;
		}
	}
	if(num == 8){
		if(diamond.objTran.z >= -14.0){
			diamond.objTran.z -= diamond.speed;
		}
		if(diamondtwo.objTran.x <= 22.0){
			diamondtwo.objTran.x += diamond.speed;
		}
		else{
			num = 9;
		}
		if(diamondtwo.objTran.z >= 0.0){
			diamondtwo.objTran.z -= diamond.speed;
		}
		if(diamondthree.objTran.x <= -3.0){
			diamondthree.objTran.x += diamond.speed;
		}
	}
	if(num == 9){
		if(diamond.objTran.x <= -5.0){
			diamond.objTran.x += diamond.speed;
		}
		else{
			seconds = difftime(time(NULL), timer);
			animationover = 1;
		}
		if(diamond.objTran.z <= -10.0){
			diamond.objTran.z += diamond.speed;
		}
		if(diamondtwo.objTran.x >= 10.0){
			diamondtwo.objTran.x -= diamond.speed;
		}
		if(diamondthree.objTran.x >= -20.0){
			diamondthree.objTran.x -= diamond.speed;
		}
		if(diamondthree.objTran.z >= 0.0){
			diamondthree.objTran.z -= diamond.speed;
		}	
	}
	if(animationover == 1){
		if(selection == 2){
			printf("Congratulations! You got it right!");
			animationover = 0;
			selection = -1;
		}
		else if((selection == 1) || (selection == 3)){
			printf("Sorry! It was under block 2!");
			animationover = 0;
			selection = -1;
		}
	}
}

void animation2(){
	if(num == 1){
		if(diamond.objTran.x <= 21.0){
			diamond.objTran.x += diamond.speed + 0.02;
		}
		else{
			num = 2;
		}
		if(diamond.objTran.z >= -3.0){
			diamond.objTran.z -= diamond.speed + 0.02;
		}
		if(diamondtwo.objTran.x >= -18.0){
			diamondtwo.objTran.x -= diamond.speed + 0.02;
		}
		if(diamondtwo.objTran.z <= 4.0){
			diamondtwo.objTran.z += diamond.speed + 0.02;
		}
		if(diamondthree.objTran.x >= -7.0){
			diamondthree.objTran.x -= diamond.speed + 0.02;
		}	
	}
	if(num == 2){
		if(diamond.objTran.x >= -3.0){
			diamond.objTran.x -= diamond.speed + 0.02;
		}
		if(diamond.objTran.z <= 10.0){
			diamond.objTran.z += diamond.speed + 0.02;
		}
		if(diamondtwo.objTran.x <= -35.0){
			diamondtwo.objTran.x += diamond.speed + 0.02;
		}
		else{
			num = 3;
		}
		if(diamondtwo.objTran.z >= 0.0){
			diamondtwo.objTran.z -= diamond.speed + 0.02;
		}
		if(diamondthree.objTran.x >= -18.0){
			diamondthree.objTran.x -= diamond.speed + 0.02;
		}
		if(diamondthree.objTran.z <= 5.0){
			diamondthree.objTran.z += diamond.speed + 0.02;
		}
	}
	if(num == 3){
		if(diamond.objTran.x <= 14.0){
			diamond.objTran.x += diamond.speed + 0.04;
		}
		if(diamond.objTran.z >= 5.0){
			diamond.objTran.z -= diamond.speed + 0.04;
		}
		if(diamondtwo.objTran.x >= 0.0){
			diamondtwo.objTran.x -= diamond.speed + 0.04;
		}
		if(diamondtwo.objTran.z >= -13.0){
			diamondtwo.objTran.z -= diamond.speed + 0.04;
		}
		if(diamondthree.objTran.x <= 20.0){
			diamondthree.objTran.x += diamond.speed + 0.04;
		}
		else{
			num = 4;
		}
		if(diamondthree.objTran.z >= 2.0){
			diamondthree.objTran.z -= diamond.speed + 0.04;
		}
	}
	if(num == 4){
		if(diamond.objTran.x >= -31.0){
			diamond.objTran.x -= diamond.speed + 0.04;
		}
		else{
			num = 5;
		}
		if(diamond.objTran.z >= -1.0){
			diamond.objTran.z -= diamond.speed + 0.04;
		}
		if(diamondtwo.objTran.x >= -3.0){
			diamondtwo.objTran.x -= diamond.speed + 0.04;
		}
		if(diamondtwo.objTran.z <= 8.0){
			diamondtwo.objTran.z += diamond.speed + 0.04;
		}
		if(diamondthree.objTran.x >= -7.0){
			diamondthree.objTran.x -= diamond.speed + 0.04;
		}
	}
	if(num == 5){
		if(diamond.objTran.x <= 22.0){
			diamond.objTran.x += diamond.speed + 0.06;
		}
		else{
			num = 6;
		}
		if(diamondtwo.objTran.x <= 7.0){
			diamondtwo.objTran.x += diamond.speed + 0.06;
		}
		if(diamondtwo.objTran.z >= 5.0){
			diamondtwo.objTran.z -= diamond.speed + 0.06;
		}
		if(diamondthree.objTran.x >= -5.0){
			diamondthree.objTran.x -= diamond.speed + 0.06;
		}
		if(diamondthree.objTran.z <= 8.0){
			diamondthree.objTran.z += diamond.speed + 0.06;
		}
	}
	if(num == 6){
		if(diamond.objTran.x <= -16.0){
			diamond.objTran.x += diamond.speed + 0.06;
		}
		else{
			num = 7;
		}
		if(diamond.objTran.z >= -12.0){
			diamond.objTran.z -= diamond.speed + 0.06;
		}
		if(diamondtwo.objTran.x <= 19.0){
			diamondtwo.objTran.x += diamond.speed + 0.06;
		}
		if(diamondtwo.objTran.z >= -3.0){
			diamondtwo.objTran.z -= diamond.speed + 0.06;
		}
		if(diamondthree.objTran.x >= -33.0){
			diamondthree.objTran.x -= diamond.speed + 0.06;
		}
		if(diamondthree.objTran.z >= 0.0){
			diamondthree.objTran.z -= diamond.speed + 0.06;
		}
	}
	if(num == 7){
		if(diamond.objTran.x >= -3.0){
			diamond.objTran.x -= diamond.speed + 0.08;
		}
		if(diamond.objTran.z <= -4.0){
			diamond.objTran.z += diamond.speed + 0.08;
		}
		if(diamondtwo.objTran.x >= -7.0){
			diamondtwo.objTran.x -= diamond.speed + 0.08;
		}
		if(diamondtwo.objTran.z <= 0.0){
			diamondtwo.objTran.z += diamond.speed + 0.08;
		}
		if(diamondthree.objTran.x <= 16.0){
			diamondthree.objTran.x += diamond.speed + 0.08;
		}
		else{
			num = 8;
		}
	}
	if(num == 8){
		if(diamond.objTran.x <= 12.0){
			diamond.objTran.x += diamond.speed + 0.08;
		}
		else{
			num = 9;
		}
		if(diamond.objTran.z <= 7.0){
			diamond.objTran.z += diamond.speed + 0.08;
		}
		if(diamondtwo.objTran.x >= -10.0){
			diamondtwo.objTran.x -= diamond.speed + 0.08;
		}
		if(diamondtwo.objTran.z <= 3.0){
			diamondtwo.objTran.z += diamond.speed + 0.08;
		}
		if(diamondthree.objTran.x >= -5.0){
			diamondthree.objTran.x -= diamond.speed + 0.08;
		}
		if(diamondthree.objTran.z <= 3.0){
			diamondthree.objTran.z += diamond.speed + 0.08;
		}
	}
	if(num == 9){
		if(diamond.objTran.z >= -14.0){
			diamond.objTran.z -= diamond.speed + 0.1;
		}
		if(diamondtwo.objTran.x <= 20.0){
			diamondtwo.objTran.x += diamond.speed + 0.1;
		}
		else{
			num = 10;
		}
		if(diamondtwo.objTran.z >= 0.0){
			diamondtwo.objTran.z -= diamond.speed + 0.1;
		}
		if(diamondthree.objTran.x <= -3.0){
			diamondthree.objTran.x += diamond.speed + 0.1;
		}
	}
	if(num == 10){
		if(diamond.objTran.x <= 7.0){
			diamond.objTran.x += diamond.speed + 0.1;
		}
		if(diamond.objTran.z >= -3.0){
			diamond.objTran.z -= diamond.speed + 0.1;
		}
		if(diamondtwo.objTran.x >= -28.0){
			diamondtwo.objTran.x -= diamond.speed + 0.1;
		}
		else{
			num = 11;
		}
		if(diamondtwo.objTran.z <= 4.0){
			diamondtwo.objTran.z += diamond.speed + 0.1;
		}
		if(diamondthree.objTran.x >= -7.0){
			diamondthree.objTran.x -= diamond.speed + 0.1;
		}	
	}
	if(num == 11){
		if(diamond.objTran.x >= -3.0){
			diamond.objTran.x -= diamond.speed + 0.12;
		}
		if(diamond.objTran.z <= 10.0){
			diamond.objTran.z += diamond.speed + 0.12;
		}
		if(diamondtwo.objTran.x <= 22.0){
			diamondtwo.objTran.x += diamond.speed + 0.12;
		}
		else{
			num = 12;
		}
		if(diamondtwo.objTran.z >= 0.0){
			diamondtwo.objTran.z -= diamond.speed + 0.12;
		}
		if(diamondthree.objTran.x >= -28.0){
			diamondthree.objTran.x -= diamond.speed + 0.12;
		}
		if(diamondthree.objTran.z <= 5.0){
			diamondthree.objTran.z += diamond.speed + 0.12;
		}
	}
	if(num == 12){
		if(diamond.objTran.x <= 24.0){
			diamond.objTran.x += diamond.speed + 0.12;
		}
		if(diamond.objTran.z >= 5.0){
			diamond.objTran.z -= diamond.speed + 0.12;
		}
		if(diamondtwo.objTran.x >= 0.0){
			diamondtwo.objTran.x -= diamond.speed + 0.12;
		}
		if(diamondtwo.objTran.z >= -3.0){
			diamondtwo.objTran.z -= diamond.speed + 0.12;
		}
		if(diamondthree.objTran.x <= 25.0){
			diamondthree.objTran.x += diamond.speed + 0.12;
		}
		else{
			num = 13;
		}
		if(diamondthree.objTran.z >= 2.0){
			diamondthree.objTran.z -= diamond.speed + 0.12;
		}
	}
	if(num == 13){
		if(diamond.objTran.x >= -30.0){
			diamond.objTran.x -= diamond.speed + 0.14;
		}
		else{
			num = 14;
		}
		if(diamond.objTran.z >= -1.0){
			diamond.objTran.z -= diamond.speed + 0.14;
		}
		if(diamondtwo.objTran.x >= -3.0){
			diamondtwo.objTran.x -= diamond.speed + 0.14;
		}
		if(diamondtwo.objTran.z <= 8.0){
			diamondtwo.objTran.z += diamond.speed + 0.14;
		}
		if(diamondthree.objTran.x <= 7.0){
			diamondthree.objTran.x += diamond.speed + 0.14;
		}
	}
	if(num == 14){
		if(diamond.objTran.x >= -12.0){
			diamond.objTran.x -= diamond.speed + 0.14;
		}
		else{
			num = 15;
		}
		if(diamondtwo.objTran.x <= 12.0){
			diamondtwo.objTran.x += diamond.speed + 0.14;
		}
		if(diamondtwo.objTran.z >= 5.0){
			diamondtwo.objTran.z -= diamond.speed + 0.14;
		}
		if(diamondthree.objTran.x >= -5.0){
			diamondthree.objTran.x -= diamond.speed + 0.14;
		}
		if(diamondthree.objTran.z <= 8.0){
			diamondthree.objTran.z += diamond.speed + 0.14;
		}
	}
	if(num == 15){
		if(diamond.objTran.x <= 19.0){
			diamond.objTran.x += diamond.speed + 0.16;
		}
		else{
			num = 16;
		}
		if(diamond.objTran.z >= -12.0){
			diamond.objTran.z -= diamond.speed + 0.16;
		}
		if(diamondtwo.objTran.x >= 6.0){
			diamondtwo.objTran.x -= diamond.speed + 0.16;
		}
		if(diamondtwo.objTran.z >= -3.0){
			diamondtwo.objTran.z -= diamond.speed + 0.16;
		}
		if(diamondthree.objTran.x >= -23.0){
			diamondthree.objTran.x -= diamond.speed + 0.16;
		}
		if(diamondthree.objTran.z >= 0.0){
			diamondthree.objTran.z -= diamond.speed + 0.16;
		}
	}
	if(num == 16){
		if(diamond.objTran.x >= -3.0){
			diamond.objTran.x -= diamond.speed + 0.16;
		}
		if(diamond.objTran.z <= -4.0){
			diamond.objTran.z += diamond.speed + 0.16;
		}
		if(diamondtwo.objTran.x >= -7.0){
			diamondtwo.objTran.x -= diamond.speed + 0.16;
		}
		if(diamondtwo.objTran.z <= 0.0){
			diamondtwo.objTran.z += diamond.speed + 0.16;
		}
		if(diamondthree.objTran.x <= 6.0){
			diamondthree.objTran.x += diamond.speed + 0.16;
		}
		else{
			num = 17;
		}
	}
	if(num == 17){
		if(diamond.objTran.x <= 12.0){
			diamond.objTran.x += diamond.speed + 0.18;
		}
		else{
			num = 18;
		}
		if(diamond.objTran.z <= 7.0){
			diamond.objTran.z += diamond.speed + 0.18;
		}
		if(diamondtwo.objTran.x >= -10.0){
			diamondtwo.objTran.x -= diamond.speed + 0.18;
		}
		if(diamondtwo.objTran.z <= 3.0){
			diamondtwo.objTran.z += diamond.speed + 0.18;
		}
		if(diamondthree.objTran.x >= -5.0){
			diamondthree.objTran.x -= diamond.speed + 0.18;
		}
		if(diamondthree.objTran.z <= 3.0){
			diamondthree.objTran.z += diamond.speed + 0.18;
		}
	}
	if(num == 18){
		if(diamond.objTran.z >= -14.0){
			diamond.objTran.z -= diamond.speed + 0.18;
		}
		if(diamondtwo.objTran.x <= 8.0){
			diamondtwo.objTran.x += diamond.speed + 0.18;
		}
		else{
			num = 19;
		}
		if(diamondtwo.objTran.z >= 0.0){
			diamondtwo.objTran.z -= diamond.speed + 0.18;
		}
		if(diamondthree.objTran.x <= -3.0){
			diamondthree.objTran.x += diamond.speed + 0.18;
		}
	}
	if(num == 19){
		if(diamond.objTran.x >= 10.0){
			diamond.objTran.x -= diamond.speed + 0.2;
		}
		if(diamond.objTran.z <= 0.0){
			diamond.objTran.z += diamond.speed + 0.2;
		}
		else{
			seconds = difftime(time(NULL), timer);
			animationover = 1;
		}
		if(diamondtwo.objTran.x >= -5.0){
			diamondtwo.objTran.x -= diamond.speed + 0.2;
		}
		if(diamondtwo.objTran.z >= -10.0){
			diamondtwo.objTran.z -= diamond.speed + 0.2;
		}
		if(diamondthree.objTran.x >= -20.0){
			diamondthree.objTran.x -= diamond.speed + 0.2;
		}
		if(diamondthree.objTran.z >= 0.0){
			diamondthree.objTran.z -= diamond.speed + 0.2;
		}
	}
	if(animationover == 1){
		if(selection == 3){
			printf("Congratulations! You got it right!");
			printf("You Win!");
			animationover = 0;
			selection = -1;
		}
		else if((selection == 1) || (selection == 2)){
			printf("Better luck next time! It was under block 3.");
			printf("You lose.");
			animationover = 0;
			selection = -1;
		}
	}
}


void animation3(){
	if(num == 1){
		if(diamond.objTran.x <= -7.0){
			diamond.objTran.x += diamond.speed + 0.03;
		}
		else{
			num = 2;
		}
		if(diamond.objTran.z <= 2.0){
			diamond.objTran.z += diamond.speed + 0.03;
		}
		if(diamondtwo.objTran.x <= 8.0){
			diamondtwo.objTran.x += diamond.speed + 0.03;
		}
		if(diamondtwo.objTran.z <= 0.0){
			diamondtwo.objTran.z += diamond.speed + 0.03;
		}
		if(diamondthree.objTran.x >= -3.0){
			diamondthree.objTran.x -= diamond.speed + 0.03;
		}
		if(diamondthree.objTran.z <= 4.0){
			diamondthree.objTran.z += diamond.speed + 0.03;
		}
	}
	if(num == 2){
		if(diamond.objTran.x <= 15.0){
			diamond.objTran.x += diamond.speed + 0.06;
		}
		if(diamond.objTran.z <= 4.0){
			diamond.objTran.z += diamond.speed + 0.06;
		}
		if(diamondtwo.objTran.x >= -18.0){
			diamondtwo.objTran.x -= diamond.speed + 0.06;
		}
		else{
			num = 3;
		}
		if(diamondtwo.objTran.z <= 2.0){
			diamondtwo.objTran.z += diamond.speed + 0.06;
		}
		if(diamondthree.objTran.x >= -22.0){
			diamondthree.objTran.x -= diamond.speed + 0.06;
		}
		if(diamondthree.objTran.z >= -17.0){
			diamondthree.objTran.z -= diamond.speed + 0.06;
		}
	}
	if(num == 3){
		if(diamond.objTran.x >= -21.0){
			diamond.objTran.x -= diamond.speed + 0.09;
		}
		else{
			num = 4;
		}
		if(diamond.objTran.z >= -10.0){
			diamond.objTran.z -= diamond.speed + 0.09;
		}
		if(diamondtwo.objTran.x <= 9.0){
			diamondtwo.objTran.x += diamond.speed + 0.09;
		}
		if(diamondtwo.objTran.z <= 3.0){
			diamondtwo.objTran.z += diamond.speed + 0.09;
		}
		if(diamondthree.objTran.x <= -12.0){
			diamondthree.objTran.x += diamond.speed + 0.09;
		}
		if(diamondthree.objTran.z <= -7.0){
			diamondthree.objTran.z += diamond.speed + 0.09;
		}
	}
	if(num == 4){
		if(diamond.objTran.z <= 7.0){
			diamond.objTran.z += diamond.speed + 0.12;
		}
		if(diamondtwo.objTran.x >= 0.0){
			diamondtwo.objTran.x -= diamond.speed + 0.12;
		}
		if(diamondtwo.objTran.z >= -5.0){
			diamondtwo.objTran.z -= diamond.speed + 0.12;
		}
		if(diamondthree.objTran.x <= 12.0){
			diamondthree.objTran.x += diamond.speed + 0.12;
		}
		else{
			num = 5;
		}
		if(diamondthree.objTran.z <= 0.0){
			diamondthree.objTran.z += diamond.speed + 0.12;
		}
	}
	if(num == 5){
		if(diamond.objTran.x <= 14.0){
			diamond.objTran.x += diamond.speed + 0.15;
		}
		else{
			num = 6;
		}
		if(diamond.objTran.z >= -7.0){
			diamond.objTran.z -= diamond.speed + 0.15;
		}
		if(diamondtwo.objTran.x >= -21.0){
			diamondtwo.objTran.x -= diamond.speed + 0.15;
		}
		if(diamondtwo.objTran.z >= -6.0){
			diamondtwo.objTran.z -= diamond.speed + 0.15;
		}
		if(diamondthree.objTran.x >= -5.0){
			diamondthree.objTran.x -= diamond.speed + 0.15;
		}
		if(diamondthree.objTran.z >= -10.0){
			diamondthree.objTran.z -= diamond.speed + 0.15;
		}
	}
	if(num == 6){
		if(diamond.objTran.x >= -5.0){
			diamond.objTran.x -= diamond.speed + 0.18;
		}
		if(diamond.objTran.z >= 10.0){
			diamond.objTran.z -= diamond.speed + 0.18;
		}
		if(diamondtwo.objTran.x <= 10.0){
			diamondtwo.objTran.x += diamond.speed + 0.18;
		}
		else{
			num = 7;
		}
		if(diamondtwo.objTran.z <= 0.0){
			diamondtwo.objTran.z += diamond.speed + 0.18;
		}
		if(diamondthree.objTran.x >= -16.0){
			diamondthree.objTran.x -= diamond.speed + 0.18;
		}
		if(diamondthree.objTran.z <= 14.0){
			diamondthree.objTran.z += diamond.speed + 0.18;
		}
	}
	if(num == 7){
		if(diamond.objTran.x <= 12.0){
			diamond.objTran.x += diamond.speed + 0.21;
		}
		if(diamond.objTran.z <= -5.0){
			diamond.objTran.z += diamond.speed + 0.21;
		}
		if(diamondtwo.objTran.x >= -7.0){
			diamondtwo.objTran.x -= diamond.speed + 0.21;
		}
		if(diamondtwo.objTran.z <= 6.0){
			diamondtwo.objTran.z += diamond.speed + 0.21;
		}
		if(diamondthree.objTran.x <= 10.0){
			diamondthree.objTran.x += diamond.speed + 0.21;
		}
		else{
			num = 8;
		}
		if(diamondthree.objTran.z >= -2.0){
			diamondthree.objTran.z -= diamond.speed + 0.21;
		}
	}
	if(num == 8){
		if(diamond.objTran.x >= -7.0){
			diamond.objTran.x -= diamond.speed + 0.24;
		}
		if(diamond.objTran.z <= 6.0){
			diamond.objTran.z += diamond.speed + 0.24;
		}
		if(diamondtwo.objTran.x >= -8.0){
			diamondtwo.objTran.x -= diamond.speed + 0.24;
		}
		if(diamondtwo.objTran.z >= -10.0){
			diamondtwo.objTran.z -= diamond.speed + 0.24;
		}
		if(diamondthree.objTran.x >= -20.0){
			diamondthree.objTran.x -= diamond.speed + 0.24;
		}
		else{
			num = 9;
		}
		if(diamondthree.objTran.z <= 4.0){
			diamondthree.objTran.z += diamond.speed + 0.24;
		}
	}
	if(num == 9){
		if(diamond.objTran.x >= -17.0){
			diamond.objTran.x -= diamond.speed + 0.27;
		}
		if(diamond.objTran.z >= -10.0){
			diamond.objTran.z -= diamond.speed + 0.27;
		}
		else{
			num = 10;
		}
		if(diamondtwo.objTran.x <= 5.0){
			diamondtwo.objTran.x += diamond.speed + 0.27;
		}
		if(diamondtwo.objTran.z <= 3.0){
			diamondtwo.objTran.z += diamond.speed + 0.27;
		}
		if(diamondthree.objTran.x <= -5.0){
			diamondthree.objTran.x += diamond.speed + 0.27;
		}
	}
	if(num == 10){
		if(diamond.objTran.x <= 12.0){
			diamond.objTran.x += diamond.speed + 0.3;
		}
		else{
			num = 11;
		}
		if(diamond.objTran.z <= -4.0){
			diamond.objTran.z += diamond.speed + 0.3;
		}
		if(diamondtwo.objTran.x >= -18.0){
			diamondtwo.objTran.x -= diamond.speed + 0.3;
		}
		if(diamondthree.objTran.z <= 16.0){
			diamondthree.objTran.z += diamond.speed + 0.3;
		}
	}
	if(num == 11){
		if(diamond.objTran.x >= -17.0){
			diamond.objTran.x -= diamond.speed + 0.33;
		}
		if(diamond.objTran.z >= -20.0){
			diamond.objTran.z -= diamond.speed + 0.33;
		}
		if(diamondtwo.objTran.x <= -5.0){
			diamondtwo.objTran.x += diamond.speed + 0.33;
		}
		if(diamondtwo.objTran.z >= 16.0){
			diamondtwo.objTran.z -= diamond.speed + 0.33;
		}
		if(diamondthree.objTran.x <= 0.0){
			diamondthree.objTran.x += diamond.speed + 0.33;
		}
		if(diamondthree.objTran.z >= -20.0){
			diamondthree.objTran.z -= diamond.speed + 0.33;
		}
		else{
			num = 12;
		}
	}
	if(num == 12){
		if(diamond.objTran.x <= -7.0){
			diamond.objTran.x += diamond.speed + 0.36;
		}
		if(diamond.objTran.z <= 2.0){
			diamond.objTran.z += diamond.speed + 0.36;
		}
		if(diamondtwo.objTran.x <= 8.0){
			diamondtwo.objTran.x += diamond.speed + 0.36;
		}
		if(diamondtwo.objTran.z >= 0.0){
			diamondtwo.objTran.z -= diamond.speed + 0.36;
		}
		if(diamondthree.objTran.x >= -3.0){
			diamondthree.objTran.x -= diamond.speed + 0.36;
		}
		if(diamondthree.objTran.z <= 4.0){
			diamondthree.objTran.z += diamond.speed + 0.36;
		}
		else{
			num = 13;
		}
	}
	if(num == 13){
		if(diamond.objTran.x <= 15.0){
			diamond.objTran.x += diamond.speed + 0.39;
		}
		if(diamond.objTran.z <= 4.0){
			diamond.objTran.z += diamond.speed + 0.39;
		}
		if(diamondtwo.objTran.x >= -18.0){
			diamondtwo.objTran.x -= diamond.speed + 0.39;
		}
		else{
			num = 14;
		}
		if(diamondtwo.objTran.z <= 2.0){
			diamondtwo.objTran.z += diamond.speed + 0.39;
		}
		if(diamondthree.objTran.x >= -22.0){
			diamondthree.objTran.x -= diamond.speed + 0.39;
		}
		if(diamondthree.objTran.z >= -17.0){
			diamondthree.objTran.z -= diamond.speed + 0.39;
		}
	}
	if(num == 14){
		if(diamond.objTran.x >= -21.0){
			diamond.objTran.x -= diamond.speed + 0.42;
		}
		else{
			num = 15;
		}
		if(diamond.objTran.z >= -10.0){
			diamond.objTran.z -= diamond.speed + 0.42;
		}
		if(diamondtwo.objTran.x <= 9.0){
			diamondtwo.objTran.x += diamond.speed + 0.42;
		}
		if(diamondtwo.objTran.z <= 3.0){
			diamondtwo.objTran.z += diamond.speed + 0.42;
		}
		if(diamondthree.objTran.x <= -12.0){
			diamondthree.objTran.x += diamond.speed + 0.42;
		}
		if(diamondthree.objTran.z <= -7.0){
			diamondthree.objTran.z += diamond.speed + 0.42;
		}
	}
	if(num == 15){
		if(diamond.objTran.z <= 7.0){
			diamond.objTran.z += diamond.speed + 0.45;
		}
		if(diamondtwo.objTran.x >= 0.0){
			diamondtwo.objTran.x -= diamond.speed + 0.45;
		}
		if(diamondtwo.objTran.z >= -5.0){
			diamondtwo.objTran.z -= diamond.speed + 0.45;
		}
		if(diamondthree.objTran.x <= 12.0){
			diamondthree.objTran.x += diamond.speed + 0.45;
		}
		else{
			num = 16;
		}
		if(diamondthree.objTran.z <= 0.0){
			diamondthree.objTran.z += diamond.speed + 0.45;
		}
	}
	if(num == 16){
		if(diamond.objTran.x <= 14.0){
			diamond.objTran.x += diamond.speed + 0.48;
		}
		else{
			num = 17;
		}
		if(diamond.objTran.z >= -7.0){
			diamond.objTran.z -= diamond.speed + 0.48;
		}
		if(diamondtwo.objTran.x >= -21.0){
			diamondtwo.objTran.x -= diamond.speed + 0.48;
		}
		if(diamondtwo.objTran.z >= -6.0){
			diamondtwo.objTran.z -= diamond.speed + 0.48;
		}
		if(diamondthree.objTran.x >= -5.0){
			diamondthree.objTran.x -= diamond.speed + 0.48;
		}
		if(diamondthree.objTran.z >= -10.0){
			diamondthree.objTran.z -= diamond.speed + 0.48;
		}
	}
	if(num == 17){
		if(diamond.objTran.x >= -5.0){
			diamond.objTran.x -= diamond.speed + 0.51;
		}
		if(diamond.objTran.z >= 10.0){
			diamond.objTran.z -= diamond.speed + 0.51;
		}
		if(diamondtwo.objTran.x <= 10.0){
			diamondtwo.objTran.x += diamond.speed + 0.51;
		}
		else{
			num = 18;
		}
		if(diamondtwo.objTran.z <= 0.0){
			diamondtwo.objTran.z += diamond.speed + 0.51;
		}
		if(diamondthree.objTran.x >= -16.0){
			diamondthree.objTran.x -= diamond.speed + 0.51;
		}
		if(diamondthree.objTran.z <= 14.0){
			diamondthree.objTran.z += diamond.speed + 0.51;
		}
	}
	if(num == 18){
		if(diamond.objTran.x <= 12.0){
			diamond.objTran.x += diamond.speed + 0.54;
		}
		if(diamond.objTran.z <= -5.0){
			diamond.objTran.z += diamond.speed + 0.54;
		}
		if(diamondtwo.objTran.x >= -7.0){
			diamondtwo.objTran.x -= diamond.speed + 0.54;
		}
		if(diamondtwo.objTran.z <= 6.0){
			diamondtwo.objTran.z += diamond.speed + 0.54;
		}
		if(diamondthree.objTran.x <= 10.0){
			diamondthree.objTran.x += diamond.speed + 0.54;
		}
		else{
			num = 19;
		}
		if(diamondthree.objTran.z >= -2.0){
			diamondthree.objTran.z -= diamond.speed + 0.54;
		}
	}
	if(num == 19){
		if(diamond.objTran.x >= -7.0){
			diamond.objTran.x -= diamond.speed + 0.57;
		}
		if(diamond.objTran.z <= 6.0){
			diamond.objTran.z += diamond.speed + 0.57;
		}
		if(diamondtwo.objTran.x >= -8.0){
			diamondtwo.objTran.x -= diamond.speed + 0.57;
		}
		if(diamondtwo.objTran.z >= -10.0){
			diamondtwo.objTran.z -= diamond.speed + 0.57;
		}
		if(diamondthree.objTran.x >= -20.0){
			diamondthree.objTran.x -= diamond.speed + 0.57;
		}
		else{
			num = 20;
		}
		if(diamondthree.objTran.z <= 4.0){
			diamondthree.objTran.z += diamond.speed + 0.57;
		}
	}
	if(num == 20){
		if(diamond.objTran.x >= -17.0){
			diamond.objTran.x -= diamond.speed + 0.6;
		}
		if(diamond.objTran.z >= -10.0){
			diamond.objTran.z -= diamond.speed + 0.6;
		}
		else{
			num = 21;
		}
		if(diamondtwo.objTran.x <= 5.0){
			diamondtwo.objTran.x += diamond.speed + 0.6;
		}
		if(diamondtwo.objTran.z <= 3.0){
			diamondtwo.objTran.z += diamond.speed + 0.6;
		}
		if(diamondthree.objTran.x <= -5.0){
			diamondthree.objTran.x += diamond.speed + 0.6;
		}
	}
	if(num == 21){
		if(diamond.objTran.x <= 12.0){
			diamond.objTran.x += diamond.speed + 0.63;
		}
		else{
			num = 22;
		}
		if(diamond.objTran.z <= -4.0){
			diamond.objTran.z += diamond.speed + 0.63;
		}
		if(diamondtwo.objTran.x >= -18.0){
			diamondtwo.objTran.x -= diamond.speed + 0.63;
		}
		if(diamondthree.objTran.z <= 16.0){
			diamondthree.objTran.z += diamond.speed + 0.63;
		}
	}
	if(num == 22){
		if(diamond.objTran.x >= -17.0){
			diamond.objTran.x -= diamond.speed + 0.66;
		}
		if(diamond.objTran.z >= -20.0){
			diamond.objTran.z -= diamond.speed + 0.66;
		}
		if(diamondtwo.objTran.x <= -5.0){
			diamondtwo.objTran.x += diamond.speed + 0.66;
		}
		if(diamondtwo.objTran.z >= 16.0){
			diamondtwo.objTran.z -= diamond.speed + 0.66;
		}
		if(diamondthree.objTran.x <= 0.0){
			diamondthree.objTran.x += diamond.speed + 0.66;
		}
		if(diamondthree.objTran.z >= -20.0){
			diamondthree.objTran.z -= diamond.speed + 0.66;
		}
		else{
			num = 23;
		}
	}
	if(num == 23){
		if(diamond.objTran.x <= -20.0){
			diamond.objTran.x += diamond.speed + 0.69;
		}
		else{
			seconds = difftime(time(NULL), timer);
			animationover = 1;
		}
		if(diamond.objTran.z <= 0.0){
			diamond.objTran.z += diamond.speed + 0.69;
		}
		if(diamondtwo.objTran.z >= -10.0){
			diamondtwo.objTran.z -= diamond.speed + 0.69;
		}
		if(diamondthree.objTran.x <= 10.0){
			diamondthree.objTran.x += diamond.speed + 0.69;
		}
		if(diamondthree.objTran.z <= 0.0){
			diamondthree.objTran.z += diamond.speed + 0.69;
		}
	}

	if(animationover == 1){
		if(selection == 1){
			printf("Congratulations! You got it right!");
			animationover = 0;
			selection = -1;
		}
		else if((selection == 2) || (selection == 3)){
			printf("Oh no! It was under block 1!");
			printf("You lose. Try playing an easier level.");
			animationover = 0;
			selection = -1;
		}
	}
		

}


void collision(){
		if(level == 1){
			if(cube.objTran.y >= 4.0){	
				cube.move = 4;	
				animation1();
			}
		}
		else if(level == 2){
			if(cube.objTran.y >= 4.0){	
				cube.move = 4;	
				animation2();
			}
		}
		else if(level == 3){
			if(cube.objTran.y >= 4.0){	
				cube.move = 4;	
				animation3();
			}
		}
		if(selection == -1){
			if(level == 1){
				cube.move = 5;
			}
			else if(level == 2){
				cube.objTran.x = 10.0;
			}
			else if(level == 3){
				cube.objTran.x = -18.0;
			}
			if(diamond.objTran.y <= 40.0){
				diamond.objTran.y += diamond.speed;
			}
			else{
				printf("\nScore: %.0f\n", seconds);
				levelover = true;
				selection = 0;
			}	
		}
		if(levelover == true){
			if(diamond.objTran.y >= 0.0){
				diamond.objTran.y -= diamond.speed;
			}
			else{
				sleep(3);
				exit(0);
			}
		}

}


void init(){
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH); 
	glEnable(GL_NORMALIZE);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glViewport(0, 0, 600, 600);
	diamond1();
	diamond2();
	diamond3();
	cube1();					

	Shader s[]={
  	{ GL_VERTEX_SHADER , "vertexshader.glsl"},
  	{ GL_FRAGMENT_SHADER , "fragmentshader.glsl"}, 
  	{ GL_NONE , NULL} 
  	};
		
  	prog=initShaders(s);


}


void display(SDL_Window* screen){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	collision();
	cube.draw();
	cube.textbuffcube();
	diamond.draw();
	diamond.textbuffone();
	diamondtwo.draw();
	diamondtwo.textbufftwo();
	diamondthree.draw();
	diamondthree.textbuffthree();

	
	glFlush();
	SDL_GL_SwapWindow(screen);
}

void checkmouse(){
	//printf("Mouse x: %d\n", mouse_down_x);
	//printf("Mouse y: %d\n", mouse_down_y);
	if((mouse_down_x >= 133) && (mouse_down_x <= 186)){
		if((mouse_down_y >= 264) && (mouse_down_y <= 534)){
			selection = 1;
		}
	}
	if((mouse_down_x >= 246) && (mouse_down_x <= 295)){
		if((mouse_down_y >= 283) && (mouse_down_y <= 513)){
			selection = 2;
		}
	}
	if((mouse_down_x >= 340) && (mouse_down_x <= 395)){
		if((mouse_down_y >= 283) && (mouse_down_y <= 513)){
			selection = 3;
		}
	}
}

void input(SDL_Window* screen){
	SDL_Event event;
	while (SDL_PollEvent(&event)){
        switch(event.type)
        {
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_SPACE:
                        break;
                    case SDLK_ESCAPE:
      					exit(0);
                        break;
                    default:
                        break;
                }
                break;

            case SDL_KEYUP:
                switch(event.key.keysym.sym)
                {
                    case SDLK_SPACE:
                        break;
                    default:
                        break;
                }
                break;

            case SDL_MOUSEBUTTONDOWN:
                mouse_down_x = event.button.x;
                mouse_down_y = (600 - event.button.y);
				checkmouse();
                break;
            default:
                break;
        }
    }
}

int main(int argc, char **argv){
	cout<<"What level would you like to try? (1, 2, or 3)"<<endl;
	cin>>level;
	timer = time(NULL); 
	SDL_Window *window;
	//initialize SDL
	if(SDL_Init(SDL_INIT_VIDEO)<0){
		fprintf(stderr,"Unable to create window: %s\n", SDL_GetError());
    	SDL_Quit();
    	exit(1);
	}

	window = SDL_CreateWindow("Christiansen & Kinel Project2",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,500,500,SDL_WINDOW_OPENGL);
	
	if(window==NULL){
		fprintf(stderr,"Unable to create window: %s\n",SDL_GetError());
	}

	SDL_GLContext glcontext=SDL_GL_CreateContext(window);
	
	//initialize glew
  	glewExperimental=GL_TRUE;
  	if(glewInit()){
    	fprintf(stderr, "Unable to initalize GLEW");
    	exit(EXIT_FAILURE);
  	}
  	printf("Once the diamonds stop moving, click the one you think the block is under.\n");
	init();
	int prevsecond = 0;
	while(true){
    			if((int)difftime(time(NULL),timer)!= prevsecond){
					if((int)difftime(time(NULL), timer)%1 == 0){
								cube.move = 1;

				}
				
    		}		
    	prevsecond = (int)difftime(time(NULL), timer); //set the second to compare next iteration
		input(window);
		display(window);
	}

		SDL_GL_DeleteContext(glcontext);
  		SDL_DestroyWindow(window);
  		SDL_Quit();
 
  		return 0;
}
