#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>
#include <assert.h>
#include "../utils.hpp"

long long CountWinningRaces(int time, int distance)
{
    assert(time > 0);
    assert(distance > 0);
    assert(time <= distance);

    long long count{0};
    int speed{0};

    for (int i = 0; i <= time; i++)
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

void SolvePart2(const std::vector<std::string> &input)
{
    std::string line1 = StripWhitespace(input[0]);
    std::string line2 = StripWhitespace(input[1]);
    
    std::vector<long long> time = ExtractNums(line1);
    std::vector<long long> distance = ExtractNums(line2);
    std::cout << time[0] << " " << distance[0] << std::endl;
    std::cout << "Number of ways to win (long): "  << CountWinningRaces(time[0], distance[0]) << std::endl;
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
    std::vector<long long> times = ExtractNums(input[0]);
    std::vector<long long> distances = ExtractNums(input[1]);
    assert(times.size() == distances.size());

    long long numWins{0};
    for (size_t i = 0; i < times.size(); i++)
    {
        long long wins = CountWinningRaces(times[i], distances[i]);
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

    SolvePart2(input);
    /// FIN ///     

    return 0;
}