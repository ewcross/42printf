/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:27:16 by ecross            #+#    #+#             */
/*   Updated: 2019/12/06 11:28:21 by ecross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <wchar.h>

# define START 0
# define END 1
# define CHAR 2
# define TYPE_SET "cspdiuxXfeng"
# define TYPE_NUM 12
# define SPEC_CHARS "-0.*123456789lh +#'"
# define SPEC_DELIMS "%-."
# define FLAG_CHARS_ARR "r0-."
# define F_NUM 4
# define NEW_FLAGS " +#'"
# define NEW_F_NUM 4
# define SIZE_CHARS "hl"
# define FLT_EPS 0.000000000000001

typedef struct		s_struct
{
	int				start_pos;
	int				end_pos;
	int				type;
	char			flag_chars[F_NUM];
	int				flag_vals[F_NUM];
	char			flag_found[F_NUM];
	char			new_flag_found[NEW_F_NUM];
	char			wide_char_found;
	wint_t			w_int;
	char			wide_str_found;
	wchar_t			*w_str;
	int				h;
	int				l;
	struct s_struct	*next;
}					t_list;

int					g_char_count;

char				*c_convert(t_list *list, va_list arg_list);
char				*s_convert(t_list *list, va_list arg_list);
char				*p_convert(t_list *list, va_list arg_list);
char				*di_convert(t_list *list, va_list arg_list);
char				*u_convert(t_list *list, va_list arg_list);
char				*x_convert(t_list *list, va_list arg_list);
char				*xx_convert(t_list *list, va_list arg_list);
char				*f_convert(t_list *list, va_list arg_list);
char				*e_convert(t_list *list, va_list arg_list);
char				*g_convert(t_list *list, va_list arg_list);
char				*n_convert(t_list *list, va_list arg_list);
long long			resize(long long arg, t_list *list);
long long unsigned	u_resize(long long unsigned arg, t_list *list);
void				get_x_p(double arg, int *x_p, t_list *list);
int					g_inf_checker(double arg, char **var_addr);
char				*trim_zeros(char *str);
int					dots(char *str);
char				*make_f(double arg, int *x_p, char *h_c, t_list *list);
wchar_t				*str_prec_wide(wchar_t *str, int prec);
wchar_t				*ft_strdup_wide(wchar_t *src);
void				put_wstr(wchar_t *w_str);
void				wide_str_handling(va_list arg_list, t_list *list, int prec);
int					wstr_too_big(va_list arg_list, t_list *list);
int					wint_too_big(va_list arg_list, t_list *list);
int					ft_strlen(char *str);
char				*num_precision(char *str, int prec, int len);
char				*add_prefix(char *str, char x);
char				*prefix_signed(char *num, t_list *list);
int					hex_get_mem_size(unsigned long long n);
char				*hex_convert(unsigned long long n, int caps);
int					get_mem_size(long long nb);
char				*ft_itoa(long long n);
int					u_get_mem_size(long long unsigned nb);
char				*ft_u_itoa(long long unsigned num);
char				*str_precision(char *str, int prec);
void				push_back(t_list **alst, t_list *new);
int					is_in(char ch, const char *set);
void				get_new_flags(const char *str, t_list *elem);
void				set_flag_value(t_list *elem, int value, char flag);
int					flag_atoi(const char *str, int start, int end);
int					get_pos(char *arr, char ch);
void				free_list(t_list **list);
void				manage_flags(t_list *elem);
void				set_format(const char *str, t_list *elem);
void				init_elem(t_list *elem, int *spec_pos);
int					add_elem(const char *str, t_list **spec_list,
								int *spec_pos);
int					specifier_pos(const char *str, int *spec_pos);
int					make_list(const char *str, t_list **spec_list);
void				negs(int r_pos, int zero_pos, int dash_pos, t_list *list);
void				check_stars(va_list arg_list, t_list *list);
char				*malloc_empty_string(void);
char				*correct_pad_zero(char *str);
int					commas_number(char *str);
char				*add_commas(char *str);
char				*pad(char *str, char ch, int width, char type);
void				write_var(char *str, t_list *spec_list);
void				write_padded(char *str, t_list *spec_list);
int					write_spec(va_list arg_list, t_list *spec_list,
							char *(*f_ptr_arr[TYPE_NUM])(t_list *, va_list));
const char			*write_plaintext(const char *ch_ptr);
void				init_f_ptr_arr(char *(*f_ptr_arr[])(t_list *, va_list));
int					write_output(const char *str, va_list arg_list,
									t_list *spec_list);
int					ft_printf(const char *str, ...);
char				*ft_strdup(const char *src);
char				*ft_strjoin(char *s1, char *s2);
int					comma_or_not(char *str);
char				*make_new_num(char *str, int i, char commas);
char				*ft_round(char *str, int next_digit, char commas);
int					pos_atoi(char *str, int start);
char				*inc_exp(char *str);
int					float_specials(double arg, char **var_addr);
char				*reformat_e(char *str, char *exp_str);
char				*make_after(int prec);
char				*make_before(double f);
char				*ftoa(double f, int prec, char hash, char comma);
double				abs_value(double d);
char				*make_exp_str(unsigned int exp, char pref);
char				*get_exponent(double *arg);
#endif
