# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 17:46:30 by ludovictrom       #+#    #+#              #
#    Updated: 2022/05/30 19:54:50 by ludovictrom      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = test.c

#HEADERS += minitalk.h
#NAME = libft.a

ROOT_DIR		?= $(shell pwd)
LIBFT_DIR		= ${ROOT_DIR}/libft_ltromber/
#LIBFT_DIR = /libft_ltromber/libft
LIBFT = ./libft_ltromber/libft.a
#LIBS	 = -L./libft_ltromber -lft
#OBJS = ${SRCS:.c=.o}

SERVER = server
CLIENT = client

OBJ_SERVER = 
OBS_CLIENT = 

CFLAGS += -Wall
FLAGS += -Werror
CFLAGS += -Wextra

CC = clang

all: $(SRCS) $(LIBFT) $(SERVER) $(CLIENT)

$(SERVER) : server.o minitalk.h
	@$(CC) server.o  $(LIBFT) -o $@
	@printf "\e[38;5;226m./$@ successfully build🥑\e[0m\n"

$(CLIENT) : client.o minitalk.h
	@$(CC) client.o $(LIBFT) -o $@
	@printf "\e[38;5;46m./$@ successfully build🥝\e[0m\n"

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)
	@echo "OK"

$(OBJS): %.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C libft_ltromber/

re:	fclean
	$(MAKE)

clean:
	$(RM) $(OBJS) $(LIBFT) $(BONUS_OBJS)
	@make clean -C libft_ltromber

fclean: clean
	@rm -f $(SERVER) $(CLIENT)
	@make fclean -C libft_ltromber
	$(RM) $(NAME)

out:
	$(CC) -g $(CFLAGS) $(SRCS) $(LIBFT_DIR) && ./a.out

ac:
	read ARGV1
	read ARGV2
	$(CC) -g $(FLAFS) $(SRCS) && ./a.out "$(ARGV1)" "$(ARGV2)" 
#read ARGV3
#"$(ARGV3)"

cleanout:
	$(RM) a.out

.PHONY: all clean fclean re
#.SILENT: