//N mod M C++
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main (int argc, char* argv[])
{
	ifstream inputFile(argv[1]);
	string line;

	if (inputFile)
	{
		while (getline(inputFile,line))
		{
			size_t commaPos = line.find(",");
			int N = atoi(line.substr(0,commaPos).c_str());
			int M = atoi(line.substr(commaPos + 1).c_str());
		
			int final = N - M * (N/M);

			cout << final << endl;
		}
	}
}