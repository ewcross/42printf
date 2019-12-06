/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils7_ft_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:28:49 by ecross            #+#    #+#             */
/*   Updated: 2019/12/06 11:36:16 by ecross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

wchar_t	*ft_strdup_wide(wchar_t *src)
{
	int		i;
	wchar_t	*new_str;

	if (!src)
		return (NULL);
	i = 0;
	while (src[i])
		i++;
	new_str = (wchar_t*)malloc(sizeof(wchar_t) * (i + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (src[i])
	{
		new_str[i] = src[i];
		i++;
	}
	new_str[i] = 0;
	return (new_str);
}

wchar_t	*str_prec_wide(wchar_t *str, int prec)
{
	int		i;
	wchar_t	*new;

	i = 0;
	while (str[i])
		i++;
	if (prec > -1 && prec < i)
	{
		if (!(new = (wchar_t*)malloc(sizeof(wchar_t) * (prec + 1))))
			return (NULL);
		new[prec] = 0;
		i = 0;
		while (i < prec)
		{
			new[i] = str[i];
			i++;
		}
		free(str);
		return (new);
	}
	else
		return (str);
}

int		float_specials(double arg, char **var_addr)
{
	if (arg == INFINITY)
	{
		*var_addr = ft_strdup("inf");
		return (1);
	}
	else if (arg == -INFINITY)
	{
		*var_addr = ft_strdup("-inf");
		return (1);
	}
	else if (arg != arg)
	{
		*var_addr = ft_strdup("nan");
		return (1);
	}
	else
		return (0);
}

int		comma_or_not(char *str)
{
	int		i;
	int		digits;

	digits = 0;
	i = 0;
	while (str[i] && str[i] != '.')
	{
		if (str[i] > 47 && str[i] < 58)
			digits++;
		i++;
	}
	if (digits % 3 || !digits)
		return (0);
	return (1);
}

char	*make_new_num(char *str, int i, char commas)
{
	char *new;

	if (!(new = (char*)malloc(3)))
		return (NULL);
	new[2] = 0;
	if (i == -1)
	{
		new[0] = '1';
		new[1] = ',';
	}
	else
	{
		new[0] = '-';
		new[1] = '1';
		str[i] = ',';
	}
	if (!commas || !comma_or_not(str))
	{
		new[1] = 0;
		if (i != -1)
			str[i] = '1';
	}
	return (ft_strjoin(new, str));
}
