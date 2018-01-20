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
	g_min_size = getpagesize();
	ft_putstr("malloc for :",debug_flag);
	ft_putnbr_endl(size,debug_flag);
	if (size == 0)
		return (NULL);
	if (size <= TINY * g_min_size)
		return (use_g_tiny(size, &g_book));
	else if (size <= SMALL * g_min_size)
		return (use_g_small(size, &g_book));
	else
		return (use_g_large(size, &g_book));
}

void free(void *data){
	t_page	*page;

	ft_putstr("free for :",debug_flag);
	ft_putnbr_hex_endl((unsigned long long)data,debug_flag);
	page = is_in_book(data, &g_book);
	if (data == NULL || page == NULL)
		return;
	else if (page->type != large)
		free_block(page, data);
	else
		delete_page(&g_book, page);
}

void	*realloc(void *ptr, size_t i)
{
	t_page		*page;
	void		*ret;
	size_t		mem_to_copy;

	ft_putstr("realloc for :",debug_flag);
	ft_putnbr_hex((unsigned long long)ptr,debug_flag);
	ft_putstr(" , ",debug_flag);
	ft_putnbr_endl(i,debug_flag);
	if (i == 0)
	{
		free(ptr);
		return (malloc(1));
	}
	page = is_in_book(ptr, &g_book);
	if (ptr == NULL || page == NULL)
		return (malloc(i));
	mem_to_copy  = realloc_block(ptr, i, page);
	if (mem_to_copy == 0)
	 	return (ptr);
	ret = malloc(i);
	ft_memcpy(ret, ptr, mem_to_copy);
	free(ptr);
    return (ret);
}
