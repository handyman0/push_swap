/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelo-do <lmelo-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:07:05 by lmelo-do          #+#    #+#             */
/*   Updated: 2025/10/21 16:08:24 by lmelo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*
** ROTAÇÃO DA PILHA A - Move todos os elementos um passo para cima
**
** Como: Passar um documento do topo da pilha para o final
** Recebe: Pilha A, flag para imprimir comando
** Faz: O primeiro elemento vai para o final da pilha
** Exemplo: [10, 20, 30] → [20, 30, 10]
*/
void	ft_ra(t_stack **a, int j)
{
	t_stack	*tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = ft_lstlast(*a);
	(*a)->next = tmp;
	*a = tmp->next;
	tmp->next = NULL;
	if (j == 0)
		write(1, "ra\n", 3);
}

/*
** TROCA NA PILHA A - Inverte os dois primeiros elementos
**
** Como: Trocar a ordem das duas primeiras cartas de um baralho
** Recebe: Pilha A, flag para imprimir comando
** Faz: Primeiro e segundo elementos trocam de lugar
** Exemplo: [10, 20, 30] → [20, 10, 30]
*/
void	ft_sa(t_stack **a, int j)
{
	t_stack	*tmp;

	if (!*a || !((*a)->next))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	if (j == 0)
		write(1, "sa\n", 3);
}

/*
** EMPURRA PARA A - Move o topo da pilha B para o topo da pilha A
**
** Como: Passar um objeto da mão direita para a esquerda
** Recebe: Pilhas A e B, flag para imprimir comando
** Faz: Remove o primeiro elemento de B e coloca como primeiro de A
*/
void	ft_pa(t_stack **a, t_stack **b, int j)
{
	t_stack	*tmp;

	if (!*b)
		return ;
	tmp = *a;
	*a = *b;
	*b = (*b)->next;
	(*a)->next = tmp;
	if (j == 0)
		write(1, "pa\n", 3);
}

/*
** ROTAÇÃO REVERSA DA PILHA A - Move todos os elementos um passo para baixo
**
** Como: Passar um documento do final da pilha para o topo
** Recebe: Pilha A, flag para imprimir comando
** Faz: O último elemento vai para o topo da pilha
** Exemplo: [10, 20, 30] → [30, 10, 20]
*/
void	ft_rra(t_stack **a, int j)
{
	t_stack	*tmp;
	int		i;

	if (!*a || !(*a)->next)
		return ;
	i = 0;
	tmp = *a;
	while ((*a)->next)
	{
		*a = (*a)->next;
		i++;
	}
	(*a)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (j == 0)
		write(1, "rra\n", 4);
}

/*
** TROCA DUPLA - Inverte os dois primeiros elementos de AMBAS as pilhas
**
** Como: Trocar as primeiras cartas de dois baralhos ao mesmo tempo
** Recebe: Pilhas A e B, flag para imprimir comando
** Faz: Executa 'sa' e 'sb' simultaneamente (economiza movimentos)
*/
void	ft_ss(t_stack **a, t_stack **b, int j)
{
	t_stack	*tmp;

	if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	if (j == 0)
		write(1, "ss\n", 3);
}
