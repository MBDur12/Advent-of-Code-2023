#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>
#include <assert.h>
#include "../utils.hpp"

void SolvePart1(const std::vector<std::string> &input)
{
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage <executable> <puzzle input>" << '\n';
        return 1;
    }

    std::vector<std::string> input;
    if (!ReadFileIntoLines(argv[1], input))
    {
        std::cerr << "Couldn't read the file provided." << '\n';
        return 1;
    }

    
    return 0;
}