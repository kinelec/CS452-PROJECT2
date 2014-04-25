#include "initShaders.h"
#include "paint.h"
#include <cstdlib>
using namespace std;

bool pressed = false;
SDL_Event event;
SDL_Event lastkey;
GLfloat pit,yaw,scalar=1;
paint diamond;
paint diamondtwo;
paint diamondthree;

void diamond1(){

GLfloat vert[]={
	0.0f,10.0f,0.0f,
	0.0f,-10.0f,0.0f,
	0.0f,0.0f,3.0f,
	0.0f,0.0f,-3.0f,	
	2.0f,0.0f,0.0f,
	-2.0f,0.0f,0.0f
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
	1.0f, 0.5f,
	1.0f, 0.5f,
	1.0f, 1.0f,
	1.0f, 1.0f };

											
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

	diamond.vertsize = sizeof(vert);
	diamond.colorsize = sizeof(color);
	diamond.elemssize = sizeof(elems);
	diamond.textsize = sizeof(text);
	diamond.move = 0;
	diamond.vertarray = (GLfloat*)malloc(sizeof(GLfloat)*diamond.vertsize);
	diamond.colorarray = (GLfloat*)malloc(sizeof(GLfloat)*diamond.colorsize);
	diamond.elemsarray = (GLubyte*)malloc(sizeof(GLfloat)*diamond.elemssize);
	diamond.textarray = (GLfloat*)malloc(sizeof(GLfloat)*diamond.textsize);
	memcpy(diamond.vertarray, vert, 4*diamond.vertsize);
	memcpy(diamond.colorarray, color, 4*diamond.colorsize);
	memcpy(diamond.textarray, text, 4*diamond.textsize);
	memcpy(diamond.elemsarray, elems, diamond.elemssize);
	
	//buffers
	glGenBuffers(3, diamond.vboID);
	glGenBuffers(1, &diamond.eboID);

	diamond.objTran.y = 0.0;
	diamond.objTran.x = -20.0;
}

void diamond2(){

GLfloat vert[]={
	0.0f,10.0f,0.0f,
	0.0f,-10.0f,0.0f,
	0.0f,0.0f,3.0f,
	0.0f,0.0f,-3.0f,	
	2.0f,0.0f,0.0f,
	-2.0f,0.0f,0.0f
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
	1.0f, 0.5f,
	1.0f, 0.5f,
	1.0f, 1.0f,
	1.0f, 1.0f };

											
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

	diamondtwo.vertsize = sizeof(vert);
	diamondtwo.colorsize = sizeof(color);
	diamondtwo.elemssize = sizeof(elems);
	diamondtwo.textsize = sizeof(text);
	diamondtwo.move = 0;
	diamondtwo.vertarray = (GLfloat*)malloc(sizeof(GLfloat)*diamondtwo.vertsize);
	diamondtwo.colorarray = (GLfloat*)malloc(sizeof(GLfloat)*diamondtwo.colorsize);
	diamondtwo.elemsarray = (GLubyte*)malloc(sizeof(GLfloat)*diamondtwo.elemssize);
	diamondtwo.textarray = (GLfloat*)malloc(sizeof(GLfloat)*diamondtwo.textsize);
	memcpy(diamondtwo.vertarray, vert, 4*diamondtwo.vertsize);
	memcpy(diamondtwo.colorarray, color, 4*diamondtwo.colorsize);
	memcpy(diamondtwo.textarray, text, 4*diamondtwo.textsize);
	memcpy(diamondtwo.elemsarray, elems, diamondtwo.elemssize);
	
	//buffers
	glGenBuffers(3, diamondtwo.vboID);
	glGenBuffers(1, &diamondtwo.eboID);

	diamondtwo.objTran.y = 0.0;
	diamondtwo.objTran.x = -5.0;
}

