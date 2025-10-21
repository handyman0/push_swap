/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelo-do <lmelo-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:01:38 by lmelo-do          #+#    #+#             */
/*   Updated: 2025/10/21 14:10:00 by lmelo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*
** Verificador de números - O porteiro da festa
** Recebe: uma string qualquer
** Faz: Verifica se é um numero valido (com ou sem sinal)
** Exemplo: "123" OK, "-456" OK, "12a3" KO, "" KO
*/
static int	ft_isnumber(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
/*
** Conversor seguro de string para número
** Recebe: string número
** Faz: Converte para inteiro verificando limites e caracteres
** Importante: Rejeita números fora do range -2147483648 a 2147483647
** Diferença do atoi normal: GERA ERRO se algo estiver errado
*/
static int	ft_atoi2(const char *str)
{
	int				mod;
	long long int	i;

	i = 0;
	mod = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			mod = -1;
		str++;
	}
	if (!*str)
		ft_error();
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error();
		i = i * 10 + (*str++ - 48);
		if ((mod == 1 && i > 2147483647) || (mod == -1 && i > 2147483648))
			ft_error();
	}
	return (mod * i);
}

/*
** Processa os argumentos entre aspas - O desembaçador
** Recebe: argumentos do programa (onde argv[1] é a string com numero)
** Faz: separa os números por espaço e cria a pilha A
** Exemplo: "./push_swap '4 67 3 87 23'" → pilha com 5 números
*/
static t_stack	*ft_sub_process(char **argv)
{
	t_stack	*a;
	char	**tmp;
	int		i;
	int		j;

	a = NULL;
	tmp = ft_split(argv[1], 32);
	if (!tmp)
		ft_exit_error(&a, NULL, NULL);
	i = 0;
	if (tmp)
	{
		while (tmp[i] != NULL)
		{
			if (!ft_isnumber(tmp[i]))
				ft_exit_error(&a, NULL, tmp);
			j = ft_atoi2(tmp[i]);
			ft_add_back(&a, ft_stack_new(j));
			i++;
		}
		ft_free_str_array(tmp);
	}
	return (a);
}

/*
** Gerenciador Principal de Argumentos
**
** Funciona como um diretor de trafego que decide:
** 	1. Se recebeu apenas 1 argumento -> string entre aspas
**		Exemplo: "./push_swap '4 67 3'"
** 	2. Se recebeu apenas 1 argumento -> lista normal
** 		Exemplo: "./push_swap 4 67 3"
**
** Importante: Sempre verifica cada número antes de adicionar à pilha.
*/
t_stack	*ft_process(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		j;

	i = 1;
	a = NULL;
	if (argc < 2)
		return (NULL);
	if (argc == 2)
		a = ft_sub_process(argv);
	else
	{
		while (i < argc)
		{
			if (!ft_isnumber(argv[i]))
				ft_exit_error(&a, NULL, NULL);
			j = ft_atoi2(argv[i]);
			ft_add_back(&a, ft_stack_new(j));
			i++;
		}
	}
	return (a);
}
