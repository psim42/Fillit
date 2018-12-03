# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fwerner <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 14:25:16 by fwerner           #+#    #+#              #
#    Updated: 2018/12/03 13:57:43 by fwerner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CFLAGS = -Wall -Wextra -Werror
INCLUDE_BASE_DIR = .
SRC_BASE_DIR = .
INCLUDES_BASE = fillit.h
SRCS_BASE = check_ttrm.c \
			insert_ttrm.c \
			map_utils.c \
			print_map.c \
			read_ttrm_file.c \
			resolve_fillit.c \
			ttrm_utils.c \
			main.c
SRCS = $(addprefix $(SRC_BASE_DIR)/,$(SRCS_BASE))
INCLUDES = $(addprefix $(INCLUDE_BASE_DIR)/,$(INCLUDES_BASE))
OBJS = $(notdir $(SRCS:.c=.o))

all: $(NAME)

$(NAME): libft/libft.a $(OBJS)
	gcc $(CFLAGS) $(OBJS) -o $(NAME) -I libft/includes -L libft -lft

%.o: %.c $(INCLUDES_BASE)
	gcc $(CFLAGS) -c $< -o $@ -I libft/includes

libft/libft.a:
	make -C libft

clean:
	make -C libft clean
	rm -f $(OBJS)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all
