#version 120

uniform float x;
uniform float z;

void main(){
     gl_FragColor = vec4(x, z, 0.6, 1.0);
}
