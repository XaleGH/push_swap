/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:16:11 by asaux             #+#    #+#             */
/*   Updated: 2024/03/12 17:38:06 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//Fill stack a when argc > 2.
t_stack	*fill_stack_a(int argc, char *argv[])
{
	int		i;
	t_stack	*stack;

	i = 0;
	stack = NULL;
	while (i < argc)
	{
		ft_lstadd_back(&stack, ft_lstnew(ft_atoi(argv[i], &stack)));
		i++;
	}
	return (stack);
}

//Fill stack a when argc == 2.
t_stack	*fill_stack_a_wsplit(char *str)
{
	char	**array;
	int		i;
	t_stack	*stack;

	i = 0;
	stack = NULL;
	array = ft_split(str, ' ');
	while (array[i])
	{
		ft_lstadd_back(&stack,
			ft_lstnew(ft_atoi_wsplit(array[i], &stack, array)));
		i++;
	}
	free_array(array);
	return (stack);
}

//Sort stack_a when only 2 or 3 values.
void	three_in_stack(t_stack **stack)
{
	int	flag;

	flag = 1;
	while (flag == 1)
	{
		if (ft_lstsize(*stack) == 2)
		{
			if ((*stack)->nb > (*stack)->nx->nb)
				swap(*stack, 'a');
			flag = 0;
		}
		else if ((*stack)->nb < (*stack)->nx->nb
			&& (*stack)->nx->nb < (*stack)->nx->nx->nb)
			flag = 0;
		else if ((*stack)->nb < (*stack)->nx->nb
			&& (*stack)->nx->nb > (*stack)->nx->nx->nb)
			reverse_rotate(stack, 'a');
		else if ((*stack)->nb > (*stack)->nx->nb
			&& (*stack)->nb > (*stack)->nx->nx->nb)
			rotate(stack, 'a');
		else if ((*stack)->nb > (*stack)->nx->nb
			&& (*stack)->nb < (*stack)->nx->nx->nb)
			swap(*stack, 'a');
	}
}

//Sort stack_a when only 4 or 5 values.
void	five_in_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	small_number;
	int	small_second;

	small_number = find_small_number(*stack_a);
	if (ft_lstsize(*stack_a) == 5)
		small_second = find_second_small_number(*stack_a);
	else
		small_second = find_small_number(*stack_a);
	while (ft_lstsize(*stack_a) > 3)
	{
		if ((*stack_a)->nb == small_number || (*stack_a)->nb == small_second)
			push(stack_a, stack_b, 'b');
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
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 2)
		stack_a = fill_stack_a(argc - 1, argv + 1);
	if (argc == 2)
		stack_a = fill_stack_a_wsplit(argv[1]);
	if (!stack_a)
		return (write(2, "Error\n", 6), 0);
	if (!check_double(stack_a))
		return (free_stack(stack_a), write(2, "Error\n", 6), 0);
	if (is_sorted(stack_a))
		return (free_stack(stack_a), 0);
	if (ft_lstsize(stack_a) == 2 || ft_lstsize(stack_a) == 3)
		three_in_stack(&stack_a);
	else if (ft_lstsize(stack_a) == 4 || ft_lstsize(stack_a) == 5)
		five_in_stack(&stack_a, &stack_b);
	else if (ft_lstsize(stack_a) > 5)
		sort_list(&stack_a, &stack_b);
	free_stack(stack_a);
	return (0);
}
