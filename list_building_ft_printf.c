/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_building_ft_printf.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:56:11 by ecross            #+#    #+#             */
/*   Updated: 2019/12/05 19:28:07 by ecross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		flag_atoi(const char *str, int start, int end)
{
	int output;

	output = 0;
	while (start < end)
	{
		output = (output * 10) + (str[start] - 48);
		start++;
	}
	return (output);
}

void	init_elem(t_list *elem, int *spec_pos)
{
	int	i;

	elem->type = spec_pos[CHAR];
	elem->next = NULL;
	elem->start_pos = spec_pos[START];
	elem->end_pos = spec_pos[END];
	elem->wide_char_found = 0;
	elem->wide_str_found = 0;
	elem->h = 0;
	elem->l = 0;
	i = 0;
	while (FLAG_CHARS_ARR[i])
	{
		elem->flag_chars[i] = FLAG_CHARS_ARR[i];
		elem->flag_vals[i] = 0;
		elem->flag_found[i] = 0;
		i++;
	}
	i = 0;
	while (NEW_FLAGS[i])
	{
		elem->new_flag_found[i] = 0;
		i++;
	}
}

int		add_elem(const char *str, t_list **spec_list, int *spec_pos)
{
	t_list	*new_elem;

	if (!(new_elem = (t_list*)malloc(sizeof(t_list))))
		return (0);
	init_elem(new_elem, spec_pos);
	set_format(str, new_elem);
	push_back(spec_list, new_elem);
	return (1);
}

int		specifier_pos(const char *str, int *spec_pos)
{
	int i;

	i = spec_pos[START] + 1;
	while (str[i])
	{
		if (!is_in(str[i], SPEC_CHARS))
			break ;
		i++;
	}
	spec_pos[END] = i;
	spec_pos[CHAR] = str[i];
	return (i);
}

int		make_list(const char *str, t_list **spec_list)
{
	int i;
	int spec_pos[3];

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '%')
				i += 2;
			else
			{
				spec_pos[START] = i;
				i = specifier_pos(str, spec_pos);
				if (!add_elem(str, spec_list, spec_pos))
					return (0);
			}
		}
		else
			i++;
	}
	return (1);
}
