/*
Construct an H-tree, given its center (x and y coordinates), starting_length and depth. You can assume that you have a drawLine method.

As a reminder, this is an example of an H-tree.

How to construct an H-tree?

An H-tree can be constructed by starting with a line segment of arbitrary length, drawing two segments of the same length at right angles to the first through its endpoints, and continuing in the same vein, reducing (dividing) the length of the line segments drawn at each stage by √2.
*/

/*
Recursive Solution
Split problem to smallest step.
  - Get the 4 children at every step.
  - Draw H with 3 lines.

Recursively call till depth is reached
*/

#include<iostream>
using namespace std;

struct Point
{
  float x, y;
  Point(float x_i, float y_i) :x(x_i), y(y_i) {};
};


// Function prints the 2 points for an H
void drawLines(float x0, float y0, float x1, float y1, char c) {
  printf("(%0.2f, %0.2f)%c%c%c%c(%0.2f, %0.2f)\n", x0, y0,c,c,c,c, x1, y1);
}

void drawH(float x, float y, float length, int depth) {
  if (depth == 0) {
    return;
  }

  //calculate the 4 end point children
  float xl, xr, yu, yd;  //an H is left-right in x, up-down in y
  Point(x, y);
  xl = x - length / 2.0;
  xr = x + length / 2.0;
  yd = y - length / 2.0;
  yu = y + length / 2.0;

  drawLines(xl, y, xr, y, '-');
  drawLines(xl, yu, xl, yd, '|');
  drawLines(xr, yu, xr, yd, '|');


  drawH(xl, yd, length / sqrtf(2.0), depth-1);
  drawH(xl, yu, length / sqrtf(2.0), depth-1);
  drawH(xr, yd, length / sqrtf(2.0), depth-1);
  drawH(xr, yu, length / sqrtf(2.0), depth-1);
  return;
}

int main() {
  drawH(0, 0, 10, 2);
  cin.get();
  return 1;
}