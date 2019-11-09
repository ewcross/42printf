/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:27:16 by ecross            #+#    #+#             */
/*   Updated: 2019/11/07 16:51:34 by ecross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define START 0
# define END 1
# define CHAR 2
# define TYPE_SET "cspdiuxX"
# define TYPE_NUM 8
# define SPEC_CHARS "-0.* 123456789"
# define FLAG_CHARS "%-."
# define F_NUM 4
# define F_CHARS_ARR "r0-."

typedef struct		s_struct
{
	int				start_pos;
	int				end_pos;
	int				type;
	char			flag_chars[F_NUM];
	int				flag_vals[F_NUM];
	char			flag_found[F_NUM];
	struct s_struct	*next;
}					t_list;

char				*c_convert(va_list arg_list, int prec);
char				*s_convert(va_list arg_list, int prec);
char				*p_convert(va_list arg_list, int prec);
char				*di_convert(va_list arg_list, int prec);
char				*u_convert(va_list arg_list, int prec);
char				*x_convert(va_list arg_list, int prec);
char				*xx_convert(va_list arg_list, int prec);
char				*num_precision(char *str, int prec, int len);
char				*add_prefix(char *str);
int					hex_get_mem_size(unsigned long n);
char				*hex_convert(unsigned long n, int caps);
int					get_mem_size(int nb);
char				*ft_itoa(int n);
int					u_get_mem_size(unsigned int nb);
char				*ft_u_itoa(unsigned int n);
char				*str_precision(char *str, int prec);
void				push_back(t_list **alst, t_list *new);
int					is_in(char ch, const char *set);
void				set_flag_value(t_list *elem, char flag, int value);
int					flag_atoi(const char *str, int start, int end);
int					get_pos(char *arr, char ch);
void				free_list(t_list **list);
void				manage_flags(t_list *elem);
void				set_format(const char *str, t_list *elem);
void				init_elem(t_list *elem, int *spec_pos);
int					add_elem(const char *str, t_list **spec_list,
								int *spec_pos);
void				specifier_pos(const char *str, int *spec_pos);
int					make_list(const char *str, t_list **spec_list);
void				check_stars(va_list arg_list, t_list *list);
void				pad(char *str, char ch, int width);
void				write_padded(char *str, t_list *spec_list);
int					write_spec(va_list arg_list, t_list *spec_list,
								char *(*f_ptr_arr[TYPE_NUM])(va_list, int));
void				init_f_ptr_arr(char *(*f_ptr_arr[TYPE_NUM])(va_list, int));
int					write_output(const char *str, va_list arg_list,
									t_list *spec_list);
int					ft_printf(const char *str, ...);
#endif
