#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {
  screen s;
  color c;
  clear_screen(s);
  c.red = 255;
  c.green = 255;
  c.blue = 255;
  draw_line(250,0,250,500,s,c); //vertical
  draw_line(0,250,500,250,s,c); //horizontal
  c.red = 0;
  c.green = 0;
  c.blue = 255;
  draw_line(250,250,500,500,s,c); //m=1
  draw_line(250,250,500,375,s,c);//octant 1
  draw_line(250,250,375,500,s,c);//octant 2
  c.red = 255;
  c.blue =0;
  draw_line(0,500,250,250,s,c);//m=-1
  draw_line(250,250,0,375,s,c);//octant 4
  draw_line(250,250,125,500,s,c);//octant 3
  c.green = 255;
  c.red = 0;
  draw_line(250,250,500,125,s,c);//octant 8
  draw_line(250,250,375,0,s,c);//octant 7
  c.red = 255;
  draw_line(250,250,0,125,s,c);//octant 5
  draw_line(250,250,125,0,s,c);//octant 6
  display(s);
  save_extension(s, "lines.png");
}
