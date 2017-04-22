static void	reverse_rotate(t_stack *stack, int which)
{
}

static void	rotate(t_stack *stack, int which)
{
}

static void	push(t_stack *stack, int which)
{
}

static void	swap(t_stack *stack, int which)
{

}

int		get_instructions(char *line, t_stack *stack)
{
	if (ft_strequ(line, "sa") || ft_strequ(line, "ss"))
		swap(stack, 1);
	else if (ft_strequ(line, "sb") || ft_strequ(line, "ss"))
		swap(stack, 2);
	else if (ft_strequ(line, "pa"))
		push(stack, 1);
	else if (ft_strequ(line, "pb"))
		push(stack, 2);
	else if (ft_strequ(line, "ra") || ft_strequ(line, "rr"))
		rotate(stack, 1);
	else if (ft_strequ(line, "rb") || ft_strequ(line, "rr"))
		rotate(stack, 2);
	else if (ft_strequ(line, "rra") || ft_strequ(line, "rrr"))
		reverse_rotate(stack, 1);
	else if (ft_strequ(line, "rrb") || ft_strequ(line, "rrr"))
		reverse_rotate(stack, 2);
	else
		return (0);
	return (1);
}
