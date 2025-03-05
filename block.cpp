#include "block.h"
#include "utility.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int BLOCK_SIZE = 16;
const char PADDING_BYTE = (char)0x81;

void xorBlock(vector<char>& block, const string& key) {
    for (int i = 0; i < BLOCK_SIZE; ++i) {
        block[i] ^= key[i];
    }
}

void swapBlock(std::vector<char>& block, const std::string& key) {
    int start = 0, end = BLOCK_SIZE - 1;

    for (char c : key) {
        if (start >= end) break;

        if ((c % 2) == 1) {
            std::swap(block[start], block[end]);
            --end;
        }
        ++start;
    }
}

vector<char> encryptBlock(const vector<char>& block, const string& key) {
    vector <char> encryptedBlock = block;
    xorBlock(encryptedBlock, key);
    swapBlock(encryptedBlock, key);
    return encryptedBlock;
}

vector<char> decryptBlock(const vector<char>& block, const string& key) {
    vector<char> decryptedBlock = block;
   
    int start = 0, end = BLOCK_SIZE - 1;
    for (size_t i = 0; i < key.size(); ++i) {
        if (start >= end) break;
        if ((key[i] % 2) == 1) {
            std::swap(decryptedBlock[start], decryptedBlock[end]);
            --end;
        }
        ++start;
    }

    for (int i = 0; i < BLOCK_SIZE; ++i) {
        decryptedBlock[i] ^= key[i];
    }

    return decryptedBlock;
}

void processBlockCipher(const string& inputFile, const string& outputFile, const string& key, const string& mode) {
    ifstream in(inputFile, ios::binary);
    ofstream out(outputFile, ios::binary);
   
    vector<char> block(BLOCK_SIZE, PADDING_BYTE);
    while (in.read(block.data(), BLOCK_SIZE) || in.gcount() > 0) {
        int bytesRead = in.gcount();
        if (bytesRead < BLOCK_SIZE) {
            fill(block.begin() + bytesRead, block.end(), PADDING_BYTE);
        }

        vector<char> processedBlock;
        if (mode == "E") {
            processedBlock = encryptBlock(block, key);
        } else {
            processedBlock = decryptBlock(block, key);

            if (in.peek() == EOF) {
                while (!processedBlock.empty() && processedBlock.back() == PADDING_BYTE) {
                    processedBlock.pop_back();
                }
            }
        }

        out.write(processedBlock.data(), processedBlock.size());
    }
}
