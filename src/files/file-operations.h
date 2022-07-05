#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
using namespace std;


int countRecords(string FILENAME) {
    ifstream inFile(FILENAME);

    string line;
    int lines = 0;
    while (inFile >> line)
        lines++;
    return lines;
}