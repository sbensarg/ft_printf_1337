/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 21:56:09 by sbensarg          #+#    #+#             */
/*   Updated: 2020/01/01 04:16:29 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef     struct 
{
    int     width;
    int     zerowidth1;
    int     precision_width2;
    int     specifier;
    int     flags;
}           s_printf;

int         ft_printf(const char *format, ...);
void        handle_percent(const char **format, va_list argptr, int *i);
void        ft_width_trick(int len, char c, int *i);
s_printf        ft_getaftermod(const char **format, va_list argptr);
void        ft_putstr(char *s, int *ptr);
void        ft_putchar(char c, int *i);
void        ft_putnbr(long nb, int	*i);
size_t      ft_strlen(const char *str);
void        handle_modaftermod(char **ptr, int *i);
int			ft_atoi(const char *str);
int         is_format(const char *mod);
int         len_num(long n);
void        ft_putunsigned(unsigned int nb, int		*i);
char        *ft_substr(char const *s, unsigned int start, size_t len);
char        *decToBinary(long long n, int flag);
char        *decToBinary_p(long long n, int flag);
char        *ft_strdup(const char *s1);
void        *ft_memcpy(void *dest, const void *src, size_t n);
char        *ft_strjoin(char const *s1, char const *s2);
s_printf	ft_clearstruct(void);
void		ft_precision_width(const char **fmt, va_list argptr, s_printf *ret);
void		ft_zero_width(const char **fmt, va_list argptr, s_printf *ret);
void		ft_flag(const char **fmt, va_list argptr, s_printf *ret);
void        handle_int(long nbr, s_printf var, int *i);
#endif
