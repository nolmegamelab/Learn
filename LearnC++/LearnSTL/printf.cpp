#include "../doctest.h"

#include <stdio.h>
#include <string>

TEST_CASE("printf")
{
	SUBCASE("invalid number of arguments")
	{
		printf("%d %s", 3);
	}

	SUBCASE("invalid string pointer")
	{
		// printf("%d %s", 3, (const char*)0x001a);
	}

	SUBCASE("find")
	{
		std::string s{ "ab cd ef g0" };

		auto p = s.find_first_of("cd");
	}
}