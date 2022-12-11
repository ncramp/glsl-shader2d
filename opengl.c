#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "header.h"

/* made change to opengl.c */ 

/* OpenGL Extensions variables */

PFNGLGENBUFFERSPROC glGenBuffers;
PFNGLBINDBUFFERPROC glBindBuffer;
PFNGLBUFFERDATAPROC glBufferData;
PFNGLDELETEBUFFERSPROC glDeleteBuffers;
PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;
PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray;
PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer;

PFNGLGETATTRIBLOCATIONPROC glGetAttribLocation;
PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation;
PFNGLUNIFORM1FPROC glUniform1f;
PFNGLUNIFORM1IPROC glUniform1i;
PFNGLUNIFORM3FVPROC glUniform3fv;
PFNGLUNIFORM4FVPROC glUniform4fv;
PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv;
PFNGLUNIFORMMATRIX3FVPROC glUniformMatrix3fv;
//extern PFNGLPROGRAMUNIFORM3FPROC glProgramUniform3f;

PFNGLGENVERTEXARRAYSPROC glGenVertexArrays;
PFNGLBINDVERTEXARRAYPROC glBindVertexArray;
PFNGLBINDFRAGDATALOCATIONPROC glBindFragDataLocation;

PFNGLUSEPROGRAMPROC glUseProgram;
PFNGLCREATESHADERPROC glCreateShader;
PFNGLDELETESHADERPROC glDeleteShader;
PFNGLCOMPILESHADERPROC glCompileShader;
PFNGLCREATEPROGRAMPROC glCreateProgram;
PFNGLATTACHSHADERPROC glAttachShader;
PFNGLLINKPROGRAMPROC glLinkProgram;
PFNGLSHADERSOURCEPROC glShaderSource;
PFNGLGETSHADERIVPROC glGetShaderiv;
PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog;
PFNGLISPROGRAMPROC glIsProgram;

PFNGLGETPROGRAMIVPROC glGetProgramiv;
PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog;


