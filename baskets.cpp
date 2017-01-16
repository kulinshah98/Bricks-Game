#include "baskets.h"

void basket_class::createBasket()
{
  printf("IN CREATE basket\n");
  GLfloat vertex_buffer_data [] = {
    pos_x - 0.5, pos_y - 0.40, 0, // vertex 1
    pos_x + 0.5, pos_y - 0.40, 0, // vertex 2
    pos_x + 0.5, pos_y + 0.40, 0, // vertex 3

    pos_x + 0.5, pos_y + 0.40,0, // vertex 3
    pos_x - 0.5, pos_y + 0.40,0, // vertex 4
    pos_x - 0.5, pos_y - 0.40,0  // vertex 1
  };

   GLfloat color_buffer_data [] = {
    0,0,0, // color 1
    0,0,0, // color 2
    0,0,0, // color 3

    0,0,0, // color 3
    0,0,0, // color 4
    0,0,0  // color 1
  };
  for(int i=0;i<18;i++)
  {
    if(i%3==0 && col==0)
    {
      color_buffer_data[i]=1;
    }
    else if(i%3==1 && col==1)
    {
      color_buffer_data[i]=1;
    }
    cout << color_buffer_data[i] << endl;
  }
  // create3DObject creates and returns a handle to a VAO that can be used later
  cout << color_buffer_data << endl;
  basket = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, color_buffer_data, GL_FILL);
}

void basket_class::init(int green)
{
  angle = 0.0f;
  trans_x=0;
  trans_y=0;
  col=green;
  if(green)
  {
    pos_x = 1.0;
    pos_y = -3.0;
  }
  else
  {
    pos_x = -1.0;
    pos_y = -3.0;
  }
}

void basket_class::drawBasket()
{
  draw(basket, glm::vec3(trans_x,trans_y,0), glm::vec3(0,0,0), 0.0f);
}

void basket_class::increaseX()
{
  trans_x+=0.09;
}

void basket_class::decreaseX()
{
  trans_x-=0.09;
}

float basket_class::giveX()
{
  return trans_x;
}
