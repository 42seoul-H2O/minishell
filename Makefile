# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 15:58:59 by hyunjuki          #+#    #+#              #
#    Updated: 2023/02/05 20:21:33 by hocsong          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCS = -I./include

SRCS_NAME = main.c \
			prompt.c \
			builtin_exit.c \
			convert_dollar_to_env.c \
			convert_dollar_to_env2.c \
			ft_getenv.c \
			get_word_len.c \
			init_t_str.c \
			is_delimiter.c \
			is_quoted.c \
			my_split.c \
			set_token_indices.c \
			set_word_count.c \
SRCS_PATH = ./srcs
SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_NAME))

OBJS_NAME = $(SRCS_NAME:.c=.o)
OBJS_PATH = ./objs
OBJS = $(addprefix $(OBJS_PATH)/, $(OBJS_NAME))

LIBFT_PATH = lib/libft
LIB_RDL = -L/opt/homebrew/opt/readline/lib
LIB_RDL_INC = -I/opt/homebrew/opt/readline/include
#LIB_RDL = -L/Users/hyunjuki/.brew/opt/readline/lib
#LIB_RDL_INC = -I/Users/hyunjuki/.brew/opt/readline/include
#LIB_RDL = -L/Users/hocsong/.brew/opt/readline/lib
#LIB_RDL_INC = -I/Users/hocsong/.brew/opt/readline/include

TEST_PATH = ./tests

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OBJS) $(INCS) -L$(LIBFT_PATH) -lft $(LIB_RDL) -lreadline -o $(NAME)

$(OBJS_PATH)/%.o : $(SRCS_PATH)/%.c
	$(CC) $(CFALGS) $(INCS) $(LIB_RDL_INC) -o $@ -c $<

clean :
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_PATH) clean

fclean : clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

re :
	$(MAKE) fclean
	$(MAKE) all

test :
	$(MAKE) -C $(TEST_PATH) re
	tests/test

.PHONY : all clean fclean re test