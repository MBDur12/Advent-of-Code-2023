#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <assert.h>


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

bool MaxCubesExceeded(std::string game, int redMax, int greenMax, int blueMax)
{
    std::vector<std::string> results = Split(game, ";");
    for (auto result : results)
    {
        std::vector<std::string> cubes = Split(result, ",");
        for (auto cube : cubes)
        {   
            std::string numStr, colour;
            for (auto c : cube)
            {
                if (c == ' ')
                {
                    continue;
                }
                
                if (std::isdigit(c))
                {
                    numStr += c;
                }
                else
                {
                    colour += c;
                }

            }
            if (colour == "red")
            {
                if (std::stoi(numStr) > redMax)
                {
                    return true;
                }
            }
            else if (colour == "blue")
            {
                if (std::stoi(numStr) > blueMax)
                {
                    return true;
                }
            }
            else if (colour == "green")
            {
                if (std::stoi(numStr) > greenMax)
                {
                    return true;
                }
            }
        }
    }
    return false;
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
    int idSum = 0;
    for (auto line : input)
    {
        std::vector<std::string> parts = Split(line, ":");
        assert (parts.size() == 2);
        std::vector<std::string> game = Split(parts[0], " ");
        int id = std::stoi(game[1]);
        assert (id > 0);
        if (!MaxCubesExceeded(parts[1], 12, 13, 14)) idSum += id;
        
    }
    std::cout << idSum << std::endl;
    /// FIN ///


    return 0;
}