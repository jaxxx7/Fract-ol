# Nom de l'exécutable
NAME = fractol

# Compilateur et flags
CC = gcc
CFLAGS  = -Wall -Wextra -Werror -Iinclude -Imlx_linux -Iminilibx-linux
LDFLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm -lbsd

SRC_DIR = src
SRC =	$(SRC_DIR)/fractol.c \
		$(SRC_DIR)/handle_pixel.c \
		$(SRC_DIR)/hooks.c \
		$(SRC_DIR)/init.c \
		$(SRC_DIR)/utils.c \
		$(SRC_DIR)/ft_loop.c 

OBJ = $(SRC:.c=.o)

# Répertoire de la libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Compilation
all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null
	@echo "libft OK"

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBFT) $(LDFLAGS) -o $(NAME)
	@echo "fractol OK"

clean:
	@$(MAKE) clean -C $(LIBFT_DIR) > /dev/null
	@rm -f $(OBJ)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR) > /dev/null
	@rm -f $(NAME)

re: fclean all