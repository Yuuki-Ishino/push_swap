/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuukiishino <yuukiishino@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:21:28 by yuukiishino       #+#    #+#             */
/*   Updated: 2025/07/11 17:31:39 by yuukiishino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_best_pos_from_two_index(t_node *a, int index, int len)
{
	int	i;
	int	pos1;
	int	pos2;

	i = 0;
	pos1 = -1;
	pos2 = -1;
	while (a)
	{
		if (pos1 == -1 && a->index == index)
			pos1 = i;
		if (pos2 == -1 && a->index == index - 1)
			pos2 = i;
		if (pos1 != -1 && pos2 != -1)
			break ;
		a = a->next;
		i++;
	}
	i = chose_best_pos(pos1, pos2, len);
	return (i);
}

int	get_best_pos_from_two_ranges(t_node *a, t_chunk_pair chunk, int len)
{
	int	i;
	int	pos1;
	int	pos2;

	i = 0;
	pos1 = -1;
	pos2 = -1;
	while (a)
	{
		if (pos1 == -1 && a->index >= chunk.min1 && a->index <= chunk.max1)
			pos1 = i;
		if (pos2 == -1 && a->index >= chunk.min2 && a->index <= chunk.max2)
			pos2 = i;
		if (pos1 != -1 && pos2 != -1)
			break ;
		a = a->next;
		i++;
	}
	i = chose_best_pos(pos1, pos2, len);
	return (i);
}

int	is_in_chunk(int index, t_chunk_pair chunk)
{
	return ((index >= chunk.min1 && index <= chunk.max1)
		|| (index >= chunk.min2 && index <= chunk.max2));
}

void	make_or_add_node(t_node **head, t_node **tail, t_node *new)
{
	if (!*head)
	{
		*head = new;
		*tail = new;
	}
	else
	{
		(*tail)->next = new;
		*tail = new;
	}
}
