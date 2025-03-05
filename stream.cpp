#include "stream.h"
#include <fstream>

using namespace std;

void processStreamCipher(const string &inputFile, const string &outputFile, const string &key, const string &mode) {
    ifstream in(inputFile, ios::binary);
    ofstream out(outputFile, ios::binary);

    char ch;
    size_t keyIndex = 0;
    while (in.get(ch)) {
        ch ^= key[keyIndex];
        out.put(ch);
        keyIndex = (keyIndex + 1) % key.length();
    }
}
