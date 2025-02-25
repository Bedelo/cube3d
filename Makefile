CC = cc
CFLAGS =  -g3 -O3
# CFLAGS = -Wall -Wextra -Werror -g3 -O3

CUBE_NAME = cube3D

SRCS = ./srcs/
INCLUDE = ./includes/

CUBE_SRC = $(SRCS)main.c \
			$(SRCS)parsing.c \
			$(SRCS)map_to_array.c \
			$(SRCS)closed_map.c \
			$(SRCS)utils_free.c \
			$(SRCS)utils_parsing.c \
			$(SRCS)error.c \
			$(SRCS)header_infos.c \
			$(SRCS)header_format.c \
			$(SRCS)map_init.c \
			$(SRCS)event_handle.c \
			$(SRCS)player.c \
			$(SRCS)render_2D.c \
			$(SRCS)utils.c \
			$(SRCS)render_3D.c \

CUBE_OBJ = $(CUBE_SRC:.c=.o)

NAME = $(CUBE_NAME)
all: $(NAME)

PATH_MLX = ./rscs/minilibx-linux/

LIBFT_PATH = ./Libft
LIBFT = $(LIBFT_PATH)/libft.a
$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

$(NAME): $(LIBFT) $(MLX) $(CUBE_OBJ)
	$(CC) $(CFLAGS) -I$(INCLUDE) $(CUBE_OBJ) -o $(CUBE_NAME) -lm -L$(LIBFT_PATH) -lft -L$(PATH_MLX) -lmlx -lXext -lX11


%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

clean:
	make -C $(LIBFT_PATH) clean
	rm -f $(CUBE_OBJ)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(CUBE_NAME) $(NAME)

re: fclean all

push:
	git add .
	git commit -m "$(m)"
	git push

.PHONY: all clean fclean re
