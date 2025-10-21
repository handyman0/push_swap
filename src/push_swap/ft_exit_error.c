/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelo-do <lmelo-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:03:11 by lmelo-do          #+#    #+#             */
/*   Updated: 2025/10/21 10:03:12 by lmelo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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
