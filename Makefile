NAME        = push_swap
BONUS       = checker

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -f
INCLUDES    = -I include -I libft/include
LIBFTDIR    = libft
LIBFT       = $(LIBFTDIR)/libft.a

GREEN = \033[1;32m
BLUE  = \033[1;34m
RED   = \033[1;31m
YELLOW  = \033[1;33m
RESET = \033[0m

SRC_DIR     = src/push_swap
BONUS_DIR   = src/checker

COMMON_FILES = \
	ft_add_back.c ft_check_dup.c ft_check_sorted.c ft_error.c \
	ft_free.c ft_parse_args_quoted.c ft_rotate_and_push.c \
	ft_rotate_type.c ft_sort_big.c ft_sort_three.c ft_stack_new.c lst_utils.c \
	lst_utils_2.c operations.c operations_2.c operations_3.c \
	solver_utils_ab.c solver_utils_ba.c ft_exit_error.c algorithm.c

PUSH_SWAP_MAIN = push_swap.c
CHECKER_MAIN   = checker.c
CHECKER_UTILS  = checker_utils.c

PUSH_SWAP_SRC  = $(addprefix $(SRC_DIR)/, $(COMMON_FILES) $(PUSH_SWAP_MAIN))
CHECKER_SRC    = $(addprefix $(SRC_DIR)/, $(COMMON_FILES)) \
				  $(BONUS_DIR)/$(CHECKER_MAIN) \
				  $(BONUS_DIR)/$(CHECKER_UTILS)

PUSH_SWAP_OBJ  = $(PUSH_SWAP_SRC:.c=.o)
CHECKER_OBJ    = $(CHECKER_SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFTDIR) --silent

$(NAME): $(PUSH_SWAP_OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(PUSH_SWAP_OBJ) -L $(LIBFTDIR) -lft -o $(NAME)
	@echo "$(GREEN)✅ Compilado:$(RESET) $(BLUE)$(NAME)$(RESET)"

$(BONUS): $(CHECKER_OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(CHECKER_OBJ) -L $(LIBFTDIR) -lft -o $(BONUS)
	@echo "$(GREEN)✅ Compilado:$(RESET) $(BLUE)$(BONUS)$(RESET)"

bonus: $(BONUS)

clean:
	@$(RM) $(PUSH_SWAP_OBJ) $(CHECKER_OBJ)
	@$(MAKE) -C $(LIBFTDIR) clean --silent
	@echo "$(YELLOW)🧹 Objetos removidos$(RESET)"

fclean: clean
	@$(RM) $(NAME) $(BONUS)
	@$(MAKE) -C $(LIBFTDIR) fclean --silent
	@echo "$(RED)🧨 Binários removidos$(RESET)"

re: fclean all

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: all clean fclean re bonus
