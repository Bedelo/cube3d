CC = cc

NAME = libft.a

CFLAGS = -Wall -Werror -Wextra


SRC = ft_isalpha.c \
 ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c \
 ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c \
 ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
 ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
 ft_putchar_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_strtrim.c ft_split.c \
 ft_putnbr_fd.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_atol.c get_next_line_bonus.c \
 ft_len_char.c ft_len_hex.c ft_len_int.c ft_len_percent.c ft_len_ptr.c ft_len_str.c \
 ft_len_unsign.c ft_printf.c ft_atodbl.c ft_isdouble.c

BONUSRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
 ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ = $(SRC:.c=.o)

SRCALL = $(SRC) $(BONUSRC)

OBJBONUS = $(SRCALL:.c=.o)
RM = rm -f

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $@ $^

%.o : %.c
	@$(CC) $(CFLAGS) -o $@ -c $? -I.

clean :
	@$(RM) $(OBJBONUS)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

bonus: $(OBJBONUS)
		ar rc $(NAME) $^

# so:
# 	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCALL)
# 	gcc -nostartfiles -shared -o libft.so $(OBJBONUS)

# .PHONY : all bonus clean fclean re so

