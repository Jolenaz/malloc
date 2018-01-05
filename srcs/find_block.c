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

t_block	*create_block(t_block *old, size_t size)
{
	t_block *new;

	new = (t_block*)((char*)old->data + size);
	new->block_size = old->block_size - size - sizeof(t_block);
	new->is_free = 1;
	new->next = old->next;
	new->data = (void*)(new + 1);
	return (new);
}

void	*find_block(t_block *block, size_t size)
{
	if (block->block_size >= size && block->is_free)
	{
		if (block->block_size > size + sizeof(t_block))
		{
			block->next = create_block(block, size);
			block->block_size = size;
		}
		block->is_free = 0;
		return (block->data);
	}
	if (block->next == NULL)
		return (NULL);
	return (find_block(block->next, size));
}
