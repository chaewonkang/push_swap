/*static void	reverse_rotate(t_stack *stack, int a)
{
}

static void	rotate(t_stack *stack, int a)
{
}*/

static void	push(t_stack *stack, int a)
{
	if (a && LEN_B > 0)
	{
		I = B[0];
		J = -1;
		while (++J + 1 < LEN_B)
			B[J] = B[J + 1];
		LEN_B -= 1;
		J = LEN_A + 1;
		while (--J > 0)
			A[J] = A[J - 1];
		A[0] = I;
		LEN_A += 1;
	}
	else if (!a && LEN_A > 0)
	{
		I = A[0];
		J = -1;
		while (++J + 1 < LEN_A)
			A[J] = A[J + 1];
		LEN_A -= 1;
		J = LEN_B + 1;
		while (--J > 0)
			B[J] = B[J - 1];
		B[0] = I;
		LEN_B += 1;
	}
}

static void	swap(t_stack *stack, int a)
{
	if (a && LEN > 1)
	{
		I = A[0];
		A[0] = A[1];
		A[1] = I;
	}
	else if (!a && LEN_B > 1)
	{
		I = B[0];
		B[0] = B[1];
		B[1] = I;

	}
}

int		get_instructions(char *line, t_stack *stack)
{
	if (ft_strequ(line, "sa") || ft_strequ(line, "ss"))
		swap(stack, 1);
	else if (ft_strequ(line, "sb") || ft_strequ(line, "ss"))
		swap(stack, 0);
	else if (ft_strequ(line, "pa"))
		push(stack, 1);
	else if (ft_strequ(line, "pb"))
		push(stack, 0);
	else if (ft_strequ(line, "ra") || ft_strequ(line, "rr"))
		rotate(stack, 1);
	else if (ft_strequ(line, "rb") || ft_strequ(line, "rr"))
		rotate(stack, 0);
	else if (ft_strequ(line, "rra") || ft_strequ(line, "rrr"))
		reverse_rotate(stack, 1);
	else if (ft_strequ(line, "rrb") || ft_strequ(line, "rrr"))
		reverse_rotate(stack, 2);
	else
		return (0);
	return (1);
}
