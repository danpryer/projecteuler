// Project Euler 13
// find first 10 digits of sum of one-hundred 50-digit no's in .txt file

#include <iostream>
#include <math.h>
#include <fstream>
#include <vector>
#include <string>

std::vector<long long> vector;

int main(){
  // load text file
  std::fstream infile;
  infile.open("euler013.txt");

  //create array and load data from .txt file
  std::string a[100] = {}; // create array with 100 entries
  for (int i = 0; i < 100; i++) { //write from .txt file into array a
    infile >> a[i];
    //std::cout << i << "    " << a[i] << std::endl; //tracer
  }

  //cut first 15 digits and sum
  long long N, sum = 0;
  for (int i = 0; i < 100; i++) {
    std::string N2 = a[i].substr(0,15);
    N = std::stol(N2);
    sum += N;
  }

  //shave down to 10 digits
  for (int i = 0; i < 7; i++) {
    sum /= 10;
  }

  //print answer
  std::cout << "The first 10 digits of sum of numbers is " << sum << std::endl;

  return 0;
}
