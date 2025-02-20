# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/04 16:13:56 by idahhan           #+#    #+#              #
#    Updated: 2025/02/20 11:55:41 by idahhan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror 
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = Mandatory/main.c Mandatory/push_swap.c Mandatory/check_arguments.c Mandatory/stack_utils.c Mandatory/swap.c Mandatory/rotate.c\
		Mandatory/push.c Mandatory/rotate_reverse.c Mandatory/sort.c Mandatory/swap_three.c Mandatory/concatinate.c Mandatory/init_stack.c\
		Mandatory/push_swap_utils.c Mandatory/set_price.c
OBJS = $(SRCS:%.c=%.o)

SRCS_B = Bonus/main_bonus.c Bonus/check_args_bonus.c Bonus/concatinate_bonus.c Bonus/init_stack_bonus.c Bonus/swap_bonus.c Bonus/rotate_bonus.c\
			Bonus/rotate_reverse_bonus.c Bonus/push_bonus.c Bonus/get_next_line.c Bonus/checker_utils.c
OBJS_B = $(SRCS_B:%.c=%.o)

HEADER = Mandatory/push_swap.h ./libft/libft.h
HEADER_BONUS = Bonus/checker.h ./libft/libft.h

all : $(NAME)

bonus : $(NAME_BONUS)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	
$(NAME_BONUS): $(OBJS_B) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_B) $(LIBFT) -o $(NAME_BONUS)

$(OBJS): %.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_B): %.o: %.c $(HEADER_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT): $(LIBFT_DIR)/*.c
	@make -C $(LIBFT_DIR)

clean:
	rm -f Mandatory/*.o
	rm -f Bonus/*.o
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: clean