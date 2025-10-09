#include "../include/push_swap.h"

/* rr - ra e rb ao mesmo tempo */
void    ft_rr(t_stack **a, t_stack **b, int j)
{
	t_stack *tmp;

	if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
	tmp = *a;
	*a = ft_lstlast(*a);
	(*a)->next = tmp;
	*a = tmp->next;
	tmp->next = NULL;
	tmp = *b;
	*b = ft_lstlast(*b);
	(*b)->next = tmp;
	*b = tmp->next;
	tmp->next = NULL;
	if (j == 0)
		write(1, "rr\n", 3);
}

/* rrr - rra e rrb ao mesmo tempo */
void    ft_rrr(t_stack **a, t_stack **b, int j)
{
    t_stack tmp;
    
}
