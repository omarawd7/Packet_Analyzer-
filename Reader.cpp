#include "Reader.h"

std::vector<std::string> Reader::read(std::string Path)
{
	std::ifstream inputFile(Path);
	while (getline(inputFile, line))
	{
		Input.push_back(line);
	}
	return Input;
}

std::vector<std::string> Reader::GetInput()
{
 return Input;
}
