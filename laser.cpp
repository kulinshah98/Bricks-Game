#include "laser.h"


void laser_class::createLaser()
{
  GLfloat vertex_buffer_data [] = {
    pos_x - 0.12, pos_y - 0.02, 0, // vertex 1
    pos_x + 0.12, pos_y - 0.02, 0, // vertex 2
    pos_x + 0.12, pos_y + 0.02, 0, // vertex 3

    pos_x + 0.12, pos_y + 0.02, 0, // vertex 3
    pos_x - 0.12, pos_y + 0.02, 0, // vertex 4
    pos_x - 0.12, pos_y - 0.02, 0,  // vertex 1

    pos_x + 0.14, pos_y, 0,
    pos_x + 0.10, pos_y + 0.11, 0,
    pos_x + 0.10, pos_y - 0.11, 0,

    pos_x - 0.10, pos_y, 0,
    pos_x - 0.14, pos_y + 0.09, 0,
    pos_x - 0.14, pos_y - 0.09, 0
  };

   GLfloat color_buffer_data [] = {
    0,0,1, // color 1
    0,0,1, // color 2
    0,0,1, // color 3

    0,0,1, // color 3
    0,0,1, // color 4
    0,0,1,  // color 1

    0,0,1,
    0,0,1,
    0,0,1,

    0,0,1,
    0,0,1,
    0,0,1
  };
  // create3DObject creates and returns a handle to a VAO that can be used later
  laser = create3DObject(GL_TRIANGLES, 12, vertex_buffer_data, color_buffer_data, GL_FILL);
}

void laser_class::init( int id_laser, float posx, float posy, float canon_angle)
{
  angle = canon_angle;
  id = id_laser;
  pos_x = posx - 3.6 + 0.4*cos(canon_angle*M_PI/90.0f);
  pos_y = posy + 0.4*sin(canon_angle*M_PI/180.0f);
  trans_x = 0;
  trans_y = 0;
}

void laser_class::drawSingleLaser()
{
  trans_y = trans_y + 0.05*sin(angle*M_PI/180.0f);
  trans_x = trans_x + 0.05*cos(angle*M_PI/180.0f);
  draw(laser, glm::vec3( trans_x + 0.4*cos(angle*M_PI/180.0f), trans_y+ 0.4*sin(angle*M_PI/180.0f), 0), glm::vec3(pos_x, pos_y, 0), angle);
}
