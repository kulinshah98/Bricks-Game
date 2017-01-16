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
extern GLMatrices Matrices;



//Defination of classes
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
  float giveX();
};

#endif


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

//Defination of Variables
extern mirror_class mirror1, mirror2, mirror3;
extern map<int,laser_class> map_laser;
extern basket_class red_basket, green_basket;
extern map<int,brick_class> map_brick;
extern int game_over, score, num_brick;

//Define Functions
void checkCollisions();
void checkLaserMirrorCollision();
void reflectLaser(int laser_id, mirror_class mirror_cp);
void checkLaserBrickCollision();
void checkBrickBasketCollision();
