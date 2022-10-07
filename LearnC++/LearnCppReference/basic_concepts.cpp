#include "../doctest.h"

#include <iostream>
#include <limits>

/// basic concept unit tests to understand c++ with cppreference.com
TEST_CASE("basic concept")
{
	SUBCASE("ascii chart")
	{
		SUBCASE("print printable characters")
		{
			std::cout << "Printable ASCII [32..126]:\n";

			for (char c{ ' ' }; c <= '~'; c++) 
			{
				std::cout << c << ((c + 1) % 32 ? ' ' : '\n');
			}
		}
	}

	SUBCASE("punctuation")
	{
		// puntuation은 사용하는 문맥에서 다시 보도록 한다. 매우 광범위하다. 
	}

	SUBCASE("fundamental types")
	{
		// x64를 기준으로 테스트 작성한다. 
		SUBCASE("sizeof")
		{
			CHECK(sizeof(int) == 4);
			CHECK(sizeof(long) == 4);
			CHECK(sizeof(long long) == 8);
			CHECK(sizeof(float) == 4);
			CHECK(sizeof(double) == 8);
			// void는 sizeof가 정의되지 않는다. 
			// CHECK(sizeof(void) == 0);

		}

		SUBCASE("numeric_limits")
		{
			using lim_int = std::numeric_limits<int>;
			CHECK(lim_int::has_infinity == false);
		}
	}

	SUBCASE("object")
	{
		SUBCASE("typeid")
		{
			struct Base1
			{
				// polymorphic type: declares a virtual member
				virtual ~Base1() {}
			};

			struct Derived1 : Base1
			{
				// polymorphic type: inherits a virtual member
			};

			struct Base2
			{
				// non-polymorphic type
			};

			struct Derived2 : Base2
			{
				// non-polymorphic type
			};

			Derived1 obj1; // object1 created with type Derived1
			Derived2 obj2; // object2 created with type Derived2

			Base1& b1 = obj1; // b1 refers to the object obj1
			Base2& b2 = obj2; // b2 refers to the object obj2

			std::cout << "Expression type of b1: " << typeid(decltype(b1)).name() << '\n'
				<< "Expression type of b2: " << typeid(decltype(b2)).name() << '\n'
				<< "Object type of b1: " << typeid(b1).name() << '\n'
				<< "Object type of b2: " << typeid(b2).name() << '\n'
				<< "Size of b1: " << sizeof b1 << '\n'
				<< "Size of b2: " << sizeof b2 << '\n';
		}
	}
}