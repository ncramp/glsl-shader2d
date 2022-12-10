#ifndef     GLXGL_HEADER
#define     GLXGL_HEADER

#include <GL/glx.h>
#include <GL/glxext.h>

extern PFNGLGENBUFFERSPROC glGenBuffers;
extern PFNGLBINDBUFFERPROC glBindBuffer;
extern PFNGLBUFFERDATAPROC glBufferData;
extern PFNGLDELETEBUFFERSPROC glDeleteBuffers;
extern PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;
extern PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray;
extern PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer;

extern PFNGLGETATTRIBLOCATIONPROC glGetAttribLocation;
extern PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation;
extern PFNGLUNIFORM1FPROC glUniform1f;
extern PFNGLUNIFORM1IPROC glUniform1i;

extern PFNGLUNIFORM3FVPROC glUniform3fv;
extern PFNGLUNIFORM4FVPROC glUniform4fv;
extern PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv;
extern PFNGLUNIFORMMATRIX3FVPROC glUniformMatrix3fv;
//extern PFNGLPROGRAMUNIFORM3FPROC glProgramUniform3f;

extern PFNGLGENVERTEXARRAYSPROC glGenVertexArrays;
extern PFNGLBINDVERTEXARRAYPROC glBindVertexArray;
extern PFNGLBINDFRAGDATALOCATIONPROC glBindFragDataLocation;

extern PFNGLUSEPROGRAMPROC glUseProgram;
extern PFNGLCREATESHADERPROC glCreateShader;
extern PFNGLDELETESHADERPROC glDeleteShader;
extern PFNGLCOMPILESHADERPROC glCompileShader;
extern PFNGLCREATEPROGRAMPROC glCreateProgram;
extern PFNGLATTACHSHADERPROC glAttachShader;
extern PFNGLLINKPROGRAMPROC glLinkProgram;
extern PFNGLSHADERSOURCEPROC glShaderSource;
extern PFNGLGETSHADERIVPROC glGetShaderiv;
extern PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog;
extern PFNGLISPROGRAMPROC glIsProgram;

extern PFNGLISVERTEXARRAYPROC glIsVertexArray;

extern PFNGLGETPROGRAMIVPROC glGetProgramiv;
extern PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog;

extern PFNGLGETUNIFORMFVPROC glGetUniformfv;

//current and new mouse positions


typedef struct{
    int width, height;
}Win;

Win window;
// basic timing

/* main.c */

/* opengl.c */

GLboolean glXWindow(Display *dpy, const char *name, int x, int y, int width, int height, Window *winRet, GLXContext *ctxRet);
GLboolean glXKillWindow(Display *dpy, Window *win, GLXContext *ctx);
void PointToVector(int x, int y, int width, int height, float v[3]);

/* shader.c */
GLint getShaderUniform(GLuint program, const char* name);
GLboolean shaderMatrix(GLuint program, const char *name, float mat[16]);
GLboolean SetupGLSL(const char *vertexPath,  const char *fragmentPath,  GLuint *progRet);
GLboolean linkProgram(GLuint program);
GLboolean compileShader(GLuint shader, GLchar* source);
GLchar *readShader(const char *filename);

/* opengl.c */

void loadExtensions();
GLuint vertexDataVAO(GLuint program, int vsize, GLfloat vertices[], GLfloat normals[], GLfloat texcoords[]);
void setShaderUniform1f(GLuint program, const char* name, GLfloat value);
void setShaderUniform1i(GLuint program, const char* name, GLint value);
void setShaderUniform3fv(GLuint program, const char* name, GLfloat value[3]);
void setShaderUniform4fv(GLuint program, const char* name, GLfloat value[4]);
void printGLSLMatrix4x4(GLuint program, const char* name);
void fpsView(GLint mouse_x, GLint mouse_y, GLfloat cameraFront[3]);

/* texture.c */

typedef struct
{
	GLubyte	*imageData;
	GLuint	bpp;											// Image Color Depth In Bits Per Pixel.
	GLuint	width;											// Image Width
	GLuint	height;											// Image Height
	GLuint	texID;											// Texture ID Used To Select A Textur
	GLuint texNum;

	// to hold GLSL uniform return value
	GLint   textureLoc;
	GLchar *textureName;
} TextureImage;												

TextureImage tex[10];
GLboolean setTextureSampler(GLuint program, TextureImage *texture, GLchar *textureName);
void makeTexture(TextureImage *texture);
GLboolean LoadTGA(TextureImage *texture, const char *filename);

#endif


