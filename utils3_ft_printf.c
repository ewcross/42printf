/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3_ft_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:51:38 by ecross            #+#    #+#             */
/*   Updated: 2019/11/07 16:57:22 by ecross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	free_list(t_list **list)
{
	t_list *temp;

	while (*list)
	{
		temp = *list;
		*list = (*list)->next;
		free(temp);
	}
}

void	pad(char *str, char ch, int width)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	width -= i;
	i = 0;
	while (i < width)
	{
		write(1, &ch, 1);
		i++;
	}
}

int		is_in(char ch, const char *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (ch == set[i])
			return (1);
		i++;
	}
	return (0);
}

int		get_pos(char *arr, char ch)
{
	int i;

	i = 0;
	while (arr[i])
	{
		if (arr[i] == ch)
			break ;
		i++;
	}
	return (i);
}
