#include "HeapAllocator.h"
#include <cassert>

HeapAllocator& HeapAllocator::Instance()
{
	static HeapAllocator instance;
	return instance;
}

HeapAllocator::HeapAllocator()
	: m_heapHandle(INVALID_HANDLE_VALUE)
{
}

HeapAllocator::~HeapAllocator()
{
	if (m_heapHandle != INVALID_HANDLE_VALUE)
	{
		Destroy();
	}
}

bool HeapAllocator::Create(size_t initialSize, size_t maxSize)
{
	m_heapHandle = ::HeapCreate(0, initialSize, maxSize);
	return true;
}

void HeapAllocator::Destroy()
{
	::HeapDestroy(m_heapHandle);
	m_heapHandle = INVALID_HANDLE_VALUE;
}

void* HeapAllocator::Alloc(size_t size)
{
	return ::HeapAlloc(m_heapHandle, HEAP_ZERO_MEMORY, size);
}

void HeapAllocator::Free(void* p)
{
	::HeapFree(m_heapHandle, HEAP_ZERO_MEMORY, p);
}
