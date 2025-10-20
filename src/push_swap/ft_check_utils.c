#include "../../include/push_swap.h"

// Checa se o caracter é negativo
int	sign(int c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

// checa se o caracter é um digito
int	digit(int c)
{
	if ((c >= 48) && (c <= 57))
		return (1);
	return (0);
}

// checa se o caracter é um espaço
int	space(int c)
{
	if (c == 32)
		return (1);
	return (0);
}

// Função que checa se o argumento é valido
int	check_error(char **argv, int i, int j)
{
	while (argv[i])
	{
		j = 0;
		while ((argv[i][j] != '\0'))
		{
			if (sign(argv[i][j]))
			{
				j++;
				if (!digit(argv[i][j]))
					return (false);
			}
			else if (digit(argv[i][j]))
			{
				j++;
				if (argv[i][j] == '\0')
					break ;
				if (!digit(argv[i][j]) && !space(argv[i][j]))
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}
