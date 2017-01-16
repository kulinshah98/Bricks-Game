#include "main.h"

using namespace std;

/* Executed when a regular key is pressed */
void keyboardDown (unsigned char key, int x, int y)
{
    switch (key) {
        case 'Q':
        case 'q':
        case 27: //ESC
            exit (0);

        case 32:
            space_held=1;
            break;
        case 's':
            s_held = 1;
            break;

        case 'f':
            f_held = 1;
            break;

        case 'a':
            a_held = 1;
            break;
        case 'd':
            d_held = 1;
            break;
        default:
            break;
    }
}

/* Executed when a regular key is released */
void keyboardUp (unsigned char key, int x, int y)
{
    switch (key) {
        case 32:
            space_held=0;
            break;

        case 's':
            s_held = 0;
            break;

        case 'f':
            f_held = 0;
            break;

        case 'a':
            a_held = 0;
            break;
        case 'd':
            d_held = 0;
            break;

        default:
            break;
    }
}


/* Executed when a special key is pressed */
void keyboardSpecialDown (int key, int x, int y)
{
  switch (key){
      case GLUT_KEY_LEFT:
        if(glutGetModifiers() == GLUT_ACTIVE_ALT)
        {
          green_basket_decrease = 1;
        }
        else if( glutGetModifiers() == GLUT_ACTIVE_CTRL)
        {
          red_basket_decrease = 1;
        }
        break;

      case GLUT_KEY_RIGHT:
        if(glutGetModifiers() == GLUT_ACTIVE_ALT)
        {
          green_basket_increase = 1;
        }
        else if( glutGetModifiers() == GLUT_ACTIVE_CTRL)
        {
          red_basket_increase = 1;
        }
        break;

      default:
        break;
  }
}

/* Executed when a special key is released */
void keyboardSpecialUp (int key, int x, int y)
{
  switch (key){
      case GLUT_KEY_LEFT:
        if(glutGetModifiers() == GLUT_ACTIVE_ALT)
        {
          green_basket_decrease = 0;
        }
        else if( glutGetModifiers() == GLUT_ACTIVE_CTRL)
        {
          red_basket_decrease = 0;
        }
        break;

      case GLUT_KEY_RIGHT:
        if(glutGetModifiers() == GLUT_ACTIVE_ALT)
        {
          green_basket_increase = 0;
        }
        else if( glutGetModifiers() == GLUT_ACTIVE_CTRL)
        {
          red_basket_increase = 0;
        }
        break;

      default:
        break;
  }
}

/* Executed when a mouse button 'button' is put into state 'state'
 at screen position ('x', 'y')
 */
void mouseClick (int button, int state, int x, int y)
{
    switch (button) {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_UP)
                triangle_rot_dir *= -1;
            break;
        case GLUT_RIGHT_BUTTON:
            if (state == GLUT_UP) {
                rectangle_rot_dir *= -1;
            }
            break;
        default:
            break;
    }
}


/* Executed when the mouse moves to position ('x', 'y') */
void mouseMotion (int x, int y)
{
}

/* Render the scene with openGL */
/* Edit this function according to your assignment */

void drawObject(glm::mat4 VP, glm::vec3 trans_coord, float rot_angle, glm::vec3 rot_coord, glm::vec3 scale_fac)
{
  glm::mat4 MVP;	// MVP = Projection * View * Model

  // Load identity to model matrix
  Matrices.model = glm::mat4(1.0f);

  /* Render your scene */

  triangle_x=triangle_x+0.005f;
  glm::mat4 translateTriangle = glm::translate (trans_coord); // glTranslatef
  glm::mat4 rotateTriangle = glm::rotate(rot_angle, rot_coord);
  glm::mat4 scaleTriangle = glm::scale(scale_fac);  // rotate about vector (1,0,0)
  glm::mat4 triangleTransform = translateTriangle * rotateTriangle*scaleTriangle;
  Matrices.model *= triangleTransform;
  MVP = VP * Matrices.model; // MVP = p * V * M

  //  Don't change unless you are sure!!
  glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);

  // draw3DObject draws the VAO given to it using current MVP matrix
  draw3DObject(triangle);
}


