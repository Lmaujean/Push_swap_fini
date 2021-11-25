/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:41:00 by lmaujean          #+#    #+#             */
/*   Updated: 2021/11/25 13:41:01 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**ft_cpy_all_arg(char **argv)
{
	int			i;
	char		**ret;

	i = 0;
	ret = NULL;
	while (argv[i])
		i++;
	ret = malloc(sizeof(char *) * (i + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (argv[i])
	{
		ret[i] = ft_strdup(argv[i]);
		if (!ret[i])
			return (ret);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

t_stack	*ft_stock_arg_in_stack(char **argv)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = NULL;
	if (argv == NULL)
		return (NULL);
	while (argv[i])
	{
		temp = ft_stack_addback(temp, ft_atoi(argv[i]), 0);
		if (temp == NULL)
			return (temp);
		i++;
	}
	return (temp);
}
