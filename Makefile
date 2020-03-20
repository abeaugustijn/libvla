# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/02 14:51:13 by aaugusti          #+#    #+#              #
#    Updated: 2020/03/07 15:00:42 by abe              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libvla.a

SRCS			=	get\
					get_addr\
					get_index\
					init\
					memcpy\
					push\
					resize\
					set\
					shrink\


CFILES			=	$(SRCS:%=vla_%.c)
OFILES			=	$(SRCS:%=vla_%.o)

FLAGS			=	-Wall -Werror -Wextra -O3

AR_COMMAND		= ar rs

all: $(NAME)

$(NAME): $(OFILES)
	$(AR_COMMAND) $(NAME) $(OFILES)

%.o: %.c
	gcc -o $@ -c $< $(FLAGS)

clean: _clean

fclean: _clean
	rm -f $(NAME) test

_clean:
	rm -f $(OFILES) test.o

re: fclean all

test: $(OFILES) test.o
	gcc -o test $(FLAGS) $(OFILES) test.o -fsanitize=address
