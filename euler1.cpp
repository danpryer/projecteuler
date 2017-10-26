// Project Euler Problem 1
// If we list all the natural numbers below 10 that are multiples
// of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
// Find the sum of all the multiples of 3 or 5 below 1000.

#include <iostream>

double sumdivideby(int x){
  int littlesum=0; // to sum up all values of x below 1000
  int adder = x; //need to hold the base value of x
  do {
    littlesum = littlesum + adder;
    adder = adder + x;
  } while (adder<1000);
  return littlesum;
}

int main(){
  int totalsum; //the total sum is the answer we are looking for
  totalsum = sumdivideby(3) + sumdivideby(5) - sumdivideby(15);
  std::cout << "The total sum of all the multiples of \n";
  std::cout << "3 or 5 below 1000 is: " << totalsum << std::endl ;
  return 0;
}
