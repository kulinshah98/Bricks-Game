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
  // Eye - Location of camera. Don't change unless you are sure!!
  glm::vec3 eye ( 5*cos(camera_rotation_angle*M_PI/180.0f), 0, 5*sin(camera_rotation_angle*M_PI/180.0f) );
  // Target - Where is the camera looking at.  Don't change unless you are sure!!
  glm::vec3 target (0, 0, 0);
  // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
  glm::vec3 up (0, 1, 0);

  // Compute Camera matrix (view)
  // Matrices.view = glm::lookAt( eye, target, up ); // Rotating Camera for 3D
  //  Don't change unless you are sure!!
  Matrices.view = glm::lookAt(glm::vec3(0,0,3), glm::vec3(0,0,0), glm::vec3(0,1,0)); // Fixed camera for 2D (ortho) in XY plane

  // Compute ViewProject matrix as view/camera might not be changed for this frame (basic scenario)
  //  Don't change unless you are sure!!
  glm::mat4 VP = Matrices.projection * Matrices.view;

  // Send our transformation to the currently bound shader, in the "MVP" uniform
  // For each model you render, since the MVP will be different (at least the M part)
  //  Don't change unless you are sure!!
  glm::mat4 MVP;	// MVP = Projection * View * Model

  // Load identity to model matrix
  Matrices.model = glm::mat4(1.0f);

  /* Render your scene */

//  printf("%d %d %d\n",trans_coord.x, trans_coord.y,trans_coord.z);
  /*if(col==0)
  {
    cout << trans_x << " " << trans_y << endl;
  }*/
  glm::mat4 translateBasket = glm::translate (glm::vec3(trans_x,trans_y,0)); // glTranslatef
  glm::mat4 basketTransform = translateBasket;
  Matrices.model *= basketTransform;
  MVP = VP * Matrices.model; // MVP = p * V * M

  //  Don't change unless you are sure!!
  glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);

  // draw3DObject draws the VAO given to it using current MVP matrix
  draw3DObject(basket);
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
