/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelo-do <lmelo-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 09:56:28 by lmelo-do          #+#    #+#             */
/*   Updated: 2025/10/21 14:38:58 by lmelo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*
** Gerenciador de erros - O alarme do sistema
** Faz: Imprime "Error" na tela e parao programa imediatamente
** Usado quando: números invalidos, duplicatas, comandos errados
*/
void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
