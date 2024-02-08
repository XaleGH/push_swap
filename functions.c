/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:15:33 by asaux             #+#    #+#             */
/*   Updated: 2024/02/06 11:55:52 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *nptr)
{
	int			i;
	int			sign;
	long int	res;

	i = 0;
	sign = 1;
	res = 3000000000;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = sign * -1;
		i++;
	}
	if (nptr[i] >= '0' && nptr[i] <= '9')
		res = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		res = res * 10 + nptr[i++] - '0';
	if ((res * sign) < -2147483648 || (res * sign) > 2147483647)
		return (write(2, "Error Value\n", 12), exit(1), 0);
	return (res * sign);
}

int	find_small_number(t_stack *stack)
{
	int small_number;

	small_number = stack->nb;
	stack = stack->nx;
	while (stack)
	{
		if (small_number > stack->nb)
			small_number = stack->nb;
		stack = stack->nx;
	}
	return (small_number);
}

int	find_second_small_number(t_stack *stack)
{
	int small_number;
	int small_second;

	small_number = find_small_number(stack);
	if (small_number != stack->nb)
		small_second = stack->nb;
	else
		small_second = stack->nx->nb;
	while (stack)
	{
		if (small_second > stack->nb && stack->nb != small_number)
			small_second = stack->nb;
		stack = stack->nx;
	}
	return (small_second);
}