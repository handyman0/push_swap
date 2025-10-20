#include "../../include/push_swap.h"

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

static int	ft_atoi2(const char *str)
{
	int				mod;
	long long int	i;

	i = 0;
	mod = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
	{
		mod = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	if (!*str)
		ft_error();
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error();
		i = i * 10 + (*str - 48);
		str++;
		if ((mod == 1 && i > 2147483647) || (mod == -1 && i > 2147483648))
			ft_error();
	}
	return (mod * i);
}

/*
	1 - essa funcão classifica as pilhas
	2 - ela pega os numeros que esta entre aspas
		por ordem ele coloca um identificador em cada numero
	3 - separa cada um identificando como um inteiro
*/
static t_stack *ft_sub_process(char **argv)
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
	while (tmp[i])
	{
		if (!ft_isnumber(tmp[i]))
			ft_exit_error(&a, NULL, NULL);
		j = ft_atoi2(tmp[i]);
		ft_add_back(&a, ft_stack_new(j));
		i++;
	}
	ft_free_str_array(tmp);
	return (a);
}

/*
Essa função faz tres coisas:
	1 - Checa se o numero de argumentos é menor que 2
	2 - Checa se o numero de argumentos é igual a 2
		se for, isso signfica que é uma string.
		e chama outra função de sub_process
	3 - Se for maior que 2
		ela lista os argumentos
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
