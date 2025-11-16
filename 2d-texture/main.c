#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//SDL includes
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include "header.h"

void loadGLSLParameters();

GLuint program;

Win window;

//window
SDL_Window* glWindow = NULL;

//SDL context
SDL_GLContext glContext;

GLuint texture;

static void initTexture2D(void){
	
	#define SIZE 16
   {
      GLubyte tex2d[SIZE][SIZE][3];
      GLint s, t;

	 for (t = 0; t < SIZE; t++) {
		for (s = 0; s < SIZE; s++) {
		#if 0
		   tex2d[s][t][0] = (s < SIZE/2) ? 0 : 255;
		   tex2d[s][t][1] = (t < SIZE/2) ? 0 : 255;
		   tex2d[s][t][2] = (s < SIZE/2) ? 0 : 255;
		#else
		   tex2d[s][t][0] = s*255/(SIZE-1);
		   tex2d[s][t][1] = t*255/(SIZE-1);
		   tex2d[s][t][2] = s*255/(SIZE-1);
		#endif
		}
	 }
      
      glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
      glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_REPEAT);
      glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
      glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

      glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
      glTexImage2D(GL_TEXTURE_2D, 0, 3, SIZE, SIZE, 0, GL_RGB, GL_UNSIGNED_BYTE, tex2d);
      glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
      
      glEnable(GL_TEXTURE_2D);
   }
}

int main(int argc, char **argv){

	//set initial window width and height - this will be overridden by window events if the window is resized etc
    window.width = 1024;
    window.height = 800;
    
	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		fprintf(stderr, "failure of SDL_Init %s\n", SDL_GetError());
		exit(1);
	}
		
	//set OpenGL 2.1
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
			
	//SDL window
	glWindow = SDL_CreateWindow("OpenGL", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, window.width, window.height, SDL_WINDOW_OPENGL);
	if(glWindow == NULL){
		fprintf(stderr, "failure of SDL_CreateWindow %s\n", SDL_GetError());
		exit(1);
	}
			
	glContext = SDL_GL_CreateContext(glWindow);
	if(glContext == NULL){
		fprintf(stderr, "failure of SDL_CreateWindow %s\n", SDL_GetError());
		exit(1);
	}
	
	//Use Vsync - RESEARCH NEEDED on this
	if(SDL_GL_SetSwapInterval( 1 ) < 0 ) {
		fprintf(stderr,"Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError() );
		exit(1); 
	} 
	
	//GLSL extensions - error check needed
	loadExtensions();	
	
	//shaders
    if(SetupGLSL("shaders/2d-texture.vs", "shaders/2d-texture.fs", &program) == GL_FALSE){
		fprintf(stderr,"SetupGLSL returned GL_FALSE\n");
		exit(1);
	}
	
    glViewport(0, 0, window.width, window.height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -0.5, 1000.0);
	glMatrixMode(GL_MODELVIEW);
	
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	initTexture2D();

	setShaderUniform1i(program, "texture", 0);
    glUseProgram(program);
	
	SDL_bool quit = SDL_FALSE;
	SDL_Event event;
	
	//While application is running
	while(!quit)
	{
		//Handle events on queue 
		while(SDL_PollEvent( &event ) != 0) 
		{ 
			//User requests quit 
			if(event.type == SDL_QUIT) 
			{ 
				quit = SDL_TRUE; 
			} 	
			if(event.type == SDL_KEYDOWN)
			{ 
				switch(event.key.keysym.sym)
				{
					case SDLK_UP: z+= step; break;
					case SDLK_DOWN: z-= step; break;
					case SDLK_q: quit = SDL_TRUE; break; 
				}
			}	
		}	
	
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0, 1.0, 1.0, 1.0);	

	glBegin(GL_QUADS);
	glTexCoord2f(1,0);
	glVertex3f( 0.9, -0.9, -30.0);
	glTexCoord2f(1,1);
	glVertex3f( 0.9,  0.9, -30.0);
	glTexCoord2f(0,1);
	glVertex3f(-0.9,  0.9, -30.0);
	glTexCoord2f(0,0);
	glVertex3f(-0.9,  -0.9, -30.0);
	glEnd();

	glFlush();
    
	//GL 'swap buffers'
	SDL_GL_SwapWindow( glWindow );
	 
	}

	// disable GLSL program
	glUseProgram(0);

	//Destroy window	
	SDL_DestroyWindow(glWindow);
	glWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}
