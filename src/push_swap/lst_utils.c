/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelo-do <lmelo-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 09:56:18 by lmelo-do          #+#    #+#             */
/*   Updated: 2025/10/21 15:44:33 by lmelo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*
** ENCONTRA O FINAL - Procura o último elemento da pilha
** Como: Encontrar a última pessoa de uma fila
** Recebe: Primeiro elemento da pilha
** Retorna: O último elemento (ou NULL se vazia)
*/
t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*
** CONTADOR - Calcula quantos elementos tem na pilha
** Recebe: Primeiro elemento da pilha
** Retorna: Número total de elementos
*/
int	ft_lstsize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

/*
** DETECTOR DE MÍNIMO - Encontra o menor número da pilha
** Como: Procurar a pessoa mais baixa de um grupo
** Recebe: Pilha de números
** Retorna: O menor valor encontrado
*/
int	ft_min(t_stack *a)
{
	int		i;

	i = a->nbr;
	while (a)
	{
		if (a->nbr < i)
			i = a->nbr;
		a = a->next;
	}
	return (i);
}

/*
** DETECTOR DE MÁXIMO - Encontra o maior número da pilha
** Como: Procurar a pessoa mais alta de um grupo
** Recebe: Pilha de números
** Retorna: O maior valor encontrado
*/
int	ft_max(t_stack *a)
{
	int		i;

	i = a->nbr;
	while (a)
	{
		if (a->nbr > i)
			i = a->nbr;
		a = a->next;
	}
	return (i);
}
