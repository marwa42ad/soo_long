# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marwamostafa <marwamostafa@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 12:57:02 by marmoham          #+#    #+#              #
#    Updated: 2023/12/30 12:45:44 by marwamostaf      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT = libft.a

MINILIBX = libmlx

SRC = get_next_line/get_next_line.c \
	  get_next_line/get_next_line_utils.c \
	  map.c \
	  main.c \
	  map_check.c \
	  map_check2.c \
	  helper.c \
	  handle_error.c \
	  collectibles.c \
	  images.c \
	  game_movements.c \
	  game_event.c 

ARC = libft/libft.a minilibx/libmlx.a

CC = cc

#CFLAG = -Wall -Werror -Wextra

FFLAGS = -framework OpenGL -framework Appkit

all: $(NAME)

$(NAME): $(LIBFT)  $(MINILIBX)
	$(CC)  $(CFLAG) $(FFLAGS) $(SRC) $(ARC) -o $(NAME)

$(LIBFT):
	make -C libft
$(MINILIBX):
	make -C minilibx
	
clean:
	rm -f -v $(OBJ)
	cd libft && make clean
	cd minilibx && make clean

fclean: clean
	rm -f $(NAME)
	cd libft && make fclean
	cd minilibx && make clean
	
re: fclean all clean
