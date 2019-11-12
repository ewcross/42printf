/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1_ft_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:44:32 by ecross            #+#    #+#             */
/*   Updated: 2019/11/12 10:21:12 by elliotcro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*str_precision(char *str, int prec)
{
	int		i;
	char	*new;

	i = 0;
	while (str[i])
		i++;
	if (prec < i)
	{
		if (!(new = (char*)malloc(prec + 1)))
			return (NULL);
		new[prec] = 0;
		i = 0;
		while (i < prec)
		{
			new[i] = str[i];
			i++;
		}
		return (new);
	}
	else
		return (str);
}

char	*num_precision(char *str, int prec, int len)
{
	int		i;
	char	*new;

	if (!(new = (char*)malloc(prec + 1)))
		return (NULL);
	new[prec] = 0;
	i = 0;
	while (i < prec - len)
	{
		new[i] = 48;
		i++;
	}
	while (str[i - (prec - len)])
	{
		new[i] = str[i - (prec - len)];
		i++;
	}
	free(str);
	return (new);
}

char	*add_prefix(char *str)
{
	int		i;
	char	*new_str;

	i = 0;
	while (str[i])
		i++;
	if (!(new_str = (char*)malloc(i + 3)))
		return (NULL);
	new_str[i + 2] = 0;
	i--;
	while (i > -1)
	{
		new_str[i + 2] = str[i];
		i--;
	}
	free(str);
	new_str[1] = 'x';
	new_str[0] = '0';
	return (new_str);
}

int		hex_get_mem_size(unsigned long long n)
{
	int digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		digits++;
		n /= 16;
	}
	return (digits);
}

char	*hex_convert(unsigned long long n, int caps)
{
	int		len;
	char	*str;

	len = hex_get_mem_size(n);
	if (!(str = (char*)malloc(len + 1)))
		return (NULL);
	str[len--] = 0;
	while (n > 0)
	{
		if (n % 16 > 9)
			str[len--] = (n % 16) + caps;
		else
			str[len--] = (n % 16) + 48;
		n /= 16;
	}
	return (str);
}
