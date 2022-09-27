
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
DOSSRC = ./src/
DOSSRCB = ./src_bonus/

NAME1 = server
NAME2 = client

SRC = ft_mt_utils.c

NAME1B = server_bonus
NAME2B = client_bonus

SRCB = ft_mt_utils_bonus.c

all : $(NAME1) $(NAME2)
bonus : $(NAME1B) $(NAME2B)

$(NAME1) : $(DOSSRC)$(NAME1:%=%.o) $(DOSSRC)$(SRC:%.c=%.o)
	$(CC) $(CFLAGS) $^ -o $@

$(NAME2) : $(DOSSRC)$(NAME2:%=%.o) $(DOSSRC)$(SRC:%.c=%.o)
	$(CC) $(CFLAGS) $^ -o $@

%.o : $(DOSSRC)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME1B) : $(DOSSRCB)$(NAME1B:%=%.o) $(DOSSRCB)$(SRCB:%.c=%.o)
	$(CC) $(CFLAGS) $^ -o $@

$(NAME2B) : $(DOSSRCB)$(NAME2B:%=%.o) $(DOSSRCB)$(SRCB:%.c=%.o)
	$(CC) $(CFLAGS) $^ -o $@

%.o : $(DOSSRCB)%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(DOSSRC)*.o
	rm -f $(DOSSRCB)*.o

fclean : clean
	rm -f server client
	rm -f server_bonus client_bonus

re : fclean all

.PHONY : all bonus clean fclean re