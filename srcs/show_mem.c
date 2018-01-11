#include "malloc.h"

void print_page(t_page *page)
{
	if (page == NULL)
		return;
	ft_putstr("|__",1);
	ft_putnbr_hex((unsigned long long)page,1);
	ft_putstr("__",1);
	ft_putnbr((unsigned long long)page,1);
	ft_putstr(" : \n",1);
	print_page(page->next);
}

void show_alloc_mem()
{
	if (g_book_h == NULL)
		return;
	if (g_book_h->tiny_page != NULL)
	{
		ft_putstr("Tiny book:\n",1);
		print_page(g_book_h->tiny_page);
	}
	if (g_book_h->small_page != NULL)
	{
		ft_putstr("Small book:\n",1);
		print_page(g_book_h->small_page);
	}
	if (g_book_h->large_page != NULL)
	{
		ft_putstr("Large book:\n",1);
		print_page(g_book_h->large_page);
	}
}