#include "bricks.h"

void brick_class::createBrick ()
{
  const GLfloat vertex_buffer_data [] = {
    -pos_x-0.15, -pos_y-0.15, 0, // vertex 1
    -pos_x+0.15, -pos_y-0.15, 0, // vertex 2
    -pos_x+0.15, -pos_y+0.15, 0, // vertex 3

    -pos_x+0.15, -pos_y+0.15 , 0, // vertex 3
    -pos_x-0.15, -pos_y+0.15, 0, // vertex 4
    -pos_x-0.15, -pos_y-0.15, 0  // vertex 1
  };

  static const GLfloat color_buffer_data [] = {
    0,0,0, // color 1
    0,0,0, // color 2
    0,0,0, // color 3

    0,0,0, // color 3
    0,0,0, // color 4
    0,0,0  // color 1
  };
}

void brick_class::init(int id_brick)
{
  id = id_brick;
  pos_y = 3.5;
  pos_x = (float )(rand()%10000) + 5;
  pos_x = pos_x - 5000;
  pos_x = (pos_x/1666.67f);
}

void brick_class::drawSingleBrick()
{
  //printf("Draw Cannon\n");
  // use the loaded shader program
  // Don't change unless you know what you are doing
  glUseProgram (programID);

  // Eye - Location of camera. Don't change unless you are sure!!
//  glm::vec3 eye ( 5*cos(camera_rotation_angle*M_PI/180.0f), 0, 5*sin(camera_rotation_angle*M_PI/180.0f) );
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
  glm::mat4 translateBrick = glm::translate (glm::vec3(pos_x,pos_y,0)); // glTranslatef
  glm::mat4 rotateBrick = glm::mat4(1.0f);
//  glm::mat4 rotateCanon = glm::translate(glm::vec3(-4.0,0,0)) * glm::rotate((float)(angle*M_PI/180.0f), rot_coord) * glm::translate(glm::vec3(4.0,0,0));  // rotate about vector (1,0,0)
  glm::mat4 brickTransform = translateBrick * rotateBrick;
  Matrices.model *= brickTransform;
  MVP = VP * Matrices.model; // MVP = p * V * M

  //  Don't change unless you are sure!!
  glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);

  // draw3DObject draws the VAO given to it using current MVP matrix
  draw3DObject(brick);
}
