/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelo-do <lmelo-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:08:19 by lmelo-do          #+#    #+#             */
/*   Updated: 2025/10/21 13:45:11 by lmelo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
/*
** Como um tradutor de comandos para as pilhas
** Recebe: linha do comando, pilhas A e B
** Faz: Identifica qual operação foi pedida e executa nas pilhas
** Exemplo: Se ler "sa" -> esxecuta swap na pilha A
*/
static void	ft_check_sub(t_stack **a, t_stack **b, const char *line)
{
	if (line[2] == 'a')
		ft_rra(a, 1);
	else if (line[2] == 'b')
		ft_rrb(b, 1);
	else if (line[2] == 'r')
		ft_rrr(a, b, 1);
}

/*
** O cerebro do checker - decodifica cada comando
** Recebe: linha de comando, pilhas A e B
** Faz: Lê como "sa", "pb", "rrr" e chama a operação correta
** Importante: O '1' no final significa "não imprimir o comando"
*/
static char	*ft_check(t_stack **a, t_stack **b, const char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		ft_sa(a, 1);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		ft_sb(b, 1);
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		ft_pa(a, b, 1);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		ft_pb(a, b, 1);
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		ft_ra(a, 1);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		ft_rb(b, 1);
	else if (line[0] == 'r' && line[1] == 'r' && line[3] == '\n')
		ft_check_sub(a, b, line);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		ft_rr(a, b, 1);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		ft_ss(a, b, 1);
	else
		ft_error_ch();
	return (get_next_line(0));
}

/*
** O motor principal do checker
** Recebe: pilhas A e B, primeira linha de comando
** Faz: Processa todos os comandos sequencialmente
**		1. Executa cada comando nas pilhas.
**		2. Verifica se a pilha A ficou ordenada.
**		3. Verifica se a pilha B está vazia.
** Resultado: "OK" se estiver correto, "KO" se houve erro.
*/
static void	ft_checker_sub(t_stack **a, t_stack **b, char *line)
{
	char	*tmp;

	while (line && *line != '\n')
	{
		tmp = line;
		line = ft_check(a, b, line);
		free(tmp);
	}
	if (*b)
		write(1, "KO\n", 3);
	else if (!ft_checksorted(*a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free(line);
}

/*
** PROGRAMA CHECKER
**
** Funcionamento:
** 		1. Lê numeros e cria a pilha A inicial.
** 		2. Aguarda comandos do usuario (do push_swap ou digitados).
** 		3. Executa cada comando nas pilhas A e B.
** 		4. Verifica o resultado final.
**
** Exemplo de uso:
**		./push_swap 2 1 3 | ./checker 2 1 3
**		↑ gera comandos		↑ verifica se funcionou
**
** Resultados:
**		"OK" - Pilha A ordenada e Pilha B vazia
**		"KO" - algo deu errado
*/
int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	if (argc == 1)
		return (0);
	b = NULL;
	a = ft_process(argc, argv);
	if (!a || ft_checkdup(a))
	{
		ft_free (&a);
		ft_error_ch();
		return (1);
	}
	line = get_next_line(0);
	if (!line && !ft_checksorted(a))
		write(1, "KO\n", 3);
	else if (!line && ft_checksorted(a))
		write(1, "OK\n", 3);
	else
		ft_checker_sub(&a, &b, line);
	ft_free(&b);
	ft_free(&a);
	return (0);
}
