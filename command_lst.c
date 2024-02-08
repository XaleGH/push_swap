/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:11:49 by asaux             #+#    #+#             */
/*   Updated: 2024/02/06 11:56:30 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!lst)
		return ;
	new->nx = *lst;
	(*lst) = new;
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*l;

	l = *lst;
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while (l->nx)
		l = l->nx;
	l->nx = new;
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->nx)
		lst = lst->nx;
	return (lst);
}

t_stack	*ft_lstnew(int content)
{
	t_stack	*list;

	list = malloc(sizeof (t_stack));
	if (!list)
		return (NULL);
	list->nb = content;
	list->nx = 0;
	return (list);
}

int	ft_lstsize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->nx;
		i++;
	}
	return (i);
}

void	ft_lstdelone(t_stack *lst)
{
	if (!lst)
		return ;
	free(lst);
}

void	ft_lstclear(t_stack **lst)
{
	t_stack	*l;

	if (!*lst)
		return ;
	while (*lst)
	{
		l = (*lst)->nx;
		ft_lstdelone(*lst);
		(*lst) = l;
	}
}