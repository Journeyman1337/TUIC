#include <TUIC/allocation.h>

#include <stddef.h>
#include <stdlib.h

static tuiAllocateCallback sAllocateCallback = malloc;

static tuiReallocateCallback sReallocateCallback = realloc;

static tuiFreeCallback sFreeCallback = free;

void tuiSetAllocateCallback(tuiAllocateCallback allocate_callback)
{
	if (allocate_callback == NULL)
	{
		sAllocateCallback = malloc;
	}
	else
	{
		sAllocateCallback = allocate_callback;
	}
}

void tuiSetReallocateCallback(tuiReallocateCallback reallocate_callback)
{
	if (reallocate_callback == NULL)
	{
		sReallocateCallback = realloc;
	}
	else
	{
		sReallocateCallback = reallocate_callback;		
	}
}

void tuiSetFreeCallback(tuiFreeCallback free_callback)
{
	if (free_callback == NULL)
	{
		sFreeCallback = free;
	}
	else
	{
		sFreeCallback = free_callback;		
	}
}

void* tuiAllocate(size_t size)
{
	return sAllocateCallback(size);
}

void* tuiReallocate(void* ptr, size_t new_size)
{
	return sReallocateCallback(ptr, new_size);
}

void tuiFree(void* ptr)
{
	sFreeCallback(ptr);
}