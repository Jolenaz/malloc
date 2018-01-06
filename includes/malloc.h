/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 11:44:22 by jbelless          #+#    #+#             */
/*   Updated: 2017/12/26 11:44:25 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H
# include <sys/mman.h>
# include <unistd.h>
# include <stdio.h>

# define TINY 1
# define SMALL 100
# define PAGE_COEF 100

# define DEBUG 0

size_t			g_min_size;

typedef enum	e_type{
	tiny,
	small,
	large
}				t_type;

typedef struct	s_block{
	size_t			block_size;
	char			is_free;
	void			*data;
	struct s_block	*next;
}				t_block;

typedef struct	s_page{
	t_type				type;
	size_t				page_size;
	size_t				max_available_size;
	struct s_page	*next;
	struct s_block		*first_block;
}				t_page;

typedef struct	s_book{
	t_page	*tiny_first_page;
	t_page	*small_first_page;
	t_page	*large_first_page;
}				t_book;

t_page		*add_page(size_t page_size, t_type type);
void			*find_page(t_page *first, size_t size);
void			*find_block(t_block *block, size_t size);
void			*use_g_tiny(size_t size, t_book *);
void			*use_g_small(size_t size, t_book *);
void			*use_g_large(size_t size, t_book *);
void			free_block(t_page *page, void *data);
t_page		*is_in_book(void *addr, t_book *book);
size_t			realloc_block(void *, size_t, t_page *);
t_block			*create_block(t_block *old, size_t size);
void			delete_page(t_book *book, t_page *page);
/*
**				libft
*/
void			ft_putstr(char *str);
unsigned long	ft_strlen(const char *str);
void			ft_putnbr(unsigned long long nbr);
void			ft_putchar(char c);
void			ft_memcpy(void *new, void *old, size_t size);
#endif
