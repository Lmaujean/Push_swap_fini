/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:23:17 by lmaujean          #+#    #+#             */
/*   Updated: 2021/11/25 13:23:18 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free(char **ptr)
{
	int	i;

	i = 0;
	if (ptr)
	{
		while (ptr[i])
		{
			free(ptr[i]);
			ptr[i] = NULL;
			i++;
		}
		free(ptr);
		ptr = NULL;
	}
}

int	*ft_copy_stack(t_stack *src)
{
	int		stack_len;
	int		i;
	t_list	*temp;
	int		*dest;

	i = 0;
	stack_len = src->len;
	temp = src->start;
	dest = malloc(sizeof(*dest) * stack_len);
	while (i < stack_len)
	{
		dest[i] = temp->value;
		temp = temp->next;
		i++;
	}
	return (*&dest);
}

void	ft_sort_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
		}
	}
}

void	ft_create_index(t_push *push)
{
	int		j;
	int		*tab;
	t_list	*tmp;

	tmp = push->stack_a->start;
	tab = ft_copy_stack(push->stack_a);
	ft_sort_tab(tab, push->stack_a->len);
	while (tmp)
	{
		j = 0;
		while (j < push->stack_a->len)
		{
			if (tab[j] == tmp->value)
			{
				tmp->index = j;
				break ;
			}
			j++;
		}
		tmp = tmp->next;
	}
	free(tab);
}

int	main(int argc, char **argv)
{
	t_push	*push;
	char	**ret;

	ret = NULL;
	if (argc == 2)
		ret = ft_split(argv[1], ' ');
	else if (argc > 2)
		ret = ft_cpy_all_arg(argv + 1);
	else
		return (0);
	push = NULL;
	push = ft_init_stack(push);
	if (ret && ret[0] && !ft_pars(ret))
	{
		push->stack_a = ft_stock_arg_in_stack(ret);
		ft_create_index(push);
		ft_sort(push);
	}
	else
		ft_putstr_fd("Error\n", 1);
	ft_free(ret);
	ft_clear_push(push);
	return (0);
}
