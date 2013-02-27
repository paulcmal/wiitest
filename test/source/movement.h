// movement.h
#ifndef _MOVEMENT_H
#define _MOVEMENT_H

#include "collisions.h"
#include <math.h>
#include "variables.h"


float random(float low, float high){
  // Return a random float
  return((float)rand()/(float)RAND_MAX/(high-low));
}

bool isUp(Circle c){
  // Returns whether the circle's middle is inside the screen
  // (from the bottom)
  return(c.y - c.radius < 0);
}

bool isDown(Circle c){
  // Returns whether the circle's middle is inside the screen
  // (from the top)
  return(c.y + c.radius >= maxY);
}

double position(Circle c, Button b){
  return((b.y + b.height/2) - c.y);
}

void isMoving(Circle& move, Button r, Button l, int& pass,
	      float& speed, float& b){
  if(isUp(move)){
    b = -b;
    move.y = move.y + (move.radius - move.y);
  }
  if(isDown(move)){
    b = -b;
    move.y = 480 - move.radius;
  }
  if(isIn(move,r)){
    float i1 = -position(move,r);
    i1 = i1 / (r.height/2);
    b = (i1*speed);
    pass = 1;
    move.x = r.x - move.radius;
    speed += 0.5;
  }
  if(isIn(move,l)){
    float i1 = position(move,l);
    i1 = i1 / (l.height/2);
    b = (-i1*speed);
    pass = 0;
    move.x = move.radius + l.width;
    speed += 0.5;
  }
    if(pass == 0){
      move.x = move.x + speed;
      move.y = move.y + b;
    }
    if(pass == 1){
      move.x = move.x - speed;
      move.y = move.y + b;
  }
}


void ia(Button& b, Circle c, float v){
  float rand = 0.0;
  if(b.y + b.height > maxY)
    b.y = maxY- b.height;
  if(b.y < 0)
    b.y = 0;
  if(c.x - b.x <= maxX/2+maxX/4){
    float pos = c.y - b.y + rand;
    if(pos > 0.0)
      b.y += v ;
    if(pos < 0.0)
      b.y -= v ;
  }
}

#endif
