#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <map>

#include <GL/glew.h>
#include <GL/glu.h>
#include <GL/freeglut.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

struct VAO {
    GLuint VertexArrayID;
    GLuint VertexBuffer;
    GLuint ColorBuffer;

    GLenum PrimitiveMode;
    GLenum FillMode;
    int NumVertices;
};
typedef struct VAO VAO;

struct GLMatrices {
	glm::mat4 projection;
	glm::mat4 model;
	glm::mat4 view;
	GLuint MatrixID;
};
extern GLMatrices Matrices;

GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);

struct VAO* create3DObject (GLenum primitive_mode, int numVertices, GLfloat* vertex_buffer_data, GLfloat* color_buffer_data, GLenum fill_mode);

struct VAO* create3DObject (GLenum primitive_mode, int numVertices, GLfloat* vertex_buffer_data, const GLfloat red, const GLfloat green, const GLfloat blue, GLenum fill_mode);

void draw3DObject (struct VAO* vao);

void reshapeWindow (int width, int height);

void initGLUT (int& argc, char** argv, int width, int height);


void keyboardDown (unsigned char key, int x, int y);

void keyboardUp (unsigned char key, int x, int y);

void keyboardSpecialDown (int key, int x, int y);

void keyboardSpecialUp (int key, int x, int y);

void keyPressed(unsigned char key, int x, int y);

void mouseClick (int button, int state, int x, int y);

void mouseMotion (int x, int y);

void draw ();

void idle ();

void draw(VAO * obj, glm::vec3 trans, glm::vec3 pos, float angle_rot);

extern GLuint programID;

extern float rectangle_rot_dir;
extern float triangle_rot_dir;
extern bool triangle_rot_status;
extern bool rectangle_rot_status;

extern float camera_rotation_angle;
extern float rectangle_rotation;
extern float triangle_rotation;
extern float triangle_x;

extern VAO *triangle, *rectangle;

extern int id_num;

void makeBrick(int value);
