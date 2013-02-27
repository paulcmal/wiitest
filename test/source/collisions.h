// collisions.h
#ifndef _COLLISIONS_H
#define _COLLISIONS_H

#include "button_class.h"
#include "circle_class.h"

// collision between Circle & Button (rectangle)
bool isIn(Circle c, Button b){
  return(((b.x + b.width) -(c.x - c.radius) > 0)
	 &&((c.x+c.radius) - b.x > 0)
	 &&(b.y + b.height) - (c.y - c.radius) > 0
	 &&((c.y+c.radius) - b.y > 0));
}

#endif
