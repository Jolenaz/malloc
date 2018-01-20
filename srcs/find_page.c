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

size_t	get_new_size(t_block *block)
{
	size_t	ret;
	t_block	*ptr;

	ret = 0;
	ptr = block;
	while (ptr)
	{
		if (ptr->is_free && (ptr->block_size > ret))
			ret = ptr->block_size;
		ptr = ptr->next;
	}
	return (ret);
}

void	*find_page(t_page *page, size_t size)
{
	void	*ret;
	if ( page->max_available_size >= size)
	{
		ret = find_block(page->first_block, size, page->type);
		page->max_available_size = get_new_size(page->first_block);
		ft_putstr("Page find : ", debug_flag);
		ft_putnbr_endl((unsigned long long)page, debug_flag);
		return (ret);
	}
	if (page->next == NULL)
		page->next = add_page(size, page->type);
	return (find_page(page->next, size));
}
