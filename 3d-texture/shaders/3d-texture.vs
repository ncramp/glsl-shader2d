#version 120

varying vec3 texCoord;

void main(){
	
	texCoord = gl_TexCoord[0].stp;
	gl_Position = ftransform();
}
