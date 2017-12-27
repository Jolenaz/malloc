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

t_book	g_book = (t_book){0, NULL, NULL, NULL};

void	*use_g_tiny(size_t size)
{
	if (g_book.tiny_first_page == NULL)
		g_book.tiny_first_page = add_page(TINY * PAGE_COEF * g_book.min_size);
	return (find_page(g_book.tiny_first_page, size));
}

void	*use_g_small(size_t size)
{
	if (g_book.small_first_page == NULL)
		g_book.small_first_page = add_page(SMALL * PAGE_COEF * g_book.min_size);
	return (find_page(g_book.small_first_page, size));
}

void	*use_g_large(size_t size)
{
	if (g_book.large_first_page == NULL)
		g_book.large_first_page = add_page(size);
	return (find_page(g_book.large_first_page, size));
}

void	*malloc_l(size_t size)
{
	if (size == 0)
		return (NULL);
	if (g_book.min_size == 0)
		g_book.min_size = getpagesize();
	if (size <= TINY)
		return (use_g_tiny(size));
	else if (size <= SMALL)
		return (use_g_small(size));
	else
		return (use_g_large(size));
}
