/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_in_stack2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:24:01 by lmaujean          #+#    #+#             */
/*   Updated: 2021/11/25 13:24:03 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*ft_new_dlist(int content, int index)
{
	t_list	*new_dlist;

	new_dlist = malloc(sizeof(*new_dlist));
	if (new_dlist == NULL)
		return (NULL);
	new_dlist->value = content;
	new_dlist->index = index;
	new_dlist->next = NULL;
	new_dlist->back = NULL;
	return (new_dlist);
}

t_stack	*ft_new_stack(int content, int index)
{
	t_list	*new_dlist;
	t_stack	*new_stack;

	new_stack = malloc(sizeof(*new_stack));
	new_dlist = ft_new_dlist(content, index);
	if (new_dlist == NULL && new_stack == NULL)
		return (NULL);
	new_stack->len = 1;
	new_stack->start = new_dlist;
	new_stack->end = new_dlist;
	return (new_stack);
}

int	ft_reverse_stack(t_stack *stack)
{
	t_list	*temp;

	if (ft_stack_empty(stack))
		return (1);
	if (stack->len == 1)
		return (1);
	temp = stack->end;
	stack->end = temp->back;
	stack->start->back = temp;
	temp->next = stack->start;
	stack->start = temp;
	stack->start->back = NULL;
	stack->end->next = NULL;
	return (0);
}

int	ft_swap_stack(t_stack *stack)
{
	int	value;
	int	index;

	if (ft_stack_empty(stack))
		return (1);
	if (stack->len == 1)
		return (1);
	value = stack->start->value;
	index = stack->start->index;
	stack->start->value = stack->start->next->value;
	stack->start->index = stack->start->next->index;
	stack->start->next->value = value;
	stack->start->next->index = index;
	return (0);
}

int	ft_push_stack(t_stack **dest, t_stack **src)
{
	if (ft_stack_empty(*src))
		return (1);
	*dest = ft_stack_addfront(*dest, (*src)->start->value,
			(*src)->start->index);
	*src = ft_stack_delfront(*src);
	return (0);
}
