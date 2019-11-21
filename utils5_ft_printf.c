/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5_ft_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 19:02:43 by ecross            #+#    #+#             */
/*   Updated: 2019/11/21 17:07:14 by ecross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*add_commas(char *str)
{
	int		i;
	int		end;
	int		new_pos;
	char	*new;

	i = 0;
	while (str[i])
		i++;
	if (str[0] == '-')
	{
		if (!(new = (char*)malloc(i + ((i - 1) / 3) + 1)))
			return (NULL);
		end = 1;
	}
	else
		if (!(new = (char*)malloc(i + (i / 3) + 1)))
			return (NULL);
	while (--i > end)
	{
		
	}
}

char	*correct_pad_zero(char *str)
{
	if (str[0] == '-' || str[0] == '+' || str[0] == ' ')
	{
		write(1, str, 1);
		g_char_count++;
		str++;
	}
	else if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
	{
		write(1, str, 2);
		g_char_count += 2;
		str += 2;
	}
	return (str);
}

long long			resize(long long arg, t_list *list)
{
	if (list->h == 2)
		return ((long long)((char)arg));
	else if (list->h == 1)
		return ((long long)((short)arg));
	else if (list->l == 1)
		return ((long long)((long)arg));
	else if (list->l == 2)
		return (arg);
	else
		return ((long long)(int)arg);
}

long long unsigned	u_resize(long long unsigned arg, t_list *list)
{
	if (list->h == 2)
		return ((long long unsigned)((char unsigned)arg));
	else if (list->h == 1)
		return ((long long unsigned)((short unsigned)arg));
	else if (list->l == 1)
		return ((long long unsigned)((long unsigned)arg));
	else if (list->l == 2)
		return (arg);
	else
		return ((long long unsigned)(int unsigned)arg);
}
