/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 11:44:33 by jbelless          #+#    #+#             */
/*   Updated: 2017/12/26 11:44:36 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_book	g_book = (t_book){NULL, NULL, NULL};
t_book	*g_book_h = &g_book;

void	*malloc(size_t size)
{
	static pthread_mutex_t	mutex;
	void					*ret;

	mutex = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	pthread_mutex_lock(&mutex);
	g_min_size = getpagesize();
	ft_putstr("malloc for :", g_debug_flag);
	ft_putnbr_endl(size, g_debug_flag);
	if (size == 0)
		ret = NULL;
	if (size <= TINY * g_min_size)
		ret = use_g_tiny(size, &g_book);
	else if (size <= SMALL * g_min_size)
		ret = use_g_small(size, &g_book);
	else
		ret = use_g_large(size, &g_book);
	pthread_mutex_unlock(&mutex);
	return (ret);
}

void	free(void *data)
{
	t_page					*page;
	static pthread_mutex_t	mutex;

	mutex = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	pthread_mutex_lock(&mutex);
	ft_putstr("free for :", g_debug_flag);
	ft_putnbr_hex_endl((unsigned long long)data, g_debug_flag);
	page = is_in_book(data, &g_book);
	if (data == NULL || page == NULL)
	{
		pthread_mutex_unlock(&mutex);
		return ;
	}
	else if (page->type != large)
		free_block(page, data);
	else
		delete_page(&g_book, page);
	pthread_mutex_unlock(&mutex);
}

void	*return_unlock(void *ret, pthread_mutex_t *mutex)
{
	pthread_mutex_unlock(mutex);
	return (ret);
}

void	*realloc(void *ptr, size_t i)
{
	t_page					*page;
	void					*ret;
	size_t					mem_to_copy;
	static pthread_mutex_t	mutex;

	mutex = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	pthread_mutex_lock(&mutex);
	ft_putstr("realloc for :", g_debug_flag);
	ft_putnbr_hex((unsigned long long)ptr, g_debug_flag);
	ft_putstr(" , ", g_debug_flag);
	ft_putnbr_endl(i, g_debug_flag);
	if (i == 0)
	{
		free(ptr);
		return (return_unlock(malloc(1), &mutex));
	}
	if (ptr == NULL || (page = is_in_book(ptr, &g_book)) == NULL)
		return (return_unlock(malloc(i), &mutex));
	mem_to_copy = realloc_block(ptr, i, page);
	if (mem_to_copy == 0)
		return (return_unlock(ptr, &mutex));
	ret = malloc(i);
	ft_memcpy(ret, ptr, mem_to_copy);
	free(ptr);
	return (return_unlock(ret, &mutex));
}
