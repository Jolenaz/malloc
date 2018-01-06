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

void	*malloc(size_t size)
{
	g_min_size = getpagesize();
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

	page = is_in_book(data, &g_book);
	if (data == NULL || page == NULL)
		return;
	else
	{
		free_block(page, data);
		// if(page->type == large)
		// 	delete_page(&g_book, page);
	}
}

void	*realloc(void *ptr, size_t i)
{
	t_page	*page;
	void		*ret;
	size_t		mem_to_copy;

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
