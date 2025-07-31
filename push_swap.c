/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuukiishino <yuukiishino@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 02:04:01 by yuukiishino       #+#    #+#             */
/*   Updated: 2025/07/12 18:43:47 by yuukiishino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	stack;
	int		size;

	if (argc == 1)
		return (0);
	if (argc == 2)
		error_exit();
	if (is_valid_args(argc, argv))
		error_exit();
	stack.a = parse_args(argc, argv);
	stack.b = NULL;
	size = stack_size(stack.a);
	change_to_index(stack.a);
	if (size == 100 || size == 500)
		sort_large(&stack, size);
	else if (size >= 2 && size <= 5)
		sort_small(&stack, size);
	else
		sort_default(&stack, size);
	free_stack(stack.a);
	free_stack(stack.b);
	return (0);
}

// <stdio.h> and printf have to remove when git push

// for check stack

	// t_node	*tmp;
	// tmp = stack.a;
	// while (tmp)
	// {
	// 	printf("num = %d : index = %d\n", tmp->value, tmp->index);
	// 	tmp = tmp->next;
	// }