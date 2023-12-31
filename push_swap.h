/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:52:54 by asaux             #+#    #+#             */
/*   Updated: 2023/12/18 19:52:49 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	i;
	struct s_stack	*nx;
}	t_stack;

//main.c
int			check_double(t_stack *stack_a);
t_stack 	*fill_stack_a(int argc, char *argv[]);
t_stack 	*fill_stack_a_wsplit(char *str);
void		three_in_stack(t_stack **stack);
void		five_in_stack(t_stack **stack_a, t_stack **stack_b);

//instructions.c
void		swap(t_stack *stack, char c);
void		ss(t_stack *stack_a, t_stack *stack_b, char c);
void		push(t_stack **src, t_stack **dest, char c);
void		rotate(t_stack **stack, char c);
void		rr(t_stack **stack_a, t_stack **stack_b, char c);
void		reverse_rotate(t_stack **stack, char c);
void		rrr(t_stack **stack_a, t_stack **stack_b, char c);


//command_lst.c
void		ft_lstadd_front(t_stack **lst, t_stack *new);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack		*ft_lstlast(t_stack *lst);
t_stack		*ft_lstnew(int content);
int			ft_lstsize(t_stack *lst);
void		ft_lstdelone(t_stack *lst);
void		ft_lstclear(t_stack **lst);

//functions.c
int			ft_atoi(char *nptr);
int			find_small_number(t_stack *stack);
int			find_second_small_number(t_stack *stack);

//ft_split.c
int			count_words(char *s, char c);
char		*ft_strldup(const char *s1, int l);
int			count_char(char *s, char c);
char		**ft_split(char const *s, char c);
#endif