# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yismaili <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/12 20:30:45 by yismaili          #+#    #+#              #
#    Updated: 2022/02/12 20:31:44 by yismaili         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

framework= -framework OpenGL -framework AppKit -g
NAME=fdf
cc = gcc
flags = -Wall -Wextra -Werror
SRCS = main.c\
	   drow.c\
	   read_maps.c\
	   key.c\
	   utils.c\

OBJS =$(SRCS:.c=.o)
INCL= fdf.h

GNL_SRC = get_next_line.c\
		  get_next_line_utils.c

GNL_OBJS =$(GNL_SRC:.c=.o)


all:utils $(NAME)

%.a:
	@make -C ./libft
	@mv ./libft/libft.a .

gnl:$(GNL_OBJS)

utils:gnl libft.a

%.o: %.c $(INCL)
	@$(cc) $(flags) $< -I $(INCL) -c
	
$(NAME):$(OBJS) utils
	
	@$(cc) $(flags) $(OBJS) $(GNL_OBJS) -lmlx $(framework) libft.a -o $(NAME)

clean:
	@rm -rf *.o
	@rm -rf ./libft/*.o
	@rm -rf ./get_next_line/*.o

fclean:clean
	@rm -rf *.a
	@rm -rf fdf

re:fclean all

.PHONY: all gnl utils clean fclean re

