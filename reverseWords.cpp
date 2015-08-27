// Code Eval Reverse Words
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream ifs(argv[1]);
	string line;
	vector<string> sentence;

	while (getline(ifs,line))
	{
		istringstream iss(line);
		sentence.clear();

		string word;
		while (iss >> word)
		{
			sentence.push_back(word);
		}

		for (short i = sentence.size() - 1; i >= 0; i--)
		{
			cout << sentence[i] << " ";
		}
		cout << endl;
	}

	return 0;
}