/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelo-do <lmelo-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 09:57:09 by lmelo-do          #+#    #+#             */
/*   Updated: 2025/10/21 15:43:01 by lmelo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*
** CONSTRUTOR DE ELEMENTOS - Cria um novo "tijolo" da pilha
**
** Recebe: Um número para armazenar
** Faz: Aloca memória para um novo elemento e guarda o número dentro
** Retorna: O novo elemento pronto para ser adicionado à pilha
** Importante: Se não conseguir memória, retorna NULL (erro tratado depois)
*/
t_stack	*ft_stack_new(int content)
{
	t_stack	*new;

	new = malloc(sizeof (t_stack));
	if (!new)
		return (NULL);
	new->nbr = content;
	new->next = NULL;
	return (new);
}
