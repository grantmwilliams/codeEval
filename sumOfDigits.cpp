#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream ifs(argv[1]);
    short num;
    string line;
    
    while (getline(ifs, line))
    {
        istringstream iss(line);
        iss >> num;
        short sum = 0;
        while (num > 0) 
        {
        	sum += num%10;
        	num /= 10;
        }
        cout << sum << endl;
    }

    return 0;
}