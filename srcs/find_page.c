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
	ft_putstr("test de merde________________\n");
	if (page->type == large)
	{
		ft_putstr("looking in :");
		ft_putnbr((unsigned long long)page);
		ft_putchar('\n');
	}
	ft_putstr("test de merde_____________2___\n");
	if (page->type != large && page->max_available_size >= size)
	{
		ret = find_block(page->first_block, size);
		page->max_available_size = get_new_size(page->first_block);
		return (ret);
	}
	if (page->next == NULL)
	{
		if (page->type == large)
		{
			page->next = add_page(size, page->type);
			ft_putstr("return page : ");
			ft_putnbr((unsigned long long)page->next);
			ft_putstr(", block : ");
			ft_putnbr((unsigned long long)page->next->first_block);
			ft_putchar('\n');
			return (page->next->first_block);
		}
		else
			page->next = add_page(page->page_size, page->type);
	}
	return (find_page(page->next, size));
}
