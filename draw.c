#include <stdio.h>
#include <stdlib.h>
#include "ml6.h"
#include "display.h"
#include "draw.h"
//octants 1 and 5
void octant15(int A, int B, int x,int y, int x1, int y1, screen s, color c){
  int d= 2*A + B;
  A = 2*A;
  B = 2*B;
  while(x<x1){
    plot(s,c,x,y);
    if(d>0){
      y++;
      d+=B;
    }
    x++;
    d+=A;
  }
}
//octants 2 and 6
void octant26(int A, int B, int x,int y, int x1, int y1, screen s, color c){
  int d= A + 2*B;
  A = 2*A;
  B = 2*B;
  while(y<y1){
    plot(s,c,x,y);
    if(d<0){
      x++;
      d+=A;
    }
    y++;
    d+=B;
  }
}
//octants 7 and 3
void octant73(int A, int B,int x,int y, int x1, int y1, screen s, color c){
  int d= A - 2*B;
  A = 2*A;
  B = 2*B;
  while(y>y1){
    plot(s,c,x,y);
    if(d>0){
      x++;
      d+=A;
    }
    y--;
    d-=B;
  }
}
//octants 8 and 4
void octant84(int A,int B, int x,int y, int x1, int y1, screen s, color c){
  int d= 2*A - B;
  A = 2*A;
  B = 2*B;
  while(x<x1){
    plot(s,c,x,y);
    if(d<0){
      y--;
      d-=B;
    }
    x++;
    d+=A;
  }
}

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  //octants 3-6, swap end points
  int x,y;
  if(x0>x1){
    x = x0;
    y = y0;
    x0 = x1;
    y0 = y1;
    x1 = x;
    y1 = y;
  }
  x = x0;
  y = y0;
  int A = y1-y0;
  int B = (x1-x0)*-1;
  //check slopes by comparing deltaX and deltaY, then call octant functions
  if(A>=0 && A<=(-1*B))octant15(A,B,x,y,x1,y1,s,c);
  else if(A>=0 && A>(-1*B))octant26(A,B,x,y,x1,y1,s,c);
  else if(A<B)octant73(A,B,x,y,x1,y1,s,c);
  else octant84(A,B,x,y,x1,y1,s,c);
  plot(s,c,x1,y1);
}
