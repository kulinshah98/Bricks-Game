#include "mirror.h"


void mirror_class::createMirror()
{
  const GLfloat vertex_buffer_data [] = {
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

   GLfloat color_buffer_data [] = {
    0,0,1, // color 1
    0,0,1, // color 2
    0,0,1, // color 3

    0,0,1, // color 3
    0,0,1, // color 4
    0,0,1,  // color 1

    0,0,1, // color 1
    0,0,1, // color 2
    0,0,1, // color 3

    0,0,1, // color 3
    0,0,1, // color 4
    0,0,1, // color 1

    0,0,1, // color 1
    0,0,1, // color 2
    0,0,1, // color 3

    0,0,1, // color 3
    0,0,1, // color 4
    0,0,1, // color 1

    0,0,1, // color 1
    0,0,1, // color 2
    0,0,1, // color 3

    0,0,1, // color 3
    0,0,1, // color 4
    0,0,1, // color 1

    0,0,1, // color 1
    0,0,1, // color 2
    0,0,1, // color 3

    0,0,1, // color 3
    0,0,1, // color 4
    0,0,1, // color 1

    0,0,1, // color 1
    0,0,1, // color 2
    0,0,1, // color 3

    0,0,1, // color 3
    0,0,1, // color 4
    0,0,1 // color 1
  };
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
  glm::mat4 translateMirror = glm::translate (glm::vec3(0,0,0)); // glTranslatef

  glm::mat4 rotateMirror = glm::translate(glm::vec3(pos_x,pos_y,0)) * glm::rotate((float)(angle*M_PI/180.0f), glm::vec3(0,0,1)) * glm::translate(glm::vec3(-pos_x,-pos_y,0));  // rotate about vector (1,0,0)
  glm::mat4 mirrorTransform = translateMirror * rotateMirror;
  Matrices.model *= mirrorTransform;
  MVP = VP * Matrices.model; // MVP = p * V * M

  //  Don't change unless you are sure!!
  glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);

  // draw3DObject draws the VAO given to it using current MVP matrix
  draw3DObject(mirror);
}