void loadExtensions(){

    glGenBuffers = (PFNGLGENBUFFERSARBPROC)glXGetProcAddress((const GLubyte *)"glGenBuffers");
    if(glGenBuffers == NULL){
        printf("glGenBuffers NULL\n");
    }

    glBindBuffer = (PFNGLBINDBUFFERPROC)glXGetProcAddress((const GLubyte *)"glBindBuffer");
    if(glBindBuffer == NULL){
        printf("glBindBuffer NULL\n");
    }

    glBufferData = (PFNGLBUFFERDATAPROC)glXGetProcAddress((const GLubyte *)"glBufferData");
    if(glBufferData == NULL){
        printf("glBufferData NULL\n");
    }

    glDeleteBuffers = (PFNGLDELETEBUFFERSPROC)glXGetProcAddress((const GLubyte *)"glDeleteBuffers");
    if(glDeleteBuffers == NULL){
        printf("glDeleteBuffers NULL\n");
    }

    glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)glXGetProcAddress((const GLubyte *)"glEnableVertexAttribArray");
    if(glEnableVertexAttribArray == NULL){
        printf("glEnableVertexAttribArray NULL\n");
    }

    glDisableVertexAttribArray = (PFNGLDISABLEVERTEXATTRIBARRAYPROC)glXGetProcAddress((const GLubyte *)"glDisableVertexAttribArray");
    if(glDisableVertexAttribArray == NULL){
        printf("glDisableVertexAttribArray NULL\n");
    }

    glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)glXGetProcAddress((const GLubyte *)"glVertexAttribPointer");
    if(glVertexAttribPointer == NULL){
        printf("glVertexAttribPointer NULL\n");
    }

    glUseProgram = (PFNGLUSEPROGRAMPROC)glXGetProcAddress((const GLubyte *)"glUseProgram");
    if(glUseProgram == NULL){
         printf("glUseProgram NULL\n");
    }

    glCreateShader = (PFNGLCREATESHADERPROC)glXGetProcAddress((const GLubyte *)"glCreateShader");
    if(glCreateShader == NULL){
        printf("glCreateShader NULL\n");
    }

    glCompileShader = (PFNGLCOMPILESHADERPROC)glXGetProcAddress((const GLubyte *)"glCompileShader");
    if(glCompileShader == NULL){
        printf("glCreateShader NULL\n");
    }

    glDeleteShader = (PFNGLDELETESHADERPROC)glXGetProcAddress((const GLubyte *)"glDeleteShader");
    if(glDeleteShader == NULL){
        printf("glDeleteShader NULL\n");
    }

    glCreateProgram = (PFNGLCREATEPROGRAMPROC)glXGetProcAddress((const GLubyte *)"glCreateProgram");
    if(glCreateProgram == NULL){
        printf("glCreateProgram NULL\n");
    }

    glAttachShader = (PFNGLATTACHSHADERPROC)glXGetProcAddress((const GLubyte *)"glAttachShader");
    if(glAttachShader == NULL){
        printf("glAttachShader NULL\n");
    }

    glLinkProgram = (PFNGLLINKPROGRAMPROC)glXGetProcAddress((const GLubyte *)"glLinkProgram");
    if(glLinkProgram == NULL){
        printf("glLinkProgram NULL\n");
    }

    glShaderSource = (PFNGLSHADERSOURCEPROC)glXGetProcAddress((const GLubyte *)"glShaderSource");
    if(glShaderSource == NULL){
        printf("glShaderSource NULL\n");
    }

    glGetShaderiv = (PFNGLGETSHADERIVPROC)glXGetProcAddress((const GLubyte *)"glGetShaderiv");
    if(glGetShaderiv == NULL){
        printf("glGetShaderiv NULL\n");
    }

    glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)glXGetProcAddress((const GLubyte *)"glGetShaderInfoLog");
    if(glGetShaderInfoLog == NULL){
        printf("glGetShaderInfoLog NULL\n");
    }

    glIsProgram = (PFNGLISPROGRAMPROC)glXGetProcAddress((const GLubyte *)"glIsProgram");
    if(glIsProgram == NULL){
        printf("glIsProgram NULL\n");
    }
    /*
    glIsVertexArray = (PFNGLISVERTEXARRAYPROC) glXGetProcAddress((const GLubyte *) "glIsVertexArray");
    if(glIsVertexArray == NULL){
		printf("glIsVertexArray NULL\n");
	}
*/
    glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)glXGetProcAddress((const GLubyte *)"glGetUniformLocation");
    if(glGetUniformLocation == NULL){
        printf("glGetUniformLocation NULL\n");
    }

    glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC)glXGetProcAddress((const GLubyte *)"glUniformMatrix4fv");
    if(glUniformMatrix4fv == NULL){
        printf("glUniformMatrix4fv NULL\n");
    }

    glUniformMatrix3fv = (PFNGLUNIFORMMATRIX3FVPROC)glXGetProcAddress((const GLubyte *)"glUniformMatrix3fv");
    if(glUniformMatrix3fv == NULL){
        printf("glUniformMatrix3fv NULL\n");
    }

    glUniform4fv = (PFNGLUNIFORM4FVPROC)glXGetProcAddress((const GLubyte *)"glUniform4fv");
     if(glUniform4fv == NULL){
        printf("glUniform4fv NULL\n");
    }

    glUniform3fv = (PFNGLUNIFORM3FVPROC)glXGetProcAddress((const GLubyte *)"glUniform3fv");
     if(glUniform3fv == NULL){
        printf("glUniform3fv NULL\n");
    }

