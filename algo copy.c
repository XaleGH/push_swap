/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:55:23 by asaux             #+#    #+#             */
/*   Updated: 2024/02/08 15:57:59 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init(t_stack **stack_a, t_stack **stack_b)
{
	int i;
	t_stack *temp;
	t_stack *save;
	
	temp = *stack_a;
	save = *stack_b;
	printf("000\n");
	while (ft_lstsize(temp) > 3)
	{
		printf("001\n");
		i = 0;
		temp = *stack_a;
		printf("002\n");
		set_index(stack_a, &temp);
		printf("003\n");
		set_index(stack_b, &save);
		printf("004\n");
		while (i <= ft_lstsize(*stack_a))
		{
			printf("005\n");
			set_target(*stack_a, stack_b);
			printf("006\n");
			push_cost(*stack_a, stack_b);
			printf("007\n");
			*stack_a = (*stack_a)->nx;
			printf("008\n");
			i++;
		}
		printf("009\n");
		*stack_a = temp;
		printf("010\n");
		cheapest(stack_a);
		printf("011\n");

		
		push(stack_a, stack_b, 'a');
		printf("012\n");
	}
	return (0);
}
void 	set_index(t_stack **stack, t_stack **temp)
{
	int	i;

	i = 0;
	while (*stack)
	{
		(*stack)->index = i;
		(*stack)->cheapest = 0;
		if (i <= (ft_lstsize(*temp) / 2))
			(*stack)->above_median = 1;
		else
			(*stack)->above_median = 0;
		*stack = (*stack)->nx;
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
			(*stack_a)->cheapest = 1;
			break;
		}
		*stack_a = (*stack_a)->nx;
	}
}
void	push_cost(t_stack *a, t_stack **b)
{
	int len_a;
	int len_b;

	len_a = ft_lstsize(a);
	len_b = ft_lstsize(*b);
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

void	set_target(t_stack *stack_a, t_stack **stack_b)
{
	t_stack *min_val;

	printf("si000\n");
	min_val = min_value(*stack_b);
	printf("value : %d\n", min_val->nb);
	printf("si001\n");
	if ((stack_a)->nb < min_val->nb)
	{
		printf("si006\n");
		(stack_a)->target_node = max_value(stack_b);
		printf("si007\n");
	}
	else
	{
		printf("si002\n");
		while (*stack_b)
		{
			printf("si003\n");
			if ((stack_a)->nb > (*stack_b)->nb && (stack_a)->nb < (*stack_b)->nx->nb)
			{
				printf("si004\n");
				(stack_a)->target_node = *stack_b;
				break;
			}
			printf("si005\n");
			*stack_b = (*stack_b)->nx;
		}
	}
	printf("si006\n");
}

t_stack	*min_value(t_stack *stack_b)
{
	t_stack *min_val;
	t_stack *temp;

	printf("min000\n");
	temp = stack_b;
	min_val = stack_b;
	printf("min001\n");
	while (stack_b->nx)
	{
		printf("min002\n");
		if (min_val->nb > (stack_b)->nx->nb)
			min_val = stack_b->nx;
		printf("min003\n");
		stack_b = (stack_b)->nx;
		printf("min004\n");
	}
	printf("min005\n");
	stack_b = temp;
	printf("min006\n");
	return (min_val);
}

t_stack	*max_value(t_stack **stack_b)
{
	t_stack	*max_val;
	t_stack	*temp;

	temp = *stack_b;
	max_val = *stack_b;
	while (*stack_b)
	{
		if (max_val->nb < (*stack_b)->nb)
			max_val = *stack_b;
		*stack_b = (*stack_b)->nx;
	}
	*stack_b = temp;
	return (max_val);
}
