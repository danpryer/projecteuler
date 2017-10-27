// Project Euler 2
// Find sum of all even values in Fibonacci sequence not exceeding 4m

#include <iostream>

int main(){
  int totalsum=0; //total sum we are looking for
  int currentfib=1; //current number
  int newfib=0; //new number to find
  int oldfib=0; //old number
  do {
    newfib = currentfib + oldfib; //find the next fib number
    std::cout << newfib << std::endl; //print it
    if (newfib % 2 == 0){ //check if even, then add to total sum
      totalsum = totalsum + newfib;
    }
    oldfib = currentfib; //appropriate hand offs
    currentfib = newfib;
  } while (newfib < 4000001); // dont go past 4m
  std::cout << "Sum of fibs is: " << totalsum << std::endl; //print result
  return 0;
}