/*
    glProgramUniform3f = (PFNGLPROGRAMUNIFORM3FPROC)glXGetProcAddress((const GLubyte *)"glProgramUniform3f");
     if(glProgramUniform3f == NULL){
        printf("glProgramUniform3f NULL\n");
    }
*/
    glGetProgramiv = (PFNGLGETPROGRAMIVPROC)glXGetProcAddress((const GLubyte *)"glGetProgramiv");
    if(glGetProgramiv == NULL){
        printf("glGetProgramiv NULL\n");
    }

    glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)glXGetProcAddress((const GLubyte *)"glGetProgramInfoLog");
    if(glGetProgramInfoLog == NULL){
        printf("glGetProgramInfoLog NULL\n");
    }

    glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)glXGetProcAddress((const GLubyte *)"glGenVertexArrays");
    if(glGenVertexArrays == NULL){
        printf("glGenVertexArrays NULL\n");
    }

    glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)glXGetProcAddress((const GLubyte *)"glBindVertexArray");
    if(glBindVertexArray == NULL){
        printf("glBindVertexArray NULL\n");
    }

    glGetAttribLocation = (PFNGLGETATTRIBLOCATIONPROC)glXGetProcAddress((const GLubyte *)"glGetAttribLocation");
    if(glGetAttribLocation == NULL){
        printf("glGetAttribLocation NULL\n");
    }

    glBindFragDataLocation = (PFNGLBINDFRAGDATALOCATIONPROC)glXGetProcAddress((const GLubyte *)"glBindFragDataLocation");
    if(glBindFragDataLocation == NULL){
        printf("glBindFragDataLocation NULL\n");
    }

    glUniform1f = (PFNGLUNIFORM1FPROC)glXGetProcAddress((const GLubyte *)"glUniform1f");
    if(glUniform1f == NULL){
        printf("glUniform1f NULL\n");
    }

    glUniform1i = (PFNGLUNIFORM1IPROC)glXGetProcAddress((const GLubyte *)"glUniform1i");
    if(glUniform1i == NULL){
        printf("glUniform1i NULL\n");
    }
    
    /* SEGMENTATION FAULT OCCURS WHEN BELOW IS LOADED - works without! */
  /*
    glGetUniformfv = (PFNGLGETUNIFORMFVPROC)glXGetProcAddress((const GLubyte *)"glGetUniformfv");
    if(glGetUniformfv == NULL){
        printf("glGetUniformfv NULL\n");
    }
    */
}

/**
 * GLSL Shader functions
*/

GLint getShaderUniform(GLuint program, const char* name){

    GLint valueLoc = glGetUniformLocation(program, name);
    if( valueLoc == -1){
        fprintf(stderr, "shader value %s NULL\n", name);
    }
    return valueLoc;
}

void setShaderUniform1f(GLuint program, const char* name, GLfloat value){

    GLint valueLoc = getShaderUniform(program, name);
    glUniform1f(valueLoc, value);
}

void setShaderUniform1i(GLuint program, const char* name, GLint value){

    GLint valueLoc = getShaderUniform(program, name);
    glUniform1i(valueLoc, value);
}

void setShaderUniform3fv(GLuint program, const char* name, GLfloat value[3]){
	
	GLint valueLoc = getShaderUniform(program, name);
	glUniform3fv(valueLoc, 1, value);
}

void setShaderUniform4fv(GLuint program, const char* name, GLfloat value[4]){
	
	GLint valueLoc = getShaderUniform(program, name);
	glUniform4fv(valueLoc, 1, value);
}

GLboolean setTextureSampler(GLuint program, TextureImage *texture, GLchar *textureName){

	//add name to *texture
	
	//strcpy(texture->textureName, textureName);
	
	//printf("here\n");
	texture->textureLoc = glGetUniformLocation(program, textureName);
	if(texture->textureLoc == -1){
		fprintf(stderr, "texture %s NULL\n", textureName);
		return GL_FALSE;
	}
	
	glUniform1i(texture->textureLoc, (texture->texNum - 1));
	return GL_TRUE;
}

