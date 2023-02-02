# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 15:58:59 by hyunjuki          #+#    #+#              #
#    Updated: 2023/02/02 16:02:07 by hyunjuki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCS = -I./includes

SRCS_NAME = main.c 
SRCS_PATH = ./srcs
SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_NAME))

OBJS_NAME = $(SRCS_NAME:.c=.o)
OBJS_PATH = ./objs
OBJS = $(addprefix $(OBJS_PATH)/, $(OBJS_NAME))

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OBJS) $(INCS) -L$(LIBFT_PATH) -lft -L$(MLX_PATH) -o $(NAME)

$(OBJS_PATH)/%.o : $(SRCS_PATH)/%.c
	$(CC) $(CFALGS) $(INCS) -o $@ -c $<

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