#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Program that is trying to replicate the Linux grep command
// A school project in a C++ course

int main(int argc, char* argv[]) {

	ifstream dataFile;
	string search1 = argv[1];
	string search2;
	string file = argv[2];
	string line;
	size_t pos;
	int index = 0;

// Open the file which we are searching from
	dataFile.open(file, ios::in);

// Display the number of arguments and the search + file that were given
	cout << "You have entered " << argc
		<< " arguments:" << "\n";

	cout << search1 << "\n";

	cout << file << "\n";

// If 2 arguments were given the program will ask for a string input
//The program will then ask for a search input and try to find it from the 1st input
	if (argc < 2) {

		cout << "Give a string from which to search for: ";
		getline(cin, line);

		cout << "Give search string: ";
		getline(cin, search2);

// Searching
		if (line.find(search2) != string::npos) {

			index = line.find(search2);

			cout << search2 << " found in " << line << " in position " << index << endl;

		}
// Nothing found
		else {

			cout << search2 << " NOT found in " << line << endl;

		}

		return 0;

	}
// If there are not 2 arguments given the program will open a given file and search from that instead
	else {

// Error in opening/finding file
		if (!dataFile) {
			cout << "Unable to open file" << endl;

			return 0;
		}

// Success in opening the file
		while (getline(dataFile, line))
		{
			cout << "File opened" << endl;

			pos = line.find(search1);

// Is supposed to search the file for given string, but doesn't work
			if (pos != string::npos)
			{

				cout << pos << ": " << line << endl;

			}
			else {

				cout << "Broken" << endl;

				return 0;
			}
		}
	}
}