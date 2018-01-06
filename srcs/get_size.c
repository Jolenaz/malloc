
#include "malloc.h"

void	*use_g_tiny(size_t size, t_book *book)
{
	if (book->tiny_first_page == NULL)
		book->tiny_first_page = add_page(TINY * PAGE_COEF * g_min_size, tiny);
	return (find_page(book->tiny_first_page, size));
}

void	*use_g_small(size_t size, t_book *book)
{
	if (book->small_first_page == NULL)
		book->small_first_page = add_page(SMALL * PAGE_COEF * g_min_size, small);
	return (find_page(book->small_first_page, size));
}

void	*use_g_large(size_t size, t_book *book)
{
	ft_putstr("large\n");
	if (book->large_first_page == NULL)
		book->large_first_page = add_page(size, large);
	ft_putstr("test succes\n");
	return (find_page(book->large_first_page, size));
}