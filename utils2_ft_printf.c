/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_ft_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:46:58 by ecross            #+#    #+#             */
/*   Updated: 2019/11/18 19:11:24 by ecross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		get_mem_size(long long nb)
{
	int mem_size;

	if (nb == 0)
		return (1);
	mem_size = 0;
	if (nb < 0)
		mem_size++;
	while (nb)
	{
		mem_size++;
		nb /= 10;
	}
	return (mem_size);
}

char	*ft_itoa(long long n)
{
	int			mem_size;
	long long	num;
	char		*str;

	num = n;
	mem_size = get_mem_size(n);
	str = (char*)malloc(sizeof(char) * (mem_size + 1));
	if (str == NULL)
		return (NULL);
	str[mem_size--] = 0;
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	while (num > 9)
	{
		str[mem_size--] = (num % 10) + 48;
		num /= 10;
	}
	str[mem_size] = (num % 10) + 48;
	return (str);
}

int		u_get_mem_size(long long unsigned nb)
{
	int mem_size;

	if (nb == 0)
		return (1);
	mem_size = 0;
	while (nb)
	{
		mem_size++;
		nb /= 10;
	}
	return (mem_size);
}

char	*ft_u_itoa(long long unsigned num)
{
	int		mem_size;
	char	*str;

	mem_size = u_get_mem_size(num);
	str = (char*)malloc(sizeof(char) * (mem_size + 1));
	if (str == NULL)
		return (NULL);
	str[mem_size--] = 0;
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	while (num > 9)
	{
		str[mem_size--] = (num % 10) + 48;
		num /= 10;
	}
	str[mem_size] = (num % 10) + 48;
	return (str);
}

void	push_back(t_list **alst, t_list *new)
{
	t_list *temp;

	if (alst == NULL)
		return ;
	temp = *alst;
	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	while (temp)
	{
		if (temp->next == NULL)
		{
			temp->next = new;
			return ;
		}
		temp = temp->next;
	}
}
