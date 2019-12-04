/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_ft_printf_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:17:31 by ecross            #+#    #+#             */
/*   Updated: 2019/12/04 18:25:16 by ecross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_round(char *str, int next_digit, char commas)
{
	int i;

	if (*str != 0 && str && next_digit > 4)
	{
		i = 0;
		while (str[i])
			i++;
		i--;
		while ((str[i] == 57 || str[i] == ',' || str[i] == '.') && i > -1)
		{
			if (str[i] == ',' || str[i] == '.')
				i--;
			else
				str[i--] = 48;
		}
		if (i == -1 || str[i] == '-')
			return (make_new_num(str, i, commas));
		else if (str[i] > 47 && str[i] < 57)
			str[i] += 1;
	}
	return (str);
}

char	*make_after(int prec)
{
	char	*after;

	if (!(after = (char*)malloc(prec + 2)))
		return (NULL);
	if (prec == -1)
		after[0] = 0;
	else
	{
		after[prec + 1] = 0;
		after[0] = '.';
	}
	return (after);
}

char	*make_before(double f)
{
	char	*before;

	if ((f < 0 && f > -1) || (1.0 / f) == -INFINITY)
		before = ft_itoa((long long)f - 1);
	else
		before = ft_itoa((long long)f);
	if ((f < 0 && f > -1) || (1.0 / f) == -INFINITY)
		before[1] = '0';
	return (before);
}

char	*ftoa(double f, int prec, char hash, char commas)
{
	int		i;
	int		to_print;
	char	*before;
	char	*after;

	if (prec == 0 && !hash)
		prec = -1;
	before = make_before(f);
	if (commas)
		before = add_commas(before);
	if (f < 0)
		f *= -1;
	f = f - (long long)f;
	after = make_after(prec);
	i = 0;
	while (i < prec)
	{
		f = f * 10;
		to_print = (long long)f;
		f = f - (long long)f;
		after[i + 1] = to_print + 48;
		i++;
	}
	after = ft_strjoin(before, after);
	return (ft_round(after, (long long)(f * 10), commas));
}
