#include "collision.h"

void checkCollisions()
{
  checkBrickBasketCollision();
  checkLaserBrickCollision();
  checkLaserMirrorCollision();
}

void reflectLaser(int laser_id, mirror_class mirror_cp)
{
  map_laser[laser_id].angle = 180.0f + mirror_cp.angle*2 - map_laser[laser_id].angle;
}

void checkLaserMirrorCollision()
{
  float tmp1,tmp2,x_coord,y_coord;
  typedef map<int,laser_class>::iterator it_type;
//  printf("In checkLaserMirrorCollision\n");
  for(it_type iterator = map_laser.begin(); iterator != map_laser.end(); iterator++)
  {
    // Check Collision Between mirror1 and laser
    tmp2 = mirror1.pos_y - mirror1.pos_x * tan((float)(90.0f+mirror1.angle)*M_PI/180.0f);
    x_coord = ((iterator->second).pos_x + (iterator->second).trans_x + 0.4*cos((iterator->second).angle*M_PI/180.0f));
    y_coord = ((iterator->second).pos_y + (iterator->second).trans_y + 0.4*sin((iterator->second).angle*M_PI/180.0f));
    tmp1 = (x_coord) * tan((float )(90.0f+mirror1.angle)*M_PI/180.0f) + tmp2;
    if(abs(y_coord - tmp1) < 0.05 && y_coord < mirror1.pos_y + 0.35*cos((float )mirror1.angle*M_PI/180.0f) && y_coord > mirror1.pos_y - 0.35*cos((float )mirror1.angle*M_PI/180.0f))
    {
      printf("Collision between mirror 1 and laser\n");
      reflectLaser(iterator->first,mirror1);
    }

    // Check Collision Between mirror2 and laser
    tmp2 = mirror2.pos_y - mirror2.pos_x * tan((float)(90.0f+mirror2.angle)*M_PI/180.0f);
    x_coord = ((iterator->second).pos_x + (iterator->second).trans_x + 0.4*cos((iterator->second).angle*M_PI/180.0f));
    y_coord = ((iterator->second).pos_y + (iterator->second).trans_y + 0.4*sin((iterator->second).angle*M_PI/180.0f));
    tmp1 = (x_coord) * tan((float )(90.0f+mirror2.angle)*M_PI/180.0f) + tmp2;
    if(abs(y_coord - tmp1) < 0.05 && y_coord < mirror2.pos_y + 0.35*cos((float )mirror2.angle*M_PI/180.0f) && y_coord > mirror2.pos_y - 0.35*cos((float )mirror2.angle*M_PI/180.0f))
    {
      printf("Collision between mirror 2 and laser\n");
      reflectLaser(iterator->first,mirror2);
    }

    // Check Collision Between mirror3 and laser
    tmp2 = mirror3.pos_y - mirror3.pos_x * tan((float)(90.0f+mirror3.angle)*M_PI/180.0f);
    x_coord = ((iterator->second).pos_x + (iterator->second).trans_x + 0.4*cos((iterator->second).angle*M_PI/180.0f));
    y_coord = ((iterator->second).pos_y + (iterator->second).trans_y + 0.4*sin((iterator->second).angle*M_PI/180.0f));
    tmp1 = (x_coord) * tan((float )(90.0f+mirror3.angle)*M_PI/180.0f) + tmp2;
    if(abs(y_coord - tmp1) < 0.05 && y_coord < mirror3.pos_y + 0.35*cos((float )mirror3.angle*M_PI/180.0f) && y_coord > mirror3.pos_y - 0.35*cos((float )mirror3.angle*M_PI/180.0f))
    {
      printf("Collision between mirror 3 and laser\n");
      reflectLaser(iterator->first,mirror3);
    }
  }
}

void checkLaserBrickCollision()
{
  typedef map<int,laser_class>::iterator it_type1;
  typedef map<int,brick_class>::iterator it_type2;

  for( it_type1 iterator1=map_laser.begin(); iterator1 != map_laser.end(); iterator1++)
  {
    for(it_type2 iterator2=map_brick.begin(); iterator2 != map_brick.end(); iterator2++)
    {
      if( abs( (iterator1->second).pos_x + (iterator1->second).trans_x - (iterator2->second).pos_x - (iterator2->second).trans_x) < 0.32 &&
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
    if(abs( -1 + red_basket.giveX() - map_brick[iterator->first].pos_x - map_brick[iterator->first].trans_x ) < 0.8  && abs( - 3  - map_brick[iterator->first].pos_y - map_brick[iterator->first].trans_y ) < 0.5 )
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
    else if(abs( 1 + green_basket.giveX() - map_brick[iterator->first].pos_x - map_brick[iterator->first].trans_x ) < 0.8  && abs( - 3  - map_brick[iterator->first].pos_y - map_brick[iterator->first].trans_y ) < 0.5 )
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
