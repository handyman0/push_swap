/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_utils_ba.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelo-do <lmelo-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 09:59:17 by lmelo-do          #+#    #+#             */
/*   Updated: 2025/10/21 16:19:50 by lmelo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*
** CALCULADOR DE EFICIÊNCIA - Movimento Duplo para Cima (ra+rb)
**
** Quando: Movendo números da pilha B para A
** Faz: Calcula quantos movimentos seriam necessários rodando
**      AMBAS as pilhas para cima ao mesmo tempo
** Vantagem: Economiza movimentos quando ambas precisam rodar
*/
int	ft_case_rarb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = ft_find_place_a(a, c);
	if (i < ft_find_index(b, c))
		i = ft_find_index(b, c);
	return (i);
}

/*
** CALCULADOR DE EFICIÊNCIA - Movimento Duplo para Baixo (rra+rrb)
**
** Quando: Movendo números da pilha B para A
** Faz: Calcula quantos movimentos seriam necessários rodando
**      AMBAS as pilhas para baixo ao mesmo tempo
** Vantagem: Economiza movimentos quando ambas precisam rodar reverso
*/
int	ft_case_rrarrb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_place_a(a, c))
		i = ft_lstsize(a) - ft_find_place_a(a, c);
	if ((i < (ft_lstsize(b) - ft_find_index(b, c))) && ft_find_index(b, c))
		i = ft_lstsize(b) - ft_find_index(b, c);
	return (i);
}

/*
** CALCULADOR DE EFICIÊNCIA - Movimento Misto (ra+rrb)
**
** Quando: Movendo números da pilha B para A
** Faz: Calcula movimentos rodando A para cima e B para baixo
** Uso: Quando é mais eficiente rodar as pilhas em direções opostas
*/
int	ft_case_rarrb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_index(b, c))
		i = ft_lstsize(b) - ft_find_index(b, c);
	i = ft_find_place_a(a, c) + i;
	return (i);
}

/*
** CALCULADOR DE EFICIÊNCIA - Movimento Misto (rra+rb)
**
** Quando: Movendo números da pilha B para A
** Faz: Calcula movimentos rodando A para baixo e B para cima
** Uso: Quando é mais eficiente rodar as pilhas em direções opostas
*/
int	ft_case_rrarb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_place_a(a, c))
		i = ft_lstsize(a) - ft_find_place_a(a, c);
	i = ft_find_index(b, c) + i;
	return (i);
}
