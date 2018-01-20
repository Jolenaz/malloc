#include "malloc.h"

t_block	*get_block(void *data, t_block *block)
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

size_t	realloc_block(void *ptr, size_t i, t_page *page)
{
	t_block *block;
	size_t	dispo;

	block = get_block(ptr, page->first_block);
	if (block->block_size >= i)
		return (0);
	if (block->next && block->next->is_free)
	{
		dispo = block->block_size + block->next->block_size + sizeof(t_block);
		if (dispo >= i)
		{
			if (dispo > i + sizeof(t_block))
				block->next = create_block(block->next, i - block->block_size - sizeof(t_block));
			else
				block->next = block->next->next;
			block->is_free = 0;
			block->block_size = i;
			return (0);
		}
	}
	return (block->block_size);
}
