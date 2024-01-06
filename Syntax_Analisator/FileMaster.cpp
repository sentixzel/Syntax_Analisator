#include "FileMaster.h"

FileMaster::FileMaster(std::string path)
{
	std::ifstream file;
	file.open(path);

	if (!file.is_open())
		throw("File did not open!\n");
		
	std::string buf;
	while (getline(file, buf))
		lines.push_back(buf);

	file.close();
}

std::string FileMaster::getLine()
{
	if (it >= lines.size())
		it = -1;

	return lines[it++];
}

std::vector<std::string> FileMaster::getLines()
{
	return lines;
}

