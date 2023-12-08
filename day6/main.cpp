#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>
#include <assert.h>
#include "../utils.hpp"

int CountWinningRaces(int time, int distance)
{
    assert(time > 0);
    assert(distance > 0);
    assert(time <= distance);

    int count{0};
    int speed{0};

    for (int i = 1; i <= time; i++)
    {
        speed = i;
        int timeRemaining = time - i;

        if (timeRemaining * speed > distance)
        {
            count++;
        }
    }   

    return count;
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
    assert(input.size() == 2);
    std::vector<int> times = ExtractNums(input[0]);
    std::vector<int> distances = ExtractNums(input[1]);
    assert(times.size() == distances.size());

    int numWins{0};
    for (size_t i = 0; i < times.size(); i++)
    {
        int wins = CountWinningRaces(times[i], distances[i]);
        if (wins > 0 && numWins > 0)
        {
            numWins *= wins;
        }
        else
        {
            numWins += wins;
        }
    }
    std::cout << "Number of winnnig race combinations: " << numWins << std::endl;


    /// FIN ///

    /// PART 2 ///
    /// FIN ///     

    return 0;
}