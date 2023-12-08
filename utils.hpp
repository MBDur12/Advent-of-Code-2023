#pragma once
#include <vector>
#include <string>

bool ReadFileIntoLines(std::string filename, std::vector<std::string> &input);
std::vector<std::string> Split(std::string s, std::string delimeter);