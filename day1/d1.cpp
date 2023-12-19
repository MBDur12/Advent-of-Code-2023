#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cctype>
#include <regex>
#include "../utils.hpp"

int FindDigitPair(std::string line)
{
    std::cout << line << '\n';
    std::string first{}, last{};
    for (auto c : line)
    {
        if (std::isdigit(c))
        {
            if (first.empty())
            {
                first = c;
            }
            last = c;
        }
    }
    int digits = std::stoi(first + last);
    return digits;
}

std::string ReplaceWordsWithDigits(std::string line)
{   
    // Prevents "burning" through letters when replacing and missing overlaps
    std::unordered_map<std::string, std::string> wordsToDigits = {{"one", "o1e"}, {"two", "t2o"}, {"three", "t3e"}, {"four", "f4r"}, {"five", "f5e"}, {"six", "s6x"}, {"seven", "s7n"}, {"eight", "e8t"}, {"nine", "n9e"}};

    for (auto &match : wordsToDigits)
    {
        std::regex pattern = std::regex(match.first);
        std::string replacement = match.second;
        line = std::regex_replace(line, pattern, replacement);
    }
    return line;
}
// When the digits can also be spelled out
int FindDigits(std::string line)
{
    std::string first{}, last{};
    std::string lineDigits = ReplaceWordsWithDigits(line);

    for (auto c : lineDigits)
    {
        if (std::isdigit(c))
        {
            if (first.empty())
            {
                first = c;
            }
            last = c;
        }
    }
    
    int digits = std::stoi(first + last);
    return digits;
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

    /// PART 1 ///
    // int digitSum = 0;
    // for (auto line : input)
    // {
    //     digitSum += FindDigitPair(line);
    // }
    // std::cout << digitSum << '\n';
    /// FIN ///

    /// PART 2 ///
    int digitSum2 = 0;
    for (auto line : input)
    {
        digitSum2 += FindDigits(line);
    }
    std::cout << digitSum2 << '\n';
    /// FIN ///

    return 0;
}