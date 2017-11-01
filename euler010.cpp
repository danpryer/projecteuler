// Project Euler 10
// Find the sum of all primes below 2000000

#include <iostream>
#include <math.h>

int checkprime(long x) { //function which checks if input number is prime
  long i;
  bool isPrime = true; // assume number is a prime, then test
  for(i = 2; i <= sqrt(x); i=i+1) {
    if(x % i == 0) { // if number to check is divisible by another number..
      isPrime = false; // then its not a prime
      break;
    } //end if
  } //end for
  return isPrime;
}

int main(){
  long primesum;
  for (long j = 2; j < 2000000; j = j + 1) { //step through numbers
    if (checkprime(j) == true) { // check if current number is prime
      primesum = primesum + j; //if so, add to sum of primes
    }
  } //then print the result
  std::cout << "The sum of all primes below 2000000 is " << primesum << std::endl;
  return 0;
}
