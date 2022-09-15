NAME		= fractol
SRCFILES	= main.c \
			  screen.c \
			  draw_fractol.c \
			  julia.c \
			  mandelbrot.c \
			  ft_atof.c \
			  hooks.c
LIBFT		= lib/libft/libft.a
MLX42		= lib/MLX42/libmlx42.a

VPATH		= src : \
			  lib/MLX42/src
OBJDIR		= obj

OBJ			= $(addprefix obj/, $(SRCFILES:.c=.o))
INC			= $(addprefix -I , \
			  lib/libft \
			  lib/MLX42/include/MLX42)
CFLAGS		= -Wall -Wextra -Werror -g
LINKING_FLAGS = -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -g

all: $(NAME)

$(NAME): $(LIBFT) $(MLX42) $(OBJ)
	$(CC) $(LINKING_FLAGS) -o $@ $^

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC) -c $(CFLAGS) $(INC) -o $@ $^

$(LIBFT):
	make bonus -C lib/libft

$(MLX42):
	make -C lib/MLX42

clean:
	rm -rf $(OBJDIR)
	make clean -C lib/libft
	make clean -C lib/MLX42

fclean:
	rm -rf $(OBJDIR) $(NAME)
	make fclean -C lib/libft
	make fclean -C lib/MLX42

re:
	make fclean
	make
