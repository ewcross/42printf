/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils7_ft_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:28:49 by ecross            #+#    #+#             */
/*   Updated: 2019/12/04 18:34:12 by ecross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
