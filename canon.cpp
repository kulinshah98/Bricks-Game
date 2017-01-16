#include "canon.h"


void laser_canon::createCanon ()
{
  // GL3 accepts only Triangles. Quads are not supported static
  GLfloat vertex_buffer_data [] = {
    -4.0,-0.25,0, // vertex 1
    -3.2,-0.25,0, // vertex 2
    -3.2, 0.25,0, // vertex 3

    -3.2, 0.25,0, // vertex 3
    -4.0, 0.25,0, // vertex 4
    -4.0,-0.25,0  // vertex 1
  };

   GLfloat color_buffer_data [] = {
    0,0,1, // color 1
    0,0,1, // color 2
    0,0,1, // color 3

    0,0,1, // color 3
    0,0,1, // color 4
    0,0,1  // color 1
  };
  // create3DObject creates and returns a handle to a VAO that can be used later
  canon = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, color_buffer_data, GL_FILL);
}

void laser_canon::drawCanon (glm::vec3 rot_coord)
{
  draw(canon, glm::vec3(pos_x, pos_y, 0), glm::vec3(-4,0,0), angle);
}

void laser_canon::init()
{
  pos_x=0;
  pos_y=0;
  angle=0.0f;
}

void laser_canon::increaseY()
{
  pos_y=pos_y+0.05;
  printf("%f",pos_y);
}

void laser_canon::decreaseY()
{
  pos_y=pos_y-0.05;
  printf("%f",pos_y);
}

void laser_canon::tiltUp()
{
  angle=angle+1;
  //printf("%f Up\n",angle);
}

void laser_canon::tiltDown()
{
  angle=angle-1;
//  printf("%f Down\n",angle);
}
