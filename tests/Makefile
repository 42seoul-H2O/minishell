# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/04 16:27:42 by hocsong           #+#    #+#              #
#    Updated: 2023/02/12 11:34:11 by hocsong          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = test

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
INCS = -I../include -I../lib/libft -I./

EXT_SRCS_PATH = ../srcs
OBJS_PATH = objs
SRCS_PATH = srcs

EXT_SRCS_WO_PATH = init_t_str.c is_quoted.c my_split.c set_word_count.c \
	get_word_len.c is_delimiter.c set_token_indices.c builtin_exit.c \
	convert_dollar_to_env.c convert_dollar_to_env2.c \
	vararr_oper1.c vararr_oper2.c vararr_oper3.c parse.c remove_quotes.c

SRCS_WO_PATH = test.c test_split.c test_parser.c
SRCS_WO_PATH += $(EXT_SRCS_WO_PATH)

SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_WO_PATH))
EXT_SRCS = $(addprefix $(EXT_SRCS_PATH)/, $(EXT_SRCS_WO_PATH))
OBJS = $(addprefix $(OBJS_PATH)/, $(SRCS_WO_PATH:.c=.o))

LIBFT_PATH = ../lib/libft

all: copy $(NAME)

$(NAME): copy $(OBJS)
	$(MAKE) -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OBJS) $(INCS) -L$(LIBFT_PATH) -lft $(LIB_RDL) -lreadline -o $(NAME)

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(OBJS)
	rm -f $(addprefix $(SRCS_PATH)/, $(EXT_SRCS_WO_PATH))
	rm -f copy

re:
	make fclean
	make all

copy:
	cp $(EXT_SRCS) srcs/