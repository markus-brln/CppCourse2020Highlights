#include "strings/strings.h"
#include <iostream>
#include <string>

using namespace std;


int main(int argc, char *argv[])
{
    size_t nIter = stoul(argv[1]);

    bool copy = true;
    if (argc > 2)                           // optional arg for copy/move
        copy = stoul(argv[2]);              // 0 will cause move to be used

                                            // construct strings obj, does all
    Strings stringsCopyMove { nIter, copy };// the testing itself
}
// Program to test copy vs move performance on Strings class.
// Strings object is filled repeatedly with env variables.
// call with:
// ./main [nIterations] [0/1 for move/copy (optional)]