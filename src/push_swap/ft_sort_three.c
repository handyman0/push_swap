/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelo-do <lmelo-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:00:14 by lmelo-do          #+#    #+#             */
/*   Updated: 2025/10/21 15:42:33 by lmelo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*
** ESPECIALISTA EM 3 NÚMEROS - Resolve o caso mais simples
**
** Recebe: Pilha A com exatamente 3 números
** Faz: Analisa as posições e aplica a sequência mínima de movimentos
** Caso 1: Menor número no topo → Rotaciona pra baixo + Troca
** Caso 2: Maior número no topo → Rotaciona pra cima + (Troca se necessário)
** Caso 3: Número do meio no topo → Decide baseado na posição do maior
*/
void	ft_sort_three(t_stack **stack_a)
{
	if (ft_min(*stack_a) == (*stack_a)->nbr)
	{
		ft_rra(stack_a, 0);
		ft_sa(stack_a, 0);
	}
	else if (ft_max(*stack_a) == (*stack_a)->nbr)
	{
		ft_ra(stack_a, 0);
		if (!ft_checksorted(*stack_a))
			ft_sa(stack_a, 0);
	}
	else
	{
		if (ft_find_index(*stack_a, ft_max(*stack_a)) == 1)
			ft_rra(stack_a, 0);
		else
			ft_sa(stack_a, 0);
	}
}
