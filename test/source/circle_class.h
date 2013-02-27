// circle_class.h
#ifndef _CIRCLE_CLASS_H
#define _CIRCLE_CLASS_H

class Circle{
 public :
  void initCircle(float X,float Y,int R);
  float x;
  float y;
  int radius;
};

void Circle::initCircle(float a,float b,int c){
  x = a;
  y = b;
  radius = c;
}


#endif
