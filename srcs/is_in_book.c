/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_book.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 15:38:06 by jbelless          #+#    #+#             */
/*   Updated: 2018/01/20 15:38:10 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_page	*is_in_page(void *addr, t_page *page)
{
	if (page == NULL)
		return (NULL);
	if (addr >= (void *)page && addr <= (void *)((char*)page + page->page_size))
		return (page);
	return (is_in_page(addr, page->next));
}

t_page	*is_in_book(void *addr, t_book *book)
{
	t_page *ret;

	ret = NULL;
	if ((ret = is_in_page(addr, book->tiny_page)) != NULL)
		return (ret);
	if ((ret = is_in_page(addr, book->small_page)) != NULL)
		return (ret);
	return (is_in_page(addr, book->large_page));
}
