#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//SDL includes
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include "header.h"

void loadGLSLParameters();

//GLSL program variable
GLuint program;

//window
SDL_Window* glWindow = NULL;

//SDL context
SDL_GLContext glContext;

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
	
	glViewport(0, 0, window.width, window.height);
	
	//shaders
    SetupGLSL("shaders/vert.vs", "shaders/frag.fs", &program);
    
    glUseProgram(program);
    
    glEnable(GL_DEPTH_TEST); 
    glCullFace(GL_BACK);
    
	SDL_bool quit = SDL_FALSE;
	SDL_Event event;
	
	GLfloat x = 0.0f;
	GLfloat z = 0.0f;
	
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
					case SDLK_LEFT: x -= 0.1; break;
					case SDLK_RIGHT: x += 0.1; break;
					case SDLK_UP: z += 0.1; break;
					case SDLK_DOWN: z -= 0.1; break;
					case SDLK_q: quit = SDL_TRUE; break; 
				}
			}	
		}	
		
	setShaderUniform1f(program, "x", x);
	setShaderUniform1f(program, "z", z); 
		
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0, 1.0, 1.0, 1.0);	
    glRecti(-1, -1, 1, 1);
   
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
