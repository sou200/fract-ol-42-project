NAME = libftprintf.a
CC = cc
AR = ar
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

SRC = ft_printf.c ft_printf_utils.c nbr_utils.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) rcs $(NAME) $?

%.o : %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean clean all
