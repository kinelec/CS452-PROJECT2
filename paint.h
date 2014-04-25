#ifndef PAINT_H_
#define PAINT_H_
#include "initShaders.h"

GLuint prog;

//generates random float from min and max
GLfloat randomgen(float min, float max){
	return min + static_cast <GLfloat> (rand())/(static_cast <GLfloat> (RAND_MAX/(max-min)));
}

class paint{
public:
	//buffers
	GLuint vaoID,vboID[3],eboID, texBufferID, texCoordID, texID;
	GLubyte* imageData;
	//vertex arrays & size
	GLfloat* vertarray;
	int vertsize;
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
    	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,eboID);
    	glBufferData(GL_ELEMENT_ARRAY_BUFFER,elemssize,elemsarray,GL_STATIC_DRAW);
		//transformation
		glm::mat4 trans;
		trans=glm::translate(trans,objTran);
    	GLint tempLoc = glGetUniformLocation(prog,"modelMatrix");
    	glUniformMatrix4fv(tempLoc,1,GL_FALSE,&trans[0][0]);

		glEnableVertexAttribArray(0);
    	glEnableVertexAttribArray(1);
		glEnableVertexAttribArray(2);		

		//movement; generates random x value
		if(move == 1){
			if(objTran.y <= -31.5){
				objTran.y = 27.0;
				objTran.x = randomgen(-27.0, 2.5);
			}
			else objTran.y -= speed;
		}
		//when collision occurs
		else if(move == 2){
			objTran.y = -80.0;
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
void textbuff(){
					
	int bmpWidth = -1;
	int bmpHeight = -1;
	int bmpSize = -1;
	loadBitmapFromFile("creature.bmp", &bmpWidth, &bmpHeight, &bmpSize, (unsigned char**)&imageData);
	
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
}
			
};

#endif
