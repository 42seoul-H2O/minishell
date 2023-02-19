# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 15:58:59 by hyunjuki          #+#    #+#              #
#    Updated: 2023/02/18 19:48:52 by hyunjuki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCS = -I./include

SRCS_NAME = main.c \
			prompt1.c \
			prompt2.c \
			convert_dollar_to_env.c \
			convert_dollar_to_env2.c \
			get_word_len.c \
			get_heredoc_fd.c \
			init_t_str.c \
			is_delimiter.c \
			is_quoted.c \
			my_split.c \
			parse.c \
			visited.c \
			remove_quotes.c \
			set_token_indices.c \
			set_word_count.c \
			builtin_main.c \
			builtin_exit.c \
			builtin_pwd.c \
			builtin_export.c \
			builtin_export2.c \
			builtin_env.c \
			builtin_echo.c \
			builtin_cd.c \
			builtin_unset.c \
			vararr_oper1.c \
			vararr_oper2.c \
			vararr_oper3.c \
			vararr_oper4.c \
			cmdlist.c \
			type_checker.c \
			cmd_executor.c \
			cmd_pipe_and_redir.c \
			catch_syntax_err.c \
			catch_syntax_err2.c \
			get_token_type.c \
			get_token_type2.c \
			get_token_types.c \
			merge_redir_tokens.c
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

test :
	@echo Compiling the tests
	@$(MAKE) -sC $(TEST_PATH) test
	@echo The tests have been compiled. The tests will now be executed.
	tests/test
	@$(MAKE) -sC $(TEST_PATH) fclean

.PHONY : all clean fclean re test
