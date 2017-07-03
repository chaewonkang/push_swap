#include "../includes/push_swap.h"

int				next_target(int *st, int len, int target, int comp)
{
	int			i;

	i = -1;
	if (comp == 1)
	{
		while (++i < len)
		{
			if (st[i] < target)
				return (i);
		}
	}
	else if (comp == 2)
	{
		while (++i < len)
		{
			if (st[i] == target)
				return (i);
		}
	}
	else if (comp == 3)
	{
		while (++i < len)
		{
			if (st[i] > target)
				return (i);
		}
	}
	return (-1);
}
