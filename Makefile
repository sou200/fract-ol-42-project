NAME = Fractol
CC = cc
CFLAGS = -Werror -Wall -Werror
MLX_FLAGS = -framework OpenGl -framework AppKit -lmlx
SRS = burning_ship.c color.c complex_utils.c fractol.c \
	julia.c key_events.c mandelbrot.c mouse_events.c \
	render.c usual_utils.c
OBJS = $(SRS:.c=.o)
RM = rm -f

FTPRINTF_DIR = ./ft_printf
FTPRINTF_LIB = $(FTPRINTF_DIR)/libftprintf.a


all : $(NAME)
$(NAME) : $(OBJS)
	@make -C $(FTPRINTF_DIR)
	$(CC) $(CFLAGS) $^ $(FTPRINTF_LIB) $(MLX_FLAGS) -o $@
%.o : %.c constants.h fractol.h
	$(CC) $(CFLAGS) -c $< -o $@
bonus : all
clean :
	@make -C $(FTPRINTF_DIR) $@
	$(RM) $(OBJS)
fclean : clean
	@make -C $(FTPRINTF_DIR) $@
	$(RM) $(NAME)
re : fclean all