/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuukiishino <yuukiishino@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:29:42 by yuukiishino       #+#    #+#             */
/*   Updated: 2025/07/11 17:09:36 by yuukiishino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !stack->a || !stack->a->next)
		return ;
	first = stack->a;
	stack->a = first->next;
	first->next = NULL;
	last = stack->a;
	while (last->next)
		last = last->next;
	last->next = first;
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !stack->b || !stack->b->next)
		return ;
	first = stack->b;
	stack->b = first->next;
	first->next = NULL;
	last = stack->b;
	while (last->next)
		last = last->next;
	last->next = first;
	write(1, "rb\n", 3);
}

static void	rotate_a(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !stack->a || !stack->a->next)
		return ;
	first = stack->a;
	stack->a = first->next;
	first->next = NULL;
	last = stack->a;
	while (last->next)
		last = last->next;
	last->next = first;
}

static void	rotate_b(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !stack->b || !stack->b->next)
		return ;
	first = stack->b;
	stack->b = first->next;
	first->next = NULL;
	last = stack->b;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	rr(t_stack *stack)
{
	rotate_a(stack);
	rotate_b(stack);
	write(1, "rr\n", 3);
}
