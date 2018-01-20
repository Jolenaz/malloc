/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_block.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 15:35:49 by jbelless          #+#    #+#             */
/*   Updated: 2018/01/20 15:35:52 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	defragment(t_block *block)
{
	t_block *ptr;

	ptr = block;
	while (ptr->next)
	{
		if (ptr->is_free && ptr->next->is_free)
		{
			ptr->block_size += ptr->next->block_size + sizeof(t_block);
			ptr->next = ptr->next->next;
			return ;
		}
		ptr = ptr->next;
	}
}

char	update_block(t_block *block, void *data)
{
	t_block	*ptr;
	char	prev_free;

	ptr = block;
	prev_free = 0;
	while (ptr)
	{
		if (ptr->data == data)
		{
			ptr->is_free = 1;
			if (ptr->next && ptr->next->is_free)
				defragment(ptr);
			if (prev_free)
				return (1);
			return (0);
		}
		prev_free = ptr->is_free;
		ptr = ptr->next;
	}
	return (0);
}

void	free_block(t_page *page, void *data)
{
	if (update_block(page->first_block, data))
	{
		if (page->type != large)
			defragment(page->first_block);
	}
}
