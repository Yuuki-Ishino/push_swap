/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuukiishino <yuukiishino@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:28:29 by yuukiishino       #+#    #+#             */
/*   Updated: 2025/07/11 16:29:20 by yuukiishino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !stack->a || !stack->a->next)
		return ;
	first = stack->a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->a = second;
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !stack->b || !stack->b->next)
		return ;
	first = stack->b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->b = second;
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack)
{
	sa(stack);
	sb(stack);
	write(1, "ss\n", 3);
}

void	pa(t_stack *stack)
{
	t_node	*temp;

	if (!stack || !stack->b)
		return ;
	temp = stack->b;
	stack->b = stack->b->next;
	temp->next = stack->a;
	stack->a = temp;
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack)
{
	t_node	*temp;

	if (!stack || !stack->a)
		return ;
	temp = stack->a;
	stack->a = stack->a->next;
	temp->next = stack->b;
	stack->b = temp;
	write(1, "pb\n", 3);
}
