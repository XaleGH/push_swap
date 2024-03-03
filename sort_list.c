/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:41:16 by asaux             #+#    #+#             */
/*   Updated: 2024/03/03 14:23:29 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//sorts stack_a in ascending order
void	sort_list(t_stack **stack_a, t_stack **stack_b)
{
	int len_a;

	len_a = ft_lstsize(*stack_a);
	if (len_a-- > 3 && !is_sorted(*stack_a))
		push(stack_a, stack_b, 'b');
	if (len_a-- > 3 && !is_sorted(*stack_a))
		push(stack_a, stack_b, 'b');
	while (len_a-- > 3 && !is_sorted(*stack_a))
	{
		init(stack_a, stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	three_in_stack(stack_a);
	while (*stack_b)
	{
		set_b_to_a(*stack_a, *stack_b);
		push_b_to_a(stack_a, stack_b);
	}
	put_min_on_top(stack_a);
}

//returns the node with the smallest value
t_stack	*min_value(t_stack *stack_b)
{
	t_stack *min_val;

	min_val = stack_b;
	while (stack_b->nx)
	{
		if (min_val->nb > stack_b->nx->nb)
			min_val = stack_b->nx;
		stack_b = (stack_b)->nx;
	}
	return (min_val);
}

//returns the node with the greatest value
t_stack	*max_value(t_stack *stack_b)
{
	t_stack	*max_val;

	max_val = stack_b;
	while (stack_b->nx)
	{
		if (max_val->nb < stack_b->nx->nb)
			max_val = stack_b->nx;
		stack_b = stack_b->nx;
	}
	return (max_val);
}
