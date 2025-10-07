#include "../include/push_swap.h"

/* essa função liberta a stack
   1 - verifica se a lista não esta vazia
   2 - percorre a lista zerando e livrando */
void    ft_free(t_stack **lst)
{
	t_stack tmp;
	if (!lst)
		return ;
	while (lst)
	{
		tmp = (*lst)->next;
		(*lst)->nbr = 0;
		free(*lst);
		(*lst) = tmp;
	}
}