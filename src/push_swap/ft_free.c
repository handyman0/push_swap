#include "../../include/push_swap.h"

/* essa função liberta a stack
   1 - verifica se a lista não esta vazia
   2 - percorre a lista zerando e livrando */
void	ft_free(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
