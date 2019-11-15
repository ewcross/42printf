/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3_ft_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:51:38 by ecross            #+#    #+#             */
/*   Updated: 2019/11/15 09:47:10 by ecross           ###   ########.fr       */
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

char	*malloc_empty_string(void)
{
	char *str;

	str = (char*)malloc(1);
	if (!str)
		return (NULL);
	str[0] = 0;
	return (str);
}

char	*pad(char *str, char ch, int width)
{
	int		i;
	char	*point;

	point = str;
	i = 0;
	while (str[i])
		i++;
	width -= i;
	i = 0;
	if (str[i] == '-' && ch == '0')
	{
		write(1, str, 1);
		g_char_count++;
		point++;
	}
	while (i < width)
	{
		write(1, &ch, 1);
		g_char_count++;
		i++;
	}
	return (point);
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
