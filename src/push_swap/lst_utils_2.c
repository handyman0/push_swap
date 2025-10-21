/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelo-do <lmelo-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:00:53 by lmelo-do          #+#    #+#             */
/*   Updated: 2025/10/21 16:02:47 by lmelo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*
** LOCALIZADOR DE POSIÇÃO - Encontra a posição de um número na pilha
**
** Recebe: Pilha e número a ser encontrado
** Faz: Percorre a pilha contando a posição até encontrar o número
** Retorna: A posição (índice) do número, ou -1 se não encontrado
*/
int	ft_find_index(t_stack *a, int nbr)
{
	int		i;

	i = 0;
	while (a->nbr != nbr)
	{
		i++;
		a = a->next;
	}
	a->index = 0;
	return (i);
}

/*
** CALCULADOR DE POSIÇÃO NA PILHA B - Onde colocar um número em B
**
** Recebe: Pilha B e número a ser inserido
** Faz: Calcula a posição ideal para manter B ordenada de forma decrescente
** Retorna: A posição onde o número deve ser inserido
** Lógica: B deve estar ordenada em ordem decrescente para eficiência
*/
int	ft_find_place_b(t_stack *stack_b, int nbr_push)
{
	int				i;
	const t_stack	*tmp;

	i = 1;
	if (nbr_push > stack_b->nbr && nbr_push < ft_lstlast(stack_b)->nbr)
		i = 0;
	else if (nbr_push > ft_max(stack_b) || nbr_push < ft_min(stack_b))
		i = ft_find_index(stack_b, ft_max(stack_b));
	else
	{
		tmp = stack_b->next;
		while (stack_b->nbr < nbr_push || tmp->nbr > nbr_push)
		{
			stack_b = stack_b->next;
			tmp = stack_b->next;
			i++;
		}
	}
	return (i);
}

/*
** CALCULADOR DE POSIÇÃO NA PILHA A - Onde colocar um número em A
**
** Recebe: Pilha A e número a ser inserido
** Faz: Calcula a posição ideal para manter A ordenada de forma crescente
** Retorna: A posição onde o número deve ser inserido
** Lógica: A deve estar ordenada em ordem crescente (objetivo final)
*/
int	ft_find_place_a(t_stack *stack_a, int nbr_push)
{
	int				i;
	const t_stack	*tmp;

	i = 1;
	if (nbr_push < stack_a->nbr && nbr_push > ft_lstlast(stack_a)->nbr)
		i = 0;
	else if (nbr_push > ft_max(stack_a) || nbr_push < ft_min(stack_a))
		i = ft_find_index(stack_a, ft_min(stack_a));
	else
	{
		tmp = stack_a->next;
		while (stack_a->nbr > nbr_push || tmp->nbr < nbr_push)
		{
			stack_a = stack_a->next;
			tmp = stack_a->next;
			i++;
		}
	}
	return (i);
}
