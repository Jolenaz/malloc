/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_page.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 15:27:51 by jbelless          #+#    #+#             */
/*   Updated: 2017/12/27 15:27:56 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		init_block(t_block *block, size_t size )
{
	block->block_size = size;
	block->is_free = 1;
	block->data = (void*)(block + 1);
	block->next = NULL;
}

void		init_page(t_page *page, size_t size, t_type type)
{
	page->page_size = size;
	page->type = type;
	page->next = NULL;
	page->max_available_size = page->page_size - sizeof(t_block) - sizeof(t_page);
	page->first_block = (t_block*)(page + 1);
	init_block( page->first_block, page->max_available_size);
}

t_page	*add_page(size_t size, t_type type)
{
	t_page	*page;

	if (type == tiny || type == small)
		size += 100 * sizeof(t_block) + sizeof(t_page);
	else
		size += sizeof(t_page) + sizeof(t_block);
	size = (size / g_min_size  + 1) * g_min_size ;
	page = (t_page	*)mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (page == MAP_FAILED)
		return (NULL);
	init_page(page, size, type);
	ft_putstr("Create New page : ", debug_flag);
	ft_putnbr_endl((unsigned long long)page, debug_flag);
	return (page);
}
