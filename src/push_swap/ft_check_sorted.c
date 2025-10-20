#include "../../include/push_swap.h"

/* Essa função checa se a pilha está ordenada */
int	ft_checksorted(t_stack *stack_a)
{
	int	i;

	if (!stack_a)
		return (1);
	i = stack_a->nbr;
	while (stack_a)
	{
		if (i > stack_a->nbr)
			return (0);
		i = stack_a->nbr;
		stack_a = stack_a->next;
	}
	return (1);
}
