#include "../include/push_swap.h"

/* função que livra a string entre os valores citados */
void    ft_freestr(char **lst)
{
	char    *n1;

	if (!lst)
		return ;
	while (*str)
	{
		n1 = *lst;
		lst++;
		free(n1);
	}
	*lst = NULL;
}

/* 
	função para separar os argumentos passados entre aspas
	e envialos para a função list_args para adicionar na lista
	com ft_split, separamos numeros de espaços.
*/
t_stack *ft_parse_args_quoted(char **argv)
{
	t_stack *stack_a;
	char    **tmp;
	int		i;
	int		j;

	stack_a = NULL;
	i = 0;
	tmp = ft_split(argv[1], 32);
	list_args(tmp, &stack_a);
	ft_freestr(tmp);
	free(tmp);
	return (stack_a);	
}