# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 15:58:59 by hyunjuki          #+#    #+#              #
#    Updated: 2023/02/13 14:57:55 by hyunjuki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCS = -I./include

SRCS_NAME = main.c \
			prompt.c \
			builtin/builtin_main.c \
			builtin/builtin_exit.c \
			builtin/builtin_pwd.c \
			builtin/builtin_export.c \
			builtin/builtin_export2.c \
			builtin/builtin_env.c \
			builtin/builtin_echo.c \
			builtin/builtin_cd.c \
			builtin/builtin_unset.c \
			vararr_oper1.c \
			vararr_oper2.c \
			vararr_oper3.c \
			cmdlist.c \
			temp_checker.c \
			temp_parser.c
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

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C $(LIBFT_PATH)
	$(CC) -g $(CFLAGS) $(OBJS) $(INCS) -L$(LIBFT_PATH) -lft $(LIB_RDL) -lreadline -o $(NAME)

$(OBJS_PATH)/%.o : $(SRCS_PATH)/%.c
	$(CC) -g $(CFALGS) $(INCS) $(LIB_RDL_INC) -o $@ -c $<

clean :
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_PATH) clean

fclean : clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all clean fclean re