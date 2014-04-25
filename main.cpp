#include "initShaders.h"
#include <cstdlib>
using namespace std;

void rotate(GLuint locate);

GLuint vaoID,vboID[3],eboID, texBufferID, texCoordID, texID;
GLuint prog;
GLubyte* imageData;
GLfloat pit,yaw,scalar=1;
glm::vec3 diamondTran;

GLfloat vertices[]={
	0.0f,10.0f,0.0f,
	0.0f,-10.0f,0.0f,
	0.0f,0.0f,3.0f,
	0.0f,0.0f,-3.0f,	
	2.0f,0.0f,0.0f,
	-2.0f,0.0f,0.0f
					};

GLfloat colors[]={
	1.0f,1.0f,1.0f,1.0f,
	1.0f,1.0f,1.0f,1.0f,
	1.0f,1.0f,1.0f,1.0f,
	1.0f,1.0f,1.0f,1.0f,
	1.0f,1.0f,1.0f,1.0f,
	1.0f,1.0f,1.0f,1.0f						
	              		};

GLfloat textPos[] = { 1.0f, 1.0f,
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

//code from Jeffrey Chastine: http://www.youtube.com/watch?v=wy-B8NiaDHg
void loadBitmapFromFile(const char* filename, int* width, int* height, int* size, unsigned char** pixel_data) {
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		printf ("Couldn't open file... aborting\n");
	}
	short identifier = -1;
	fread(&identifier, 1, sizeof(short), fp); printf ("Identifer is: %c\n", identifier);
	int filesize = -1;
	fread(&filesize, 1, sizeof(int), fp); printf ("filesize is: %d\n", filesize);
	int reserved = -1;
	fread(&reserved, 1, sizeof(int), fp); printf ("reserved is: %d\n", reserved);
	int bitmap_offset = -1;
	fread(&bitmap_offset, 1, sizeof(int), fp); printf ("bitmap_offset is: %d\n", bitmap_offset);
	int bitmap_header_size = -1;
	fread(&bitmap_header_size, 1, sizeof(int), fp); printf ("bitmap_header_size is: %d\n", bitmap_header_size);
	int bitmap_width = -1;
	fread(&bitmap_width, 1, sizeof(int), fp); printf ("bitmap_width is: %d\n", bitmap_width);
	int bitmap_height = -1;
	fread(&bitmap_height, 1, sizeof(int), fp); printf ("bitmap_height is: %d\n", bitmap_height);
	short bitmap_planes = -1;
	fread(&bitmap_planes, 1, sizeof(short), fp); printf ("bitmap_planes is: %d\n", bitmap_planes);
	short bits_per_pixel= -1;
	fread(&bits_per_pixel, 1, sizeof(short), fp); printf ("bits_per_pixel is: %d\n", bits_per_pixel);
	int compression = -1;
	fread(&compression, 1, sizeof(int), fp); printf ("compression is: %d\n", compression);
	int bitmap_data_size = -1;
	fread(&bitmap_data_size, 1, sizeof(int), fp); printf ("bitmap_data_size is: %d\n", bitmap_data_size);
	int hresolution = -1;
	fread(&hresolution, 1, sizeof(int), fp); printf ("hresolution is: %d\n", hresolution);
	int vresolution = -1;
	fread(&vresolution, 1, sizeof(int), fp); printf ("vresolution is: %d\n", vresolution);
	int num_colors = -1;
	fread(&num_colors, 1, sizeof(int), fp); printf ("num_colors is: %d\n", num_colors);
	int num_important_colors = -1;
	fread(&num_important_colors, 1, sizeof(int), fp); printf ("num_important_colors is: %d\n", num_important_colors);
	
	// Jump to the data already!
	fseek (fp, bitmap_offset, SEEK_SET);
	unsigned char* data = new unsigned char[bitmap_data_size];
	// Read data in BGR format
	fread (data, sizeof(unsigned char), bitmap_data_size, fp);
	
	// Make pixel_data point to the pixels
	*pixel_data = data;
	*size = bitmap_data_size;
	*width = bitmap_width;
	*height = bitmap_height;
	fclose(fp);
}


