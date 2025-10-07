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

void    ft_checkdup(t_stack *a);
t_stack	*ft_sub_process(char **argv);
t_stack	*ft_process(int argc, char **argv);
void    ft_free(t_stack **lst);

#endif