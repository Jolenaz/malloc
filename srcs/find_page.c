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

void	*find_page(t_book_page *page, size_t size)
{
	if (page->max_available_size >= size)
		return (find_block((char*)page->this + sizeof(t_book_page), size));
	if (page->next == NULL)
		page->next = add_page(page->page_syze);
	return (find_page(page->next, size));
}