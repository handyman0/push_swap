/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelo-do <lmelo-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 09:55:34 by lmelo-do          #+#    #+#             */
/*   Updated: 2025/10/21 14:29:38 by lmelo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*
** Adiciona um novo elemento no FINAL da pilha
** Como adcionar uma pessoal no final da fila
** Se a pilha estiver vazia, o novo elemento se torna o primeiro
** Se já elementos, encontra o último e conecta o novo elemento
*/
void	ft_add_back(t_stack **stack, t_stack *stack_new)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = stack_new;
	else
		(ft_lstlast(*stack))->next = stack_new;
}
