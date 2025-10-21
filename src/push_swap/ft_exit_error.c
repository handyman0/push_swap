/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelo-do <lmelo-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:03:11 by lmelo-do          #+#    #+#             */
/*   Updated: 2025/10/21 14:41:29 by lmelo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*
** Faxineiro de emergência - Limpa tudo antes de sair com erro
** Recebe: pilhas A e B, array temporário (se houver)
** Faz: libera TODA a memória alocada antes de mostrar o erro
** Importante: Evita memory leaks mesmo em caso de erro
*/
static void	ft_free_all(t_stack **a, t_stack **b, char **tmp)
{
	if (tmp)
		ft_free_str_array(tmp);
	if (a)
		ft_free(a);
	if (b)
		ft_free(b);
}

void	ft_exit_error(t_stack **a, t_stack **b, char **tmp)
{
	ft_free_all(a, b, tmp);
	ft_error();
}
