#version 120

varying vec2 texCoord;

void main(){
	
	texCoord = gl_TexCoord[0].st;
	gl_Position = ftransform();
}
