#include "../../include/push_swap.h"

// Cria um novo nó na pilha com o numero dado
t_stack	*ft_stack_new(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nbr = content;
	new->next = NULL;
	return (new);
}
