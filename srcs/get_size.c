
#include "malloc.h"

void	*use_g_tiny(size_t size, t_book *book)
{
	ft_putstr("Tiny ask : ", debug_flag);
	ft_putnbr_endl(size, debug_flag);
	if (book->tiny_page == NULL)
		book->tiny_page = add_page(TINY * PAGE_COEF * g_min_size, tiny);
	return (find_page(book->tiny_page, size));
}

void	*use_g_small(size_t size, t_book *book)
{
	ft_putstr("Small ask : ", debug_flag);
	ft_putnbr_endl(size, debug_flag);
	if (book->small_page == NULL)
		book->small_page = add_page(SMALL * PAGE_COEF * g_min_size, small);
	return (find_page(book->small_page, size));
}

void	*use_g_large(size_t size, t_book *book)
{
	ft_putstr("Large ask : ", debug_flag);
	ft_putnbr_endl(size, debug_flag);
	if (book->large_page == NULL)
		book->large_page = add_page(size, large);
	return (find_page(book->large_page, size));
}