#include "../include/push_swap.h"

/* função que ordena se foram passados 3 argumentos */
void    ft_sort_three(t_stack **stack_a)
{
	if (first > second && second < third && first < third)
		sa(stack_a);
	else if (first > second && second > third && first > third)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first > second && second < third && first > third)
		ra(stack_a);
	else if (first < second && second > third && first < third)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (first < second && second > third && first > third)
		rra(stack_a);
}