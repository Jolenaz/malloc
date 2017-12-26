/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 11:44:33 by jbelless          #+#    #+#             */
/*   Updated: 2017/12/26 11:44:36 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_book book = (t_book){{0}};

void* mallocL(size_t size)
{
	if(book.meta_data.page_size == 0)
	{
		book.meta_data.page_size = getpagesize();
		putstr("init size\n");
	}

	printf("page size = %zu\n",book.meta_data.page_size);

	size = 0;
    return (NULL);
}