GLboolean shaderMatrix(GLuint program, const char *name, float mat[16]){

   GLint valueLoc = getShaderUniform(program, name);
   glUniformMatrix4fv(valueLoc, 1, GL_FALSE, mat);
   return GL_TRUE;
}

GLboolean SetupGLSL(const char *vertexPath,  const char *fragmentPath, GLuint *progRet){

    GLuint vs, fs;
    GLchar *vertexShader = readShader(vertexPath);
    GLchar *fragmentShader = readShader(fragmentPath);

    if(strlen(vertexShader) > 0 && strlen(fragmentShader) > 0){
        printf("\nVERTEX_SHADER %s ..source string is present \n", vertexShader);
        printf("\nFRAGMENT_SHADER %s ..source string is present \n", fragmentShader);
    }else{
		return GL_FALSE;
	}

    if((vs = glCreateShader(GL_VERTEX_SHADER)) == 0){
	   fprintf(stderr, "vertex shader error - glCreateShader() \n");
       return GL_FALSE;
    }

    if((fs = glCreateShader(GL_FRAGMENT_SHADER)) == 0){
	   fprintf(stderr, "fragment shader error - glCreateShader() \n");
       return GL_FALSE;
    }
 
    if(!compileShader(vs, vertexShader) || !compileShader(fs, fragmentShader)){
	  fprintf(stderr, "could not compile shaders \n");
      return GL_FALSE;
    }

    GLuint program = glCreateProgram();

    //test needed here - glIsProgram()

    glAttachShader(program, vs);
    glAttachShader(program, fs);

    linkProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    free(vertexShader);
    free(fragmentShader);

    *progRet = program;

    return GL_TRUE;
}

GLboolean linkProgram(GLuint program){

	glLinkProgram(program);

	int infoLogLength = 0;
	int charsWritten = 0;

	glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLogLength);
	if(infoLogLength > 0){

		GLchar* infoLog = (GLchar *) malloc(infoLogLength);
		if(infoLog == NULL){
			fprintf(stderr, "infoLog NULL - could not allocate infolog buffer");
			return GL_FALSE;
		}

		glGetProgramInfoLog(program, infoLogLength, &charsWritten, infoLog);
		if(charsWritten > 0){
			fprintf(stderr, "linkProgram infoLog");
			return GL_FALSE;
		}

		free(infoLog);

		return GL_FALSE;
	}
	return GL_TRUE;
}

GLboolean compileShader(GLuint shader, GLchar* source){

     int compiled = 1;
     int infoLogLength = 0;
     int charsWritten = 0;

     glShaderSource(shader, 1, (const GLchar**) &source, NULL);
     glCompileShader(shader);

     glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
        if(compiled == 0){

                glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);
                if(infoLogLength > 0){

                    GLchar *infoLog = (GLchar *)malloc(infoLogLength);
                    if(infoLog == NULL){
					   fprintf(stderr, "infoLog NULL - could not allocate infolog buffer");
                       return GL_FALSE;
                    }

                    glGetShaderInfoLog(shader, infoLogLength, &charsWritten, infoLog);
                    if(charsWritten > 0){
                        fprintf(stderr, "linkProgram infoLog");
                        return GL_FALSE; 
                    }

                    free(infoLog);

                    return GL_FALSE;
                }
    }

    return GL_TRUE;
}

GLchar *readShader(const char *filename){

    GLchar *content = NULL;
    int count = 0;

    FILE *file;

    if((file = fopen(filename, "r")) != NULL){

        fseek(file, 0, SEEK_END);
        count = ftell(file);
        rewind(file);

        if(count > 0){
            content = (char *)malloc(sizeof(char) * (count + 1));
            count = fread(content, sizeof(char), count, file);
            /* adding a new line and end */
            content[count] = '\0';
        }
        fclose(file);

    }else{
        fprintf(stderr,"%s\n", (const char*)"Error reading shader file");
        exit(1);
    }

    return content;
}
