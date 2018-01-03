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

# define IS_FREE 1
# define IS_LAST 2

# define TINY 1
# define SMALL 100
# define PAGE_COEF 100

# define DEBUG 1

size_t			g_min_size;

typedef struct	s_block{
	size_t	block_size;
	char	state;
	void	*data;
}				t_block;

typedef struct	s_book_page{
	size_t				page_size;
	size_t				max_available_size;
	struct s_book_page	*next;
	struct s_block		*first_block;
}				t_book_page;

typedef struct	s_book{
	t_book_page	*tiny_first_page;
	t_book_page	*small_first_page;
	t_book_page	*large_first_page;
}				t_book;

t_book_page		*add_page(size_t page_size);
void			*find_page(t_book_page *first_page, size_t size);
void			*find_block(t_block *block, size_t size);
void			*malloc(size_t i);
void			*use_g_tiny(size_t size, t_book *);
void			*use_g_small(size_t size, t_book *);
void			*use_g_large(size_t size, t_book *);
char			is_in_book(void *addr, t_book *book);
/*
**				tools
*/
char			is_free(char state);
char			is_last(char state);
/*
**				libft
*/
void			ft_putstr(char *str);
unsigned long	ft_strlen(const char *str);
void			ft_putnbr(unsigned long long nbr);
void			ft_putchar(char c);
#endif
