/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:26:21 by lmaujean          #+#    #+#             */
/*   Updated: 2021/11/25 13:26:23 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_find_best_move_right(t_stack *stack, int min, int max)
{
	t_list	*tmp;
	int		i;

	tmp = stack->start;
	i = 0;
	while (tmp)
	{
		if (tmp->index > min && tmp->index < max)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

int	ft_find_best_move_left(t_stack *stack, int min, int max)
{
	t_list	*tmp;
	int		i;

	tmp = stack->end;
	i = 0;
	while (tmp)
	{
		if (tmp->index > min && tmp->index < max)
			return (i + 1);
		tmp = tmp->back;
		i++;
	}
	return (-1);
}

int	ft_find_best_pivot(t_stack *stack, int min, int max)
{
	int	left;
	int	right;

	left = ft_find_best_move_left(stack, min, max);
	right = ft_find_best_move_right(stack, min, max);
	if (((right == -1) || (right <= left)) && right != -1)
		return (1);
	else if (((left == -1) || (left <= right)) && left != -1)
		return (-1);
	else
		return (0);
}

void	ft_best_push_to_b(t_push *push)
{
	int	move;

	move = ft_find_best_pivot(push->stack_a, push->min, push->pivot);
	if (move == 1)
	{
		move = ft_find_best_move_right(push->stack_a, push->min, \
			push->pivot);
		while (move > 0)
		{
			ft_ra(push);
			move--;
		}
		ft_pb(push);
	}
	else if (move == -1)
	{
		move = ft_find_best_move_left(push->stack_a, push->min, \
			push->pivot);
		while (move > 0)
		{
			ft_rra(push);
			move--;
		}
		ft_pb(push);
	}
}
