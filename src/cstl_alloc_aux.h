/*
 *  Memory management auxiliary interface. 
 *  Copyright (C)  2008,2009,2010  Wangbo
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 *  Author e-mail: activesys.wb@gmail.com
 *                 activesys@sina.com.cn
 */

#ifndef _CSTL_ALLOC_AUX_H
#define _CSTL_ALLOC_AUX_H

#ifdef __cplusplus
extern "C" {
#endif

/** include section **/

/** constant declaration and macro section **/

/** data type declaration and struct, union, enum section **/

/** exported global variable declaration section **/
extern void (*_g_pfun_default_malloc_handler)(void);

/** exported function prototype section **/
/**
 * Malloc for out of memory condition.
 * @param t_memset memory size.
 * @return point to the allocated memory.
 */
extern void* _alloc_malloc_out_of_memory(size_t t_memsize);

/**
 * Malloc memory.
 * @param t_memsize memory size.
 * @return point to the allocated memory.
 */
extern void* _alloc_malloc(size_t t_memsize);

/**
 * Free memory.
 * @param pv_allocmem memory.
 * @return void.
 * @remarks if pv_allocmem == NULL, then the function of behavior is undefined.
 */
extern void _alloc_free(void* pv_allocmem);

/**
 * Apply a formated memory list.
 * @param pt_allocater pointer that point to allocater.
 * @param t_allocsize  the size of allocated memory.
 * @return void.
 * @remarks if pt_allocater == NULL then the function of behavior is undefined.
 */
extern void _alloc_apply_formated_memory(alloc_t* pt_allocater, size_t t_allocsize);

/**
 * Get memory chunk from memory pool.
 * @param pt_allocater  pointer pointes to allocater.
 * @param t_allocsize   the size of allocated memory chunk.
 * @param pn_alloccount the number of allocated memory chunk.
 * @return pointer pointes to allocated chunk.
 * @remarks if pt_allocater == NULL or pn_alloccount == NULL, then the function of behavior is undefined.
 *          if the total size of allocated memory chunk is less than the size of memory pool, then allocated
 *          memory chunk from memory pool directly. if the size of memory pool is less than total size of
 *          allocated memory chunk, but greater than or equal to the size of only one memory chunk, than
 *          allocated appropriate number of memory chunk, then update the allocate count. otherwise allocated
 *          larger memory pool from allocated memory chunk.
 */
extern char* _alloc_get_memory_chunk(alloc_t* pt_allocater, size_t t_allocsize, size_t* pt_alloccount);

#ifdef __cplusplus
}
#endif

#endif /* _CSTL_ALLOC_AUX_H */
/** eof **/

