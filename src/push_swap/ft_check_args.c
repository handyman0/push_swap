#include "../../include/push_swap.h"

void	alpha_check(char **argv)
{
	int i;
	int j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (ft_isalpha(argv[i][j]))
				ft_error();
			j++;
		}
		i++;
	}
}

int	check_args(char **argv)
{
	alpha_checker(argv);
	if (!check_error(argv, 1, 0))
		return (false);
	return (true);
}
