#include "mirror.h"


void mirror_class::createMirror()
{
  GLfloat vertex_buffer_data [] = {
    pos_x - 0.03, pos_y - 0.35,0, // vertex 1
    pos_x + 0.03, pos_y - 0.35,0, // vertex 2
    pos_x + 0.03, pos_y + 0.35,0, // vertex 3

    pos_x + 0.03, pos_y + 0.35,0, // vertex 3
    pos_x - 0.03, pos_y + 0.35,0, // vertex 4
    pos_x - 0.03, pos_y - 0.35,0,  // vertex 1

    pos_x + 0.03, pos_y + 0.35 - 0.12, 0,
    pos_x + 0.03 + 0.13, pos_y + 0.35 - 0.12, 0,
    pos_x + 0.03 + 0.13, pos_y + 0.35 - 0.12 + 0.016, 0,

    pos_x + 0.03 + 0.13, pos_y + 0.35 - 0.12 + 0.016, 0,
    pos_x + 0.03, pos_y + 0.35 - 0.12 + 0.016, 0,
    pos_x + 0.03, pos_y + 0.35 - 0.12, 0,

    pos_x + 0.03, pos_y + 0.35 - 0.12*2, 0,
    pos_x + 0.03 + 0.13, pos_y + 0.35 - 0.12*2, 0,
    pos_x + 0.03 + 0.13, pos_y + 0.35 - 0.12*2 + 0.016, 0,

    pos_x + 0.03 + 0.13, pos_y + 0.35 - 0.12*2 + 0.016, 0,
    pos_x + 0.03, pos_y + 0.35 - 0.12*2 + 0.016, 0,
    pos_x + 0.03, pos_y + 0.35 - 0.12*2, 0,

    pos_x + 0.03, pos_y + 0.35 - 0.12*3, 0,
    pos_x + 0.03 + 0.13, pos_y + 0.35 - 0.12*3, 0,
    pos_x + 0.03 + 0.13, pos_y + 0.35 - 0.12*3 + 0.016, 0,

    pos_x + 0.03 + 0.13, pos_y + 0.35 - 0.12*3 + 0.016, 0,
    pos_x + 0.03, pos_y + 0.35 - 0.12*3 + 0.016, 0,
    pos_x + 0.03, pos_y + 0.35 - 0.12*3, 0,

    pos_x + 0.03, pos_y + 0.35 - 0.12*4, 0,
    pos_x + 0.03 + 0.13, pos_y + 0.35 - 0.12*4, 0,
    pos_x + 0.03 + 0.13, pos_y + 0.35 - 0.12*4 + 0.016, 0,

    pos_x + 0.03 + 0.13, pos_y + 0.35 - 0.12*4 + 0.016, 0,
    pos_x + 0.03, pos_y + 0.35 - 0.12*4 + 0.016, 0,
    pos_x + 0.03, pos_y + 0.35 - 0.12*4, 0,

    pos_x + 0.03, pos_y + 0.35 - 0.12*5, 0,
    pos_x + 0.03 + 0.13, pos_y + 0.35 - 0.12*5, 0,
    pos_x + 0.03 + 0.13, pos_y + 0.35 - 0.12*5 + 0.016, 0,

    pos_x + 0.03 + 0.13, pos_y + 0.35 - 0.12*5 + 0.016, 0,
    pos_x + 0.03, pos_y + 0.35 - 0.12*5 + 0.016, 0,
    pos_x + 0.03, pos_y + 0.35 - 0.12*5, 0
  };

  GLfloat color_buffer_data[118];
  for(int i=0;i<110;i++)
  {
    if(i%3==2)
    {
      color_buffer_data[i]=1;
    }
    else
    {
      color_buffer_data[i]=0;
    }
  }
  // create3DObject creates and returns a handle to a VAO that can be used later
  mirror = create3DObject(GL_TRIANGLES, 36, vertex_buffer_data, color_buffer_data, GL_FILL);
}

void mirror_class::init(int id_mir)
{
  id=id_mir;
    if(id_mir==1)
    {
      angle = 55.0f;
      pos_x = 0.5f;
      pos_y = 2.7f;
    }
    else if(id_mir==2)
    {
      angle = -30.0f;
      pos_x = 2.3f;
      pos_y = -1.8f;
    }
    else if(id_mir==3)
    {
      angle =  13.0f;
      pos_x = 2.7f;
      pos_y = 1.3f;
    }
}

void mirror_class::drawMirror()
{
  draw(mirror, glm::vec3(0,0,0), glm::vec3(pos_x,pos_y,0), angle);
}
