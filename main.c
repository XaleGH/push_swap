/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:16:11 by asaux             #+#    #+#             */
/*   Updated: 2024/02/16 15:57:39 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Fill stack a when argc > 2.
t_stack *fill_stack_a(int argc, char *argv[])
{
	int i;
	t_stack *stack;

	i = 0;
	stack = NULL;
	while (i < argc)
	{
		ft_lstadd_back(&stack, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	return (stack);
}
//Fill stack a when argc == 2.
t_stack *fill_stack_a_wsplit(char *str)
{
	char 	**array;
	int 	i;
	t_stack	*stack;

	i = 0;
	stack = NULL;
	array = ft_split(str, ' ');
	while (array[i])
	{
		ft_lstadd_back(&stack, ft_lstnew(ft_atoi(array[i])));
		i++;
	}
	return (stack);
}

//Check double in stack_a.
int	check_double(t_stack *stack_a)
{
	t_stack *temp;

	temp = stack_a->nx;
	while (stack_a->nx != NULL)
	{
		while (temp != NULL)
		{
			if (stack_a->nb == temp->nb)
				return (0);
			temp = temp->nx;
		}
		stack_a = stack_a->nx;
		temp = stack_a->nx;
	}
	return (1);
}
//Sort stack_a when only 2 or 3 values.
void	three_in_stack(t_stack **stack)
{
	int flag;

	flag = 1;
	while (flag == 1)
	{
		if (ft_lstsize(*stack) == 2)
		{
			if ((*stack)->nb > (*stack)->nx->nb)
				swap(*stack, 'a');
			flag = 0;
		}
		else if ((*stack)->nb < (*stack)->nx->nb && (*stack)->nx->nb < (*stack)->nx->nx->nb)
			flag = 0;
		else if ((*stack)->nb < (*stack)->nx->nb && (*stack)->nx->nb > (*stack)->nx->nx->nb)
			reverse_rotate(stack, 'a');
		else if ((*stack)->nb > (*stack)->nx->nb && (*stack)->nb > (*stack)->nx->nx->nb)
			rotate(stack, 'a');
		else if ((*stack)->nb > (*stack)->nx->nb && (*stack)->nb < (*stack)->nx->nx->nb)
			swap(*stack, 'a');
	}
}
//Sort stack_a when only 4 or 5 values.
void	five_in_stack(t_stack **stack_a, t_stack **stack_b)
{
	int small_number;
	int small_second;

	small_number = find_small_number(*stack_a);
	if (ft_lstsize(*stack_a) == 5)
		small_second = find_second_small_number(*stack_a);
	else
		small_second = find_small_number(*stack_a);
	while (ft_lstsize(*stack_a) > 3)
	{
		if ((*stack_a)->nb == small_number || (*stack_a)->nb == small_second)
			push(stack_a, stack_b, 'b');
		rotate(stack_a, 'a');
	}
	three_in_stack(stack_a);
	if (ft_lstsize(*stack_b) == 2)
		if ((*stack_b)->nb < (*stack_b)->nx->nb)
			swap(*stack_b, 'b');
	while (*stack_b)
		push(stack_b, stack_a, 'a');
}

int	main(int argc, char *argv[])
{
	t_stack *stack_a;
	t_stack *stack_b;
	t_stack *temp;
	
	temp = NULL;
	stack_a = NULL;
	stack_b = NULL;
	if (argc > 2)
		stack_a = fill_stack_a(argc - 1, argv + 1);
	if (argc == 2)
		stack_a = fill_stack_a_wsplit(argv[1]);
	if (!check_double(stack_a))
		return (write(2, "Error Double\n", 13), 0);
	
	temp = stack_a;
	while(stack_a != NULL)
	{
		printf("nb : %d\n", stack_a->nb);
		printf("push_cost : %d\n", stack_a->push_cost);
		printf("cheapest : %d\n", stack_a->cheapest);
		printf("above_median : %d\n", stack_a->above_median);
		printf("index : %d\n", stack_a->index);
		printf("\n");
		stack_a = stack_a->nx;
	}
	stack_a = temp;
	printf("%d\n", ft_lstsize(stack_a));
	if (ft_lstsize(stack_a) == 2 || ft_lstsize(stack_a) == 3)
		three_in_stack(&stack_a);
	else if (ft_lstsize(stack_a) == 4 || ft_lstsize(stack_a) == 5)
		five_in_stack(&stack_a, &stack_b);
	else if (ft_lstsize(stack_a) > 5)
	{
		sort_list(&stack_a, &stack_b);
	}
	
	while(stack_a != NULL)
	{
		printf("nb : %d\n", stack_a->nb);
		printf("push_cost : %d\n", stack_a->push_cost);
		printf("cheapest : %d\n", stack_a->cheapest);
		printf("above_median : %d\n", stack_a->above_median);
		printf("index : %d\n", stack_a->index);
		printf("target_node_nb : %d\n", stack_a->target_node->nb);
		printf("target_node_index : %d\n", stack_a->target_node->index);
		printf("\n");
		stack_a = stack_a->nx;
	}
	while(stack_b != NULL)
	{
		printf("nb_b : %d\n", stack_b->nb);
		printf("push_cost_b : %d\n", stack_b->push_cost);
		printf("cheapest_b : %d\n", stack_b->cheapest);
		printf("above_median_b : %d\n", stack_b->above_median);
		printf("index_b : %d\n", stack_b->index);
		printf("target_node_nb_b : %d\n", stack_b->target_node->nb);
		printf("target_node_index_b : %d\n", stack_b->target_node->index);
		printf("\n");
		stack_b = stack_b->nx;
	}
	return (0);
}
