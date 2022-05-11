#include "../doctest.h"

#include <stdio.h>

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
}