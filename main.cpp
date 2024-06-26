#include <iostream>

#include "srcnn.hpp"

using namespace std;

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        cout << "Usage: ./SRCNN_cpp <input image path>" << endl;
        return 1;
    }
    string filename = argv[1];

    SRCNN srcnn;
    
    srcnn.generate(filename);

    return 0;
}
