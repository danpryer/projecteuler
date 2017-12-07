//Packages
#include <iostream>
#include <math.h>
#include <fstream>
#include <vector>
#include <string>

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

long long factorial(long long n) { //function to calculate factorials
  if (n == 1 || n == 0) {
    n = 1;
  } else if ( n < 0) {
    n = 0;
  } else {
    int i = 1;
    long long holder = n;
    while (i < holder) {
      n = n * i;
      i++;
    }
  }
  return n;
}
