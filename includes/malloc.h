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
# include <pthread.h>

# define TINY 1
# define SMALL 100
# define PAGE_COEF 100

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
	size_t				max_free_size;
	struct s_page		*next;
	struct s_block		*first_block;
}				t_page;

typedef struct	s_book{
	t_page	*tiny_page;
	t_page	*small_page;
	t_page	*large_page;
}				t_book;

t_page			*add_page(size_t page_size, t_type type);
void			*find_page(t_page *first, size_t size);
void			*find_block(t_block *block, size_t size, t_type t);
void			*use_g_tiny(size_t size, t_book *b);
void			*use_g_small(size_t size, t_book *b);
void			*use_g_large(size_t size, t_book *b);
void			free_block(t_page *page, void *data);
t_page			*is_in_book(void *addr, t_book *book);
long long int	realloc_block(void *d, size_t i, t_page *b);
t_block			*create_block(t_block *old, size_t size);
void			delete_page(t_book *book, t_page *page);
t_block			*get_block(void *data, t_block *block);
/*
**				libft
*/
unsigned int	ft_strlen(const char *str);
void			ft_memcpy(void *new, void *old, size_t size);
void			ft_putchar(char c, char flag);
void			ft_putstr(char *str, char flag);
void			ft_putnbr(unsigned long long nbr, char flag);
void			ft_putnbr_endl(unsigned long long nbr, char flag);
void			ft_putnbr_hex(unsigned long long nbr, char flag);
void			ft_putnbr_hex_endl(unsigned long long nbr, char flag);
void			print_mem_hex(void *data, size_t size);
/*
**				debug
*/
void			use_malloc_debug(int flag);
void			show_alloc_mem(void);
void			print_mem(void *data);
/*
**				globales variables
*/
size_t			g_min_size;
int				g_debug_flag;
t_book			*g_book_h;
#endif
