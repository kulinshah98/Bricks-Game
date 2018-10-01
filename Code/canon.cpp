#include "canon.h"


void laser_canon::createCanon ()
{
  // GL3 accepts only Triangles. Quads are not supported static
  GLfloat vertex_buffer_data [] = {
    -4.0,-0.15,0, // vertex 1
    -3.2,-0.15,0, // vertex 2
    -3.2, 0.15,0, // vertex 3

    -3.2, 0.15,0, // vertex 3
    -4.0, 0.15,0, // vertex 4
    -4.0,-0.15,0  // vertex 1
  };

   GLfloat color_buffer_data [] = {
     0.10f,0.37f,0.57f,
     0.10f,0.37f,0.57f,
     0.10f,0.37f,0.57f,

     0.10f,0.37f,0.57f,
     0.10f,0.37f,0.57f,
     0.10f,0.37f,0.57f
  };

  GLfloat vertex_buffer_data2 [] = {
    -4.0,-0.35,0, // vertex 1
    -3.7,-0.35,0, // vertex 2
    -3.7, 0.35,0, // vertex 3

    -3.7, 0.35,0, // vertex 3
    -4.0, 0.35,0, // vertex 4
    -4.0,-0.35,0  // vertex 1
  };

  GLfloat color_buffer_data2 [] = {
    0.10f,0.37f,0.57f,
    0.10f,0.37f,0.57f,
    0.10f,0.37f,0.57f,

    0.10f,0.37f,0.57f,
    0.10f,0.37f,0.57f,
    0.10f,0.37f,0.57f
  };
  // create3DObject creates and returns a handle to a VAO that can be used later
  canon_back = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data2, color_buffer_data2, GL_FILL);
  canon = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, color_buffer_data, GL_FILL);
}

void laser_canon::drawCanon (glm::vec3 rot_coord)
{
  draw(canon_back, glm::vec3(pos_x, pos_y, 0), glm::vec3(0,0,0), 0);
  draw(canon, glm::vec3(pos_x, pos_y, 0), glm::vec3(-4.0,0,0), angle);
}

void laser_canon::init()
{
  pos_x=0;
  pos_y=0;
  angle=0.0f;
}

void laser_canon::increaseY()
{
  if(pos_y < 3.7)
  {
    pos_y=pos_y+0.05;
  }
}

void laser_canon::decreaseY()
{
  if(pos_y > -3.1)
  {
    pos_y=pos_y-0.05;
  }
}

void laser_canon::tiltUp()
{
  if(angle < 88)
  {
    angle=angle+1;
  }
}

void laser_canon::tiltDown()
{
  if(angle > -88)
  {
    angle=angle-1;
  }
}
