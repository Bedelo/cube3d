CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -O3

CUBE_NAME = cube3D

SRCS = ./srcs/
INCLUDE = ./includes/

CUBE_SRC = $(SRCS)main.c \
			$(SRCS)parsing.c


CUBE_OBJ = $(CUBE_SRC:.c=.o)

NAME = $(CUBE_NAME)
all: $(NAME)

$(NAME_MAC): $(CUBE_OBJ)
	$(CC) $(CFLAGS) -I$(INCLUDE) -o $(CUBE_NAME) $(CUBE_OBJ) -lm -L$(LIBFT_PATH) -lft

PATH_MLX = ./minilibx-linux/

$(NAME): $(LIBFT) $(MLX) $(CUBE_OBJ) 
	$(CC) $(CFLAGS) -I$(INCLUDE) -o $(CUBE_NAME) $(CUBE_OBJ) -lm -L$(LIBFT_PATH) -lft -L$(PATH_MLX) -lmlx -lXext -lX11

LIBFT_PATH = ./Libft
LIBFT = $(LIBFT_PATH)/libft.a
$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

mac:
	$(NAME_MAC)

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