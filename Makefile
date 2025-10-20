# **************************************************************************** #
#                                   CONFIG                                     #
# **************************************************************************** #

NAME = push_swap
BONUS = checker

CC = cc
CFLAGS = -g -Wall -Wextra -Werror -Wunused-function -fsanitize=address
RM = rm -f

LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a
INCLUDES = -I include -I $(LIBFTDIR)/include

SRC_DIR = src/push_swap
BONUS_DIR = src/checker

# **************************************************************************** #
#                                   SOURCES                                    #
# **************************************************************************** #

COMMON_FILES = \
	ft_add_back.c \
	ft_add_front.c \
	ft_check_args.c \
	ft_check_dup.c \
	ft_check_sorted.c \
	ft_check_utils.c \
	ft_error.c \
	ft_free.c \
	ft_list_args.c \
	ft_parse.c \
	ft_parse_args_quoted.c \
	ft_rotate_and_push.c \
	ft_rotate_type.c \
	ft_sort_big.c \
	ft_sort_three.c \
	ft_stack_new.c \
	lst_utils.c \
	lst_utils_2.c \
	operations.c \
	operations_2.c \
	operations_3.c \
	solver_utils_ab.c \
	solver_utils_ba.c \
	ft_exit_error.c \
	algorithm.c

PUSH_SWAP_MAIN = push_swap.c
CHECKER_MAIN   = checker.c
CHECKER_UTILS  = checker_utils.c

# Arquivos completos de cada binário
PUSH_SWAP_SRC  = $(addprefix $(SRC_DIR)/, $(COMMON_FILES) $(PUSH_SWAP_MAIN))
CHECKER_SRC    = $(addprefix $(SRC_DIR)/, $(COMMON_FILES)) \
				  $(BONUS_DIR)/$(CHECKER_MAIN) \
				  $(BONUS_DIR)/$(CHECKER_UTILS)

# Objetos
PUSH_SWAP_OBJ  = $(PUSH_SWAP_SRC:.c=.o)
CHECKER_OBJ    = $(CHECKER_SRC:.c=.o)

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFTDIR)
# relinkando na linha 72
$(NAME): $(PUSH_SWAP_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(PUSH_SWAP_OBJ) -L $(LIBFTDIR) -lft -o $(NAME)
	@echo "✅ Compilado: $(NAME)"

$(BONUS): $(CHECKER_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(CHECKER_OBJ) -L $(LIBFTDIR) -lft -o $(BONUS)
	@echo "✅ Compilado: $(BONUS)"

bonus: $(BONUS)

# **************************************************************************** #
#                                   CLEANUP                                    #
# **************************************************************************** #

clean:
	@$(RM) $(PUSH_SWAP_OBJ) $(CHECKER_OBJ)
	@$(MAKE) -C $(LIBFTDIR) clean
	@echo "🧹 Objetos removidos"

fclean: clean
	@$(RM) $(NAME) $(BONUS)
	@$(MAKE) -C $(LIBFTDIR) fclean
	@echo "🧨 Binários removidos"

re: fclean all

# **************************************************************************** #
#                                   UTILS                                      #
# **************************************************************************** #

# Compila arquivos .c individualmente
%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: all clean fclean re bonus
