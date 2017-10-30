// Project Euler 3
// Find the largest prime factor of the number 600851475143

#include <iostream>
#include <math.h>

int main(){
  long N, maxprime, i, x;
  //std::cout << "pls give integer" << std::endl;
  //std::cin >> N;
  N = 600851475143;
  x = N; // placeholder for end message
  for (i=2; i<sqrt(N);i=i+1){
    if (N % i == 0){
      std::cout << N << " is divisible by " << i << std::endl;
      N = N/i;
    }
  }
  std::cout << "The largest prime factor of " << x;
  std::cout << " is " << N << std::endl;
  return 0;
}
