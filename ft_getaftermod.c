/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getaftermod.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 00:08:25 by sbensarg          #+#    #+#             */
/*   Updated: 2020/01/01 02:15:53 by sbensarg         ###   ########.fr       */
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

s_printf    ft_getaftermod(const char **fmt, va_list argptr)
{
	s_printf ret;

	ret = ft_clearstruct();
	*fmt = *fmt + 1;
	while (**fmt != '\0')
	{
		if (**fmt == '*' && *(*fmt - 1) != '.')
			ret.width = va_arg(argptr, int);
		else if (**fmt == '*' && *(*fmt - 1) == '.')
			ret.precision_width2 = va_arg(argptr, int);
		else if (**fmt == '.')
		{
			if (*(*fmt + 1) == '*')
			{
				ret.precision_width2 = va_arg(argptr, int);
				*fmt = *fmt + 1;
			}
			else if (*(*fmt + 1) >= '0' && *(*fmt + 1) <= '9')
				ret.precision_width2 = ft_atoi(*fmt + 1);
			else
				ret.precision_width2 = 0;
			while (*(*fmt + 1) >= '0' && *(*fmt + 1) <= '9')
				*fmt = *fmt + 1;
		}
		else if (**fmt == '0' && *(*fmt + 1) == '.')
		{
			ret.width = 0;
			ret.precision_width2 = 0;
			*fmt = *fmt + 1;
		}
		else if (**fmt == '0')
		{
			if (*(*fmt + 1) == '*')
			{
				ret.zerowidth1 = va_arg(argptr, int);
				*fmt = *fmt + 1;
			}
			else if (*(*fmt + 1) >= '0' && *(*fmt + 1) <= '9')
				ret.zerowidth1 = ft_atoi(*fmt);
			else
				ret.zerowidth1 = 0;
			while (*(*fmt + 1) >= '0' && *(*fmt + 1) <= '9')
				*fmt = *fmt + 1;
		}
		else if (**fmt == '-')
		{
			if (*(*fmt + 1) == '*')
			{
				ret.width = va_arg(argptr, int);
				if (ret.width > 0)
					ret.width = ret.width * -1;
				*fmt = *fmt + 1;
			}
			else if (*(*fmt + 1) >= '0' && *(*fmt + 1) <= '9')
				ret.width = ft_atoi(*fmt);
			else
				ret.width = 0;
			while (*(*fmt + 1) >= '0' && *(*fmt + 1) <= '9')
				*fmt = *fmt + 1;
		}
		else if (**fmt >= '1' && **fmt <= '9')
		{
			ret.width = ft_atoi(*fmt);
			while (*(*fmt + 1) >= '0' && *(*fmt + 1) <= '9')
				*fmt = *fmt + 1;
		}
		else if (ret.specifier == 0 && (**fmt < '1' || **fmt > '9'))
		{
			ret.specifier = **fmt;
			break ;
		}
		*fmt = *fmt + 1;
	}
	return (ret);
}
