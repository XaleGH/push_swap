/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:56:49 by asaux             #+#    #+#             */
/*   Updated: 2024/02/19 10:40:00 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *cheapest;

	cheapest = get_cheapest(*stack_a);
	if (cheapest->above_median == 1 && cheapest->target_node->above_median == 1)
		rr_both(stack_a, stack_b, cheapest);
	else if (cheapest->above_median == 0 && cheapest->target_node->above_median == 0)
		rrr_both(stack_a, stack_b, cheapest);
	pre_push(stack_a, cheapest, 'a');
	pre_push(stack_b, cheapest->target_node, 'b');
	push(stack_a, stack_b, 'a');
}

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
void	rr_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest)
{
	while (*stack_a != cheapest && *stack_b != cheapest->target_node)
		rr(stack_a, stack_b, 'c');
	set_index(*stack_a);
	set_index(*stack_b);
}
void	rrr_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest)
{
	while (*stack_a != cheapest && *stack_b != cheapest->target_node)
		rrr(stack_a, stack_b, 'c');
	set_index(*stack_a);
	set_index(*stack_b);
}

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

void	sort_list(t_stack **stack_a, t_stack **stack_b)
{
	int len_a;

	len_a = ft_lstsize(*stack_a);
	if (len_a-- > 3)
		push(stack_a, stack_b, 'a');
	if (len_a-- > 3)
		push(stack_a, stack_b, 'a');
	while (len_a-- > 3)
	{
		init(stack_a, stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	three_in_stack(stack_a);
	//set_b_to_a(*stack_a, *stack_b);
	while (*stack_b)
	{
		set_b_to_a(*stack_a, *stack_b);
		push_b_to_a(stack_a, stack_b);
 		/*printf("nb_b : %d\n", (*stack_b)->nb);
		printf("push_cost_b : %d\n", (*stack_b)->push_cost);
		printf("cheapest_b : %d\n", (*stack_b)->cheapest);
		printf("above_median_b : %d\n", (*stack_b)->above_median);
		printf("index_b : %d\n", (*stack_b)->index);
		printf("target_node_nb_b : %d\n", (*stack_b)->target_node->nb);
		printf("target_node_index_b : %d\n", (*stack_b)->target_node->index);
		printf("\n"); */
		//*stack_b = (*stack_b)->nx;
	}
	put_min_on_top(stack_a);
}
