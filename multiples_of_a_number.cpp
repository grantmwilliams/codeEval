#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream ifs(argv[1]);
    int x, n;
    string line;
    
    while (getline(ifs, line)) {
        for (int i = 0; i < line.size(); ++i)
            if (line[i] == ',') line[i] = ' ';

        istringstream iss(line);
        iss >> x >> n;

        for (int j =1; ; j++)
        	if (n * j >= x)
            {    
        	    cout << n * j << endl;
        	    break;
            }
    }

    return 0;
}