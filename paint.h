#ifndef PAINT_H_
#define PAINT_H_
#include "initShaders.h"

#if defined(__BORLANDC__)
    typedef unsigned char uint8_t;
    typedef __int64 int64_t;
    typedef unsigned long uintptr_t;
#elif defined(_MSC_VER)
    typedef unsigned char uint8_t;
    typedef __int64 int64_t;
#else
    #include <stdint.h>
#endif

GLuint prog;

//generates random float from min and max
GLfloat randomgen(float min, float max){
	return min + static_cast <GLfloat> (rand())/(static_cast <GLfloat> (RAND_MAX/(max-min)));
}

class paint{
public:
	//buffers
	GLuint vaoID,vboID[4],eboID, texBufferID[2], texCoordID, texID, texBufferIDcube, texIDcube, texture;
	GLubyte* imageData;
	GLubyte* cubeimageData;

	GLuint vbo_cube_texcoords;
    GLuint texture_id[4];
	//vertex arrays & size
	GLfloat* vertarray;
	int vertsize;

	GLfloat* norms;
	int normssize;
	//color arrays & size
	GLfloat* colorarray;
	int colorsize;
	GLfloat* textarray;
	int textsize;
	//elems arrays & size
  	GLubyte* elemsarray;
  	int elemssize;
	//transformation
	glm::vec3 objTran;
	//if moves move is set to 1; on collision move is set to 2
	int move;
	//speed
	float speed;

	void draw(){

		//buffers
		glGenVertexArrays(1,&vaoID);
    	glBindVertexArray(vaoID);
    	glBindBuffer(GL_ARRAY_BUFFER,vboID[0]);
    	glBufferData(GL_ARRAY_BUFFER,vertsize,vertarray,GL_STATIC_DRAW);
    	glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void*)0);
    	glBindBuffer(GL_ARRAY_BUFFER, vboID[1]);
    	glBufferData(GL_ARRAY_BUFFER,colorsize,colorarray,GL_STATIC_DRAW);
    	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);
		glBindBuffer(GL_ARRAY_BUFFER, vboID[2]);
		glBufferData(GL_ARRAY_BUFFER, textsize, textarray, GL_STATIC_DRAW);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);
		glBindBuffer(GL_ARRAY_BUFFER, vboID[3]);
		glBufferData(GL_ARRAY_BUFFER,normssize,norms,GL_STATIC_DRAW);
		glVertexAttribPointer(3, 3,GL_FLOAT,GL_FALSE,0,(void*)0);; 
    	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,eboID);
    	glBufferData(GL_ELEMENT_ARRAY_BUFFER,elemssize,elemsarray,GL_STATIC_DRAW);
		//transformation
		glm::mat4 trans;
		trans = glm::translate(trans, objTran);
    	GLint tempLoc = glGetUniformLocation(prog,"modelMatrix");
    	glUniformMatrix4fv(tempLoc,1,GL_FALSE,&trans[0][0]);

		GLfloat amb[]={0.7f,0.7f,0.7f,1.0f};
		GLfloat light1d[] = {200.0f, 200.0f, 200.0f};
  		GLfloat light1c[] = {1.0f, 1.0f, 1.0f};
    
		GLint lightLocation = glGetUniformLocation(prog,"Ambient");
		glUniform4fv(lightLocation,1,amb);
		lightLocation = glGetUniformLocation(prog,"LightD1");
		glUniform3fv(lightLocation,1,light1d);

		lightLocation = glGetUniformLocation(prog,"LightC1");
		glUniform3fv(lightLocation,1,light1c);

		lightLocation = glGetUniformLocation(prog,"Half1");
		glUniform3fv(lightLocation,1,light1d);


		glEnableVertexAttribArray(0);
    	glEnableVertexAttribArray(1);
		glEnableVertexAttribArray(2);
		glEnableVertexAttribArray(3);		

		//movement; generates random x value
		if(move == 1){
			if(objTran.y <= 5.0){
				objTran.y += speed+0.4;
			if(objTran.x >= -19.0){
				objTran.x -= speed+0.2;
					if(objTran.z >= 0.0){
						objTran.z -= speed;
					}
				}
			}
		}
		else if(move == 2){
			objTran.x = -100.0;
		}
		else if(move == 3){
			objTran.x = -5.0;
			objTran.z = -10.0;
		}

		glDrawElements(GL_POLYGON,elemssize,GL_UNSIGNED_BYTE,NULL);
	
  	}

	//code from Jeffrey Chastine: http://www.youtube.com/watch?v=wy-B8NiaDHg
