# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-hadd <ael-hadd@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/18 13:36:35 by ael-hadd          #+#    #+#              #
#    Updated: 2022/02/20 17:53:51 by ael-hadd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

BONUS		=	checker

FILES		=	Files/push_swap.c Files/numbers_checking.c Files/operations1.c Files/operations2.c \
				Files/stack_storing.c Files/ft_sort_in_tab.c Files/indexing_manager.c \
				Files/meduim_sorting.c Files/mini_sorting.c \

BNS_FILES	=	Files/checker.c Files/numbers_checking.c Files/operations1.c Files/operations2.c \
				Files/stack_storing.c \

LIB			=	Files/libftX/libftX.a

LIB_FILES	=	Files/libftX/ft_atoi.c Files/libftX/ft_isdigit.c Files/libftX/ft_split.c \
				Files/libftX/ft_strdup.c Files/libftX/ft_strjoin.c Files/libftX/ft_strlen.c \
				Files/libftX/ft_strncmp.c Files/libftX/ft_substr.c  Files/libftX/get_next_line.c \
				Files/libftX/get_next_line_utils.c Files/libftX/ft_isspace.c \

$(NAME)		:	$(LIB) $(FILES)
		@cc -Wall -Werror -Wextra $(FILES) $(LIB) -o $(NAME)
		@echo "\033[0;32mPush_swap is ready ;)\033[0;32m"

$(LIB)		:	$(LIB_FILES)
		@$(MAKE) -C Files/libftX/

$(BONUS)	:	$(LIB)	$(BNS_FILES)
		@cc -Wall -Werror -Wextra $(BNS_FILES) $(LIB) -o $(BONUS)
		@echo "\033[0;32mChecker is ready ;)\033[0;32m"

all			:	$(NAME)

bonus		:	$(BONUS)

clean		:
			@rm -f $(NAME)
		@echo "\033[0;31mPush_swap removed x\033[0;31m"
		@$(MAKE) clean -C Files/libftX/

fclean		:	clean
		@rm -f $(BONUS)
		@echo "\033[0;31mChecker removed x\033[0;31m"
		@$(MAKE) fclean -C Files/libftX/

re			:	fclean all

.PHONY		:	all clean fclean re