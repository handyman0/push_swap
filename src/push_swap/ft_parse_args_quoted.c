/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args_quoted.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelo-do <lmelo-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 09:58:29 by lmelo-do          #+#    #+#             */
/*   Updated: 2025/10/21 15:17:57 by lmelo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*
** Limpador de arrays de strings - O especialista em limpeza dupla
** Recebe: um array de strings (como ["1", "2", "3" ])
** Faz: Libera cada string individualmente e depois o array principal
** Usado para: limpar resultado do ft_split (números entre aspas)
*/
void	ft_free_str_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
