CC := cc
CFLAGS := -Wall -Wextra -Werror -fsanitize=address
NAME	:= fractol
MLX_FLAG        := -L/usr/X11R6/lib -lX11 -lX11 -lXext -framework OpenGL -framework AppKit
PRINTF_DIR        := ./ft_printf
PRINTF            := libftprintf.a
MINILIBX_DIR    := ./minilibx-linux
MINILIBX        := libmlx.a
MINILIBX_DAR	:= libmlx_Darwin.a

SRCS            := ./src/main.c
OBJS            := $(SRCS:%.c=%.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)
$(NAME):	$(OBJS)
	$(MAKE) -C $(PRINTF_DIR)
	$(MAKE) -C $(MINILIBX_DIR) all
	$(CC) $(CFLAGS) $(MLX_FLAG) $(OBJS) $(PRINTF_DIR)/$(PRINTF) $(MINILIBX_DIR)/$(MINILIBX) -o $(NAME)
	# $(CC) $(OBJS) -L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit $(MINILIBX_DIR)/$(MINILIBX_DAR) -o $(NAME)

clean:
	$(MAKE) -C $(PRINTF_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(PRINTF_DIR) fclean
	$(MAKE) -C $(MINILIBX_DIR) clean
	$(RM) $(NAME)

re: fclean all