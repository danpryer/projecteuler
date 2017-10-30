// General solution to Euler Project problem 3 that is both robust and fast.
// Works by creating a factor tree till all you are left with is a prime
// number which by definition will be the largest prime.
// For the problem stated, N = 600851475143.

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

int main(){
  long N, j, y;
  std::cout << "Submit an integer to find the largest prime factor:" << std::endl;
  std::cin >> N; // take a user input for N
  y = N; // placeholder for end message
  if (checkprime(N) == true) { //check if initial N is a prime
    std::cout << "The original number entered, " << N << ", is a prime!" << std::endl;
  }
  for (j = 2; j < sqrt(y); j = j + 1){
    if (N % j == 0){
      if (N == j) { // to stop the answer from being 1
        break;
      }
      N = N / j; // factor out j
      std::cout << "Divided by " << j << ", now checking " << N << std::endl;
      j = 1; // reset so j will be 2 again when the for statement loops
      if (checkprime(N) == true) { // to get the final answer
        std::cout << "The largest prime factor of " << y << " is " << N << std::endl;
        j = sqrt(y) - 1;
      } // end if
    } // end if
  } // end for
  return 0;
}
