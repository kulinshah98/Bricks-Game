#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

#include <GL/glew.h>
#include <GL/glu.h>
#include <GL/freeglut.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

extern GLuint programID;

extern float triangle_rot_dir;
extern float rectangle_rot_dir;
extern bool triangle_rot_status;
extern bool rectangle_rot_status;

extern float camera_rotation_angle;
extern float rectangle_rotation;
extern float triangle_rotation;
extern float triangle_x;

extern VAO *triangle, *rectangle;
