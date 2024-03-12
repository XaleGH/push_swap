/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:56:49 by asaux             #+#    #+#             */
/*   Updated: 2024/03/12 17:39:07 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//function that pushes the node with the lowest push_cost from stack a to b
void	move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(*stack_a);
	if (cheapest->above_median == 1 && cheapest->target_node->above_median == 1)
		rr_both(stack_a, stack_b, cheapest);
	else if (cheapest->above_median == 0
		&& cheapest->target_node->above_median == 0)
		rrr_both(stack_a, stack_b, cheapest);
	pre_push(stack_a, cheapest, 'a');
	pre_push(stack_b, cheapest->target_node, 'b');
	push(stack_a, stack_b, 'b');
}

//place the node in the right place before the push
void	pre_push(t_stack **stack, t_stack *cheapest, char c)
{
	while (*stack != cheapest)
	{
		if (cheapest->above_median == 1)
			rotate(stack, c);
		else
			reverse_rotate(stack, c);
	}
}

//rotate the 2 stacks until one of the two nodes is at index 0
void	rr_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest)
{
	while (*stack_a != cheapest && *stack_b != cheapest->target_node)
		rr(stack_a, stack_b, 'c');
	set_index(*stack_a);
	set_index(*stack_b);
}

//reverse rotate the 2 stacks until one of the two nodes is at index 0
void	rrr_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest)
{
	while (*stack_a != cheapest && *stack_b != cheapest->target_node)
		rrr(stack_a, stack_b, 'c');
	set_index(*stack_a);
	set_index(*stack_b);
}

//returns the node with the cheapest at 1
t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest == 1)
			return (stack);
		stack = stack->nx;
	}
	return (NULL);
}
