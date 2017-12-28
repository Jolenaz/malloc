/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_block.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:04:28 by jbelless          #+#    #+#             */
/*   Updated: 2017/12/27 16:04:31 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	create_block(t_block *new, t_block *old, size_t old_size)
{
	new->block_size = old->block_size - old_size - sizeof(t_block);
	new->state = old->state;
	new->data = (void*)(new + 1);
	return ;
}

void	*find_block(t_block *block, size_t size)
{
	t_block *next_block;

	if (block->block_size >= size && is_free(block->state))
	{
		if (block->block_size > size)
		{
			create_block((t_block*)((char*)block->data + size), block, size);
			if (is_last(block->state))
				block->state = block->state ^ IS_LAST;
			block->block_size = size;
		}
		block->state = block->state ^ IS_FREE;
		return (block->data);
	}
	if (is_last(block->state))
		return (NULL);
	next_block = (t_block*)((char*)(block->data) + block->block_size);
	return (find_block(next_block, size));
}
