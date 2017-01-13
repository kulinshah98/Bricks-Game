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
using namespace std;

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

GLMatrices Matrices;

GLuint programID;

float triangle_rot_dir = 1;
float rectangle_rot_dir = 1;
bool triangle_rot_status = true;
bool rectangle_rot_status = true;
int id_brick=0;
int level=1;

float camera_rotation_angle = 90;
float rectangle_rotation = 0;
float triangle_rotation = 0;
float triangle_x = 2.0f;

VAO *triangle, *rectangle;

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

laser_canon canon_obj;

#ifndef BRICK_H
#define BRICK_H

class brick_class
{
public:
  int obj_type,id;
  float angle,pos_x,pos_y;
  VAO * brick;

public:
  void createBrick();
  void drawSingleBrick();
  void init(int id_brick);
};

#endif

map<int,brick_class> map_brick;
