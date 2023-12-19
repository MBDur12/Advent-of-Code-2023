#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <assert.h>
#include "../utils.hpp"

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

int PowerOfCubes(std::string game)
{
    int red{0}, green{0}, blue{0};
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
                if (std::stoi(numStr) > red)
                {
                    red = std::stoi(numStr);
                }
            }
            else if (colour == "blue")
            {
                if (std::stoi(numStr) > blue)
                {
                    blue = std::stoi(numStr);
                }
            }
            else if (colour == "green")
            {
                if (std::stoi(numStr) > green)
                {
                    green = std::stoi(numStr);
                }
            }
        }
    }
    return red*green*blue;
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

    /// PART 2 ///
    int powerSum = 0;
    for (auto line : input)
    {
        std::vector<std::string> parts = Split(line, ":");
        assert (parts.size() == 2);
        std::vector<std::string> game = Split(parts[0], " ");
        int id = std::stoi(game[1]);
        assert (id > 0);
        powerSum += PowerOfCubes(parts[1]);
    }
    std::cout << powerSum << std::endl;
    /// FIN ///     

    return 0;
}