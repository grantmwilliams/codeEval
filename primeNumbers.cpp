//Segmented Prime Number Function
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <stdint.h>

using namespace std;

// Not sure what codeEval's L1 cache size is? 4096?


// Sieve primes <= limit and set segmentSize to size of array in bytes.
void segmentedSieve(unsigned long int limit)
{
	limit = limit -1;
	const int L1D_CACHE_SIZE = 32768; // cache size
	const int segmentSize = L1D_CACHE_SIZE;
	int sqrt = (int) std::sqrt((double) limit);
	unsigned long int count = (limit < 2) ? 0 : 1;
	unsigned long int s = 2;
	unsigned long int n = 3;

	// Vector to sieve with
	std::vector<char> sieve(segmentSize);

	// Generate small primes <= sqrt
	std::vector<char> isPrime(sqrt + 1, 1);
	for (int i = 2; i*i <= sqrt; i++)
		if (isPrime[i])
			for (int j = i*i; j <= sqrt; j +=i)
				isPrime[j]=0;

	std::vector<int> primes;
	std::vector<int> next;
	std::vector<unsigned long int> allPrimes;

	for (unsigned long int low = 0; low <= limit; low += segmentSize)
	{
		std::fill(sieve.begin(), sieve.end(),1);

		// Current segment = interval[low, high]
		unsigned long int high = std::min(low + segmentSize - 1, limit);

		// Store small primes needed to cross off multiples
		for (; s * s <= high; s++)
		{
			if (isPrime[s])
			{
				primes.push_back((int) s);
					next.push_back((int)(s * s - low));
			}
		}
		// Sieve the current segment
		for (std::size_t i = 1; i < primes.size(); i++)
		{
			int j = next[i];
			for (int k = primes[i] * 2; j < segmentSize; j += k)
				sieve[j] = 0;
			next[i] = j - segmentSize;
		}

		std::cout << "2";
		for (; n <= high; n += 2)
		{
			if (sieve[n - low]) // n is prime
			{
				count++;
				//allPrimes.push_back((unsigned long int) n-low);
				std::cout << "," << (n-low) << std::endl;
			}
		}
	}
	/* MAYBE NOT NEEDED
	std:: cout << "2";
	for (int ii = 0; ii < count-1; ii++){
		std::cout << "," << allPrimes[ii];
	}
	std:: cout << std::endl;
	*/
}

int main(int argc, char *argv[]) 
{
    ifstream ifs(argv[1]);
    unsigned int val;
    while (ifs >> val) 
    {
      segmentedSieve(val);
    }
    return 0;
}