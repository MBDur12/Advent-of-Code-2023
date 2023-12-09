#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>
#include <unordered_map>
#include <cmath>
#include <assert.h>
#include "../utils.hpp"

int CountMatchingCards(std::string lottery)
{
    int count{0};
    // String of the form: 41 48 83 86 17 | 83 86  6 31 17  9 48 53
    std::vector<std::string> cards = Split(lottery, "|");
    assert(cards.size() == 2);

    std::vector<long> winningCards = ExtractNums(cards[0]);
    std::vector<long> playCards = ExtractNums(cards[1]);

    for (auto num : playCards)
    {
        if (std::find(winningCards.begin(), winningCards.end(), num) != winningCards.end())
        {
            count += 1;
        }
    }

    return count;
}

void SolvePart1(const std::vector<std::string> &input)
{
    std::vector<std::string> cards{};
    int totalCount{0};

    for (size_t i = 0; i < input.size(); i++)
    {
        std::vector<std::string> parts = Split(input[i], ":");
        int count = CountMatchingCards(parts[1]);
        totalCount += std::pow(2, count - 1);
    }

    std::cout << "Part1: " << totalCount << std::endl;
}

void SolvePart2(const std::vector<std::string> &input)
{
    std::vector<int> counts(input.size(), 1);
    for (size_t i = 0; i < input.size(); i++)
    {
        std::vector<std::string> parts = Split(input[i], ":");
        int matches = CountMatchingCards(parts[1]);
        for (size_t j = i+1; j < matches+i+1; j++)
        {
            counts[j] += counts[i]; // ACCOUNT for copies
        }
    }

    int totalCount{0};
    for (auto count : counts)
    {
        totalCount += count;
    }
    std::cout << "Part2: " << totalCount << std::endl;
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

    SolvePart1(input);
    SolvePart2(input);
    return 0;
}