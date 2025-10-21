/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelo-do <lmelo-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:00:30 by lmelo-do          #+#    #+#             */
/*   Updated: 2025/10/21 14:36:03 by lmelo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*
** Verificador de ordem - O organizador perfeccionista
** Recebe: uma pilha de números
** Faz: Verifica se os números estão em ordem crescente (do menor para o maior)
** Retorna: 1 se estiver ordenada, 0 se estiver desordenada
** Exemplo: [1, 2, 3, 4] -> OK, [1, 3, 2, 4] -> KO
*/
int	ft_checksorted(t_stack *stack_a)
{
	int	i;

	if (!stack_a)
		return (1);
	i = stack_a->nbr;
	while (stack_a)
	{
		if (i > stack_a->nbr)
			return (0);
		i = stack_a->nbr;
		stack_a = stack_a->next;
	}
	return (1);
}
