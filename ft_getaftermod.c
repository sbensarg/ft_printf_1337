/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getaftermod.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 00:08:25 by sbensarg          #+#    #+#             */
/*   Updated: 2020/01/01 03:40:43 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_width_num(const char **fmt, s_printf *ret)
{
	ret->width = ft_atoi(*fmt);
	while (*(*fmt + 1) >= '0' && *(*fmt + 1) <= '9')
		*fmt = *fmt + 1;
}

void		ft_zero_point(const char **fmt, s_printf *ret)
{
	ret->width = 0;
	ret->precision_width2 = 0;
	*fmt = *fmt + 1;
}

void		ft_getaftermodcond(const char **fmt, va_list argptr, s_printf *ret)
{
	while (**fmt != '\0')
	{
		if (**fmt == '*' && *(*fmt - 1) != '.')
			ret->width = va_arg(argptr, int);
		else if (**fmt == '*' && *(*fmt - 1) == '.')
			ret->precision_width2 = va_arg(argptr, int);
		else if (**fmt == '.')
			ft_precision_width(fmt, argptr, ret);
		else if (**fmt == '0' && *(*fmt + 1) == '.')
			ft_zero_point(fmt, ret);
		else if (**fmt == '0')
			ft_zero_width(fmt, argptr, ret);
		else if (**fmt == '-')
			ft_flag(fmt, argptr, ret);
		else if (**fmt >= '1' && **fmt <= '9')
			ft_width_num(fmt, ret);
		else if (ret->specifier == 0 && (**fmt < '1' || **fmt > '9'))
		{
			ret->specifier = **fmt;
			break ;
		}
		*fmt = *fmt + 1;
	}
}

s_printf	ft_getaftermod(const char **fmt, va_list argptr)
{
	s_printf ret;

	ret = ft_clearstruct();
	*fmt = *fmt + 1;
	ft_getaftermodcond(fmt, argptr, &ret);
	return (ret);
}