void diamond3(){

GLfloat vert[]={
	0.0f,10.0f,0.0f,
	0.0f,-10.0f,0.0f,
	0.0f,0.0f,3.0f,
	0.0f,0.0f,-3.0f,	
	2.0f,0.0f,0.0f,
	-2.0f,0.0f,0.0f
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
	1.0f, 0.5f,
	1.0f, 0.5f,
	1.0f, 1.0f,
	1.0f, 1.0f };

											
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

	diamondthree.vertsize = sizeof(vert);
	diamondthree.colorsize = sizeof(color);
	diamondthree.elemssize = sizeof(elems);
	diamondthree.textsize = sizeof(text);
	diamondthree.move = 0;
	diamondthree.vertarray = (GLfloat*)malloc(sizeof(GLfloat)*diamondthree.vertsize);
	diamondthree.colorarray = (GLfloat*)malloc(sizeof(GLfloat)*diamondthree.colorsize);
	diamondthree.elemsarray = (GLubyte*)malloc(sizeof(GLfloat)*diamondthree.elemssize);
	diamondthree.textarray = (GLfloat*)malloc(sizeof(GLfloat)*diamondthree.textsize);
	memcpy(diamondthree.vertarray, vert, 4*diamondthree.vertsize);
	memcpy(diamondthree.colorarray, color, 4*diamondthree.colorsize);
	memcpy(diamondthree.textarray, text, 4*diamondthree.textsize);
	memcpy(diamondthree.elemsarray, elems, diamondthree.elemssize);
	
	//buffers
	glGenBuffers(3, diamondthree.vboID);
	glGenBuffers(1, &diamondthree.eboID);

	diamondthree.objTran.y = 0.0;
	diamondthree.objTran.x = 10.0;
}



void init(){
	
	glEnable(GL_DEPTH_TEST);
	glViewport(0, 0, 600, 600);	
	
	diamond1();
	diamond2();
	diamond3();

	diamond.textbuff();
	diamondtwo.textbuff();
	diamondthree.textbuff();				


	Shader s[]={
  	{ GL_VERTEX_SHADER , "vertexshader.glsl"},
  	{ GL_FRAGMENT_SHADER , "fragmentshader.glsl"}, 
  	{ GL_NONE , NULL} 
  	};
		
  	prog=initShaders(s);

}

void display(SDL_Window* screen){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	//collision();
	diamond.draw();
	diamondtwo.draw();
	diamondthree.draw();

	glFlush();
	SDL_GL_SwapWindow(screen);
}
/*
void input(SDL_Window* screen){
	if(pressed){
		if(diamond.objTran.x <= -27){
			diamond.objTran.x = -27;
		}
		else if(lastkey.key.keysym.sym == SDLK_LEFT){
 			diamond.objTran.x -= 0.5;
		}
		if(diamond.objTran.x >= 2.5){ 
			diamond.objTran.x = 2.5;
		}
		else if(lastkey.key.keysym.sym == SDLK_RIGHT){
			diamond.objTran.x += 0.5;
		}
	}
    while ( SDL_PollEvent(&event) )
    {
        switch (event.type)
        {
            case SDL_QUIT:
				break;
            case SDL_KEYDOWN:
                pressed = true;
                break;
            case SDL_KEYUP:
                pressed = false;
                break;
            default:
                break;
        }
    }
	lastkey = event;
}
*/
int main(int argc, char **argv){
	SDL_Window *window;
	
	//initialize SDL
	if(SDL_Init(SDL_INIT_VIDEO)<0){
		fprintf(stderr,"Unable to create window: %s\n", SDL_GetError());
    	SDL_Quit();
    	exit(1);
	}

	window = SDL_CreateWindow("Christiansen & Kinel Project1",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,500,500,SDL_WINDOW_OPENGL);
	
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
  
	init();
	while(true){
    
		//input(window);
		display(window);
	}

	SDL_GL_DeleteContext(glcontext);
  	SDL_DestroyWindow(window);
  	SDL_Quit();
 
  	return 0;
}
