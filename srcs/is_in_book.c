
#include "malloc.h"

char	is_in_page(void *addr, t_book_page *page)
{
	if (page == NULL)
		return (0);
	if (addr >= (void *)page && addr <= (void *)((char*)page + page->page_size))
		return (1);
	if (page->next != NULL)
		return(is_in_page(addr, page->next));
	return (0);
}

char	is_in_book(void *addr, t_book *book)
{
	if (is_in_page(addr, book->tiny_first_page))
		return (1);
	if (is_in_page(addr, book->small_first_page))
		return (1);
	if (is_in_page(addr, book->large_first_page))
		return (1);
	return (0);
}