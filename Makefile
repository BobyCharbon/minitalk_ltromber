SRCS = 

HEADERS += minitalk.h

#OBJS = ${SRCS:.c=.o}

SERVER =

CLIENT = 

OBJ_SERVER = 

OBS_CLIENT = 

CFLAGS += -Wall
FLAGS += -Werror
CFLAGS += -Wextra

CC = clang


all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)
	@echo "OK"

$(OBJS): %.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@


re:	fclean
	$(MAKE)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

out:
	$(CC) -g $(CFLAGS) $(SRCS) && ./a.out

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