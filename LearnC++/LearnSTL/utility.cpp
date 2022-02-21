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
		// 교환 가능할 때만 컴파일이 된다. enable_if_t에서 컴파일 에러가 없는 것은 아니다. 
		decltype(std::swap(_STD declval<doctest::Approx&>(), _STD declval<doctest::Approx&>()));
	}

	SUBCASE("enable_if")
	{
		int v;
		swap<int, 0>(v);
	}

	SUBCASE("pair")
	{
		// 생성자에서 enable_if_t를 사용하여 함수 생성 여부를 결정하고 
		// explicit로 암묵적인 변환을 허용하는 범위를 결정하여 보다 안전한 코드를 생성한다. 

		std::pair p(3, 5);
	}

	// annotated_utility.hpp를 다 읽었다. 
	// 
}