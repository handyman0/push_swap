#include "../include/push_swap.h"

/*  Essa função calcula a quantidade de rotações necessárias.
	Os calculos são feitos para o caso ra+rb */
int ft_case_rarb(t_stack *a, t_stack *b, int c)
{
	int i;

	i = ft_find_place_a(b, c);
	if (i < ft_find_index(a, c))
		i = ft_find_index(a, c);
	return (i);
}

/*  Essa função calcula a quantidade de rotações necessárias.
    Os calculos são feitos para o caso rra+rrb */
int ft_case_rrarrb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_place_a(b, c))
		i = ft_lstsize(b) - ft_find_place_a(b, c);
	if ((i < (ft_lstsize(a) - ft_find_index(a, c))) && ft_find_index(a, c))
		i = ft_lstsize(a) - ft_find_index(a, c);
	return (i);
}

/*  Essa função calcula a quantidade de rotações necessárias.
    Os calculos são feitos para o caso ra+rrb */
int ft_case_rarrb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_place_a(a, c))
		i = ft_lstsize(a) - ft_find_place_a(a, c);
	i = ft_find_place_a(b, c) + i;
	return (i);
}

/*  Essa função calcula a quantidade de rotações necessárias.
    Os calculos são feitos para o caso rra+rb */
int ft_case_rrarb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_place_a(b, c))
		i = ft_lstsize(b) - ft_find_place_a(b, c);
	i = ft_find_place_a(a, c) + i;
	return (i);
}
