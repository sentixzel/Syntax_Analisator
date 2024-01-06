#pragma once
#include <string>
#include <vector>

class FormatText
{
public:
	static std::vector<std::string> DeleteCommentary(std::vector<std::string>&);
	static std::vector<std::string> DeleteSpaces(std::vector<std::string>&);
	static std::string InOneString(std::vector<std::string>&);
	//one string format
	//static std::string AddSpaces(std::string&);
};

