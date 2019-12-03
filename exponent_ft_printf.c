/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exponent_ft_printf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elliotcross <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:37:54 by ecross            #+#    #+#             */
/*   Updated: 2019/12/02 14:16:06 by elliotcro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

double	abs_value(double d)
{
	if (d < 0)
		return (d * -1);
	return (d);
}

char	*make_exp_str(unsigned int exp, char pref)
{
	char *before;
	char *exponent;

	exponent = ft_u_itoa((long long unsigned)exp);
	if (ft_strlen(exponent) == 1)
	{
		if (!(before = (char*)malloc(4)))
			return (NULL);
		before[2] = 48;
	}
	else
	{
		if (!(before = (char*)malloc(4)))
			return (NULL);
	}
	before[3] = 0;
	before[0] = 'e';
	before[1] = pref;
	return (ft_strjoin(before, exponent));
}

char	*get_exponent(double *arg)
{
	unsigned int	exp;
	char			pref;

	exp = 0;
	if (!*arg)
		return (make_exp_str(exp, '+'));
	pref = '+';
	if (abs_value(*arg) + FLT_EPS > 1.0)
	{
		while (abs_value(*arg) + FLT_EPS > 10)
		{
			*arg /= 10;
			exp++;
		}
	}
	else
	{
		pref = '-';
		while (abs_value(*arg) + FLT_EPS <= 1.0)
		{
			*arg *= 10;
			exp++;
		}
	}
	return (make_exp_str(exp, pref));
}
