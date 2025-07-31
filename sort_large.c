/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuukiishino <yuukiishino@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 20:37:02 by yuukiishino       #+#    #+#             */
/*   Updated: 2025/07/16 18:51:45 by yuukiishino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chose_rr_or_rb(int index, t_stack *stack, t_chunk_pair chunk)
{
	int	a_top_index;

	if (stack->a)
		a_top_index = stack->a->index;
	else
		a_top_index = -1;
	if (index >= chunk.min1 && index <= chunk.max1)
	{
		if (a_top_index < 0 || is_in_chunk(a_top_index, chunk))
			rb(stack);
		else
			rr(stack);
	}
}

void	push_chunk_to_b(t_stack *stack, t_chunk_pair chunk)
{
	int	pos;
	int	len;
	int	index;

	while (has_index_in_range(stack->a, chunk.min1, chunk.max1)
		|| has_index_in_range(stack->a, chunk.min2, chunk.max2))
	{
		len = stack_size(stack->a);
		pos = get_best_pos_from_two_ranges(stack->a, chunk, len);
		if (pos <= len / 2)
			while (pos-- > 0)
				ra(stack);
		else
			while (pos++ < len)
				rra(stack);
		index = stack->a->index;
		pb(stack);
		chose_rr_or_rb(index, stack, chunk);
	}
}

void	pa_and_sa_with_b(t_stack *stack, int pos, int len, int max_idx)
{
	pa(stack);
	len = stack_size(stack->b);
	pos = get_best_pos_from_two_index(stack->b, max_idx, len);
	if (pos <= len / 2)
		while (pos-- > 0)
			rb(stack);
	else
		while (pos++ < len)
			rrb(stack);
	pa(stack);
	sa(stack);
}

void	push_chunk_to_a(t_stack *stack)
{
	int	max_idx;
	int	pos;
	int	len;
	int	now_b_index;

	while (stack->b)
	{
		max_idx = get_max_index(stack->b);
		len = stack_size(stack->b);
		pos = get_best_pos_from_two_index(stack->b, max_idx, len);
		if (pos <= len / 2)
			while (pos-- > 0)
				rb(stack);
		else
			while (pos++ < len)
				rrb(stack);
		now_b_index = stack->b->index;
		if (now_b_index == max_idx)
			pa(stack);
		else
			pa_and_sa_with_b(stack, pos, len, max_idx);
	}
}

void	sort_large(t_stack *stack, int size)
{
	int				chunk_count;
	int				chunk_size;
	int				i;
	int				j;
	t_chunk_pair	chunk;

	if (size == 100)
		chunk_count = 10;
	else
		chunk_count = 20;
	chunk_size = size / chunk_count;
	i = chunk_count / 2 - 1;
	j = i + 1;
	while (i >= 0 || j < chunk_count)
	{
		chunk.min1 = i * chunk_size;
		chunk.max1 = (i + 1) * chunk_size - 1;
		chunk.min2 = j * chunk_size;
		chunk.max2 = (j + 1) * chunk_size - 1;
		push_chunk_to_b(stack, chunk);
		i--;
		j++;
	}
	push_chunk_to_a(stack);
}
