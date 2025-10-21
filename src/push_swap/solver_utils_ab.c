/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_utils_ab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelo-do <lmelo-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 09:56:50 by lmelo-do          #+#    #+#             */
/*   Updated: 2025/10/21 16:18:08 by lmelo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*
** CALCULADOR DE EFICIÊNCIA - Movimento Duplo para Cima (ra+rb)
**
** Quando: Movendo números da pilha A para B
** Faz: Calcula quantos movimentos seriam necessários rodando
**      AMBAS as pilhas para cima ao mesmo tempo
** Vantagem: Economiza movimentos quando ambas precisam rodar
*/
int	ft_case_rarb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = ft_find_place_b(b, c);
	if (i < ft_find_index(a, c))
		i = ft_find_index(a, c);
	return (i);
}

/*
** CALCULADOR DE EFICIÊNCIA - Movimento Duplo para Baixo (rra+rrb)
**
** Quando: Movendo números da pilha A para B
** Faz: Calcula quantos movimentos seriam necessários rodando
**      AMBAS as pilhas para baixo ao mesmo tempo
** Vantagem: Economiza movimentos quando ambas precisam rodar reverso
*/
int	ft_case_rrarrb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_place_b(b, c))
		i = ft_lstsize(b) - ft_find_place_b(b, c);
	if ((i < (ft_lstsize(a) - ft_find_index(a, c))) && ft_find_index(a, c))
		i = ft_lstsize(a) - ft_find_index(a, c);
	return (i);
}

/*
** CALCULADOR DE EFICIÊNCIA - Movimento Misto (ra+rrb)
**
** Quando: Movendo números da pilha A para B
** Faz: Calcula movimentos rodando A para cima e B para baixo
** Uso: Quando é mais eficiente rodar as pilhas em direções opostas
*/
int	ft_case_rrarb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_index(a, c))
		i = ft_lstsize(a) - ft_find_index(a, c);
	i = ft_find_place_b(b, c) + i;
	return (i);
}

/*
** CALCULADOR DE EFICIÊNCIA - Movimento Misto (rra+rb)
**
** Quando: Movendo números da pilha A para B
** Faz: Calcula movimentos rodando A para baixo e B para cima
** Uso: Quando é mais eficiente rodar as pilhas em direções opostas
*/
int	ft_case_rarrb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_place_b(b, c))
		i = ft_lstsize(b) - ft_find_place_b(b, c);
	i = ft_find_index(a, c) + i;
	return (i);
}
