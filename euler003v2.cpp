// Alternate approach to euler problem 3 (slow)

#include <iostream>
#include <math.h>

int checkprime(long x) { //function which checks if input number is prime
  long i;
  bool isPrime = true;
  for(i = 2; i <= sqrt(x); i=i+1) {
    if(x % i == 0) {
      isPrime = false;
      break;
    }
  }
  return isPrime;
}

int main(){
  long N = 600851475143; // set number to find factor of here
  long j;
  bool primefound = false;
  if (checkprime(N) == true) { //check if N is a prime
    primefound = true;
    std::cout << "The original number entered, " << N << ", is a prime!" << std::endl;
  }
  do {
    for (j = (N+1)/2; j > 1; j = j - 1) {
      if (N % j == 0) { // check if j a factor of N
        if (checkprime(j) == true) { // check if j a prime
          primefound = true;
          std::cout << "The largest prime factor is " << j << std::endl;
          break;
        } //end if
      } //end if
    } // end for
  } while (primefound ==false); // end do
  return 0;
}
