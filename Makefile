CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -O3

CUBE_NAME = cube3D

SRCS = ./srcs/
INCLUDE = ./includes/

CUBE_SRC = $(SRCS)main.c


CUBE_OBJ = $(CUBE_SRC:.c=.o)

NAME = $(CUBE_NAME)
all: $(NAME)

$(CUBE_NAME): $(CUBE_OBJ)
	$(CC) $(CFLAGS) -I$(INCLUDE) -o $(CUBE_NAME) $(CUBE_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

clean:
	rm -f $(CUBE_OBJ)

fclean: clean
	rm -f $(CUBE_NAME) $(NAME)

re: fclean all

push:
	git add .
	git commit -m "$(m)"
	git push

.PHONY: all clean fclean re