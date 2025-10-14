#include "../../include/push_swap.h"

// Essa função é a segunda parte da função ft_check.
static void	*ft_check_sub(t_stack **a, t_stack **b, char *line)
{
	if (line[2] == 'a')
		ft_rra(a, 1);
	else if (line[2] == 'b')
		ft_rrb(b, 1);
	else if (line[2] == 'r')
		ft_rrr(a, b, 1);
}

// Essa função lê as linhas e verifica se o comando é válido.
// Se for válido, executa o comando na pilha correspondente.
static char	*ft_check(t_stack **a, t_stack **b, char *line)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		ft_sa(a, 1);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		ft_sb(b, 1);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		ft_pa(a, b, 1);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		ft_pb(a, b, 1);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		ft_ra(a, 1);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		ft_rb(b, 1);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		ft_rr(a, b, 1);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ft_ss(a, b, 1);
	else
		ft_error_ch();
	return (get_next_line(0));
}

// Essa função checa a validade dos comandos e das pilhas.
// Se for valido, e a pilha A estiver ordenada, o programa escreve "OK".
// Se a pilha A não estiver ordenada, escreve "KO".
static void	*ft_checker_sub(t_stack **a, t_stack **b, char *line)
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
	else if (ft_checksorted(*a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free(line);
}

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	char	*line;

	b = NULL;
	a = ft_process(argc, argv);
	if (!a || ft_checkdup(a))
	{
		ft_free(&a);
		ft_error_ch();
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
