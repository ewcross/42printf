/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1_ft_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:44:32 by ecross            #+#    #+#             */
/*   Updated: 2019/11/18 19:02:02 by ecross           ###   ########.fr       */
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
	if (prec > -1 && prec < i)
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
		free(str);
		return (new);
	}
	else
		return (str);
}

char	*num_precision(char *str, int prec, int str_pos)
{
	int		str_begin;
	char	*new;

	if (str[0] == '-')
		str_begin = 1;
	else
		str_begin = 0;
	if (!(new = (char*)malloc(prec + 1 + str_begin)))
		return (NULL);
	new[str_begin + prec--] = 0;
	while (str_pos > str_begin - 1)
		new[str_begin + prec--] = str[str_pos--];
	while (prec > str_begin - 1)
		new[str_begin + prec--] = 48;
	if (str_begin)
	{
		new[str_begin + prec] = 48;
		new[prec] = '-';
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
	while (n > 9)
	{
		if (n % 16 > 9)
			str[len--] = (n % 16) + caps;
		else
			str[len--] = (n % 16) + 48;
		n /= 16;
	}
	if (n % 16 > 9)
		str[len--] = (n % 16) + caps;
	else
		str[len--] = (n % 16) + 48;
	return (str);
}
