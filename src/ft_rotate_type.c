#include "../include/push_swap.h"

/* Essa função calcula e decide a melhor combinação de rotações
   é a melhor para usar e ordenar a pilha. é claro que, após a rotação
   sempre resta uma operação de push que eu implementei no código.
   essa função sera utilizada durante do push de B para A */
int	ft_rotate_type_ba(t_stack *a, t_stack *b)
{
	int i;
	t_stack *tmp;

	tmp = b;
	i = ft_case_rrarrb_a(a, b, b->nbr);
	while (tmp)
	{
		if (i > ft_case_rarb_a(a, b, tmp->nbr))
			i = ft_case_rarb_a(a, b, tmp->nbr);
		if (i > ft_case_rrarrb_a(a, b, tmp->nbr))
			i = ft_case_rrarrb_a(a, b, tmp->nbr);
		if (i > ft_case_rarrb_a(a, b, tmp->nbr))
			i = ft_case_rarrb_a(a, b, tmp->nbr);
		if (i > ft_case_rrarb_a(a, b, tmp->nbr))
			i = ft_case_rrarb_a(a, b, tmp->nbr);
		tmp = tmp->next;
	}
	return (i);
}

/* Essa função calcula e decide a melhor combinação de rotações
   é a melhor para usar e ordenar a pilha. é claro que, após a rotação
   sempre resta uma operação de push que eu implementei no código.
   essa função sera utilizada durante do push de A para B. */
int	ft_rotate_type_ab(t_stack *a, t_stack *b)
{
	int	i;
	t_stack *tmp;

	tmp = a;
	i = ft_case_rrarrb(a, b, a->nbr);
	while (tmp)
	{
		if (i > ft_case_rarb(a, b, tmp->nbr))
			i = ft_case_rarb(a, b, tmp->nbr);
		if (i > ft_case_rrarrb(a, b, tmp->nbr))
			i = ft_case_rrarrb(a, b, tmp->nbr);
		if (i > ft_case_rarrb(a, b, tmp->nbr))
			i = ft_case_rarrb(a, b, tmp->nbr);
		if (i > ft_case_rrarb(a, b, tmp->nbr))
			i = ft_case_rrarb(a, b, tmp->nbr);
		tmp = tmp->next;
	}
	return (i);
}