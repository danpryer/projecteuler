// Project Euler 6
// Find the difference between the sum of the squares
// of the first one hundred natural numbers and the square of the sum.

#include <iostream>
#include <math.h>

int sumofsquares(int x){ //calculates sum of squares up to x
  long sumsquares = 0;
  int i;
  for (i = 1; i <= x; i = i + 1) {
    sumsquares = sumsquares + i*i;
  }
  return sumsquares;
}

int squareofsums(int x){ //calculates square of sums up to x
  long squaresums = 0;
  int i;
  for (i = 1; i <= x; i = i + 1) {
    squaresums = squaresums + i;
  }
  squaresums = squaresums * squaresums;
  return squaresums;
}

int main() { // calculates and prints the diff as answer
  long answer;
  long N = 100;
  answer = squareofsums(N) - sumofsquares(N);
  std::cout << "Answer is " << answer << std::endl;
return 0;
}
