#include <iostream>
#include <fstream>

using namespace std;

void number_of_ones(int val)
{
	int total = 0;
	while (val)
	{
		if (val & 1)
			total++;
		val >>= 1;
	}
	std::cout << total << std::endl;
}

int main(int argc, char *argv[]) 
{
    ifstream ifs(argv[1]);
    unsigned int val;
    while (ifs >> val) 
    {
      number_of_ones(val);
    }
    return 0;
}