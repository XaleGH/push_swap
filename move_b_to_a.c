/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:11:09 by asaux             #+#    #+#             */
/*   Updated: 2024/02/19 16:42:55 by asaux            ###   ########.fr       */
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
	t_stack	*closest_nb;
	t_stack	*target_node;
	t_stack	*temp_a;

	while (stack_b)
	{
		temp_a = stack_a;
		closest_nb = max_value(stack_a);
		while (temp_a)
		{
			if (temp_a->nb > stack_b->nb && temp_a->nb <= closest_nb->nb)
			{
				closest_nb = temp_a;
				target_node = temp_a;
			}
			temp_a = temp_a->nx;
		}
		if (closest_nb->nb < stack_b->nb)
			stack_b->target_node = min_value(stack_a);
		else
			stack_b->target_node = target_node;
		stack_b = stack_b->nx;
	}
}

void	push_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	pre_push(stack_a, (*stack_b)->target_node, 'a');
	push(stack_b, stack_a, 'a');
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