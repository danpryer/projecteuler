// Project Euler 5
// What is the smallest positive number that is evenly divisible by all
// of the numbers from 1 to 20?

#include <iostream>
#include <math.h>

int division(int x) { // function to check if input number is divisible
  bool divi = true; // by the numbers 1 through 20
  int i;
  for (i = 1; i <=20; i = i + 1){
    if (x % i != 0) {
      divi = false;
      break;
    }
  }
  return divi;
}

int main(){
  long y = 0;
  bool found = false;
  do { //step through values of y and use division function to find answer
    y = y + 1;
    found = division(y);
  } while (found == false);
  std::cout << "The smallest positive number that is evenly ";
  std::cout << "divisible by the first 20 numbers is " << y << std::endl;
  return 0;
}
