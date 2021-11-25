/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_move_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:35:16 by lmaujean          #+#    #+#             */
/*   Updated: 2021/11/25 13:35:19 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_find_pivot_right(t_stack *stack, int pivot)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = stack->start;
	while (tmp)
	{
		if (tmp->index == pivot)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	ft_find_pivot_left(t_stack *stack, int pivot)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = stack->end;
	while (tmp)
	{
		if (tmp->index == pivot)
			return (i);
		tmp = tmp->back;
		i++;
	}
	return (i);
}

int	ft_nbr_move_b(t_stack *stack, int index)
{
	int	right;
	int	left;

	left = ft_find_pivot_left(stack, index);
	right = ft_find_pivot_right(stack, index);
	if (left < right)
	{
		if (left == 0)
			return (-1);
		else
			return ((left + 1) * -1);
	}
	else
		return (right);
}

void	ft_move_under_pivot(t_push *push, char choice, int pivot, int move)
{
	if (choice == 'A')
		move = ft_nbr_move_b(push->stack_a, pivot);
	else
		move = ft_nbr_move_b(push->stack_b, pivot);
	if (move < 0)
	{
		while (move++ < 0)
		{
			if (choice == 'A')
				ft_rra(push);
			else
				ft_rrb(push);
		}
	}
	else
	{
		while (move-- > 0)
		{
			if (choice == 'A')
				ft_ra(push);
			else
				ft_rb(push);
		}
	}
}

void	ft_choice_swap(t_push *push)
{
	int	move_a;
	int	move_b;

	move_a = 0;
	move_b = 0;
	if (push->stack_a && push->stack_a->start->next)
	{
		if (push->stack_a->start->index == \
		push->stack_a->start->next->index + 1)
			move_a = 1;
	}
	if (push->stack_b && push->stack_b->start->next)
	{
		if (push->stack_b->start->index == \
		push->stack_b->start->next->index + 1)
			move_b = 1;
	}
	if (move_a == 1 && move_b == 1)
		ft_ss(push);
	else if (move_a == 1)
		ft_sa(push);
	else if (move_b == 1)
		ft_sb(push);
}