void init(){
	
	glEnable(GL_DEPTH_TEST);
	glViewport(0, 0, 600, 600);	
	glGenVertexArrays(1,&vaoID);
	glBindVertexArray(vaoID);
	
	glGenBuffers(3, vboID);
	glBindBuffer(GL_ARRAY_BUFFER,vboID[0]);
	glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
	glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void*)0);
	
	glBindBuffer(GL_ARRAY_BUFFER, vboID[1]);
	glBufferData(GL_ARRAY_BUFFER,sizeof(colors),colors,GL_STATIC_DRAW);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glBindBuffer(GL_ARRAY_BUFFER, vboID[2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(textPos), textPos, GL_STATIC_DRAW);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);  

	glGenBuffers(1,&eboID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,eboID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(elems),elems,GL_STATIC_DRAW);
	

	int bmpWidth = -1;
	int bmpHeight = -1;
	int bmpSize = -1;
	loadBitmapFromFile("creature3.bmp", &bmpWidth, &bmpHeight, &bmpSize, (unsigned char**)&imageData);
	
	glEnable(GL_TEXTURE_2D);				
	glGenTextures(1, &texBufferID);				
	glBindTexture(GL_TEXTURE_2D, texBufferID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, bmpWidth, bmpHeight, 0, GL_BGR, GL_UNSIGNED_BYTE, imageData);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);	
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	;
	glActiveTexture(GL_TEXTURE0);
	glUniform1i(texID, 0);


	Shader s[]={
  	{ GL_VERTEX_SHADER , "vertexshader.glsl"},
  	{ GL_FRAGMENT_SHADER , "fragmentshader.glsl"}, 
  	{ GL_NONE , NULL} 
  	};
		
  	prog=initShaders(s);
  
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

}


void display(SDL_Window* screen){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	
	glm::mat4 trans;
	
	trans = glm::translate(trans,diamondTran);
  	trans = glm::rotate(trans,pit,glm::vec3(1,0,0));//rotate around x axis
  	trans = glm::rotate(trans,yaw,glm::vec3(0,1,0));//rotate arround y axis
  	trans = glm::scale(trans,glm::vec3(scalar));//scaling
    
	//transformation matrix
  	GLint tmpLocation = glGetUniformLocation(prog,"modelMatrix");
	glUniformMatrix4fv(tmpLocation,1,GL_FALSE,&trans[0][0]);
	
	texCoordID = glGetAttribLocation(prog, "s_vTexCoord");
	glEnableVertexAttribArray(texCoordID);
	glVertexAttribPointer(texCoordID, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);
	texID = glGetUniformLocation(prog, "texture");

	glDrawElements(GL_TRIANGLES,24,GL_UNSIGNED_BYTE,NULL);
	glFlush();
	SDL_GL_SwapWindow(screen);
}

void input(SDL_Window* screen){
	
	//keyboard events
	SDL_Event event;
	while (SDL_PollEvent(&event)){
		switch (event.type){
			case SDL_QUIT:exit(0);break;
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym){
					case SDLK_ESCAPE:exit(0);
					case SDLK_w:diamondTran.y+=2;break;
					case SDLK_s:diamondTran.y-=2;break;
					case SDLK_a:diamondTran.x-=2;break;
					case SDLK_d:diamondTran.x+=2;break;
					case SDLK_e:scalar+=.1f;break;
					case SDLK_q:scalar-=.1f;break;
					case SDLK_i:pit+=2;break;
					case SDLK_k:pit-=2;break;
					case SDLK_j:yaw+=2;break;
					case SDLK_l:yaw-=2;break;
				}
		}
	}
}


int main(int argc, char **argv){
	SDL_Window *window;
	
	//initialize SDL
	if(SDL_Init(SDL_INIT_VIDEO)<0){
		fprintf(stderr,"Unable to create window: %s\n", SDL_GetError());
    	SDL_Quit();
    	exit(1);
	}

	window = SDL_CreateWindow("Kinel Lab 3",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,500,500,SDL_WINDOW_OPENGL);
	
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
		input(window);
		display(window);
	}

	SDL_GL_DeleteContext(glcontext);
  	SDL_DestroyWindow(window);
  	SDL_Quit();
 
  	return 0;
}
