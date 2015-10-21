#pragma once
#include <vector>


class IOManager
{
public:
	static bool readFileToBuffer(const std::string &filename, std::vector<unsigned char> &buffer);
	static bool readFileToBuffer(const std::string &filename, std::string &buffer);
};
