// Project Euler 4
// Find largest palindrome made from product of two 3 digit numbers
// Palindrome = number that reads the same forwards as backwards

#include <iostream>
#include <math.h>

int reverse(int i){ // function to reverse an input integer i
  int rev = 0;
  int m = 0;
  while ( i != 0) {
    m = (i % 10);
    rev = (rev*10) + m;
    i = i / 10;
  }
  return rev;
}

int main() {
  int x, y, prod, palindrome;
  for (x = 999; x > 99; x = x - 1) { //start from largest x and count down
    for (y = 999; y > 99; y = y - 1) { //start from largest x and count down
      prod = x * y;
      if (prod == reverse(prod)) { //check if product is palindrome
        if (prod > palindrome) { // is new palindrome larger?
          palindrome = prod; //replace previous largest with new largest
        } //end if
      } //end if
    } // end y for
  } // end x for
  std::cout << "The largest palindromic number made from the product ";
  std::cout << "of two 3-digit numbers is " << palindrome << std::endl;
  return 0;
}
