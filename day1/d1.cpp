#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>

bool ReadFile(std::string filename, std::vector<std::string> &input)
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

int FindDigitPair(std::string line)
{
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

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage <executable> <puzzle input>" << '\n';
        return 1;
    }

    std::vector<std::string> input;
    if (!ReadFile(argv[1], input))
    {
        std::cerr << "Couldn't read the file provided." << '\n';
        return 1;
    }

    /// PART 1 ///
    int digitSum = 0;
    for (auto line : input)
    {
        digitSum += FindDigitPair(line);
 
    }
    std::cout << digitSum << '\n';
    /// FIN ///

    
    return 0;
}