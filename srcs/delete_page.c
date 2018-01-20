/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_page.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 15:33:26 by jbelless          #+#    #+#             */
/*   Updated: 2018/01/20 15:33:30 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void			delete_page(t_book *book, t_page *page)
{
	t_page *ptr;

	ft_putstr("page to destroy : ", g_debug_flag);
	ft_putnbr_hex_endl((unsigned long long)page, g_debug_flag);
	ptr = book->large_page;
	if (ptr == page)
	{
		book->large_page = ptr->next;
		if (munmap(page, page->page_size) != 0)
			ft_putstr("delete probleme\n", g_debug_flag);
		return ;
	}
	while (ptr->next)
	{
		if (ptr->next == page)
		{
			ptr->next = ptr->next->next;
			ft_putstr("new next : ", g_debug_flag);
			ft_putnbr_hex_endl((unsigned long long)ptr->next, g_debug_flag);
			munmap(page, page->page_size);
			return ;
		}
		ptr = ptr->next;
	}
}
