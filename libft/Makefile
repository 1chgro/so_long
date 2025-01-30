NAME = libft.a
SRCS =  ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strncmp.c\
		ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c\
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c\
		ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
		ft_strcmp.c

FLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o:%.c libft.h
	cc $(FLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean