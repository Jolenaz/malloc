#include "malloc.h"

void print_block(t_block *block)
{
	if (block == NULL)
		return;
	ft_putstr("|  |__ Block :",1);
	ft_putnbr_hex((unsigned long long)block,1);
	ft_putstr(", is free :",1);
	if (block->is_free)
		ft_putstr("True, block size :",1);
	else
		ft_putstr("False, block size :",1);
	ft_putnbr(block->block_size,1);
	ft_putstr(", data addr :",1);
	ft_putnbr_hex_endl((unsigned long long)block->data,1);
	print_block(block->next);
	return;
}

void print_page(t_page *page)
{
	if (page == NULL)
		return;
	ft_putstr("|__ Page :",1);
	ft_putnbr_hex((unsigned long long)page,1);
	ft_putstr(", size :",1);
	ft_putnbr((unsigned long long)page->page_size,1);
	ft_putstr(", free size :",1);
	ft_putnbr_endl((unsigned long long)page->max_available_size,1);
	print_block(page->first_block);
	print_page(page->next);
}

void show_all_mem()
{
	if (g_book_h == NULL)
		return;
	if (g_book_h->tiny_page != NULL)
	{
		ft_putstr("Tiny book:\n",1);
		print_page(g_book_h->tiny_page);
		ft_putstr("___________________________________________________\n",1);
		ft_putstr("___________________________________________________\n",1);
	}
	if (g_book_h->small_page != NULL)
	{
		ft_putstr("Small book:\n",1);
		print_page(g_book_h->small_page);
		ft_putstr("___________________________________________________\n",1);
		ft_putstr("___________________________________________________\n",1);
	}
	if (g_book_h->large_page != NULL)
	{
		ft_putstr("Large book:\n",1);
		print_page(g_book_h->large_page);
		ft_putstr("___________________________________________________\n",1);
		ft_putstr("___________________________________________________\n",1);
	}
}