#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "utils.hpp"

bool ReadFileIntoLines(std::string filename, std::vector<std::string> &input)
{
    std::ifstream file{filename};
    if (!file)
    {
        std::cerr << "Cannot open file " << filename << '\n';
        return false;
    }

    std::string line;
    while (getline(file, line))
    {
        input.push_back(line);
    }

    file.close();
    return true;
}

std::vector<std::string> Split(std::string s, std::string delimeter)
{
    size_t start = 0, end, delimeterLen = delimeter.length();
    std::string currentToken;
    std::vector<std::string> result;

    while ((end = s.find(delimeter, start)) != std::string::npos)
    {
        currentToken = s.substr(start, end - start);
        start = end + delimeterLen;
        result.push_back(currentToken);
    }

    result.push_back(s.substr(start));
    return result;
}