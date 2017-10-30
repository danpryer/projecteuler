#include <iostream>
#include <math.h>

int checkprime(long x) { //function which checks if input number is prime
  long i;
  bool isPrime = true;
  for(i = 2; i <= x / 2; i=i+1) {
    if(x % i == 0) {
      isPrime = false;
      break;
    }
  }
  return isPrime;
}

int main(){



  return 0;
}
