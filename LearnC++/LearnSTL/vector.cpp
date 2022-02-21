#include "../doctest.h"

#include <vector>
#include <iostream>

TEST_CASE("std::vector")
{
	SUBCASE("simple usage")
	{
		std::vector<int> vs; 

		for (int i = 0; i < 10; ++i)
		{
			vs.push_back(i);
		}

		std::vector<int>::iterator iter = vs.begin();
		int sum = 0;

		for (iter = vs.begin(); iter != vs.end(); ++iter)
		{
			sum += *iter;
		}

		std::cout << "sum: " << sum << std::endl;
		CHECK(sum == 9 * 10 / 2);
	}
}