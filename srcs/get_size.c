
#include "malloc.h"

void	*use_g_tiny(size_t size, t_book * book)
{
	if (book->tiny_first_page == NULL)
		book->tiny_first_page = add_page(TINY * PAGE_COEF * g_min_size);
	return (find_page(book->tiny_first_page, size));
}

void	*use_g_small(size_t size, t_book * book)
{
	if (book->small_first_page == NULL)
		book->small_first_page = add_page(SMALL * PAGE_COEF * g_min_size);
	return (find_page(book->small_first_page, size));
}

void	*use_g_large(size_t size, t_book * book)
{
	if (book->large_first_page == NULL)
	{
		size_t new_size = ((size / g_min_size) + 1) * g_min_size;
		book->large_first_page = add_page(new_size);
	}
	return (find_page(book->large_first_page, size));
}