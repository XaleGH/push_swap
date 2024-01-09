/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:52:29 by asaux             #+#    #+#             */
/*   Updated: 2023/12/18 17:19:07 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements). sa
//swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements). sb
void	swap(t_stack *stack, char c)
{
	int	temp;

	temp = 0;
	if (!stack || !stack->nx)
		return;
	temp = stack->i;
	stack->i = stack->nx->i;
	stack->nx->i = temp;
	if (c == 'a')
		write(1, "sa\n", 3);
	if (c == 'b')
		write(1, "sb\n", 3);
}
//sa and sb at the same time. ss
void	ss(t_stack *stack_a, t_stack *stack_b, char c)
{
	swap(stack_a, c);
	swap(stack_b, c);
	write(1, "ss\n", 3);
}

//push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty. pa
//push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty. pb
void	push(t_stack **src, t_stack **dest, char c)
{
	t_stack *temp;

	if (!*src)
		return;
	temp = *src;
	*src = (*src)->nx;
	temp->nx = NULL;
	ft_lstadd_front(dest, temp);
	if (c == 'a')
		write(1, "pa\n", 3);
	if (c == 'b')
		write(1, "pb\n", 3);
}

//rotate a - shift up all elements of stack a by 1. The first element becomes the last one. ra
//rotate b - shift up all elements of stack b by 1. The first element becomes the last one. rb
void	rotate(t_stack **stack, char c)
{
	t_stack *temp;
	
	if (!stack)
		return;
	temp = *stack;
	*stack = (*stack)->nx;
	temp->nx = NULL;
	ft_lstadd_back(stack, temp);
	if (c == 'a')
		write(1, "ra\n", 3);
	if (c == 'b')
		write(1, "rb\n", 3);
}
//ra and rb at the same time. rr
void	rr(t_stack **stack_a, t_stack **stack_b, char c)
{
	rotate(stack_a, c);
	rotate(stack_b, c);
	write(1, "rr\n", 3);
}

//reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one. rra
//reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one. rrb
void	reverse_rotate(t_stack **stack, char c)
{
	t_stack *temp;
	
	if (!*stack || !(*stack)->nx)
		return;
	temp = *stack;
	while (temp->nx->nx)
		temp = temp->nx;
	temp->nx->nx = *stack;
	*stack = temp->nx;
	temp->nx = NULL;
	if (c == 'a')
		write(1, "rra\n", 4);
	if (c == 'b')
		write(1, "rrb\n", 4);
}
//rra and rrb at the same time. rrr
void	rrr(t_stack **stack_a, t_stack **stack_b, char c)
{
	reverse_rotate(stack_a, c);
	reverse_rotate(stack_b, c);
	write(1, "rrr\n", 4);
}

