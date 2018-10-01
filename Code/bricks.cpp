#include "bricks.h"

void brick_class::createBrick ()
{
  GLfloat vertex_buffer_data [] = {
    pos_x-0.10, pos_y-0.10, 0, // vertex 1
    pos_x+0.10, pos_y-0.10, 0, // vertex 2
    pos_x+0.10, pos_y+0.10, 0, // vertex 3

    pos_x+0.10, pos_y+0.10 , 0, // vertex 3
    pos_x-0.10, pos_y+0.10, 0, // vertex 4
    pos_x-0.10, pos_y-0.10, 0  // vertex 1
  };
  float tmp2,tmp1;
  if(col_brick==0)
  {
    tmp1=0;
    tmp2=0;
  }
  else if(col_brick==1)
  {
    tmp1=1;
    tmp2=0;
  }
  else
  {
    tmp1=0;
    tmp2=1;
  }

  //cout << col_brick << " " << tmp1 << " " << tmp2 << endl;
   GLfloat color_buffer_data [] = {
    tmp1,tmp2,0, // color 1
    tmp1,tmp2,0, // color 2
    tmp1,tmp2,0, // color 3

    tmp1,tmp2,0, // color 3
    tmp1,tmp2,0, // color 4
    tmp1,tmp2,0  // color 1
  };
  brick = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, color_buffer_data, GL_FILL);
}

void brick_class::init(int id_brick)
{
  int num=rand();
  id = id_brick;
  pos_y = 3.5;
  pos_x = ((float )(num%10000)) + 5.0f;
  pos_x = pos_x - 5000;
  pos_x = (pos_x/1666.67f);
  angle = 0.0f;
  trans_x=0;
  trans_y=0;
  col_brick = ((rand()%3));
}

void brick_class::drawSingleBrick()
{
  trans_y-=speed;
  draw(brick, glm::vec3(0,trans_y,0), glm::vec3(pos_x, pos_y,0), angle);
}
