/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getaftermod.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 00:08:25 by sbensarg          #+#    #+#             */
/*   Updated: 2019/12/19 17:39:01 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

s_printf    ft_clearstruct(void)
{
	s_printf var;
	
    var.width = -1;
	var.width2 = -1;
    var.precision_width1 = 0;
	var.precision_width2 = 0;
    var.specifier = 0;
    var.flags = 0;
	return (var);
}

s_printf    ft_getaftermod(const char **fmt, va_list argptr)
{
	s_printf ret;

	ret = ft_clearstruct();
	while (**fmt != '\0')
	{
		
		if (**fmt == '*')
		{
			if (ret.width < 0)
				ret.width = va_arg(argptr, int);
			else
				ret.width2 = va_arg(argptr, int);
			if (ret.width < 0)
    		{
        		ret.width *= -1;
        		ret.flags = 1;
    		}
			if (ret.width2 == -1 && ret.width >= 0 && ret.flags == 1)
			{
        		ret.width2 *= -1;
			//	ret.precision_width2 = 1;
			}
		}
		else if (**fmt == '.')
			if (ret.precision_width1 == 1 || ret.width >= 0)
				ret.precision_width2 = 1;
			else
				ret.precision_width1 = 1;
		else if (**fmt == '0')
			if (ret.precision_width1 == 1 || ret.width >= 0)
				ret.precision_width2 = 1;
			else
				ret.precision_width1 = 1;
		else if (**fmt == '-')                                                                                                                                                                                                                                                                                             
			ret.flags = 1;
		else if (**fmt >= '1' && **fmt <= '9' && ret.width == -1)
		{
			if (ret.width >= 0)
				ret.width2 = ft_atoi(*fmt);
			else
				ret.width = ft_atoi(*fmt);
			while (**fmt >= '0' && **fmt <= '9')
				*fmt = *fmt + 1;
			*fmt = *fmt - 1;
		}
		else if (ret.specifier == 0 && **fmt != '%' && (**fmt < '1' || **fmt > '9'))
		{
			ret.specifier = **fmt;
			break;
		}
		*fmt = *fmt + 1;
	}
	return (ret);
}
