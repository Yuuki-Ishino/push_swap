/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuukiishino <yuukiishino@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 02:02:43 by yuukiishino       #+#    #+#             */
/*   Updated: 2025/07/12 18:41:37 by yuukiishino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*a;
	t_node	*b;
}	t_stack;

typedef struct s_chunk_pair
{
	int	min1;
	int	max1;
	int	min2;
	int	max2;
}	t_chunk_pair;

// sort small and large
void	sort_large(t_stack *stack, int size);
void	sort_small(t_stack *stack, int size);
void	sort_default(t_stack *stack, int size);

// parsing.c
int		is_valid_args(int argc, char **argv);
t_node	*parse_args(int argc, char **argv);

// utils1.c
long	ft_atol(const char *str);
void	free_stack(t_node *stack);
void	error_exit(void);
int		stack_size(t_node *stack);
void	change_to_index(t_node *head);

// utils2.c
int		max_bit_length(int max_value);
int		get_max_index(t_node *a);
int		has_index_in_range(t_node *a, int min, int max);
int		get_position_of_index(t_node *a, int index);
int		chose_best_pos(int pos1, int pos2, int len);

// utils3.c
int		get_best_pos_from_two_index(t_node *a, int index, int len);
int		get_best_pos_from_two_ranges(t_node *a, t_chunk_pair chunk, int len);
int		is_in_chunk(int index, t_chunk_pair chunk);
void	make_or_add_node(t_node **head, t_node **tail, t_node *new);

// operations1.c
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);
void	pa(t_stack *stack);
void	pb(t_stack *stack);

//operations2.c
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);

//operations3.c
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);

#endif