#include "FormatText.h"

std::vector<std::string> FormatText::DeleteCommentary(std::vector<std::string>& text)
{
	int deleteFlag = 0;

	for (int i = 0; i < text.size(); i++)
	{
		if (deleteFlag == 2 && !text[i - 1].empty())
			text[i - 1].pop_back();

		for (int j = 1; j < text[i].size(); j++)
			switch (deleteFlag)
			{
			case 2:
				if (text[i][j - 1] == '*' && text[i][j] == '/')
				{
					text[i].erase(j, 1);
					deleteFlag = 0;
				}
				text[i].erase(--j, 1);
				break;

			default:
				if (text[i][j - 1] == '/')
				{
					if (text[i][j] == '/')
						text[i].erase(j - 1, text[i].back());

					else if (text[i][j] == '*')
					{
						deleteFlag = 2;
						text[i].erase(--j, 1);
					}
				}
			}
	}

	return text;
}

std::vector<std::string> FormatText::DeleteSpaces(std::vector<std::string>& text)
{
	for (int i = 0; i < text.size(); i++)
	{
		while (text[i][0] == '\n' || text[i][0] == ' ' || text[i][0] == '\t' || text[i][0] == '\r')
			text[i].erase(0, 1);

		for (int j = 1; j < text[i].size(); j++)
		{
			while ((text[i][j - 1] == ' ') && text[i][j] == ' ')
				text[i].erase(--j, 1);
		}

		while (text[i].size() > 0 && (text[i].back() == '\n' || text[i].back() == ' ' || text[i].back() == '\t' || text[i].back() == '\r'))
			text[i].pop_back();

		if (text[i].size() == 0)
			text.erase(text.begin() + i--);
	}

	return text;
}

std::string FormatText::InOneString(std::vector<std::string>& lines)
{
	std::string wholeString;

	for (int i = 0; i < lines.size(); i++)
	{
		wholeString = wholeString + lines[i];
		wholeString.push_back('\n');
	}

	return wholeString;
}