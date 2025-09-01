/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuukiishino <yuukiishino@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:49:43 by yuukiishino       #+#    #+#             */
/*   Updated: 2025/09/01 23:30:07 by yuukiishino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_safe(const char *str, t_node *head)
{
	int		sign;
	long	result;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		if (sign == 1 && result > (INT_MAX - (*str - '0')) / 10)
			error_free_exit(head);
		if (sign == -1 && result > ((-(long)INT_MIN - (*str - '0')) / 10))
			error_free_exit(head);
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

int	stack_size(t_node *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void	free_stack(t_node *stack)
{
	t_node	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

void	error_free_exit(t_node *stack)
{
	if (stack)
		free_stack(stack);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	change_to_index(t_node *head)
{
	t_node	*cur;
	t_node	*cmp;
	int		index;

	cur = head;
	while (cur != NULL)
	{
		index = 0;
		cmp = head;
		while (cmp != NULL)
		{
			if (cmp->value < cur->value)
				index++;
			cmp = cmp->next;
		}
		cur->index = index;
		cur = cur->next;
	}
}
