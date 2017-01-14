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
//typedef struct GLMatrices Matrices;


void keyboardDown (unsigned char key, int x, int y);

void keyboardUp (unsigned char key, int x, int y);

void keyboardSpecialDown (int key, int x, int y);

void keyboardSpecialUp (int key, int x, int y);

void mouseClick (int button, int state, int x, int y);

void mouseMotion (int x, int y);

void createTriangle ();

void createRectangle ();

void draw ();

void idle ();

void menu(int op);

void addGLUTMenus ();

void initGL (int width, int height);

struct VAO* create3DObject (GLenum primitive_mode, int numVertices, const GLfloat* vertex_buffer_data, GLfloat* color_buffer_data, GLenum fill_mode=GL_FILL);

struct VAO* create3DObject (GLenum primitive_mode, int numVertices, const GLfloat* vertex_buffer_data, const GLfloat red, const GLfloat green, const GLfloat blue, GLenum fill_mode=GL_FILL);

void draw3DObject (struct VAO* vao);

void reshapeWindow (int width, int height);

void initGLUT (int& argc, char** argv, int width, int height);

GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);

void keyPressed(unsigned char key, int x, int y);

extern GLuint programID;

extern float rectangle_rot_dir;
extern float triangle_rot_dir;
extern bool triangle_rot_status;
extern bool rectangle_rot_status;

extern float camera_rotation_angle;
extern float rectangle_rotation;
extern float triangle_rotation;
extern float triangle_x;

extern int id_num,level,id_brick;

extern VAO *triangle, *rectangle;

#ifndef CANON_H
#define CANON_H

class laser_canon
{
public:
  int obj_type,id;
  float angle,pos_x,pos_y;
  VAO * canon;

public:
  void createCanon();
  void drawCanon(glm::vec3 rot_coord);
  void init();
  void increaseY();
  void decreaseY();
  void tiltUp();
  void tiltDown();
};

#endif

extern laser_canon canon_obj;


#ifndef BRICK_H
#define BRICK_H

class brick_class
{
public:
  int obj_type,id,col_brick;
  float angle,pos_x,pos_y,trans_x,trans_y;
  VAO * brick;

public:
  void createBrick();
  void drawSingleBrick();
  void init(int id_brick);
};

#endif

extern std::map<int,brick_class> map_brick;

void makeBrick(int value);

void drawBricks();
