NAME_CLIENT = client
NAME_SERVER = server
HEADER_FILE = minitalk.h
INC_DIR = ./includes/
SRC_DIR = ./srcs/
CFLAGS = -Wall -Wextra -Werror
CC = gcc
SRC_FILES_CLIENT =	$(SRC_DIR)main.c \
					$(SRC_DIR)ft_eat.c \
					$(SRC_DIR)ft_isnum.c \
					$(SRC_DIR)ft_printstatus.c \
					$(SRC_DIR)ft_threads.c
SRC_FILES_SERVER = 

OBJS_CLIENT = $(SRC_FILES_CLIENT:.c=.o)
OBJS_SERVER = $(SRC_FILES_SERVER:.c=.o)

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(SRC_FILES_CLIENT) $(INC_DIR) $(HEADER_FILE)
	$(CC) $(CFLAGS) $(SRC_FILES_CLIENT) -o $(NAME_CLIENT)

$(NAME_SERVER): $(SRC_FILES_SERVER) $(INC_DIR) $(HEADER_FILE)
	$(CC) $(CFLAGS) $(SRC_FILES_SERVER) -o $(NAME_SERVER)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all

.PHONY: all clean fclean re
