/*
	Copyright (c) 2021 Daniel Valcour
	
	Permission is hereby granted, free of charge, to any person obtaining a copy of
	this software and associated documentation files (the "Software"), to deal in
	the Software without restriction, including without limitation the rights to
	use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
	the Software, and to permit persons to whom the Software is furnished to do so,
	subject to the following conditions:
	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.
	
	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
	FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
	COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
	IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
	CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include <TUIC/tuic.h>

#include <stdlib.h>

void* default_allocate(size_t size)
{
	void* ptr = malloc(size);
	memset(ptr, 0, size);
	return ptr;
}

void* default_reallocate(void* to_realloc, size_t size)
{
	void* ptr = realloc(to_realloc, size);
	memset(ptr, 0, size);
	return ptr;
}

void default_free(void* data)
{
	free(data);
}

static tuiAllocateCallback sAllocateCallback = default_allocate;

static tuiReallocateCallback sReallocateCallback = default_reallocate;

static tuiFreeCallback sFreeCallback = default_free;


void tuiSetAllocateCallback(tuiAllocateCallback callback)
{
	if (callback == NULL)
	{
		sAllocateCallback = default_allocate;
	}
	else
	{
		sAllocateCallback = callback;
	}
}

void tuiSetReallocateCallback(tuiReallocateCallback callback)
{
	if (callback == NULL)
	{
		sReallocateCallback = default_reallocate;
	}
	else
	{
		sReallocateCallback = callback;
	}
}

void tuiSetFreeCallback(tuiFreeCallback callback)
{
	if (callback == NULL)
	{
		sFreeCallback = default_free;
	}
	else
	{
		sFreeCallback = callback;
	}
}

void* tuiAllocate(size_t size)
{
	return sAllocateCallback(size);
}

void* tuiReallocate(void* to_realloc, size_t size)
{
	return sReallocateCallback(to_realloc, size);
}

void tuiFree(void* to_free)
{
	sFreeCallback(to_free);
}
