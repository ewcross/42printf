/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_ft_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:34:30 by ecross            #+#    #+#             */
/*   Updated: 2019/11/26 13:12:07 by elliotcro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*comma_or_not(char *str)
{
	int		i;
	int		digits;
	char	*new;

	digits = 0;
	i = 0;
	while (str[i] && str[i] != '.')
	{
		if (str[i] > 47 && str[i] < 58)
			digits++;
		i++;
	}
	if (!(new = (char*)malloc(2)))
		return (NULL);
	new[1] = 0;
	if (digits % 3 || !digits)
		new[0] = 0;
	else
		new[0] = ',';
	return (new);
}

char	*make_new_num(char *str, int i, char commas)
{
	char *new;
	
	if (i == -1)
	{
		if (!(new = (char*)malloc(2)))
				return (NULL);
		new[1] = 0;
		new[0] = '1';
	}
	else
	{
		if (!(new = (char*)malloc(3)))
				return (NULL);
		new[2] = 0;
		new[0] = str[i];
		new[1] = '1';
	}
	if (commas)
		return (ft_strjoin(ft_strjoin(new, comma_or_not(str)), str));
	else
		return (ft_strjoin(new, str));
}

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
			{
				str[i] = 48;
				i--;
			}
		}
		if (i == -1 || str[i] == '-' || str[i] == '+' || str[i] == ' ')
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
	printf("digit to round from is: %d\n", (int)(f * 10));
	return (ft_round(after, (long long)(f * 10), commas));
}
