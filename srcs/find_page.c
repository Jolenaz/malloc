/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_page.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 15:36:48 by jbelless          #+#    #+#             */
/*   Updated: 2017/12/27 15:36:52 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

size_t	max(size_t a, size_t b)
{
	if (a > b)
		return (a);
	return (b);
}

size_t	get_new_size(t_block *block)
{
	size_t	ret;
	t_block	*next_block;

	ret = 0;
	if (is_free(block->state))
		ret = block->block_size;
	if (!is_last(block->state))
	{
		next_block = (t_block*)((char*)(block->data) + block->block_size);
		return (max(ret, get_new_size(next_block)));
	}
	return (ret);
}

void	*find_page(t_book_page *page, size_t size)
{
	void	*ret;

	if (page->max_available_size >= size)
	{
		ret = find_block(page->first_block, size);
		page->max_available_size = get_new_size(page->first_block);
		return (ret);
	}
	if (page->next == NULL)
		page->next = add_page(page->page_size);
	return (find_page(page->next, size));
}
