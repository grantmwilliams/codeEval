#include <iostream>
#include <fstream>

using namespace std;


void age_distribution(int val)
{
	if (val >= 0 && val <= 2)
		std::cout << "Still in Mama's arms" << std::endl;
	else if (val == 3 || val == 4)
		std::cout << "Preschool Maniac" << std::endl;
	else if (val >= 5 && val <= 11)
		std::cout << "Elementary school" << std::endl;
	else if (val >= 12 && val <= 14)
		std::cout << "Middle school" << std::endl;
	else if (val >= 15 && val <= 18)
		std::cout << "High school" << std::endl;
	else if (val >= 19 && val <= 22)
		std::cout << "College" << std::endl;
	else if (val >= 23 && val <= 65)
		std::cout << "Working for the man" << std::endl;
	else if (val >= 66 && val <= 100)
		std::cout << "The Golden Years" << std::endl;
	else
		std::cout << "This program is for humans" << std::endl;

}


int main(int argc, char *argv[]) 
{
    ifstream ifs(argv[1]);
    unsigned int val;
    while (ifs >> val) 
    {
      age_distribution(val);
    }
    return 0;
}