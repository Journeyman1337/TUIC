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
/*! \file heap.h
 */
#ifndef TUIC_HEAP_H //header guard
#define TUIC_HEAP_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/types.h>
/*! @name Allocation Callbacks
 *
 * These callback types define functions that can be set to override all allocation, reallocation, and memory free operations used by TUIC.
 *
 *  @{ */
/*!
 * @brief Callback type used to define how memory is allocated.
 */
typedef void*(*tuiAllocateCallback) (size_t size);
/*!
 * @brief Callback type used to define how memory is reallocated.
 */
typedef void*(*tuiReallocateCallback) (void* to_realloc, size_t size);
/*!
 * @brief Callback type used to define how memory is freed.
 */
typedef void(*tuiFreeCallback) (void* to_free);
/*! @} */
/*! @name Allocation Callback Functions
 *
 * These functions are used to set or disable the statically global callback functions used by TUIC.
 *
 *  @{ */
/*!
 * @brief Set the allocate callback.
 *
 * @param callback The allocate callback. Set to NULL to resset to the default.
 */
void tuiSetAllocateCallback(tuiAllocateCallback callback);
/*!
 * @brief Set the reallocate callback.
 *
 * @param callback The reallocate callback. Set to NULL to resset to the default.
 */
void tuiSetReallocateCallback(tuiReallocateCallback callback);
/*!
 * @brief Set the free callback.
 *
 * @param callback The free callback. Set to NULL to resset to the default.
 */
void tuiSetFreeCallback(tuiFreeCallback callback);
/*! @} */
/*! @name Allocation Callback Functions
 *
 * These functions are used manage heap memory using the set callbacks or using malloc, realloc, and free from stdlib.h if none are set.
 *
 *  @{ */
/*!
 * @brief Allocate a block of heap memory, using the allocate callback if it is set.
 *
 * @param size The size of the block to allocate.
 *
 * @returns A pointer to the allocated memory.
 */
void* tuiAllocate(size_t size);
/*!
 * @brief Reallocate a block of heap memory, using the reallocate callback if it is set.
 *
 * @param to_realloc A pointer to the memory to reallocate.
 * @param size The new size of the memory.
 *
 * @returns A pointer to the reallocated memory.
 */
void* tuiReallocate(void* to_realloc, size_t size);
/*!
 * @brief Free a block of heap memory, using the free callback if it is set.
 *
 * @param to_realloc A pointer to the memory to free.
 */
void tuiFree(void* to_free);
/*! @} */
#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard
