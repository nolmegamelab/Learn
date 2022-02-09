#include "../doctest.h"
#include <type_traits>

namespace {
	template <bool _First_value, class _First, class... _Rest>
	struct _Conjunction { // handle false trait or last trait
		using type = _First;

		// �Ʒ� assertó�� _First_value�� ���� ���� Rest�� ��� ���� ��� ��Ī�ȴ�. 
		static_assert(_First_value == true || _First_value == false);
		static_assert(sizeof...(_Rest) == 0);
	};

	template <class _True, class _Next, class... _Rest>
	struct _Conjunction<true, _True, _Next, _Rest...> { // the first trait is true, try the next one
		// ���⼭ recursion���� _Rest�� ��� ���� ������ ����� �Ŀ� type�� �����ȴ�. 
		using type = typename _Conjunction<_Next::value, _Next, _Rest...>::type;
	};

	template <class... _Traits>
	struct conjunction : std::true_type {}; // If _Traits is empty, true_type

	// variadic template�� recursion�� ��� �ؼҵ� ���� type�� �����ȴ�. 
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

	// Ÿ�� ���� ��Ī�� recursion�� �˸� ��ü�� ������ �� �ִ�. 
	// variadic template�� �Ķ���͵��� ������ 0�� ���� ��Ī�� �� �ִ�. 
	// __�� �����ϴ� �Լ��� �� ������ �����Ϸ� ���ο� �����Ǿ� �ִ�. 
	//  
}