void draw ()
{
  float time_interval=0.006;
  time_interval=time_interval*(id_brick/10 + 1);
  if(game_over==1)
  {
    printf("%d\n",score-5);
    exit(0);
  }
  now = ((float )clock())/CLOCKS_PER_SEC;
  if(space_held && now - prev_space > time_interval)
  {
    laser_class laser_obj;
    map_laser[id_laser]=laser_obj;
    map_laser[id_laser].init(id_laser, canon_obj.pos_x, canon_obj.pos_y, canon_obj.angle);
    map_laser[id_laser].createLaser();
    id_laser++;
    prev_space=now;
  }

  if(now - prev_brick > time_interval*5 )
  {
    makeBrick();
    prev_brick=now;
  }
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  // use the loaded shader program
  // Don't change unless you know what you are doing
  checkCollisions();
  glUseProgram (programID);
  changeCanonPosition();
  canon_obj.drawCanon( glm::vec3(0,0,1) );
  changeBasketPosition();
  drawBricks();
  drawLasers();
  mirror1.drawMirror();
//  mirror2.drawMirror();
  //mirror3.drawMirror();
  red_basket.drawBasket();
  green_basket.drawBasket();
  // Swap the frame buffers
  glutSwapBuffers ();
}

void checkCollisions()
{
  checkBrickBasketCollision();
  checkLaserBrickCollision();
  checkLaserMirrorCollision();
}

void checkLaserMirrorCollision()
{
  typedef map<int,laser_class>::iterator it_type;
  /*for(it_type iterator = map_laser.begin(); iterator != map_laser.end(); iterator++)
  {
    if(mirror1.)
  }*/
}

void checkLaserBrickCollision()
{
  typedef map<int,laser_class>::iterator it_type1;
  typedef map<int,brick_class>::iterator it_type2;

  for( it_type1 iterator1=map_laser.begin(); iterator1 != map_laser.end(); iterator1++)
  {
    for(it_type2 iterator2=map_brick.begin(); iterator2 != map_brick.end(); iterator2++)
    {
      if( abs( (iterator1->second).pos_x + (iterator1->second).trans_x - (iterator2->second).pos_x - (iterator2->second).trans_x) < 0.22 &&
          abs( (iterator1->second).pos_y + (iterator1->second).trans_y - (iterator2->second).pos_y - (iterator2->second).trans_y) < 0.22)
          {
            cout << "Collision between laser and brick\n";
              map_brick.erase(iterator2);
              map_laser.erase(iterator1);
              break;
          }
    }
  }
}

void checkBrickBasketCollision()
{
  typedef map<int,brick_class>::iterator it_type;
  for( it_type iterator=map_brick.begin(); iterator != map_brick.end(); iterator++)
  {
    if(abs( -1 + red_basket.giveX() - map_brick[iterator->first].pos_x - map_brick[iterator->first].trans_x ) < 0.6  && abs( - 3  - map_brick[iterator->first].pos_y - map_brick[iterator->first].trans_y ) < 0.5 )
    {
      printf("RED COLLIDE\n");
      if( map_brick[iterator->first].col_brick != 1)
      {
        game_over=1;
        printf("game over\n");
      }
      score+=5;
      num_brick--;
      map_brick.erase(iterator->first);
    }
    else if(abs( 1 + green_basket.giveX() - map_brick[iterator->first].pos_x - map_brick[iterator->first].trans_x ) < 0.6  && abs( - 3  - map_brick[iterator->first].pos_y - map_brick[iterator->first].trans_y ) < 0.5 )
    {
      printf("GREEN COLLIDE\n");
      if( map_brick[iterator->first].col_brick != 2)
      {
        game_over=1;
        printf("game over\n");
      }
      score+=5;
      num_brick--;
      map_brick.erase(iterator->first);
    }
  }
}

