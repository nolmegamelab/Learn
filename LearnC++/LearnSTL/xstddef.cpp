#include "../doctest.h"
#include <xstddef>
#include <iostream>

TEST_CASE("xstddef")
{
	SUBCASE("plus")
	{
		int v1 = 1; 
		int v2 = 2; 

		// std::plus의 기본 타잎이 void 이지만 컴파일 타잎에 기본 타잎을 지정하기 위한 
		// 용도이고 실제 사용이 불가능한 점을 활용한다. 
		auto rv = std::plus<int>()(v1, v2);
		CHECK(rv == 3);
	}

	SUBCASE("plus 2")
	{
		int v1 = 1; 
		int v2 = 2; 

		// 기본 타잎이 void인 경우의 특수화로 타잎을 operator()에서 추론하여 사용한다. 
		auto rv = std::plus<void>()(v1, v2);
		CHECK(rv == 3);
	}

	SUBCASE("addressof")
	{
		int v1 = 0;
		int v2 = 0;

		std::cout << std::addressof(v1) << std::endl;
		std::cout << std::addressof(v2) << std::endl;
	}
}