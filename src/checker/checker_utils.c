/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelo-do <lmelo-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 09:51:25 by lmelo-do          #+#    #+#             */
/*   Updated: 2025/10/21 12:40:59 by lmelo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
/* função de erro para o checker */
void	ft_error_ch(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
