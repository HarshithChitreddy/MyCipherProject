#include <iostream>
#include <fstream>
#include "block.h"
#include "stream.h"
#include "utility.h"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 6) {
        cerr << "Invalid number of arguments" << endl;
        return 1;
    }

    string cipherType = argv[1];
    string inputFile = argv[2];
    string outputFile = argv[3];
    string keyFile = argv[4];
    string mode = argv[5];

    if (cipherType != "B" && cipherType != "S") {
        cerr << "Invalid Function Type" << endl;
        return 1;
    }

    if (mode != "E" && mode != "D") {
        cerr << "Invalid Mode Type" << endl;
        return 1;
    }

    if (!fileExists(inputFile)) {
        cerr << "Input File Does Not Exist" << endl;
        return 1;
    }

    if (!fileExists(keyFile)) {
        cerr << "Key File Does Not Exist" << endl;
        return 1;
    }

    string key = readFile(keyFile);

    if (cipherType == "B") {
        processBlockCipher(inputFile, outputFile, key, mode);
    } else {
        processStreamCipher(inputFile, outputFile, key, mode);
    }

    return 0;
}