#include "canon.h"


void laser_canon::createCanon ()
{
  // GL3 accepts only Triangles. Quads are not supported static
  const GLfloat vertex_buffer_data [] = {
    -4.0,-0.25,0, // vertex 1
    -3.2,-0.25,0, // vertex 2
    -3.2, 0.25,0, // vertex 3

    -3.2, 0.25,0, // vertex 3
    -4.0, 0.25,0, // vertex 4
    -4.0,-0.25,0  // vertex 1
  };

  static const GLfloat color_buffer_data [] = {
    0,0,0, // color 1
    0,0,0, // color 2
    0,0,0, // color 3

    0,0,0, // color 3
    0,0,0, // color 4
    0,0,0  // color 1
  };

  // create3DObject creates and returns a handle to a VAO that can be used later
  canon = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, color_buffer_data, GL_FILL);
}

void laser_canon::drawCanon (glm::vec3 rot_coord)
{
  //printf("Draw Cannon\n");

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
  glm::mat4 translateCanon = glm::translate (glm::vec3(pos_x,pos_y,0)); // glTranslatef

  glm::mat4 rotateCanon = glm::translate(glm::vec3(-4.0,0,0)) * glm::rotate((float)(angle*M_PI/180.0f), rot_coord) * glm::translate(glm::vec3(4.0,0,0));  // rotate about vector (1,0,0)
  glm::mat4 canonTransform = translateCanon * rotateCanon;
  Matrices.model *= canonTransform;
  MVP = VP * Matrices.model; // MVP = p * V * M

  //  Don't change unless you are sure!!
  glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);

  // draw3DObject draws the VAO given to it using current MVP matrix
  draw3DObject(canon);

}

void laser_canon::init()
{
  pos_x=0;
  pos_y=0;
  angle=0.0f;
}

void laser_canon::increaseY()
{
  pos_y=pos_y+0.1;
  printf("%f",pos_y);
}

void laser_canon::decreaseY()
{
  pos_y=pos_y-0.1;
  printf("%f",pos_y);
}

void laser_canon::tiltUp()
{
  angle=angle+2;
  printf("%f Up\n",angle);
}

void laser_canon::tiltDown()
{
  angle=angle-2;
  printf("%f Down\n",angle);
}
