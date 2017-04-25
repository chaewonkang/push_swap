#include "../includes/push_swap.h"

static void	reverse_rotate(t_stack *env, int *st, int len)
{
	int	i;
	int	j;

	if (len > 1)
	{
		i = st[len - 1];
		j = len;
		while (--j > 0)
			st[j] = st[j - 1];
		st[j] = i;
	}
	OP_OK = 1;
}

static void	rotate(t_stack *env, int *st, int len)
{
	int	i;
	int	j;

	if (len > 1)
	{
		i = st[0];
		j = -1;
		while (++j + 1 < len)
			st[j] = st[j + 1];
		st[j] = i;
	}
	OP_OK = 1;
}

static void	push(int *st1, int *st2, int *len1, int *len2)
{
	int	i;
	int	j;

	if (*len2 > 0)
	{
		i = st2[0];
		j = -1;
		while (++j + 1 < *len2)
			st2[j] = st2[j + 1];
		*len2 -= 1;
		j = *len1 + 1;
		while (--j > 0)
			st1[j] = st1[j - 1];
		st1[0] = i;
		*len1 += 1;
	}
}

static void	swap(t_stack *env, int *tab, int len)
{
	int	i;

	if (len > 1)
	{
		i = tab[0];
		tab[0] = tab[1];
		tab[1] = i;
	}
	OP_OK = 1;
}

int		get_operations(char *line, t_stack *env)
{
	if (ft_strequ(line, "sa") || ft_strequ(line, "ss"))
		swap(env, A, LEN_A);
	if (ft_strequ(line, "sb") || ft_strequ(line, "ss"))
		swap(env, B, LEN_B);
	else if (ft_strequ(line, "pa") && (OP_OK = 1))
		push(A, B, &LEN_A, &LEN_B);
	else if (ft_strequ(line, "pb") && (OP_OK = 1))
		push(B, A, &LEN_B, &LEN_A);
	else if (ft_strequ(line, "ra") || ft_strequ(line, "rr"))
		rotate(env, A, LEN_A);
	if (ft_strequ(line, "rb") || ft_strequ(line, "rr"))
		rotate(env, B, LEN_B);
	else if (ft_strequ(line, "rra") || ft_strequ(line, "rrr"))
		reverse_rotate(env, A, LEN_A);
	if (ft_strequ(line, "rrb") || ft_strequ(line, "rrr"))
		reverse_rotate(env, B, LEN_B);
	if (!OP_OK)
		return (0);
	return (1);
}
