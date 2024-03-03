/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_double.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:41:35 by asaux             #+#    #+#             */
/*   Updated: 2024/03/03 12:29:50 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//sa and sb at the same time. ss
void	ss(t_stack *stack_a, t_stack *stack_b, char c)
{
	swap(stack_a, c);
	swap(stack_b, c);
	write(1, "ss\n", 3);
}

//ra and rb at the same time. rr
void	rr(t_stack **stack_a, t_stack **stack_b, char c)
{
	rotate(stack_a, c);
	rotate(stack_b, c);
	write(1, "rr\n", 3);
}

//rra and rrb at the same time. rrr
void	rrr(t_stack **stack_a, t_stack **stack_b, char c)
{
	reverse_rotate(stack_a, c);
	reverse_rotate(stack_b, c);
	write(1, "rrr\n", 4);
}

//Check double value in stack_a.
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
