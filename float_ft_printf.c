/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_ft_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:34:30 by ecross            #+#    #+#             */
/*   Updated: 2019/11/18 11:35:23 by ecross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_getlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char		*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*new_str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new_str = (char*)malloc(ft_getlen(s1) + ft_getlen(s2) + 1);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new_str[i] = s2[j];
		i++;
		j++;
	}
	new_str[i] = 0;
	return (new_str);
}


void	ft_round(char *str, int next_digit)
{
	int i;

	if (next_digit > 4)
	{
		i = 0;
		while (str[i])
			i++;
		i--;
		while (str[i] == 57)
		{
			str[i] = 48;
			i--;
		}
		if (str[i] > 47 && str[i] < 57)
			str[i] += 1;
	}
}

char	*make_after(int prec)
{
	char	*after;

	if(!(after = (char*)malloc(prec + 2)))
			return (NULL);
	after[prec + 1] = 0;
	after[0] = '.';
	return (after);
}

char	*ftoa(long double f, int prec)
{
	int		i;
	int		to_print;
	char	*before;
	char	*after;

	if (prec == 0)
		return (ft_itoa((long long)f));
	before = ft_itoa((long long)f);
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
	ft_round(after, (long long)(f * 10));
	return (ft_strjoin(before, after));
}
