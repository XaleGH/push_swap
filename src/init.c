/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:55:23 by asaux             #+#    #+#             */
/*   Updated: 2024/03/12 17:31:05 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//initiate attribut of stacks
int	init(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*temp;

	i = -1;
	temp = *stack_a;
	set_index(*stack_a);
	set_index(*stack_b);
	set_target_a_to_b(*stack_a, *stack_b);
	while (++i < ft_lstsize(temp))
	{
		push_cost(*stack_a, *stack_b, temp);
		*stack_a = (*stack_a)->nx;
	}
	*stack_a = temp;
	cheapest(*stack_a);
	return (0);
}

//set index for each node in stack
void	set_index(t_stack *stack)
{
	int		i;
	t_stack	*temp;

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

//set at 1 the attribut cheapest of the first node with the smallest push_cost
void	cheapest(t_stack *stack_a)
{
	int		cheapest;
	t_stack	*temp;

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
			break ;
		}
		stack_a = stack_a->nx;
	}
}

//calculates the number of moves required to put the nodes in the right place
void	push_cost(t_stack *a, t_stack *b, t_stack *temp)
{
	int	len_a;
	int	len_b;

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

//assigns a target to each nodes in the stack_a
void	set_target_a_to_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*closest_nb;
	t_stack	*target_node;
	t_stack	*temp_b;

	while (stack_a)
	{
		temp_b = stack_b;
		closest_nb = min_value(stack_b);
		while (temp_b)
		{
			if (temp_b->nb < stack_a->nb && temp_b->nb >= closest_nb->nb)
			{
				closest_nb = temp_b;
				target_node = temp_b;
			}
			temp_b = temp_b->nx;
		}
		if (closest_nb->nb > stack_a->nb)
			stack_a->target_node = max_value(stack_b);
		else
			stack_a->target_node = target_node;
		stack_a = stack_a->nx;
	}
}
