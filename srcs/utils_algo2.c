/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:25:26 by lmaujean          #+#    #+#             */
/*   Updated: 2021/11/25 13:25:28 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_get_index_min(t_stack *stack)
{
	t_list	*temp;
	int		index;

	temp = stack->start;
	index = temp->index;
	while (temp)
	{
		if (temp->next && temp->next->index < index)
			index = temp->next->index;
		temp = temp->next;
	}
	return (index);
}

int	ft_get_index_max(t_stack *stack)
{
	t_list	*temp;
	int		index;

	temp = stack->start;
	index = temp->index;
	while (temp)
	{
		if (temp->next && temp->next->index > index)
			index = temp->next->index;
		temp = temp->next;
	}
	return (index);
}
