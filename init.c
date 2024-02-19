/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:55:23 by asaux             #+#    #+#             */
/*   Updated: 2024/02/16 14:49:24 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init(t_stack **stack_a, t_stack **stack_b)
{
	int i;
	t_stack *temp;
	
	i = -1;
	temp = *stack_a;
	set_index(*stack_a);
	set_index(*stack_b);
	while (++i < ft_lstsize(temp))
	{
		set_target_a_to_b(*stack_a, *stack_b);
		push_cost(*stack_a, *stack_b, temp);
		*stack_a = (*stack_a)->nx;
	}
	*stack_a = temp;
	cheapest(*stack_a);
	return (0);
}
void 	set_index(t_stack *stack)
{
	int	i;
	t_stack *temp;

	i = 0;
	temp = stack;
	while (stack)
	{
		stack->index = i;
		stack->cheapest = 0;
		if (i <= (ft_lstsize(temp) / 2))
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->nx;
		i++;
	}
}

void	cheapest(t_stack *stack_a)
{
	int cheapest;
	t_stack *temp;

	temp = stack_a;
	cheapest = stack_a->push_cost;
	while (stack_a)
	{
		if (stack_a->push_cost < cheapest)
			cheapest = stack_a->push_cost;
		stack_a = stack_a->nx;
	}
	stack_a = temp;
	while (stack_a)
	{
		if (stack_a->push_cost == cheapest)
		{
			stack_a->cheapest = 1;
			break;
		}
		stack_a = stack_a->nx;
	}
}
void	push_cost(t_stack *a, t_stack *b, t_stack *temp)
{
	int len_a;
	int len_b;

	len_a = ft_lstsize(temp);
	len_b = ft_lstsize(b);
	if (a->above_median == 1 && a->target_node->above_median == 1)
		{
			a->push_cost = a->index;
			if (a->index < a->target_node->index)
				a->push_cost = a->target_node->index;
		}
	if (a->above_median == 0 && a->target_node->above_median == 0)
		{
			a->push_cost = len_a - a->index;
			if (len_a - a->index < len_b - a->target_node->index)
				a->push_cost = len_b - a->target_node->index;
		}
	if (a->above_median == 1 && a->target_node->above_median == 0)
		a->push_cost = a->index + (len_b - a->target_node->index);
	if (a->above_median == 0 && a->target_node->above_median == 1)
		a->push_cost = (len_a - a->index) + a->target_node->index;
}

void	set_target_a_to_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *min_val;
	t_stack *max_val;

	min_val = min_value(stack_b);
	max_val = max_value(stack_b);
	if (stack_a->nb < min_val->nb || stack_a->nb > max_val->nb)
		stack_a->target_node = max_val;
	else
	{
		while (stack_b)
		{
			if (stack_a->nb < stack_b->nb && stack_a->nb > stack_b->nx->nb)
			{
				stack_a->target_node = stack_b->nx;
				break;
			}
			if (stack_b->nb < stack_b->nx->nb)
			{
				stack_a->target_node = stack_b;
				break;
			}
			stack_b = stack_b->nx;
		}
	}
}

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
