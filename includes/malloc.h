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

typedef struct	s_block{
	size_t	block_size;
	char	state;
	void	*this;
}				t_block;

typedef struct	s_book_page{
	size_t				page_syze;
	size_t				max_available_size;
	struct s_book_page	*next;
	void				*this;
}				t_book_page;

typedef struct	s_book{
	size_t		min_size;
	t_book_page	*tiny_first_page;
	t_book_page	*small_first_page;
	t_book_page	*large_first_page;
}				t_book;

t_book_page		*add_page(size_t page_size);
void			*find_page(t_book_page *first_page, size_t size);
void			*find_block(char *block, size_t size);
/*
**				libft
*/
void			putstr(char *str);
unsigned long	strlen(const char *str);

#endif