void loadBitmapFromFile(const char* filename, int* width, int* height, int* size, unsigned char** pixel_data) {
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		printf ("Couldn't open file... aborting\n");
	}
	short identifier = -1;
	fread(&identifier, 1, sizeof(short), fp); //printf ("Identifer is: %c\n", identifier);
	int filesize = -1;
	fread(&filesize, 1, sizeof(int), fp); //printf ("filesize is: %d\n", filesize);
	int reserved = -1;
	fread(&reserved, 1, sizeof(int), fp); //printf ("reserved is: %d\n", reserved);
	int bitmap_offset = -1;
	fread(&bitmap_offset, 1, sizeof(int), fp); //printf ("bitmap_offset is: %d\n", bitmap_offset);
	int bitmap_header_size = -1;
	fread(&bitmap_header_size, 1, sizeof(int), fp); //printf ("bitmap_header_size is: %d\n", bitmap_header_size);
	int bitmap_width = -1;
	fread(&bitmap_width, 1, sizeof(int), fp); //printf ("bitmap_width is: %d\n", bitmap_width);
	int bitmap_height = -1;
	fread(&bitmap_height, 1, sizeof(int), fp); //printf ("bitmap_height is: %d\n", bitmap_height);
	short bitmap_planes = -1;
	fread(&bitmap_planes, 1, sizeof(short), fp); //printf ("bitmap_planes is: %d\n", bitmap_planes);
	short bits_per_pixel= -1;
	fread(&bits_per_pixel, 1, sizeof(short), fp); //printf ("bits_per_pixel is: %d\n", bits_per_pixel);
	int compression = -1;
	fread(&compression, 1, sizeof(int), fp); //printf ("compression is: %d\n", compression);
	int bitmap_data_size = -1;
	fread(&bitmap_data_size, 1, sizeof(int), fp); //printf ("bitmap_data_size is: %d\n", bitmap_data_size);
	int hresolution = -1;
	fread(&hresolution, 1, sizeof(int), fp); //printf ("hresolution is: %d\n", hresolution);
	int vresolution = -1;
	fread(&vresolution, 1, sizeof(int), fp); //printf ("vresolution is: %d\n", vresolution);
	int num_colors = -1;
	fread(&num_colors, 1, sizeof(int), fp); //printf ("num_colors is: %d\n", num_colors);
	int num_important_colors = -1;
	fread(&num_important_colors, 1, sizeof(int), fp); //printf ("num_important_colors is: %d\n", num_important_colors);
	
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
void textbuffone(){

	int bmpWidth = -1;
	int bmpHeight = -1;
	int bmpSize = -1;
	loadBitmapFromFile("creature.bmp", &bmpWidth, &bmpHeight, &bmpSize, (unsigned char**)&imageData);

	GLint uniform_mytexture;
	GLint attribute_texcoord;

	glBindTexture(GL_TEXTURE_2D, texture_id[0]);
   	uniform_mytexture = glGetUniformLocation(prog, "texture");
  
   	glBindBuffer(GL_ARRAY_BUFFER, vbo_cube_texcoords);
   	glBufferData(GL_ARRAY_BUFFER, textsize, textarray, GL_STATIC_DRAW);

	attribute_texcoord = glGetAttribLocation(prog, "texCoord");
   	glEnableVertexAttribArray(attribute_texcoord);
  	glVertexAttribPointer(attribute_texcoord, 2, GL_FLOAT, GL_FALSE, 0, 0);

	
 
	glBindTexture(GL_TEXTURE_2D, texture_id[0]);
   	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);	
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
 	glTexImage2D(GL_TEXTURE_2D,0, GL_RGB,bmpWidth,bmpHeight,0,GL_RGB,GL_UNSIGNED_BYTE,imageData);

	glActiveTexture(GL_TEXTURE0);
	glUniform1i(uniform_mytexture, 0);

}

