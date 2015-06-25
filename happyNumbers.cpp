// Happy Numbers for CodeEval in C++
#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool checkHappy(int num)
{
	int sum = 0;
	int digit = 0;

	for (; num > 0; num /=10) // loop to pull digits off
	{
		digit = (num % 10);
		sum += (digit * digit);
	}

	if (sum == 1)
		return 1;

	for (int i = 0; i < )
}

int main(int argc, char* argv[])
{
	ifstream inputFile (argv[1]);
	string line;
	
	if (inputFile)
	{
		while (getline(inputFile, line))
		{
			int n = atoi(line.c_str());
			cout << checkHappy(n) << endl;
		}
	}
}