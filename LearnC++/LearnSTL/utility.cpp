#include "../doctest.h"

#include <utility>
#include <algorithm>

namespace {
	template
		<class _Ty, std::enable_if_t<std::_Is_swappable<_Ty>::value, int> _Enabled>
		void swap(_Ty& v)
	{

	}
}

TEST_CASE("utility")
{
	SUBCASE("swap")
	{
		// ��ȯ ������ ���� �������� �ȴ�. enable_if_t���� ������ ������ ���� ���� �ƴϴ�. 
		decltype(std::swap(_STD declval<doctest::Approx&>(), _STD declval<doctest::Approx&>()));
	}

	SUBCASE("enable_if")
	{
		int v;
		swap<int, 0>(v);
	}

	SUBCASE("pair")
	{
		// �����ڿ��� enable_if_t�� ����Ͽ� �Լ� ���� ���θ� �����ϰ� 
		// explicit�� �Ϲ����� ��ȯ�� ����ϴ� ������ �����Ͽ� ���� ������ �ڵ带 �����Ѵ�. 

		std::pair p(3, 5);
	}

	// annotated_utility.hpp�� �� �о���. 
	// 
}