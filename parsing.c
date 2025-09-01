/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuukiishino <yuukiishino@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:05:35 by yuukiishino       #+#    #+#             */
/*   Updated: 2025/09/01 23:28:55 by yuukiishino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_number(char *str)
{
	int		i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	is_double_num(t_node *head, int num)
{
	if (!head)
		return (0);
	while (head)
	{
		if (head->value == num)
			return (1);
		head = head->next;
	}
	return (0);
}

static t_node	*new_node(int num)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		error_exit();
	new->value = num;
	new->next = NULL;
	return (new);
}

t_node	*parse_args(int argc, char **argv)
{
	t_node	*head;
	t_node	*tail;
	t_node	*new;
	int		i;
	int		num;

	i = 1;
	head = NULL;
	tail = NULL;
	while (i < argc)
	{
		num = ft_atoi_safe(argv[i], head);
		if (is_double_num(head, num))
			error_free_exit(head);
		new = new_node(num);
		make_or_add_node(&head, &tail, new);
		i++;
	}
	return (head);
}
