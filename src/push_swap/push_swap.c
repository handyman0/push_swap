/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelo-do <lmelo-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:02:55 by lmelo-do          #+#    #+#             */
/*   Updated: 2025/10/21 16:20:11 by lmelo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*
** PROGRAMA PRINCIPAL PUSH_SWAP - O Ordenador Inteligente
**
** Funcionamento:
** 1. Se não receber argumentos → sai silenciosamente
** 2. Converte argumentos em números e cria a pilha A
** 3. Verifica se há erros (duplicatas, números inválidos)
** 4. Se já estiver ordenado → não faz nada (já está pronto)
** 5. Se não estiver → chama o algoritmo de ordenação
** 6. Libera toda a memória antes de terminar
**
** Exemplos de uso:
**   ./push_swap 2 1 3        # Ordena três números
**   ./push_swap "4 67 3 87"  # Ordena números entre aspas
**   ./push_swap 1 2 3        # Não faz nada (já ordenado)
*/
int	main(int argc, char **argv)
{
	t_stack	*a;

	if (argc == 1)
		return (0);
	a = ft_process(argc, argv);
	if (!a || ft_checkdup(a))
	{
		ft_free(&a);
		ft_error();
	}
	if (!ft_checksorted(a))
		ft_sort(&a);
	ft_free(&a);
	return (0);
}
