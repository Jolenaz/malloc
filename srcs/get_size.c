
#include "malloc.h"

void	*use_g_tiny(size_t size, t_book *book)
{
	ft_putstr("Tiny ask : ");
	ft_putnbrendl(size);
	if (book->tiny_first_page == NULL)
		book->tiny_first_page = add_page(TINY * PAGE_COEF * g_min_size, tiny);
	return (find_page(book->tiny_first_page, size));
}

void	*use_g_small(size_t size, t_book *book)
{
	ft_putstr("Small ask : ");
	ft_putnbrendl(size);
	if (book->small_first_page == NULL)
		book->small_first_page = add_page(SMALL * PAGE_COEF * g_min_size, small);
	return (find_page(book->small_first_page, size));
}

void	*use_g_large(size_t size, t_book *book)
{
	ft_putstr("Large ask : ");
	ft_putnbrendl(size);
	if (book->large_first_page == NULL)
		book->large_first_page = add_page(size, large);
	return (find_page(book->large_first_page, size));
}