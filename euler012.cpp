// Project Euler 12
// What is the value of the first triangle number to
// have over five hundred divisors?

#include <iostream>
#include <math.h>
#include <vector>

std::vector<std::vector<long> > matrix; //initialise matrix
//Matrix will store the prime factors in column 1
//and the number of occurences of the factor +1 in second column.
//The product of all the entries in the 2nd column gives the divisors

int checkprime(long x) { //function which checks if input number is prime
  long i;
  bool isPrime = true;
  for(i = 2; i <= sqrt(x+5); i=i+1) {
    if(x % i == 0) {
      isPrime = false;
      break;
    }
  }
  if (x==2) {
    isPrime = true;
  }
  return isPrime;
}



int main() {
  long N = 1;
  long vecrows;
  long divisors;

  //set up array
  matrix.clear();
  matrix.resize(4); //initial size of array is 4 rows
  for (int i = 0; i < 4; i++){ //initialise 2d array
    matrix[i].resize(2); // array needs 2 columns
    matrix[i][1] = 1; //want to record count of prime factor + 1
    matrix[i][0] = 0;
  }

  while (divisors < 501) { // **main logic loop**
    divisors = 1;
    long triangle = (N*(N+1)/2); //calc triangle
    long holder = triangle; //holder used to calc prime factors
    long currentrow = 0; //reset row in matrix

    //wipe array clean
    vecrows = matrix.size();
    for (int i = 0; i < vecrows; i++){
      matrix[i][1] = 1;
      matrix[i][0] = 0;
    }

    //perform a prime factorisation of triangle
    for (long i = 2; i <= sqrt(triangle); i++) {
      if (holder % i == 0){ //is i a factor?
        if (checkprime(i) == true) { //is i a prime?

          // add prime factor i to array and increment count of i
          if (matrix[currentrow][0] == 0 || matrix[currentrow][0] == i){
            matrix[currentrow][0] = i;
            matrix[currentrow][1] = matrix[currentrow][1] + 1;
          } else {
            currentrow = currentrow + 1;
            if (currentrow == vecrows){ //increase size if need be
              //std::cout << "Trigger" << std::endl; //trigger
              matrix.resize(vecrows+1);
              matrix[vecrows].resize(2);
              matrix[currentrow][0] = 0;
              matrix[currentrow][1] = 1;
              vecrows = matrix.size();
            }
            matrix[currentrow][0] = i;
            matrix[currentrow][1] = matrix[currentrow][1] + 1;
          }
          holder = holder / i; //factor out i
          i--; //see if i is factor again
        }
      }
    }

    // go through prime factor array and find divisors
    // from product of 2nd column
    currentrow = 0;
    while (matrix[currentrow][0] != 0) {
      divisors = divisors * matrix[currentrow][1];
      //std::cout << matrix[currentrow][0] << " " << matrix[currentrow][1] <<std::endl; //tracer
      currentrow++;
      if (currentrow == vecrows) { //stops segmentation fault 11
        break;
      }
    }

    //tracer
    //std::cout << "Triangle: " << triangle << " Divisors: " << divisors <<std::endl;

    //if answer found
    if (divisors > 500) {
      std::cout << "The answer is " << triangle << " !" << std::endl;
      break;
    }
    N++; //cycle for next triangle
  }

  return 0;
}
