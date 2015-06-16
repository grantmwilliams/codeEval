//Segmented Prime Number Function
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <stdint.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

// Not sure what codeEval's L1 cache size is?


// Sieve primes <= limit and set segmentSize to size of array in bytes.
void segmentedSieve(unsigned long int firstLim, unsigned long int limit)
{
	const int L1D_CACHE_SIZE = 10000; // cache size
	const int segmentSize = L1D_CACHE_SIZE;
	int sqrt = (int) std::sqrt((double) limit);
	long int count = (limit < 2) ? 0 : 1;
	unsigned long int s = 2;
	unsigned long int n = 3;
	unsigned long int primeCount;
	long int firstCount = 0;
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
	//std::vector<unsigned long int> allPrimes;

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

		for (; n <= high; n += 2)
		{
			if (sieve[n - low]) // n is prime
			{
				count++;
				if ((n-low)<= firstLim)
					firstCount++;
			}
		}
	}


	std::cout << count - firstCount << std::endl;
	
}

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while (fgets(line, sizeof(line), fp))
        {
            char *token = strtok(line, ",");
            int m = atoi(token);

            token = strtok(NULL, ",");
            int n = atoi(token);

            segmentedSieve(m,n);
        }
        fclose(fp);
    }
    return 0;
}