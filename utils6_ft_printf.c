/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6_ft_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:34:02 by ecross            #+#    #+#             */
/*   Updated: 2019/12/04 17:28:35 by ecross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		pos_atoi(char *str, int start)
{
	int output;
	int neg;

	output = 0;
	neg = 1;
	if (str[start] == 43 || str[start] == 45)
	{
		neg *= 44 - str[start];
		start++;
	}
	while (str[start])
	{
		output = (output * 10) + (str[start] - 48);
		start++;
	}
	return (output * neg);
}

char    *inc_exp(char *str)
{
	int i;

	i = 0;
	while (str[i])
	        i++;
	i--;
	while (str[i] == 57 && (str[i] != '+' || str[i] != '-'))
	        str[i--] = 48;
	if (str[i] == '+' || str[i] == '-')
	{
	        str[0] = str[1];
	        str[1] = '1';
	        return (ft_strjoin(ft_strdup("e"), str));
	}
	else if (str[i] > 47 && str[i] < 57)
	        str[i] += 1;
	return (str);
}

char    *reformat_e(char *str, char *exp_str)
{
	int		i;
	char	*new;

	if ((str[0] == '1' && str[1] == '0')
			|| (str[0] == '-' && str[1] == '1' && str[2] == '0'))
	{
		if (!(new = (char*)malloc(ft_strlen(str))))
		        return (NULL);
		i = 0;
		while (str[++i])
		        new[i - 1] = str[i];
		new[i - 1] = 0;
		if (str[0] == '-')
		{
		        new[0] = '-';
		        new[1] = '1';
		}
		else
		        new[0] = '1';
		free(str);
		return (ft_strjoin(new, inc_exp(exp_str)));
	}
	return (ft_strjoin(str, exp_str));
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*new_str;

	if (src == NULL)
		return (NULL);
	i = 0;
	while (src[i])
		i++;
	new_str = (char*)malloc(sizeof(*src) * (i + 1));
	if (new_str == NULL)
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
