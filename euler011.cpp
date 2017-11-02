// Project Euler 11
// Find the greatest product of four adjacent numbers in the same direction
// (up, down, left, right or diagonally) in the 20x20 grid

#include <iostream>
#include <math.h>
#include <fstream>

int main() {
  std::fstream infile;
  infile.open("euler011.txt"); //load file
  int a[20][20] = {}; // create blank array of 0's
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      a[i][j] = 0;
    }
  }
  for (int i = 0; i < 20; i++) { //write from .txt file into array a
    for (int j = 0; j < 20; j++) {
      infile >> a[i][j];
      //std::cout << a[i][j] << " "; //tracer print
    }
    //std::cout << std::endl; //tracer print
  }
  infile.close();
  int x, y = 0; // grid coordinates
  long maxprod = 0; // answer to find
  long currentprod = 0; // placeholder for current product calculated
  for (x = 0; x < 20; x++) { // step through columns
    for (y = 0; y < 20; y++) { // step through rows
      if ( x < 17) { //do horizontal product
        currentprod = a[x][y] * a[x+1][y] * a[x+2][y] * a[x+3][y];
        if (currentprod > maxprod) {
          maxprod = currentprod;
        }
      if (y < 17) { // do vertical product
        currentprod = a[x][y] * a[x][y+1] * a[x][y+2] * a[x][y+3];
        if (currentprod > maxprod) {
          maxprod = currentprod;
        }
      }
      if (y > 2 && x < 17) { // do diagonal / product
        currentprod = a[x][y] * a[x+1][y-1] * a[x+2][y-2] * a[x+3][y-3];
        if (currentprod > maxprod) {
          maxprod = currentprod;
        }
      }
      if (y <17 && x < 17) { // do diagonal \ product
        currentprod = a[x][y] * a[x+1][y+1] * a[x+2][y+2] * a[x+3][y+3];
        if (currentprod > maxprod) {
          maxprod = currentprod;
        }
      }
      }
    }
  }
  std::cout << "The largest product is " << maxprod << std::endl;
  return 0;
}
