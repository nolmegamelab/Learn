#include "../doctest.h"

#include <ctime>
#include <functional>
#include <numeric>
#include <random>
#include <vector>
#include <iostream>

TEST_CASE("algorithm")
{
	SUBCASE("accumulate")
	{
		std::vector vs{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

		auto v = std::accumulate(vs.begin(), vs.end(), 0);
		CHECK(v == 9 * 10 / 2);
	}

	SUBCASE("adjacent_difference")
	{
		std::vector<int> vs{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		std::vector<int> os(vs.size());
	
		auto iter = std::adjacent_difference(vs.begin(), vs.end(), os.begin());
		for (auto& v : os)
		{
			std::cout << v << ",";
		}
		std::cout << std::endl;
	}

	SUBCASE("binary search")
	{
		std::vector<int> vs;

		//random device�� �׻� ����� �� �ִ� �� �ƴϴ�. 
		std::mt19937 engine((unsigned int)time(nullptr)); 
		std::uniform_int_distribution<int> dist(0, 100000);

		// dist�� operator()�� ���� �Լ� ��ü�̰�, engine�� �ƱԸ�Ʈ�� ���� �� �ִ�. 
		auto generator = std::bind(dist, engine);

		// ������ ��忡�� ���� ������ ���� ���� �� �� ����. 

		for (int i = 0; i < 10000; i++)
		{
			auto v = generator();
			vs.push_back(v);
		}

		std::sort(vs.begin(), vs.end(), std::less());

		for (int i = 0; i < 10; ++i)
		{
			std::cout << vs[i] << " " ;
		}
		std::cout << std::endl;

		bool result = std::binary_search(vs.begin(), vs.end(), vs[5]);
		CHECK(result == true);
	}
}