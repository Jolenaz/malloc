ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so

CC = gcc
CFLAGS =  -Wall -Wextra -Werror
DYLDFLAGS = -shared
IFLAGS = -I $(INC_DIR)
PFLAGS = -lpthread

INC_DIR = ./includes/
INC_FILES = malloc.h

SRC_DIR = ./srcs/
SRC_FILES = malloc.c \
			libft.c \
			libft2.c \
			print_mem.c \
			add_page.c \
			find_page.c \
			find_block.c \
			get_size.c \
			is_in_book.c \
			free_block.c \
			realloc_block.c \
			delete_page.c \
			debug.c \
			show_mem.c


OBJ_DIR = ./obj/
OBJ_FILES = $(SRC_FILES:.c=.o)

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
INC = $(addprefix $(INC_DIR), $(INC_FILES))

all: $(OBJ_DIR) $(NAME) auteur

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
 
$(OBJ_DIR)%.o:  $(SRC_DIR)%.c $(INC)
	$(CC) $(CFLAGS) $(IFLAGS)  -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) $(DYLDFLAGS) $(PFLAGS) $^ -o $(NAME)
	rm -f libft_malloc.so
	ln -s libft_malloc_$(HOSTTYPE).so libft_malloc.so 

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)
	rm -f libft_malloc.so

re: fclean all

.PHONY: all re fclean clean