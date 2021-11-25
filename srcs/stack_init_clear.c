/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_clear.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:24:49 by lmaujean          #+#    #+#             */
/*   Updated: 2021/11/25 13:24:51 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_push	*ft_init_stack(t_push *push)
{
	push = malloc(sizeof(*push));
	push->stack_a = NULL;
	push->stack_b = NULL;
	return (push);
}

t_push	*ft_clear_push(t_push *push)
{
	while (push->stack_a)
		push->stack_a = ft_stack_delfront(push->stack_a);
	while (push->stack_b)
		push->stack_b = ft_stack_delfront(push->stack_b);
	free(push);
	push = NULL;
	return (push);
}
