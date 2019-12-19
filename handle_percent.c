/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:43:10 by sbensarg          #+#    #+#             */
/*   Updated: 2019/12/18 18:34:37 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    handle_percent(const char  **fmt, va_list argptr, int   *i)
{
    s_printf    var;
    int     nbr;
    
    
    var = ft_getaftermod(fmt, argptr);
    if (var.specifier == 'd' || var.specifier == 'i')
        nbr = va_arg(argptr, int);
        
    if (var.width >= 0 && var.precision_width1 == 0 && var.flags == 0)
    {
        if (var.width2 > 0)
            ft_width_trick(var.width - var.width2, ' ', i);
        else
            ft_width_trick(var.width - len_num(nbr), ' ', i);
    }
    if (var.width >= 0 && var.precision_width1 == 1 && var.flags == 0)
    {
        if (var.width2 > 0)
            ft_width_trick(var.width - var.width2, '0', i);
        else
            ft_width_trick(var.width - len_num(nbr), '0', i);
    }
    if (var.width2 >= 0 && var.precision_width2 == 0)
        ft_width_trick(var.width2 - len_num(nbr), ' ', i);
        
    if (var.width2 >= 0 && var.precision_width2 == 1)
        ft_width_trick(var.width2 - len_num(nbr), '0', i);
        
    if (var.specifier == 's')
        ft_putstr(va_arg(argptr, char*), i);
    else if (var.specifier == 'x')
        ft_putstr(decToBinary(va_arg(argptr, int), 1), i);
    else if (var.specifier == 'd' || var.specifier == 'i')
        ft_putnbr(nbr, i);
    else if (var.specifier == 'c')
        ft_putchar(va_arg(argptr, int), i);
    else if (var.specifier == 'u')
        ft_putunsigned(va_arg(argptr, unsigned int), i);
    else
        ft_putchar(var.specifier, i);
    if (var.flags == 1 && var.width >= 0)
    {
        if (var.width2 > 0)
            ft_width_trick(var.width - var.width2, ' ', i);
        else
            ft_width_trick(var.width - len_num(nbr), ' ', i);
    }
    /*if (var.flags == 1 && var.width2 >= 0)
        ft_width_trick(var.width2 - len_num(nbr), ' ', i);*/
}