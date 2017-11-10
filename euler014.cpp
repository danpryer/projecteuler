// Project Euler 14
// See https://projecteuler.net/problem=14 for description of problem
// Which starting number, under one million, produces the longest chain?
// Note: Once the chain starts the terms are allowed to go above one million.

//Packages
#include <iostream>
#include <math.h>
#include <fstream>
#include <vector>
#include <string>

//vector for storing the chain length for a given number N
std::vector<long> chainlen(1000000);

int main(){
  long maxchain = 0;
  long maxN;

  //set all values to 0 in vector
  for (long N = 1; N < 1000001; N++){
    chainlen[N] = 0;
    //std::cout << chainlen[N] << std::endl; //tracer
  }

  //main code for solving problem
  for (long N = 2; N < 1000001; N++){
    long n = 0;
    long counter = 0;
    if (chainlen[N] == 0){ //if chainlen for this number isn't calculated yet
      n = N; // calculate with n to keep N preserved
      while (n != 1) {
        if (n % 2 == 0) { //if N even
          n = n/2;
          counter++;
        } else { //if N odd
          n = (3*n) + 1;
          counter++;
        }

        //section to stop recalculation of chains
        if (n < N) {
          if (chainlen[n] != 0) { // if you hit an already calculated number
            counter = counter + chainlen[n]; // inherit counter from the chain
            chainlen[N] = counter;
            n = 1; // now exit the while loop
          }
        }
      }
      chainlen[N] = counter;

      //find largest chain and associated N
      if (chainlen[N] > maxchain){
        maxchain = chainlen[N];
        maxN = N;
      }
    //std::cout << "N = " << N << "  Counter = " << counter << std::endl; //tracer
    }
  }

  //print result
  std::cout << "The answer is " << maxN << std::endl;

  return 0;
}
