/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuukiishino <yuukiishino@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:31:50 by yuukiishino       #+#    #+#             */
/*   Updated: 2025/07/16 18:33:59 by yuukiishino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->a->value;
	b = stack->a->next->value;
	c = stack->a->next->next->value;
	if (a < b && b < c)
		return ;
	else if (a < c && c < b)
	{
		sa(stack);
		ra(stack);
	}
	else if (b < a && a < c)
		sa(stack);
	else if (c < a && a < b)
		rra(stack);
	else if (b < c && c < a)
		ra(stack);
	else if (c < b && b < a)
	{
		sa(stack);
		rra(stack);
	}
}

void	sort_4(t_stack *stack, int size)
{
	int	min_pos;

	min_pos = get_position_of_index(stack->a, 0);
	if (min_pos <= size / 2)
		while (min_pos-- > 0)
			ra(stack);
	else
		while (min_pos++ < size)
			rra(stack);
	pb(stack);
	sort_3(stack);
	pa(stack);
}

void	sort_5(t_stack *stack)
{
	int	top;

	while (stack_size(stack->a) > 3)
	{
		top = stack->a->index;
		if (top == 0 || top == 1)
			pb(stack);
		else
			ra(stack);
	}
	sort_3(stack);
	if (stack->b->index < stack->b->next->index)
		sb(stack);
	pa(stack);
	pa(stack);
}

void	sort_small(t_stack *stack, int size)
{
	if (size == 2)
	{
		if (stack->a->value > stack->a->next->value)
			sa(stack);
	}
	else if (size == 3)
		sort_3(stack);
	else if (size == 4)
		sort_4(stack, size);
	else if (size == 5)
		sort_5(stack);
}
