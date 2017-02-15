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

  c.red = 0;
  c.green = 255;
  c.blue = 0;
  draw_line(0,0,250,125,s,c);//octant 1 & 5
  draw_line(250,125,500,0,s,c);//octant 8 & 4

  draw_line(500,0,250,500,s,c); //octant 7 & 3
  draw_line(0,0,250,500,s,c); //octant 2 & 6
  display(s);
  save_extension(s, "lines.png");
}
