// Project Euler 8
// Find the thirteen adjacent digits in the 1000-digit number that have
// the greatest product. What is the value of this product?

#include <iostream>
#include <math.h>
#include <string.h>

long prod13(long x){ // takes input x and finds product of individual digits
  long product = 1;
  long m = 0;
  while ( x != 0) {
    m = (x % 10); // shave off a digit
    if (m != 1){ // as long as digit isnt a 1, do a product
      product = product * m;
      if (product != 0){
      }
    }
    x = x / 10;
  }
  return product;
}

int main() {
  std::string N = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";
  int lenN = N.length(); //gets length of above number (stored in string form)
  long i = 0; // increment through i
  long long maxprod = 0; //to store max product
  long long prod = 0;
  long long y; // to take 13 digit no and feed to prod13 function
  for (i = 0; i <= lenN - 13; i = i + 1){ // step through all possible 13 digit no's
    std::string N2 = N.substr(i,13); // copys 13 digits from N, from the i'th pos
    y = std::stol(N2); //converts 13 digit string to a long
    prod = prod13(y);
    if (prod > maxprod){
      maxprod = prod;
    }
  }
  std::cout << "The largest product is " << maxprod << std::endl;
  return 0;
}