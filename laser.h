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

extern int id_num;
extern float camera_rotation_angle;
extern GLuint programID;



struct VAO* create3DObject (GLenum primitive_mode, int numVertices, GLfloat* vertex_buffer_data, GLfloat* color_buffer_data, GLenum fill_mode);

struct VAO* create3DObject (GLenum primitive_mode, int numVertices, GLfloat* vertex_buffer_data, const GLfloat red, const GLfloat green, const GLfloat blue, GLenum fill_mode);

void draw3DObject (struct VAO* vao);

void draw(VAO * obj, glm::vec3 trans, glm::vec3 pos, float angle_rot);


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
