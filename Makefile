# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsprigga <bsprigga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/13 12:01:29 by bsprigga          #+#    #+#              #
#    Updated: 2019/03/08 18:31:15 by bsprigga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME_PS = push_swap
NAME_CH = checker

INCLUDES := includes libft/includes
CC = clang
FLAGS := -Wall -Werror -Wextra -g
VPATH := . srcs

SRCS_PS =	push_swap.c \
			errors_handling_part_1.c \
			errors_handling_part_2.c \
			stacks_setup.c \
			sorting_operations_push_swap.c \
			sorting_part_1.c \
			sorting_part_2.c \
			sorting_part_3.c \
			sorting_part_4.c \
			support_part_1.c \
			support_part_2.c 
			
SRCS_CH =	checker.c \
			errors_handling_part_1.c \
			errors_handling_part_2.c \
			stacks_setup.c \
			support_part_1.c \
			support_part_2.c \
			sorting_operations_push_swap.c \
			sorting_operations_checker_part_1.c \
			sorting_operations_checker_part_2.c \
			flag_v_and_printing.c 

OBJECTS_PS = $(SRCS_PS:.c=.o)
OBJECTS_CH = $(SRCS_CH:.c=.o)

all: $(NAME_PS) $(NAME_CH)

$(NAME_PS): libft/libft.a $(OBJECTS_PS)
	gcc $(FLAGS) $(OBJECTS_PS) $(addprefix -I,$(INCLUDES)) -lft -L./libft -o $@

$(NAME_CH): libft/libft.a $(OBJECTS_CH)
	gcc $(FLAGS) $(OBJECTS_CH) $(addprefix -I,$(INCLUDES)) -lft -L./libft -o $@

libft/libft.a:
	$(MAKE) -C libft

$(OBJECTS_PS): %.o: %.c
	gcc $(FLAGS) -c $< -o $@ $(addprefix -I,$(INCLUDES))

$(OBJECTS_CH): %.o: %.c
	gcc $(FLAGS) -c $< -o $@ $(addprefix -I,$(INCLUDES))

clean:
	rm -f $(OBJECTS_PS) $(OBJECTS_CH)
	#$(MAKE) -C ./libft clean

fclean: clean
	rm -f $(NAME_PS) $(NAME_CH)

re: fclean all

rebuild_lib:
	$(MAKE) re -C libft

re1: rebuild_lib fclean all
	
fclean1: fclean
	$(MAKE) fclean -C libft
	