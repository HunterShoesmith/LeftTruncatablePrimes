#include <iostream>
#include <vector>

bool isPrime(unsigned long long x);
bool leftTruncatable(unsigned long long y);
int width(unsigned long long p);

int main() {
  /*
  unsigned long long int primes[] = {357686312646216567629137,1,22,5,7,11};
  std::cout << "Number of primes to test: " << (sizeof(primes)/sizeof(*primes)) << std::endl;
  

  int arrLen = (sizeof(primes)/sizeof(*primes));
  */ 
  int intPrimes[] = {2,3,5,7};
  
  std::vector<unsigned long long> prevPrimes;

  for (int i=0;i<4;i++){
    prevPrimes.push_back(intPrimes[i]);
  }
  
  int prevPrimesLen = prevPrimes.size();

  std::vector<unsigned long long> currPrimes;
  
  //how many places to do loop for
  std::cout << "how many digits to find left truncatable primes(please PLEASE no larger than 14): ";
  int places=0;
  std::cin >> places;
  places--;



  long LeftTrunTotal = 0;

  for (int z=0;z<places;z++){
    for (int i=0;i<prevPrimesLen;i++){
      int lenth = width(prevPrimes[i]);
        
      unsigned long long exp = 10;
      //power of 10 to add
        
      for (int m=1;m<lenth;m++){
        exp *= 10;
      }
      for (int n=1;n<10;n++){
        //get length of prev prime
        
        
        
        //get num to test
        //std::cout << n << "   " << exp << std::endl;
        //std::cout <<"  " << prevPrimes[i] << "  " <<n << "  " <<lenth << std::endl;
        unsigned long long test = prevPrimes[i] + n*exp;
        
        //test it if it is prime add it to   the curr vector if it is;
        //no need to test left truncation because the parent is prime
        if (isPrime(test)){
          currPrimes.push_back (test);
          std::cout << "true: " <<  test << std::endl;
          LeftTrunTotal++;
        } 
        else std::cout << "false: " <<  test << std::endl;
      }
    }
    //itterate and prime contents of currPrimes;
    for (unsigned long long q : currPrimes){
      std::cout << q << ' ';
    }
    std::cout << std::endl;
    prevPrimes = currPrimes;
    currPrimes.clear();
    prevPrimesLen = prevPrimes.size();
  }
  std::cout << "Total left truncatable primes up to " << places+1 << " places: " << LeftTrunTotal << std::endl;
/*
  for (int i=0;i<arrLen;i++){
    std::cout << primes[i] << " is prime: " <<isPrime(primes[i]) << std::endl;
    std::cout << primes[i] << " is leftTruncatablePrime: "  << leftTruncatable(primes[i]) << std::endl;
  }
  */
}

int width(unsigned long long p){
  int lengthY = 0;
  do {
    ++lengthY;
    p /= 10;
  }while (p);
  return lengthY;
}

bool leftTruncatable(unsigned long long y){

  unsigned long long int copy = y;
  int lengthY;
  do {
    ++lengthY;
    copy /= 10;
  }while (copy);

  for (int i=0;i<lengthY;i++){
    if (!(isPrime(y))) return false;
    y = y%10;
  }

  return true;

}

bool isPrime(unsigned long long n) {
    // Assumes that n is a positive natural number
    // We know 1 is not a prime number
    if (n == 1) {
        return false;
    }

    unsigned long long int i = 2;
    // This will loop from 2 to int(sqrt(x))
    while (i*i <= n) {
        // Check if i divides x without leaving a remainder
        if (n % i == 0) {
            // This means that n has a factor in between 2 and sqrt(n)
            // So it is not a prime number
            return 0;
        }
        i += 1;
    }
    // If we did not find any factor in the above loop,
    // then n is a prime number
    return true;
}