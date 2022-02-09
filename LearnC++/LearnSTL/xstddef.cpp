#include "../doctest.h"
#include <xstddef>
#include <iostream>

TEST_CASE("xstddef")
{
	SUBCASE("plus")
	{
		int v1 = 1; 
		int v2 = 2; 

		// std::plus�� �⺻ Ÿ���� void ������ ������ Ÿ�ٿ� �⺻ Ÿ���� �����ϱ� ���� 
		// �뵵�̰� ���� ����� �Ұ����� ���� Ȱ���Ѵ�. 
		auto rv = std::plus<int>()(v1, v2);
		CHECK(rv == 3);
	}

	SUBCASE("plus 2")
	{
		int v1 = 1; 
		int v2 = 2; 

		// �⺻ Ÿ���� void�� ����� Ư��ȭ�� Ÿ���� operator()���� �߷��Ͽ� ����Ѵ�. 
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