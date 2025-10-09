#include "../include/push_swap.h"

/* função que retorna o ultimo argumento da pilha */
t_stack *ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/* função que retorna o tamanho da pilha */
int ft_lstsize(t_stack *lst)
{
	size_t i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
/* função que retorna o menor numero da pilha */
int ft_min(t_stack *a)
{
	int i;

	i = a->nbr;
	while (a)
	{
		if (a->nbr < i)
			i = a->nbr;
		a = a->next;
	}
	return (i);
}
/* função que retorna o maior numero da pilha */
int	ft_max(t_stack *a)
{
    int i;

    i = a->nbr;
    while (a)
    {
        if (a->nbr > i)
            i = a->nbr;
        a = a->next;
    }
    return (i);
}