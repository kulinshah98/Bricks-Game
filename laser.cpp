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
  trans_y = trans_y + 0.05*sin(angle*M_PI/180.0f);
  trans_x = trans_x + 0.05*cos(angle*M_PI/180.0f);
  //glm::mat4 translateLaser = glm::translate(glm::vec3( trans_x,trans_y,0));
  glm::mat4 translateLaser = glm::translate (glm::vec3( trans_x + 0.12*cos(angle*M_PI/180.0f), trans_y+ 0.62*sin(angle*M_PI/180.0f), 0)); // glTranslatef
  glm::mat4 rotateLaser = glm::translate(glm::vec3(pos_x,pos_y,0)) * glm::rotate((float)(angle*M_PI/180.0f), glm::vec3(0,0,1)) * glm::translate(glm::vec3(-pos_x, -pos_y, 0));  // rotate about vector (1,0,0)
  glm::mat4 laserTransform = translateLaser * rotateLaser;
  //glm::mat4 laserTransform= glm::mat4(1.0f);
  Matrices.model *= laserTransform;
  MVP = VP * Matrices.model; // MVP = p * V * M

  //  Don't change unless you are sure!!
  glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);

  // draw3DObject draws the VAO given to it using current MVP matrix
  draw3DObject(laser);
}
