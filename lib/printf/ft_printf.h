/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 21:10:53 by aminoru-          #+#    #+#             */
/*   Updated: 2022/07/07 17:53:01 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <wchar.h>
# include "../libft/libft.h"

# define P_HOLDER_ALL "-0# +123456789*"
# define P_HOLDER_ALL_FLAGS "-0# +"
# define P_HOLDER_JUSTIFY '-'
# define P_HOLDER_LEFT_PADS '0'
# define P_HOLDER_STAR '*'
# define P_HOLDER_PRECISION '.'
# define P_HOLDER_PREFIX "# +"

# define DECIMAL_BASE "0123456789"
# define OCTAL_BASE "01234567"
# define HEXADECIMAL_L_BASE "0123456789abcdef"
# define HEXADECIMAL_U_BASE "0123456789ABCDEF"

# define SPACE ' '
# define PLUS '+'
# define MINUS '-'
# define PREFIX_OCTAL "0"
# define PREFIX_HEX_L "0x"
# define PREFIX_HEX_U "0X"

typedef struct s_format
{
	const char	*format;
	va_list		ap;
	size_t		i;
	size_t		len;
}				t_format;

typedef struct s_holder
{
	int		left_justify;
	int		width;
	int		precision;
	char	padding;
	char	specifier;
	char	*argument;
	char	*prefix;
	size_t	len;
}				t_holder;

int			ft_printf(const char *format, ...);
int			ft_vprintf(const char *format, va_list ap);

// Structs inicialization
t_format	*ft_inicialize_stdout(const char *format, va_list ap);
t_holder	*ft_inicialize_placeholder(void);

// Placeholder
void		ft_placeholder(t_format *fmt);
void		*ft_format_specifiers(t_format *fmt, t_holder *h);
void		*ft_sub_specifier(t_format *fmt, t_holder *h);
void		ft_fs_flags(t_format *fmt, t_holder *h);
void		ft_fs_width(t_format *fmt, t_holder *h);
void		ft_fs_precision(t_format *fmt, t_holder *h);
void		ft_fs_specifier(t_format *fmt, t_holder *h);
void		ft_type_specifier(t_format *fmt, t_holder *h);

// Adicional function to LIBFT
char		*ft_appendchr(char const *s, char const ch);
char		*ft_strndup(const char *s1, size_t n);
char		*ft_uitoa(unsigned long nbr, char *base);

// Convert functions
void		ft_convert_c(t_format *fmt, t_holder *h);
void		ft_convert_s(t_format *fmt, t_holder *h);
void		ft_convert_ux(t_format *fmt, t_holder *h, char *base);
void		ft_convert_p(t_format *fmt, t_holder *h);
void		ft_convert_pct(t_holder *h);
void		ft_convert_d_i(t_format *fmt, t_holder *h);

// Convert utils
void		ft_add_prefix(t_holder *h, int sign);
void		ft_fill_left_pad(char **src, char padding, int width);
void		ft_fill_right_pad(char **src, char padding, int width);

#endif