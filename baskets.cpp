#include "baskets.h"

void basket_class::createBasket()
{
  printf("IN CREATE basket\n");
  GLfloat vertex_buffer_data [] = {
    pos_x - 0.43, pos_y - 0.40, 0, // vertex 1
    pos_x + 0.43, pos_y - 0.40, 0, // vertex 2
    pos_x + 0.57, pos_y + 0.40, 0, // vertex 3

    pos_x + 0.57, pos_y + 0.40,0, // vertex 3
    pos_x - 0.57, pos_y + 0.40,0, // vertex 4
    pos_x - 0.43, pos_y - 0.40,0  // vertex 1
  };
  int i;
  GLfloat color_buffer_data[27];
  if(col)
  {
    for(i=0;i<18;i++)
    {
      if(i%3==0)
      {
        color_buffer_data[i]=0.32f;
      }
      else if(i%3==1)
      {
        color_buffer_data[i]=0.78f;
      }
      else if(i%3==2)
      {
        color_buffer_data[i]=0.08f;
      }
    }
  }
  else
  {
    for(i=0;i<18;i++)
    {
      if(i%3==0)
      {
        color_buffer_data[i]=0.95f;
      }
      else if(i%3==1)
      {
        color_buffer_data[i]=0.23f;
      }
      else if(i%3==2)
      {
        color_buffer_data[i]=0.23f;
      }
    }
  }
  // create3DObject creates and returns a handle to a VAO that can be used later
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
//  cout << trans_x << " " << trans_y << " IN Basket" << endl;
  draw(basket, glm::vec3(trans_x,trans_y,0), glm::vec3(0,0,0), 0.0f);
}

void basket_class::increaseX()
{
  if(pos_x + trans_x < 3.5)
  {
    trans_x+=0.09;
  }
}

void basket_class::decreaseX()
{
  if(pos_x + trans_x > -3.5)
  {
    trans_x-=0.09;
  }
}

float basket_class::giveX()
{
  return trans_x;
}

void basket_class::assignX(float val)
{
  trans_x=val;
}
