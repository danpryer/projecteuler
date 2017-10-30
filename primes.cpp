// simple function to check if an input integer is prime or not

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
  long n;
  std::cout << "Enter a positive integer: ";
  std::cin >> n;

  if (checkprime(n)==true)
      std::cout << "This is a prime number" << std::endl;
  else
      std::cout << "This is not a prime number" << std::endl;
  return 0;
}
