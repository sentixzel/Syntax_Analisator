#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class FileMaster
{
	std::vector<std::string> lines;
	int it = 0;
	
public:
	//std::string <���_�����>
	FileMaster(std::string);

	std::string getLine();
	std::vector<std::string> getLines();
};

