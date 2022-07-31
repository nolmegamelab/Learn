#include "../doctest.h"

#include <xmemory>
#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <concurrent_unordered_map.h>
#include <concurrent_unordered_set.h>

#include "HeapAllocator.h"

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

	SUBCASE("allocator")
	{
		std::list<int> lst; 

		lst.push_back(3);
	}
}

TEST_CASE("allocator")
{
	HeapAllocator::Instance().Create(512*1024*1024);

	SUBCASE("vector")
	{
		std::vector<int, StlHeapAllocator<int>> vec;

		vec.push_back(3);
	}

	SUBCASE("list")
	{
		std::list<int, StlHeapAllocator<int>> lst;

		lst.push_back(3);
	}

	SUBCASE("map")
	{
		std::map<int, int, std::less<int>, StlHeapAllocator<std::pair<const int, int>>> map;

		map.insert(std::pair(3, 3));
	}
}