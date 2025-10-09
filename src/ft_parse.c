#include "../include/push_swap.h"

/* 
	Essa função faz tres coisas:
		1. verifica se o numero de input é menor que 2
		2. verifica se o numero de input é igual a 2
			se for, significa que é um string entre aspas
		3. verifica se o numero de input é maior que 2
			se for, significa que é uma lista de argumentos
*/
t_stack *ft_parse(int argc, char **argv)
{
	t_stack *stack_a;
	int i;
	int j;

	i = 1;
	stack_a = NULL;
	if (argc < 2)
		ft_error();
	else if (argc == 2)
		stack_a = ft_parse_args_quoted(argv);
	else
		list_args(argv, &stack_a);
	return (stack_a);
}