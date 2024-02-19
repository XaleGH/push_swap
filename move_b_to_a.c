/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:11:09 by asaux             #+#    #+#             */
/*   Updated: 2024/02/19 10:43:20 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	set_index(stack_a);
	set_index(stack_b);
	set_target_b_to_a(stack_a, stack_b);
	
}

void	set_target_b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *min_val;
	t_stack *max_val;

	min_val = min_value(stack_a);
	max_val = max_value(stack_a);
	while (stack_b)
	{
		if (stack_b->nb < min_val->nb || stack_b->nb > max_val->nb)
			stack_b->target_node = min_val;
		else
		{
			while (stack_a)
			{
				if (stack_b->nb > stack_a->nb && stack_b->nb < stack_a->nx->nb)
				{
					stack_b->target_node = stack_a->nx;
					break;
				}
				if (stack_a->nb > stack_a->nx->nb)
				{
					stack_b->target_node = stack_a;
					break;
				}
				stack_a = stack_a->nx;
			}
		}
		stack_b = stack_b->nx;
	}
}

void	push_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	pre_push(stack_a, (*stack_b)->target_node, 'b');
	push(stack_b, stack_a, 'b');
}

void	put_min_on_top(t_stack **stack_a)
{
	t_stack	*min;

	min = min_value(*stack_a);
	while (*stack_a != min)
	{
		if (min->above_median)
			rotate(stack_a, 'a');
		else
			reverse_rotate(stack_a, 'a');
	}
}