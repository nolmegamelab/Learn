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

		//random device는 항상 사용할 수 있는 건 아니다. 
		std::mt19937 engine((unsigned int)time(nullptr)); 
		std::uniform_int_distribution<int> dist(0, 100000);

		// dist가 operator()를 갖는 함수 객체이고, engine을 아규먼트로 받을 수 있다. 
		auto generator = std::bind(dist, engine);

		// 릴리스 모드에서 벡터 내용을 거의 전혀 볼 수 없다. 

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