void changeBasketPosition()
{
  if(red_basket_increase==1)
  {
    red_basket.increaseX();
  }
  if(red_basket_decrease==1)
  {
    red_basket.decreaseX();
  }
  if(green_basket_increase==1)
  {
    green_basket.increaseX();
  }
  if(green_basket_decrease==1)
  {
    green_basket.decreaseX();
  }
}

void changeCanonPosition()
{
  if(a_held)
  {
    canon_obj.tiltUp();
  }
  if(s_held)
  {
    canon_obj.increaseY();
  }
  if(d_held)
  {
    canon_obj.tiltDown();
  }
  if(f_held)
  {
    canon_obj.decreaseY();
  }
}
/* Executed when the program is idle (no I/O activity) */

void drawLasers()
{
  if(id_laser>0)
  {
    typedef map<int,laser_class>::iterator it_type;
    for( it_type iterator=map_laser.begin(); iterator != map_laser.end(); iterator++)
    {
      map_laser[iterator->first].drawSingleLaser();
    }
  }
}

void makeBrick()
{
  //printf("%d\n",id_brick);
  int num=rand();
  //printf("%d\n",num);
  if(level==1)
  {
    brick_class brick_obj;
    map_brick[id_brick]=brick_obj;
    map_brick[id_brick].init(id_brick);
    map_brick[id_brick].createBrick();
    id_brick++;
    num_brick++;
  }
   //glutPostRedisplay();

   //glutTimerFunc(150, makeBrick, 0);
}

void drawBricks()
{
  if(num_brick>0)
  {
    typedef map<int,brick_class>::iterator it_type;
    for( it_type iterator=map_brick.begin(); iterator != map_brick.end(); iterator++)
    {
      map_brick[iterator->first].drawSingleBrick();
    }
  }
}

void idle () {
    // OpenGL should never stop drawing
    // can draw the same scene or a modified scene
    // clear the color and depth in the frame buffer
    draw (); // drawing same scene
}

/* Process menu option 'op' */
void menu(int op)
{
    switch(op)
    {
        case 'Q':
        case 'q':
            exit(0);
    }
}

void addGLUTMenus ()
{
    // create sub menus
    int subMenu = glutCreateMenu (menu);
    glutAddMenuEntry ("Do Nothing", 0);
    glutAddMenuEntry ("Really Quit", 'q');

    // create main "middle click" menu
    glutCreateMenu (menu);
    glutAddSubMenu ("Sub Menu", subMenu);
    glutAddMenuEntry ("Quit", 'q');
    glutAttachMenu (GLUT_MIDDLE_BUTTON);
}

/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL (int width, int height)
{
	// Create the models
//	Create Canon
  canon_obj.createCanon();
  canon_obj.init();

// Create Baskets
  red_basket.init(0);
  red_basket.createBasket();

  green_basket.init(1);
  green_basket.createBasket();

  mirror1.init(1);
  mirror1.createMirror();

  mirror2.init(2);
  mirror2.createMirror();

  mirror3.init(3);
  mirror3.createMirror();

	// Create and compile our GLSL program from the shaders
	programID = LoadShaders( "Sample_GL.vert", "Sample_GL.frag" );
	// Get a handle for our "MVP" uniform
	Matrices.MatrixID = glGetUniformLocation(programID, "MVP");


	reshapeWindow (width, height);

	// Background color of the scene
	glClearColor (0.87f, 0.87f, 0.87f, 0.0f); // R, G, B, A
	glClearDepth (1.0f);

	glEnable (GL_DEPTH_TEST);
	glDepthFunc (GL_LEQUAL);

	cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
	cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
	cout << "VERSION: " << glGetString(GL_VERSION) << endl;
	cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}

int main (int argc, char** argv)
{
	int width = 1000;
	int height = 600;
  srand(time(NULL));
    initGLUT (argc, argv, width, height);
    map_brick.clear();
    addGLUTMenus ();

	initGL (width, height);

    glutMainLoop ();

    return 0;
}
