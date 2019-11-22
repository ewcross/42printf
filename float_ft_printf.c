/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_ft_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:34:30 by ecross            #+#    #+#             */
/*   Updated: 2019/11/22 16:09:01 by ecross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*new_str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(new_str = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	i = -1;
	while (s1[++i])
		new_str[i] = s1[i];
	j = 0;
	while (s2[j])
	{
		new_str[i] = s2[j];
		i++;
		j++;
	}
	new_str[i] = 0;
	free(s1);
	free(s2);
	return (new_str);
}

void	ft_round(char *str, int next_digit)
{
	int i;

	if (*str == 0)
		return ;
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

char	*ftoa(double f, int prec, char hash, char commas)
{
	int		i;
	int		to_print;
	char	*before;
	char	*after;

	if (prec == 0 && !hash)
		prec = -1;
	before = ft_itoa((long long)f);
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
	ft_round(after, (long long)(f * 10));
	return (ft_strjoin(before, after));
}
