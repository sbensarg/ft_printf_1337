/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getaftermodutils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 03:40:53 by sbensarg          #+#    #+#             */
/*   Updated: 2020/01/01 03:42:21 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

s_printf	ft_clearstruct(void)
{
	s_printf var;

	var.width = 0;
	var.zerowidth1 = 0;
	var.precision_width2 = -1;
	var.flags = 0;
	var.specifier = 0;
	return (var);
}

void		ft_precision_width(const char **fmt, va_list argptr, s_printf *ret)
{
	if (*(*fmt + 1) == '*')
	{
		ret->precision_width2 = va_arg(argptr, int);
		*fmt = *fmt + 1;
	}
	else if (*(*fmt + 1) >= '0' && *(*fmt + 1) <= '9')
		ret->precision_width2 = ft_atoi(*fmt + 1);
	else
		ret->precision_width2 = 0;
	while (*(*fmt + 1) >= '0' && *(*fmt + 1) <= '9')
		*fmt = *fmt + 1;
}

void		ft_zero_width(const char **fmt, va_list argptr, s_printf *ret)
{
	if (*(*fmt + 1) == '*')
	{
		ret->zerowidth1 = va_arg(argptr, int);
		*fmt = *fmt + 1;
	}
	else if (*(*fmt + 1) >= '0' && *(*fmt + 1) <= '9')
		ret->zerowidth1 = ft_atoi(*fmt);
	else
		ret->zerowidth1 = 0;
	while (*(*fmt + 1) >= '0' && *(*fmt + 1) <= '9')
		*fmt = *fmt + 1;
}

void		ft_flag(const char **fmt, va_list argptr, s_printf *ret)
{
	if (*(*fmt + 1) == '*')
	{
		ret->width = va_arg(argptr, int);
		if (ret->width > 0)
			ret->width = ret->width * -1;
		*fmt = *fmt + 1;
	}
	else if (*(*fmt + 1) >= '0' && *(*fmt + 1) <= '9')
		ret->width = ft_atoi(*fmt);
	else
		ret->width = 0;
	while (*(*fmt + 1) >= '0' && *(*fmt + 1) <= '9')
		*fmt = *fmt + 1;
}
