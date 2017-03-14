/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 00:36:38 by pmclaugh          #+#    #+#             */
/*   Updated: 2017/03/01 21:30:58 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <stddef.h>
# include <wchar.h>
# include <locale.h>
# include "libft.h"
# define FLAG "-+ #0"
# define LENGTH "hljztL"
# define SPECIFIER "csdioxXufFeEaAgGp%nUCSDO"

typedef struct	s_conv
{
	int		percent;
	int		minus;
	int		plus;
	int		space;
	int		hash;
	int		zero;
	int		width;
	int		precision_on;
	int		precision;
	char	length[3];
	char	specifier;
	char	*str;
	char 	endchar;
	int 	wstrlen;
}				t_conv;

char			*prepend(char *str, char c);
char			*apppend(char *str, char c);
int				chr_at(char *str, char c);
char			*insert_at(char *str, char c, int index);

void			im_char(t_conv *conv, va_list va);
void			im_str(t_conv *conv, va_list va);
void			im_int(t_conv *conv, va_list va);
void			im_uint(t_conv *conv, va_list va);
void			im_double(t_conv *conv, va_list va);
void			im_oct(t_conv *conv, va_list va);
void			im_hex(t_conv *conv, va_list va);
void			im_point(t_conv *conv, va_list va);
void			im_pct(t_conv *conv, va_list va);
void			im_n(t_conv *conv, va_list va);
void			im_lint(t_conv *conv, va_list va);
void			import(t_conv *conv, va_list va);
void			setup_import(void);
void	im_nope(t_conv *conv, va_list va);
void	im_wchar(t_conv *conv, va_list va);
void	im_wstr(t_conv *conv, va_list va);


void			pr_char(t_conv *conv);
void			pr_str(t_conv *conv);
void			pr_int(t_conv *conv);
void			pr_double(t_conv *conv);
void			pr_point(t_conv *conv);
void			pr_pct(t_conv *conv);
void			pr_n(t_conv *conv);
void	pr_oct(t_conv *conv);
void			process(t_conv *conv);
void			setup_process(void);
void 	pr_nope(t_conv *conv);

char	*wint_to_str(wchar_t wint);
char	*wstr_to_str(wchar_t *wstr);

void			(*g_import[24])(t_conv *, va_list);
void			(*g_process[24])(t_conv *);

int				ft_printf(char *str, ...);

void	print_conv(t_conv *conv);

#endif
