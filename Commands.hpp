#pragma once
#ifndef _COMMANDS_HPP_
#define _COMMANDS_HPP_

#include <string>
#include <algorithm>

enum class COMMANDS
{
	HELP = 0,
	ADD,
	SUBTRACT,
	RENAME,
	PAINT,
	SEARCH,
	LIST,
	HIDE,
	RESTORE
};

COMMANDS CommandForString(std::string str)
{
	std::string u{*std::transform(str.begin(), str.end(), str.begin(), std::toupper)};
	COMMANDS result = COMMANDS::HELP;
	if (u == "ADD")
	{
		result = COMMANDS::ADD;
	}
	else if (u == "SUBTRACT")
	{
		result = COMMANDS::SUBTRACT;
	}
	else if (u == "RENAME")
	{
		result = COMMANDS::RENAME;
	}
	else if (u == "PAINT")
	{
		result = COMMANDS::PAINT;
	}
	else if (u == "SEARCH")
	{
		result = COMMANDS::SEARCH;
	}
	else if (u == "LIST")
	{
		result = COMMANDS::LIST;
	}
	else if (u == "HIDE")
	{
		result = COMMANDS::HIDE;
	}
	else if (u == "RESTORE")
	{
		result = COMMANDS::RESTORE;
	}
	return result;
}

#endif
