/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuukiishino <yuukiishino@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:30:22 by yuukiishino       #+#    #+#             */
/*   Updated: 2025/07/11 17:06:14 by yuukiishino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack)
{
	t_node	*prev;
	t_node	*last;

	if (!stack || !stack->a || !stack->a->next)
		return ;
	prev = NULL;
	last = stack->a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = stack->a;
	stack->a = last;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack)
{
	t_node	*prev;
	t_node	*last;

	if (!stack || !stack->b || !stack->b->next)
		return ;
	prev = NULL;
	last = stack->b;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = stack->b;
	stack->b = last;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
	write(1, "rrr\n", 4);
}
