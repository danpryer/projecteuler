// Project Euler 15
// How many routes are there through a 20x20 grid (starting top left
// and moving to bottom right, and can only move right and down)?


// this is a simple permutations question. can rephrase it as
// i have two bags with 20 coins in each, how many different
//ways can i pull the coins from the bag?
#include "eulerheader.h"

int main() {
  long long answer=1;

  //binomial coefficient C(n,k) = C(40,20) = answer
  //answer = factorial(40) / (factorial(20) * factorial(20));
  //this can also be calculated as:
  for (int i=1; i <21; i++){
    answer = answer * (20+i)/i;
  }

  std::cout << "Answer is: " << answer << std::endl;

  return 0;
}
