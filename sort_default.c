/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_default.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuukiishino <yuukiishino@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 01:34:16 by yuukiishino       #+#    #+#             */
/*   Updated: 2025/07/11 16:26:01 by yuukiishino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_default(t_stack *stack, int size)
{
	int		max_bits;
	int		i;
	int		j;

	max_bits = max_bit_length(get_max_index(stack->a));
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((stack->a->index >> i) & 1) == 0)
				pb(stack);
			else
				ra(stack);
			j++;
		}
		while (stack->b)
			pa(stack);
		i++;
	}
}
