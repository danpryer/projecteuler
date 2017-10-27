// Project Euler 3
// Find the largest prime factor of the number 600851475143

#include <iostream>

int main(){
  double theprime = 600851475143;
  int primefinder = (theprime + 1) / 2; //start from the half way point
  bool primefound = false;
  do{
    for (primefinder > 2; primefinder = primefinder - 1){
      //check to see if primefinder is a prime number
      bool isprime = true;
      int i;
      for (i = primefinder / 2; i >2; i = i - 1){
        if (primefinder % i == 0)
          isprime = false;
          break;
      }
    }
  } while (primefound == false);
  return 0;
}
