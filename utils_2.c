/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuukiishino <yuukiishino@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:17:53 by yuukiishino       #+#    #+#             */
/*   Updated: 2025/07/11 17:08:57 by yuukiishino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_bit_length(int max_value)
{
	int	bits;

	bits = 0;
	while ((max_value >> bits) != 0)
		bits++;
	return (bits);
}

int	get_max_index(t_node *a)
{
	int	max;

	max = 0;
	while (a)
	{
		if (a->index > max)
			max = a->index;
		a = a->next;
	}
	return (max);
}

int	has_index_in_range(t_node *a, int min, int max)
{
	while (a)
	{
		if (a->index >= min && a->index <= max)
			return (1);
		a = a->next;
	}
	return (0);
}

int	get_position_of_index(t_node *a, int index)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->index == index)
			break ;
		i++;
		a = a->next;
	}
	return (i);
}

int	chose_best_pos(int pos1, int pos2, int len)
{
	int	pos1_sub;
	int	pos2_sub;

	if (pos1 == -1)
		return (pos2);
	if (pos2 == -1)
		return (pos1);
	pos1_sub = pos1;
	pos2_sub = pos2;
	if (pos1 > len / 2)
		pos1_sub = len - pos1;
	if (pos2 > len / 2)
		pos2_sub = len - pos2;
	if (pos1_sub < pos2_sub)
		return (pos1);
	else
		return (pos2);
}
