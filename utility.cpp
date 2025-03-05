#include "utility.h"
#include <fstream>

using namespace std;

bool fileExists(const string &filename) {
    ifstream file(filename);
    return file.good();
}

string readFile(const string &filename) {
    ifstream file(filename);
    return string((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
}