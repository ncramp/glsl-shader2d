glsl-shader2d:main.o opengl.o
	gcc -o glsl-shader2d main.o opengl.o -lGL -lm -Wall -lSDL2
	
main.o: main.c
	gcc -c -g main.c header.h

opengl.o: opengl.c
	gcc -c -g opengl.c header.h

clean:
	rm main.o opengl.o 
