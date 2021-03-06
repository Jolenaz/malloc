/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_block.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 15:44:34 by jbelless          #+#    #+#             */
/*   Updated: 2018/01/20 15:44:36 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_block			*get_block(void *data, t_block *block)
{
	t_block *ptr;

	ptr = block;
	while (ptr)
	{
		if (ptr->data == data)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

void			create_realloc(t_block *block, size_t size, size_t dispo)
{
	t_block *tmp;

	tmp = block->next->next;
	block->next = (t_block*)((char*)(block->data) + size);
	block->next->is_free = 1;
	block->next->next = tmp;
	block->next->data = (void*)(block->next + 1);
	block->next->block_size = dispo - size - sizeof(t_block);
}

long long int	realloc_block(void *ptr, size_t i, t_page *page)
{
	t_block *block;
	size_t	dispo;

	if ((block = get_block(ptr, page->first_block)) == NULL)
		return (-1);
	if (block->block_size >= i)
		return (0);
	if (block->next && block->next->is_free)
	{
		dispo = block->block_size + block->next->block_size + sizeof(t_block);
		if (dispo >= i)
		{
			if (dispo > i + sizeof(t_block))
				create_realloc(block, i, dispo);
			else
				block->next = block->next->next;
			block->is_free = 0;
			block->block_size = i;
			return (0);
		}
	}
	return (block->block_size);
}
