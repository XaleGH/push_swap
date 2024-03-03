/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:09:07 by asaux             #+#    #+#             */
/*   Updated: 2024/03/03 14:49:08 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//free the stack
void	free_stack(t_stack *stack_a)
{
	t_stack *temp;
	
	
	while (stack_a)
	{
		temp = stack_a->nx;
		free(stack_a);
		stack_a = temp;
	} 
}

//free the array
void	free_array(char **array)
{
	int i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}
