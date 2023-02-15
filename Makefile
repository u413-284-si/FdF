# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sqiu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 10:37:52 by sqiu              #+#    #+#              #
#    Updated: 2023/02/15 17:31:00 by sqiu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

NAME		= fdf

CFLAGS 		= -Wall -Wextra -Werror
CPPFLAGS	= -I/usr/include -I./mlx_linux	-I./inc		# search in directories for included Makefiles
LDFLAGS		= -L./libft	-L./mlx_linux -L/usr/lib		# search for libraries in libft, mlx_Linux and /usr/lib
LDLIBS		= -lft -lm -lmlx_Linux -lXext -lX11 -lz		# link libraries: libft, libm, libmlx_Linux, libXext, libX11, libz
OPTION 		= -c -O3									# -c generates object files, -O3 adds compile time, but reduces execution time and code size 					
DEBUG		= -g
CC 			= cc

INCDIR		= ./inc/
INCLIST		= fdf.h algo.h colour.h error.h events.h image.h initiate.h \
			main.h manip.h parse.h transformation.h utils.h window.h
INC			= $(addprefix ${INCDIR}, ${INCLIST})

SRCDIR		= ./src/
SRCLIST		= main.c error.c initiate.c parse.c ft_atoi_base.c utils.c \
			colour.c algo.c events.c image.c transformation.c window.c \
			manip.c
SRC			= $(addprefix ${SRCDIR}, ${SRCLIST})

OBJDIR		= ./obj/
OBJLIST		= $(SRCLIST:%.c=%.o) 
OBJ			= $(addprefix ${OBJDIR}, ${OBJLIST})


#Colours

DEF_COLOUR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#Rules

all:			 $(NAME)

$(NAME):		 $(OBJ)
				@$(MAKE) all -C ./libft
				@$(MAKE) all -C ./mlx_linux
				@$(CC) $^ $(LDFLAGS) $(LDLIBS) $(CPPFLAGS) -o $@
				@echo "$(YELLOW)Compiling: $^ $(DEF_COLOUR)"
				@echo "$(GREEN)fdf compiled!$(DEF_COLOUR)"

${OBJDIR}%.o:	 ${SRCDIR}%.c ${INC}
				@$(CC) $(CFLAGS) $(CPPFLAGS) $(OPTION) $(DEBUG) $< -o $@

clean:
				@$(MAKE) clean -C ./libft
				@$(MAKE) clean -C ./mlx_linux
				@rm -f $(OBJ)
				@echo "$(BLUE)object files cleaned!$(DEF_COLOUR)"
fclean: 		clean
				@$(MAKE) fclean -C ./libft
				@$(MAKE) clean -C ./mlx_linux
				@rm -f $(NAME)
				@echo "$(CYAN)executable & object files cleaned!$(DEF_COLOUR)"

re: 			fclean all

.PHONY: 		all clean fclean re
