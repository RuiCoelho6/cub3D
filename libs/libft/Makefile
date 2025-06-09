FLGS = -Wall -Wextra -Werror

NAME = libft.a

SOURCES = ft_atoi.c ft_isdigit.c ft_memmove.c ft_split.c \
ft_strlcat.c ft_strrchr.c ft_bzero.c ft_isprint.c ft_memset.c\
ft_strlcpy.c ft_strtrim.c ft_calloc.c ft_itoa.c ft_putchar_fd.c\
ft_strchr.c ft_strlen.c ft_substr.c ft_isalnum.c ft_memchr.c\
ft_putendl_fd.c ft_strdup.c ft_strmapi.c ft_tolower.c \
ft_isalpha.c ft_memcmp.c ft_putnbr_fd.c ft_striteri.c \
ft_strncmp.c ft_toupper.c ft_isascii.c ft_memcpy.c ft_putstr_fd.c\
ft_strjoin.c ft_strnstr.c \

SOURCES_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
ft_lstiter.c ft_lstmap.c \

OBJECT = $(SOURCES:.c=.o) 

OBJECT_BONUS = $(SOURCES_BONUS:.c=.o)

CC = cc

RM = rm -f

all: $(NAME)

$(NAME): $(OBJECT)
	ar rcs $(NAME) $(OBJECT)

bonus: $(OBJECT_BONUS) $(NAME)
	ar rcs $(NAME) $(OBJECT_BONUS)

clean:
	$(RM)  $(OBJECT) $(OBJECT_BONUS)

fclean: clean
	$(RM) $(NAME) 

re: fclean all

exec:
	cc -g $(FLGS) $(SOURCES) $(SOURCES_BONUS) -lbsd

norm: 
	yes y | python3 -m c_formatter_42 -c $(SOURCES)
