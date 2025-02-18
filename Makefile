# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/04 16:13:56 by idahhan           #+#    #+#              #
#    Updated: 2025/02/18 15:47:44 by idahhan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror 
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = main.c push_swap.c check_arguments.c stack_utils.c swap.c rotate.c push.c rotate_reverse.c sort.c swap_three.c concatinate.c init_stack.c push_swap_utils.c set_price.c
OBJS = $(SRCS:%.c=%.o)

HEADER = push_swap.h ./libft/libft.h


all : $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT): $(LIBFT_DIR)/*.c
	@make -C $(LIBFT_DIR)

clean:
	rm -f *.o
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: clean