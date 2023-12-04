#include <stdlib.h>
#include <stdio.h>

#include <bitset>
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <sstream>

using namespace std;

int main(int argc, char **argv) {

std::string mystring;

std::ifstream myfile ("Seq5_SHA-512_NRS.txt");



if ( myfile.is_open() ) { 
  myfile >> mystring;

}

mystring.pop_back();


std::ofstream datafile("Seq5_SHA-512_NRS.dat", std::ios_base::binary | std::ios_base::out);

    char buf[3];
    buf[2] = 0;

    std::stringstream input(mystring);
    input.flags(std::ios_base::hex);
    while (input)
    {
        input >> buf[0] >> buf[1];
        long val = strtol(buf, nullptr, 16);
        datafile << static_cast<unsigned char>(val & 0xff);
    }

  

  return 0;
}
