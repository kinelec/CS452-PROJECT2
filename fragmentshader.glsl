#version 130


uniform vec4 Ambient;
uniform vec3 LightD1;
uniform vec3 LightC1;
uniform vec3 Half1;

in vec3 pass_normal;
in vec4 pass_color;

varying vec2 texCoordID;
uniform sampler2D texture;

out vec4 out_color;

void main(){
	vec3 N = pass_normal;
  	vec3 amb = vec3(Ambient);


	float diffuse1 = max(0.0, dot(N, normalize(LightD1)));
	float specular1 = max(0.0, dot(N, (Half1)));

	if(diffuse1 == 0.0)
    	specular1 = 0.0;
  	else
      	specular1 = pow(specular1, 7);

  	vec3 scatteredLight = Ambient.rgb + LightC1 * diffuse1;
  	vec3 reflectedLight = LightC1 * specular1 * 20;

  	vec3 rgb = min( (pass_color.rgb * amb) * scatteredLight + reflectedLight, vec3(1.0));

  //out_color = vec4(rgb, pass_color.a);
	out_color = vec4(rgb, pass_color.a)*texture2D(texture,texCoordID);
}
