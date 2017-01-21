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
//typedef struct GLMatrices Matrices;



// Defination of classes

#ifndef CANON_H
#define CANON_H

class laser_canon
{
public:
  int obj_type,id;
  float angle,pos_x,pos_y;
  VAO * canon;
  VAO * canon_front;

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


// Defination of Variables
extern GLuint programID;
extern bool triangle_rot_status,rectangle_rot_status;

extern float camera_rotation_angle,rectangle_rotation,triangle_rotation,triangle_rot_dir,rectangle_rot_dir;
extern float triangle_x,now,prev_space,prev_brick;

extern int id_num,id_laser,level,id_brick,green_basket_decrease,red_basket_increase,red_basket_decrease,green_basket_increase,a_held,s_held,d_held,f_held;
extern int space_held,game_over,num_brick,score,canon_held;

extern VAO *triangle, *rectangle;
extern laser_canon canon_obj;
extern std::map<int,brick_class> map_brick;
extern basket_class red_basket, green_basket;
extern std::map<int,laser_class> map_laser;
extern mirror_class mirror1, mirror2, mirror3;
extern VAO * lower_block;

//Define Functions
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
struct VAO* create3DObject (GLenum primitive_mode, int numVertices, GLfloat* vertex_buffer_data, GLfloat* color_buffer_data, GLenum fill_mode=GL_FILL);
struct VAO* create3DObject (GLenum primitive_mode, int numVertices, GLfloat* vertex_buffer_data, const GLfloat red, const GLfloat green, const GLfloat blue, GLenum fill_mode=GL_FILL);
void draw3DObject (struct VAO* vao);
void reshapeWindow (int width, int height);
void initGLUT (int& argc, char** argv, int width, int height);
GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);
void keyPressed(unsigned char key, int x, int y);
void changeBasketPosition();
void changeCanonPosition();
void checkLaserBrickCollision();
void makeBrick();
void drawBricks();
void drawLasers();
void checkCollisions();
void checkBrickBasketCollision();
void checkLaserMirrorCollision();
void draw(VAO * obj, glm::vec3 trans, glm::vec3 pos, float angle_rot);
void cursor_routine(int x,int y);
void drawBackground();
