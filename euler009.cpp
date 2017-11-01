// Project Euler 9
// There exists exactly one Pythagorean triplet for which a + b + c = 1000.
// Find the product abc.

#include <iostream>
#include <math.h>

int pythtrip(int x, int y, int z){ // check if 3 no's are a pyth triplet
  bool ispyth = false;
  if (x*x + y*y == z*z){
    ispyth = true;
  }
  return ispyth;
}

int main(){ // steps through a, b, c, putting the combination into pythtrip func
  long product;
  for (int a = 1; a <= 997; a = a + 1){
      for (int b = 1; b <= 997; b = b + 1){
        for (int c = 1; c <= 997; c = c + 1){
          if (pythtrip(a, b, c) == true) { // if pyth triplet then..
            if (a + b + c == 1000) { // see if they add to 1000
              product = a * b * c; // if they do, find and print the product
              std::cout << "The product of abc is " << product << std::endl;
              a = b = c = 998;
            }
          }
        }
      }
  }
  return 0;
}
