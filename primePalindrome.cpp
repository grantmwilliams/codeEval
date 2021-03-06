// Largest Prime Palindrome Problem CodeEval
#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int isPalindrome(int num){
 int dig = 0;
 int n = num;
 int rev = 0;
 while (num > 0)
 {
      dig = num % 10;
      rev = rev * 10 + dig;
      num = num / 10;
 }
 if (rev==n)
    return 1;
 else
    return 0;
}

int main(){
	int i = 0;
    const int upper = 1000;
    int k = 0;
    const int lim = (sqrt(upper)+1);
    int tot = 0;
    bool array[upper+1];
        

    // begin by setting array to show all possible primes as true
    while (++i<upper+1){
        array[i] = true;
    }
    // now start to set multiples as false
    i = 2;
    while (i<=lim) {   //count through array 1 by 1 to sqrt of upper (i)
        
        if (array[i] == true) {   // test if that array index no. is true as a poss prime
            k = i*i; // set array mod loop var = main loop index (multiple in question)
            while (k <= upper+1){    // check all multiples up to upper
                array[k] = false;    // set all multiples as false (not prime)
                k = k + i;           // increment k up its times table
            }
        }
        i++;
    }
    array [1] = false; // clear index 1 as not prime (an exception)
    
    //Now loop to total the index numbers of the TRUE entries
    int j=1000;
    while (--j > 0){
        if (array [j] == true && isPalindrome[j] == 1){ 
            std::cout << i << std::endl;
        }
    }
    
    return 0;
}