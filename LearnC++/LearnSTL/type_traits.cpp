#include "../doctest.h"
#include <type_traits>

namespace {
	template <bool _First_value, class _First, class... _Rest>
	struct _Conjunction { // handle false trait or last trait
		using type = _First;

		// 아래 assert처럼 _First_value는 관계 없이 Rest가 비어 있을 경우 매칭된다. 
		static_assert(_First_value == true || _First_value == false);
		static_assert(sizeof...(_Rest) == 0);
	};

	template <class _True, class _Next, class... _Rest>
	struct _Conjunction<true, _True, _Next, _Rest...> { // the first trait is true, try the next one
		// 여기서 recursion으로 _Rest가 모두 사용될 때까지 진행된 후에 type이 결정된다. 
		using type = typename _Conjunction<_Next::value, _Next, _Rest...>::type;
	};

	template <class... _Traits>
	struct conjunction : std::true_type {}; // If _Traits is empty, true_type

	// variadic template의 recursion이 모두 해소된 후의 type이 결정된다. 
	template <class _First, class... _Rest>
	struct conjunction<_First, _Rest...> : _Conjunction<_First::value, _First, _Rest...>::type {
		// the first false trait in _Traits, or the last trait if none are false
	};

	template <class... _Traits>
	_INLINE_VAR constexpr bool conjunction_v = conjunction<_Traits...>::value;
}

TEST_CASE("type_traits")
{
	SUBCASE("sequence")
	{
		std::make_index_sequence<3> seq;
		CHECK(seq.size()==3);


	}

	SUBCASE("conjunction")
	{
		bool rv = std::conjunction_v<std::true_type, std::false_type>;
		CHECK(rv == false);

		bool rv2 = std::conjunction_v<std::true_type, std::true_type>;
		CHECK(rv2 == true);

		bool rv3 = std::conjunction<std::true_type>::value;
		CHECK(rv3 == true);
	}

	SUBCASE("conjuction debugging")
	{
		bool rv3 = conjunction<std::false_type>::value;
		CHECK(rv3 == false);
	}

	// 타잎 패턴 매칭과 recursion을 알면 대체로 이해할 수 있다. 
	// variadic template의 파라미터들은 개수가 0일 때도 매칭할 수 있다. 
	// __로 시작하는 함수들 중 상당수가 컴파일러 내부에 구현되어 있다. 
	//  
}