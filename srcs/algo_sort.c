/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:22:45 by lmaujean          #+#    #+#             */
/*   Updated: 2021/11/25 13:22:50 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_push_to_a(t_push *push)
{
	int	move;

	move = 0;
	while (push->stack_b)
	{
		ft_move_under_pivot(push, 'B', push->pivot - 1, move);
		ft_pa(push);
		push->pivot = push->stack_a->start->index;
		ft_choice_swap(push);
	}
	ft_move_under_pivot(push, 'A', push->min, move);
}

void	ft_push_to_b(t_push *push)
{
	int	save;

	push->max = ft_get_index_max(push->stack_a);
	push->min = ft_get_index_min(push->stack_a);
	push->pivot = push->stack_a->len / 10 + 1;
	save = push->pivot;
	while (push->stack_a->len > 3)
	{
		if (push->pivot >= push->max)
			push->pivot = push->max - 1;
		if (ft_find_best_pivot(push->stack_a, push->min, \
				push->pivot) == 0)
			push->pivot += save;
		else
			ft_best_push_to_b(push);
	}
	ft_sort_3(push);
	ft_ra(push);
}

void	ft_medium_sort(t_push *push)
{
	ft_push_to_b(push);
	ft_push_to_a(push);
}
