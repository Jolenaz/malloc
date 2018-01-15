
#include  "malloc.h"

void			delete_page(t_book *book, t_page *page)
{
	t_page *ptr;
	ft_putstr("page to destroy : ", debug_flag);
	ft_putnbr_hex_endl((unsigned long long) page, debug_flag);

	ptr = book->large_page;
	if (book->large_page == page)
	{
		book->large_page = ptr->next;
		if (munmap(page, page->page_size) != 0)
			ft_putstr("delete probleme\n", debug_flag);
		return;
	}
	while(ptr->next)
	{
		if (ptr->next == page)
		{
			ptr->next = ptr->next->next;
			ft_putstr("new next : ", debug_flag);
			ft_putnbr_hex_endl((unsigned long long)ptr->next, debug_flag);
			munmap(ptr->next, page->page_size);
			return;
		}
		ptr = ptr->next;
	}
 }
