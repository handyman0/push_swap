#include "../../include/push_swap.h"

/* função que livra a string entre os valores citados */
void	ft_free_str_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

/*
	função para separar os argumentos passados entre aspas
	e envialos para a função list_args para adicionar na lista
	com ft_split, separamos numeros de espaços.
*/
t_stack *ft_parse_args_quoted(char **argv)
{
	t_stack *stack_a;
	char	**tmp;

	stack_a = NULL;
	tmp = ft_split(argv[1], 32);
	list_args(tmp, &stack_a);
	ft_free_str_array(tmp);
	return (stack_a);
}
