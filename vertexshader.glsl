#version 130

uniform mat4 Matrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;

in vec3 in_position;

in vec4 in_color;
out vec4 pass_color;
in vec3 in_normal;
out vec3 pass_normal;
attribute vec2 texCoord;
out vec2 texCoordID;

void main(){
	pass_normal = in_normal;
  	pass_color=in_color;
	gl_Position = Matrix*viewMatrix*modelMatrix*vec4(in_position,1.0); 
	texCoordID = texCoord;
}
