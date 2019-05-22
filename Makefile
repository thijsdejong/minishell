# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tde-jong <tde-jong@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/29 11:36:07 by tde-jong       #+#    #+#                 #
#    Updated: 2019/05/20 14:30:17 by tde-jong      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
FLAGS = -Wall -Werror -Wextra -Wunreachable-code
INCLUDES = -I./includes -I./libft
LIBFT= ./libft/libft.a
LIB = -L./libft/ -lft
VPATH = \
./srcs \
./srcs/builtin \
./srcs/env \
./srcs/shell \
./srcs/parser \
./srcs/evaluator \
./srcs/external
SRCS = main \
\
builtin builtin_cd builtin_echo builtin_env builtin_exit builtin_setenv \
builtin_unsetenv \
\
env_add_key_value env_delete env_duplicate env_get_by_key env_join_key_value \
env_set_key_value env_to_array \
\
shell_display_prompt shell_run \
\
parser parser_split_input parser_handle_expansions\
\
evaluator \
\
external
OBJECTS := $(SRCS:%=%.o)
SRCS := $(SRCS:%=%.c)

all: $(OBJECTS) $(LIBFT) $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) $(FLAGS) $^ $(INCLUDES) $(LIB) -o $(NAME)
	@echo "[+] $(NAME) has been compiled"

$(OBJECTS): $(SRCS)
	@$(CC) $(FLAGS) $^ $(INCLUDES) -c

$(LIBFT):
	@$(MAKE) -C libft

clean:
	@rm -f $(OBJECTS)
	@$(MAKE) -C libft clean
	@echo "[-] removed object files"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C libft fclean
	@echo "[-] removed binaries"

re: fclean all

run: all
	./minishell
