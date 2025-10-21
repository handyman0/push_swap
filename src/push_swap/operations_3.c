/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelo-do <lmelo-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 09:54:51 by lmelo-do          #+#    #+#             */
/*   Updated: 2025/10/21 15:45:43 by lmelo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*
** ROTAÇÃO DA PILHA B - Move todos os elementos um passo para cima
** Como: Passar um documento do topo da pilha para o final
** Recebe: Pilha B, flag para imprimir comando
** Faz: O primeiro elemento vai para o final da pilha
** Exemplo: [10, 20, 30] → [20, 30, 10]
*/
void	ft_rb(t_stack **b, int j)
{
	t_stack	*tmp;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = ft_lstlast(*b);
	(*b)->next = tmp;
	*b = tmp->next;
	tmp->next = NULL;
	if (j == 0)
		write(1, "rb\n", 3);
}

/*
** TROCA NA PILHA B - Inverte os dois primeiros elementos
** Como: Trocar a ordem das duas primeiras cartas de um baralho
** Recebe: Pilha B, flag para imprimir comando
** Faz: Primeiro e segundo elementos trocam de lugar
** Exemplo: [10, 20, 30] → [20, 10, 30]
*/
void	ft_sb(t_stack **b, int j)
{
	t_stack	*tmp;

	if (!*b || !((*b)->next))
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	if (j == 0)
		write(1, "sb\n", 3);
}
