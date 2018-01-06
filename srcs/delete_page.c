
#include  "malloc.h"

void			delete_page(t_book *book, t_page *page)
{
	t_page *ptr;
	ft_putstr("page to destroy : ");
	ft_putnbr((unsigned long long) page);
	ft_putchar('\n');

	ptr = book->large_first_page;
	if (book->large_first_page == page)
	{
		book->large_first_page = ptr->next;
		if (munmap(page, page->page_size + sizeof(t_page)) != 0)
			ft_putstr("delete probleme\n");
		return;
	}
	while(ptr->next)
	{
		if (ptr->next == page)
		{
			ptr->next = ptr->next->next;
			ft_putstr("new next : ");
			ft_putnbr((unsigned long long)ptr->next);
			ft_putchar('\n');
			munmap(ptr->next, page->page_size + sizeof(t_page));
			return;
		}
		ptr = ptr->next;
	}
 }
