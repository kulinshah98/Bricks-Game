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

  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  // use the loaded shader program
  // Don't change unless you know what you are doing
  glUseProgram (programID);
  changeBasketPosition();
  changeCanonPosition();
  canon_obj.drawCanon( glm::vec3(0,0,1) );
  //makeBrick();
  drawBricks();
  red_basket.drawBasket();
  green_basket.drawBasket();
  // Swap the frame buffers
  glutSwapBuffers ();
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

void makeBrick(int value)
{
  //printf("%d\n",id_brick);
  int num=rand();
  //printf("%d\n",num);
  if(level==1 && num%7==0)
  {
    brick_class brick_obj;
    map_brick[id_brick]=brick_obj;
    map_brick[id_brick].init(id_brick);
    map_brick[id_brick].createBrick();
    id_brick++;
  }
   glutPostRedisplay();

   glutTimerFunc(150, makeBrick, 0);
}

void drawBricks()
{
  if(id_brick>0)
  {
    typedef map<int,brick_class>::iterator it_type;
    for( it_type iterator=map_brick.begin(); iterator != map_brick.end(); iterator++)
    {
    //  printf("%d",iterator->first);
    //  printf("***********************\n");
      map_brick[iterator->first].drawSingleBrick();
      //printf("hi\n");
    }
  }
}

void idle () {
    // OpenGL should never stop drawing
    // can draw the same scene or a modified scene
    // clear the color and depth in the frame buffer
  //  makeBrick();
    draw (); // drawing same scene
    //drawBricks();
  //  printf("Hello\n");
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
