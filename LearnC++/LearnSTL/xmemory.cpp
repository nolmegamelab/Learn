#include "../doctest.h"

#include <xmemory>
#include <iostream>

namespace {
	struct X {
		bool destructor_called_ = false; 

		~X() {
			destructor_called_ = true;
			std::cout << "destructor called" << std::endl;
		}
	};
}

TEST_CASE("xmemory")
{
	SUBCASE("exception and destructor")
	{
		try
		{
			X x;
			throw std::exception("manual");
		}
		catch (std::exception& ex)
		{
			ex;
		}
	}
}