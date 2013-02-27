// button_class.h
#ifndef _BUTTON_CLASS_H
#define _BUTTON_CLASS_H

class Button{
 public :
  void initButton(int a,int b,int c,int d);
  int x;
  int y;
  int width;
  int height;
};

void Button::initButton(int a,int b,int c,int d){
  x = a;
  y = b;
  width = c;
  height = d;
}


#endif
