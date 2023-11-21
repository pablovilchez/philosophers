# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/02 20:33:48 by pvilchez          #+#    #+#              #
#    Updated: 2023/10/07 20:14:43 by pvilchez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc -g
CFLAGS = -Wall -Wextra -Werror
REMOVE = rm -rf

OBJ_PATH = obj
SRC_PATH = src
INC_PATH = include

HEADERS	= -I ./include

SRC_FILES = philo.c capt_args.c print_table.c mutex_func.c run_philos.c\
			philo_actions.c

SRC := $(addprefix $(SRC_PATH)/, $(SRC_FILES))
OBJ = $(SRC:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)

ORANGE = \033[1;38;5;208m
RESET = \033[0m
U_LINE = \033[4m
YELLOW = \033[1;38;5;226m

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(LIBFT_LIB_PATH) $(MLX42_LIB_PATH) $(MLX42FLAGS_MAC) $(HEADERS) -o $@
	@echo "\n$(ORANGE)$(U_LINE)$(NAME): Mandatory Compiled$(RESET) \n"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)
	@echo "$(YELLOW)$(NAME) Compiling:$(RESET) $(notdir $<)"

clean:
	@$(REMOVE) $(OBJ_PATH)

fclean: clean
	@$(REMOVE) $(NAME)

re: fclean all

.PHONY: all clean fclean re