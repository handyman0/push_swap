/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelo-do <lmelo-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 09:52:36 by lmelo-do          #+#    #+#             */
/*   Updated: 2025/10/21 14:44:32 by lmelo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*
** Limpador de pilhas - O coletor de lixo
** Recebe: uma pilha (A ou B)
** Faz: Percorre toda a pilha liberando cada elemento da memoria
** Importante: usado no final do programa e em casos de erro
*/
void	ft_free(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
