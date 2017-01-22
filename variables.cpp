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
int id_brick=0,id_laser=0,game_over=0,num_brick=0,score=0;
int level=1,green_basket_decrease=0,red_basket_increase=0,red_basket_decrease=0,green_basket_increase=0;
int space_held=0,s_held=0,a_held=0,d_held=0,f_held=0,canon_held=0,red_basket_held=0,green_basket_held=0;

float camera_rotation_angle = 90,now=0,prev_space=0,prev_brick=0;
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

#ifndef BASKET_H
#define BASKET_H

class basket_class
{
public:
  int obj_type,id;
  float angle,pos_x,pos_y,trans_x,trans_y;
  VAO * basket;

public:
  void createBasket();
  void init(int green);
  void drawBasket();
  void increaseX();
  void decreaseX();
  void assignX(float val);;
  float giveX();
};

#endif

basket_class red_basket, green_basket;

#ifndef LASER_H
#define LASER_H

class laser_class
{
public:
  int obj_type,id;
  float angle,pos_x,pos_y,trans_x,trans_y;
  VAO * laser;

public:
  void createLaser();
  void init( int id_laser, float posx, float posy, float canon_angle);
  void drawSingleLaser();
};

#endif

map<int,laser_class> map_laser;


#ifndef MIRROR_H
#define MIRROR_H

class mirror_class
{
public:
  int obj_type,id;
  float angle,pos_x,pos_y;
  VAO * mirror;

public:
  void createMirror();
  void init(int id_mir);
  void drawMirror();
};

#endif

mirror_class mirror1, mirror2, mirror3;

VAO * lower_block;
