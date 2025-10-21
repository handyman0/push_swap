/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelo-do <lmelo-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:03:04 by lmelo-do          #+#    #+#             */
/*   Updated: 2025/10/21 16:06:23 by lmelo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*
** ROTAÇÃO DUPLA - Move ambas as pilhas para cima simultaneamente
**
** Como: Dois elevadores subindo ao mesmo tempo
** Recebe: Pilhas A e B, flag para imprimir comando
** Faz: Executa 'ra' e 'rb' ao mesmo tempo (economiza movimentos)
*/
void	ft_rr(t_stack **a, t_stack **b, int j)
{
	t_stack	*tmp;

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

/*
** AUXILIAR DE ROTAÇÃO DUPLA REVERSA - Roda a pilha B para baixo
**
** Função auxiliar para ft_rrr - faz a parte da pilha B
*/
static void	ft_rrr_sub(t_stack **b, int j)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *b;
	while ((*b)->next)
	{
		i++;
		*b = (*b)->next;
	}
	(*b)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (j == 0)
		write(1, "rrr\n", 4);
}

/*
** ROTAÇÃO DUPLA REVERSA - Move ambas as pilhas para baixo simultaneamente
**
** Como: Dois elevadores descendo ao mesmo tempo
** Recebe: Pilhas A e B, flag para imprimir comando
** Faz: Executa 'rra' e 'rrb' ao mesmo tempo (economiza movimentos)
*/
void	ft_rrr(t_stack **a, t_stack **b, int j)
{
	t_stack	*tmp;
	int		i;

	if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
	i = 0;
	tmp = *a;
	while ((*a)->next)
	{
		i++;
		*a = (*a)->next;
	}
	(*a)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	ft_rrr_sub(b, j);
}

/*
** EMPURRA PARA B - Move o topo da pilha A para o topo da pilha B
**
** Como: Passar um objeto da mão esquerda para a direita
** Recebe: Pilhas A e B, flag para imprimir comando
** Faz: Remove o primeiro elemento de A e coloca como primeiro de B
*/
void	ft_pb(t_stack **stack_a, t_stack **stack_b, int j)
{
	t_stack	*tmp;

	if (!*stack_a)
		return ;
	tmp = *stack_b;
	*stack_b = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_b)->next = tmp;
	if (j == 0)
		write(1, "pb\n", 3);
}

/*
** ROTAÇÃO REVERSA DA PILHA B - Move todos os elementos um passo para baixo
**
** Como: Passar um documento do final da pilha para o topo
** Recebe: Pilha B, flag para imprimir comando
** Faz: O último elemento vai para o topo da pilha
** Exemplo: [10, 20, 30] → [30, 10, 20]
*/
void	ft_rrb(t_stack **b, int j)
{
	t_stack	*tmp;
	int		i;

	if (!*b || !(*b)->next)
		return ;
	i = 0;
	tmp = *b;
	while ((*b)->next)
	{
		i++;
		*b = (*b)->next;
	}
	(*b)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (j == 0)
		write(1, "rrb\n", 4);
}
