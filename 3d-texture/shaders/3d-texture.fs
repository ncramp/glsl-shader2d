#version 120

varying vec3 texCoord;

uniform sampler3D texture;

void main()
{
	gl_FragColor = texture3D(texture, texCoord);
}
