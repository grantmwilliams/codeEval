#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <stdint.h>

using namespace std;

void primeSieve()
{   
    const long int numSize = 105000;
    const int limit = 1000;
    int count = 0;
    long int total = 0;
    int sqrt = (int) std::sqrt((double) numSize);
    
    // Vector to sieve with
    std::vector<char> sieve(numSize); 

    // Set all values to true except 1
    std::fill(sieve.begin() + 1, sieve.end(),1);

    for (int i = 2; i <= sqrt; i++)
        if (sieve[i])
            for (long int j = i*i; j <= numSize - 1; j +=i)
                sieve[j] = 0;

    for (int k = 1;count <= limit; k++)
        if (sieve[k])
        {
            total += ((int) k);
            count++;
        }
    std::cout << total - 1 << std::endl;
}

int main()
{
    primeSieve();
    return 0;
}
