// Project Euler 7
// Find the 10001st prime number

#include <iostream>
#include <math.h>

int checkprime(long x) { //function which checks if input number is prime
  long i;
  bool isPrime = true;
  for(i = 2; i <= sqrt(x); i=i+1) {
    if(x % i == 0) {
      isPrime = false;
      break;
    } //end if
  } //end for
  return isPrime;
}

int main() {
  long j, primecount;
  primecount = 0; // to count which prime has been found
  j = 1; // increment search through j
  bool primefound = false; // to end do while loop when answer found
  do {
    j = j + 1; // initial j is therefore 2
    if (checkprime(j) == true) { //check if j is a prime
      primecount = primecount + 1; //if so, increment counter
      if (primecount == 10001) { // if we have found the answer
        std::cout << "The 10001st prime number is " << j << std::endl;
        primefound = true;
        break;
      }
    }
  } while (primefound == false);
  return 0;
}
