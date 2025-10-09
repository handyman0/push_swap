#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../libft/include/libft.h"

typedef struct s_stack
{
	long    nbr;
	long    index;
	struct s_stack *next;
	struct s_stack *prev;

}    t_stack;

int 	ft_checksorted(t_stack *stack_a);
int 	ft_list_args(char **argv, t_stack **stack_a);
int 	check_args(char **argv);
void    ft_checkdup(t_stack *a);
void    ft_free(t_stack **lst);
void    alpha_checker(char **argv);
void    ft_checkdup(t_stack *a);
void    ft_error(void);
void	ft_freestr(char **lst);
t_stack	*ft_process(int argc, char **argv);
t_stack	*ft_sub_process(char **argv);
t_stack *ft_parse(int argc, char **argv);
t_stack *ft_parse_args_quoted(char **argv);

#endif