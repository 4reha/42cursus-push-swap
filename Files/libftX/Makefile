# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-hadd <ael-hadd@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/07 14:58:30 by ael-hadd          #+#    #+#              #
#    Updated: 2022/02/18 17:00:31 by ael-hadd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftX.a

SRC_FILE	=	ft_atoi.c ft_isdigit.c ft_split.c \
				ft_strdup.c ft_strjoin.c ft_strlen.c ft_strncmp.c ft_substr.c \
				get_next_line.c get_next_line_utils.c ft_isspace.c \


OBJ_FILE	=	ft_atoi.o ft_isdigit.o ft_split.o \
				ft_strdup.o ft_strjoin.o ft_strlen.o ft_strncmp.o ft_substr.o \
				get_next_line.o get_next_line_utils.o ft_isspace.o \


all: $(NAME)

$(NAME):	$(OBJ_FILE)
		@ar rc $(NAME) $(OBJ_FILE)
		@echo "\033[0;32mLibftX Compiled √\033[0;32m"

$(OBJ_FILE):	$(SRC_FILE)
		@cc -Wall -Werror -Wextra -c  $(SRC_FILE)
		

clean:
	@rm -f $(OBJ_FILE) $(BONUS_OBJ)

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;31mLibftX Cleaned x\033[0;31m"

re: fclean $(NAME)


.PHONY		:	all clean fclean re bonus
