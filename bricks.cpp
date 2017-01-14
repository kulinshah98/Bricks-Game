#include "bricks.h"

void brick_class::createBrick ()
{
  const GLfloat vertex_buffer_data [] = {
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

  cout << col_brick << " " << tmp1 << " " << tmp2 << endl;
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
  trans_y-=0.01f;
  glm::mat4 translateCanon = glm::translate (glm::vec3(0,trans_y,0)); // glTranslatef

  glm::mat4 rotateCanon = glm::translate(glm::vec3(-4.0,0,0)) * glm::rotate((float)(angle*M_PI/180.0f), glm::vec3(1,0,0)) * glm::translate(glm::vec3(4.0,0,0));  // rotate about vector (1,0,0)
  glm::mat4 canonTransform = translateCanon * rotateCanon;
  Matrices.model *= canonTransform;
  MVP = VP * Matrices.model; // MVP = p * V * M

  //  Don't change unless you are sure!!
  glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);

  // draw3DObject draws the VAO given to it using current MVP matrix
  draw3DObject(brick);
}
