/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5_ft_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 19:02:43 by ecross            #+#    #+#             */
/*   Updated: 2019/11/27 11:19:04 by ecross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int					commas_number(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	if (str[0] == '-')
		i--;
	if (!(i % 3))
		return ((i / 3) - 1);
	else
		return (i / 3);
}

char				*add_commas(char *str)
{
	int		i;
	int		commas;
	int		pos;
	char	*new;

	i = ft_strlen(str);
	commas = commas_number(str);
	pos = i + commas;
	if (!(new = (char*)malloc(pos + 1)))
		return (NULL);
	new[pos--] = 0;
	str = str + (i - 1);
	while (commas)
	{
		i = 4;
		while (--i > 0)
			new[pos--] = *(str--);
		new[pos--] = ',';
		commas--;
	}
	while (pos > -1)
		new[pos--] = *(str--);
	free(++str);
	return (new);
}

char				*correct_pad_zero(char *str)
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
