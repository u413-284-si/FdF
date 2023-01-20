# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sqiu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 10:37:52 by sqiu              #+#    #+#              #
#    Updated: 2023/01/20 15:08:58 by sqiu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

NAME		= fdf
INC			= fdf.h
SRC			= main.c error.c initiate.c parse.c ft_atoi_base.c

OBJ			= $(SRC:%.c=%.o) 
CFLAGS 		= -Wall -Wextra -Werror
CPPFLAGS	= -I/usr/include -I./mlx_linux
LDFLAGS		= -L./libft	-L./mlx_linux -L/usr/lib		# search for libraries in libft, mlx_Linux and /usr/lib
LDLIBS		= -lft -lm -lmlx_Linux -lXext -lX11 -lz		# link libraries: libft, libm, libmlx_Linux, libXext, libX11, libz
OPTION 		= -c -O3									# -c generates object files, -O3 adds compile time, but reduces execution time and code size 					
CC 			= cc

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#Rules

all: $(NAME)

$(NAME): $(OBJ)
		@$(MAKE) all -C ./libft
		@$(MAKE) all -C ./mlx_linux
		@$(CC) $^ $(LDFLAGS) $(LDLIBS) $(CPPFLAGS) -o $@
		@echo "$(YELLOW)Compiling: $^ $(DEF_COLOR)"
		@ar rcs $@ $^
		@echo "$(GREEN)fdf compiled!$(DEF_COLOR)"

%.o:	 %.c 
		@$(CC) $(CFLAGS) $(CPPFLAGS) $(OPTION) $< -o $@

clean:
		@$(MAKE) clean -C ./libft
		@$(MAKE) clean -C ./mlx_linux
		@rm -f $(OBJ)
		@echo "$(BLUE)object files cleaned!$(DEF_COLOR)"
fclean: clean
		@$(MAKE) fclean -C ./libft
		@$(MAKE) clean -C ./mlx_linux
		@rm -f $(NAME)
		@echo "$(CYAN)executable & object files cleaned!$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re
