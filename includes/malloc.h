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

typedef struct	s_meta_data{
	size_t		page_size;
}				t_meta_data;

typedef struct	s_book{
	t_meta_data	meta_data;
}				t_book;

void			putstr(char *str);
unsigned long	strlen(const char *str);

#endif
