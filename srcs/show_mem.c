/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 15:46:57 by jbelless          #+#    #+#             */
/*   Updated: 2018/01/20 15:47:00 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	print_block(t_block *block)
{
	if (block == NULL)
		return ;
	ft_putstr("|  |__ Block :", 1);
	ft_putnbr_hex((unsigned long long)block, 1);
	ft_putstr(", is free :", 1);
	if (block->is_free)
		ft_putstr("True, block size :", 1);
	else
		ft_putstr("False, block size :", 1);
	ft_putnbr(block->block_size, 1);
	ft_putstr(", data addr :", 1);
	ft_putnbr_hex_endl((unsigned long long)block->data, 1);
	print_block(block->next);
	return ;
}

void	print_page(t_page *page)
{
	if (page == NULL)
		return ;
	ft_putstr("|__ Page :", 1);
	ft_putnbr_hex((unsigned long long)page, 1);
	ft_putstr(", size :", 1);
	ft_putnbr((unsigned long long)page->page_size, 1);
	ft_putstr(", free size :", 1);
	ft_putnbr_endl((unsigned long long)page->max_free_size, 1);
	print_block(page->first_block);
	print_page(page->next);
}

void	show_all_mem(void)
{
	static pthread_mutex_t	mutex;

	mutex = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	pthread_mutex_lock(&mutex);
	if (g_book_h == NULL)
	{
		pthread_mutex_unlock(&mutex);
		return ;
	}
	if (g_book_h->tiny_page != NULL)
	{
		ft_putstr("Tiny book:\n", 1);
		print_page(g_book_h->tiny_page);
	}
	if (g_book_h->small_page != NULL)
	{
		ft_putstr("Small book:\n", 1);
		print_page(g_book_h->small_page);
	}
	if (g_book_h->large_page != NULL)
	{
		ft_putstr("Large book:\n", 1);
		print_page(g_book_h->large_page);
	}
	pthread_mutex_unlock(&mutex);
}

void	print_mem(void *data)
{
	t_page					*page;
	static pthread_mutex_t	mutex;
	t_block					*block;

	mutex = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	pthread_mutex_lock(&mutex);
	if ((page = is_in_book(data, g_book_h)) == NULL
			|| (block = get_block(data, page->first_block)) == NULL)
	{
		ft_putstr("addr was not allocated\n", 1);
		pthread_mutex_unlock(&mutex);
		return ;
	}
	if (block->block_size >= 0xffffffff)
	{
		ft_putstr("to mutch data to print\n", 1);
		pthread_mutex_unlock(&mutex);
		return ;
	}
	print_mem_hex(data, block->block_size);
}
