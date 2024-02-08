/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:55:23 by asaux             #+#    #+#             */
/*   Updated: 2024/02/06 11:59:13 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init(t_stack **stack_a, t_stack **stack_b)
{
	int i;
	t_stack *temp;
	
	temp = *stack_a;
	while (ft_lstsize(temp) > 3)
	{
		i = 0;
		temp = *stack_a;
		while (i <= ft_lstsize(*stack_a))
		{
			(*stack_a)->index = i;
			if (i <= (ft_lstsize(temp) / 2))
				(*stack_a)->above_median = true;
			else
				(*stack_a)->above_median = false;
			set_target(stack_a, stack_b, (*stack_a)->index);
			(*stack_a)->push_cost = push_cost(stack_a, stack_b, i);
			*stack_a = (*stack_a)->nx;
			i++;
		}
		cheapest(stack_a);
		push(stack_a, stack_b, 'a');
	}
}

void	cheapest(t_stack **stack_a)
{
	int cheapest;
	t_stack *temp;

	temp = *stack_a;
	cheapest = (*stack_a)->push_cost;
	while (*stack_a)
	{
		if ((*stack_a)->push_cost < cheapest)
			cheapest = (*stack_a)->push_cost;
		*stack_a = (*stack_a)->nx;
	}
	*stack_a = temp;
	while (*stack_a)
	{
		if ((*stack_a)->push_cost == cheapest)
		{
			(*stack_a)->cheapest = true;
			break;
		}
		*stack_a = (*stack_a)->nx;
	}
}
int	push_cost(t_stack **stack_a, t_stack **stack_b, int index)
{
	int	cost;

	cost = 0;
	
	return (cost);
}

void	set_target(t_stack **stack_a, t_stack **stack_b, int index)
{
	t_stack *temp;
	int min_val;

	temp = *stack_a;
	while (*stack_a)
	{
		if ((*stack_a)->index == index)
			break;
		*stack_a = (*stack_a)->nx;
	}
	min_val = min_value(stack_b);
	if ((*stack_a)->nb < min_val)
		(*stack_a)->target_node = max_value;
	else
	{
		while (*stack_b)
		{
			if ((*stack_a)->nb > (*stack_b)->nb && (*stack_a)->nb < (*stack_b)->nx->nb)
			{
				(*stack_a)->target_node = (*stack_b)->nx->index;
				break;
			}
			*stack_b = (*stack_b)->nx;
		}
	}
}

int	min_value(t_stack **stack_b)
{
	int min_val;
	t_stack *temp;

	temp = *stack_b;
	min_val = (*stack_b)->nb;
	while (*stack_b)
	{
		if (min_val > (*stack_b)->nb)
			min_val = (*stack_b)->nb;
		*stack_b = (*stack_b)->nx;
	}
	*stack_b = temp;
	return (min_val);
}

int	max_value(t_stack **stack_b)
{
	int max_val;
	t_stack *temp;

	temp = *stack_b;
	max_val = (*stack_b)->nb;
	while (*stack_b)
	{
		if (max_val < (*stack_b)->nb)
			max_val = (*stack_b)->nb;
		*stack_b = (*stack_b)->nx;
	}
	*stack_b = temp;
	return (max_val);
}
