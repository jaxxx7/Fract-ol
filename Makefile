# Nom de l'exécutable
NAME = fractol

# Compilateur et flags
CC = gcc
CFLAGS  = -Wall -Wextra -Werror -Iinclude -Imlx_linux
LDFLAGS = -Lmlx_linux -lmlx -lXext -lX11 -lm -lbsd

SRC_DIR = src
SRC =	$(SRC_DIR)/check_input.c \
		$(SRC_DIR)/init_stack.c \
		$(SRC_DIR)/operations.c \
		$(SRC_DIR)/push_swap.c \
		$(SRC_DIR)/set_index.c \
		$(SRC_DIR)/sort_stack.c \
		$(SRC_DIR)/utils.c \
		$(SRC_DIR)/free_stack.c \

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
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)
	@echo "fractol OK"

clean:
	@$(MAKE) clean -C $(LIBFT_DIR) > /dev/null
	@rm -f $(OBJ)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR) > /dev/null
	@rm -f $(NAME)

re: fclean all%