void textbufftwo(){

	int bmpWidth = -1;
	int bmpHeight = -1;
	int bmpSize = -1;
	loadBitmapFromFile("creature.bmp", &bmpWidth, &bmpHeight, &bmpSize, (unsigned char**)&imageData);

	GLint uniform_mytexture;
	GLint attribute_texcoord;

	glBindTexture(GL_TEXTURE_2D, texture_id[1]);
   	uniform_mytexture = glGetUniformLocation(prog, "texture");
  
   	glBindBuffer(GL_ARRAY_BUFFER, vbo_cube_texcoords);
   	glBufferData(GL_ARRAY_BUFFER, textsize, textarray, GL_STATIC_DRAW);

	attribute_texcoord = glGetAttribLocation(prog, "texCoord");
   	glEnableVertexAttribArray(attribute_texcoord);
  	glVertexAttribPointer(attribute_texcoord, 2, GL_FLOAT, GL_FALSE, 0, 0);

	
 
	glBindTexture(GL_TEXTURE_2D, texture_id[1]);
   	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);	
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
 	glTexImage2D(GL_TEXTURE_2D,0, GL_RGB,bmpWidth,bmpHeight,0,GL_RGB,GL_UNSIGNED_BYTE,imageData);

	glActiveTexture(GL_TEXTURE1);
	glUniform1i(uniform_mytexture, 1);

}

void textbuffthree(){

	int bmpWidth = -1;
	int bmpHeight = -1;
	int bmpSize = -1;
	loadBitmapFromFile("creature.bmp", &bmpWidth, &bmpHeight, &bmpSize, (unsigned char**)&imageData);

	GLint uniform_mytexture;
	GLint attribute_texcoord;

	glBindTexture(GL_TEXTURE_2D, texture_id[2]);
   	uniform_mytexture = glGetUniformLocation(prog, "texture");
  
   	glBindBuffer(GL_ARRAY_BUFFER, vbo_cube_texcoords);
   	glBufferData(GL_ARRAY_BUFFER, textsize, textarray, GL_STATIC_DRAW);

	attribute_texcoord = glGetAttribLocation(prog, "texCoord");
   	glEnableVertexAttribArray(attribute_texcoord);
  	glVertexAttribPointer(attribute_texcoord, 2, GL_FLOAT, GL_FALSE, 0, 0);

	
 
	glBindTexture(GL_TEXTURE_2D, texture_id[2]);
   	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);	
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
 	glTexImage2D(GL_TEXTURE_2D,0, GL_RGB,bmpWidth,bmpHeight,0,GL_RGB,GL_UNSIGNED_BYTE,imageData);

	glActiveTexture(GL_TEXTURE2);
	glUniform1i(uniform_mytexture, 2);

}

void textbuffcube(){

	int bmpWidth = -1;
	int bmpHeight = -1;
	int bmpSize = -1;
	loadBitmapFromFile("cube.bmp", &bmpWidth, &bmpHeight, &bmpSize, (unsigned char**)&cubeimageData);
					
	GLint uniform_mytexture;
	GLint attribute_texcoord;

	glBindTexture(GL_TEXTURE_2D, texture_id[3]);
   	uniform_mytexture = glGetUniformLocation(prog, "texture");
  
   	glBindBuffer(GL_ARRAY_BUFFER, vbo_cube_texcoords);
   	glBufferData(GL_ARRAY_BUFFER, textsize, textarray, GL_STATIC_DRAW);

	attribute_texcoord = glGetAttribLocation(prog, "texCoord");
   	glEnableVertexAttribArray(attribute_texcoord);
  	glVertexAttribPointer(attribute_texcoord, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glBindTexture(GL_TEXTURE_2D, texture_id[3]);
   	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);	
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
 	glTexImage2D(GL_TEXTURE_2D,0, GL_RGB,bmpWidth,bmpHeight,0,GL_RGB,GL_UNSIGNED_BYTE,cubeimageData);

	glActiveTexture(GL_TEXTURE3);
	glUniform1i(uniform_mytexture, 3);
}		
};


#endif
