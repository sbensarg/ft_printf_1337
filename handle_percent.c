/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:43:10 by sbensarg          #+#    #+#             */
/*   Updated: 2020/01/01 03:48:44 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    put_specstr(char *str, int len, int   *i)
{
    int j;
    int ret;

    j = 0;
    ret = 0;
    while(len > 0 && str[j] != '\0')
    {
        ft_putchar(str[j], i);
        ret = 1;
        len--;
        j++;
    }
    return (ret);
}

void    handle_string(char  *str, s_printf var, int   *i)
{
   int lenstr;
   int  j;
   
    j = 0;
    str = (str == NULL) ? "(null)" : str;
    lenstr = ft_strlen(str);
    if (var.width >= 0)
    {
        if (var.precision_width2 >= 0 && var.precision_width2 < lenstr && lenstr > 0)
            ft_width_trick(var.width - var.precision_width2, ' ', i);
        else
            ft_width_trick(var.width - lenstr, ' ', i);
    }
    if (var.precision_width2 >= 0)
        put_specstr(str, var.precision_width2, i);
    else
        ft_putstr(str, i);
    if (var.width < 0 && (var.precision_width2 >= lenstr || lenstr == 0))
         ft_width_trick((var.width * -1) - lenstr, ' ', i);
    else if ((var.width < 0 && var.precision_width2 < lenstr && var.precision_width2 >= (var.width * -1)) || var.precision_width2 == -1)
        ft_width_trick((var.width * -1) - lenstr, ' ', i);
    else if ((var.width < 0 && var.precision_width2 < lenstr && var.precision_width2 >= (var.width * -1)) || var.precision_width2 == 0)
        ft_width_trick((var.width * -1), ' ', i);
    else if ( var.width < 0 && var.precision_width2 < (var.width * -1) && var.precision_width2 < lenstr && var.precision_width2 < 0)
        ft_width_trick((var.width * -1) - lenstr, ' ', i);
    else if (var.width < 0 && var.precision_width2 < (var.width * -1) && var.precision_width2 > 0)
         ft_width_trick((var.width * -1) - var.precision_width2, ' ', i);
}

void handle_x(char  *str, s_printf var, int *i)
{
    int lenstr;
    
    if (str[0] == '0' && str[1] == '\0' && var.precision_width2 == 0)
        lenstr = 0;
    else
        lenstr = ft_strlen(str);
    
    if (var.width > var.precision_width2 && var.precision_width2 >= lenstr)
        ft_width_trick(var.width - var.precision_width2, ' ', i);
    else if (var.width > var.precision_width2 && var.precision_width2 < lenstr)
        ft_width_trick(var.width - lenstr, ' ', i);
    if (var.zerowidth1 > 0 && var.precision_width2 >= lenstr)
        ft_width_trick(var.zerowidth1 - var.precision_width2, ' ', i);
    else if (var.zerowidth1 > 0 && var.precision_width2 < lenstr && var.precision_width2 >= 0)
        ft_width_trick(var.zerowidth1 - lenstr, ' ', i);
    if(var.precision_width2 >= 0)
         ft_width_trick(var.precision_width2 - lenstr, '0', i);
    if (var.zerowidth1 > 0 && var.precision_width2 < 0)
        ft_width_trick(var.zerowidth1 - lenstr, '0', i);
    if (lenstr == 0 && var.precision_width2 >= 0)
        ft_strlen(str);
    else
        ft_putstr(str, i);
    if (var.width < 0 && var.precision_width2 < (var.width * -1) && lenstr >= var.precision_width2 && var.precision_width2 > 0)
        ft_width_trick((var.width * -1) - lenstr, ' ', i);
    else if (var.width < 0 && var.precision_width2 < (var.width * -1) && lenstr < var.precision_width2 && var.precision_width2 > 0) 
        ft_width_trick((var.width * -1) - var.precision_width2, ' ', i);
    else if (var.width < 0 && var.precision_width2 <= 0)
        ft_width_trick((var.width * -1) - lenstr, ' ', i);
    if (var.zerowidth1 < 0 && var.precision_width2 <= 0)
        ft_width_trick((var.zerowidth1 * -1) - lenstr, ' ', i);
}

void    handle_p(char  *str, s_printf var, int *i)
{
    int lenstr;
    
    str = ft_strjoin("0x", str);
    if (str[2] == '0' && str[3] == '\0' && var.precision_width2 == 0)
        lenstr = 2;
    else
        lenstr = ft_strlen(str);
    
    if (var.width > var.precision_width2 && var.precision_width2 >= lenstr)
        ft_width_trick(var.width - var.precision_width2, ' ', i);
    else if (var.width > var.precision_width2 && var.precision_width2 < lenstr)
        ft_width_trick(var.width - lenstr, ' ', i);
    if (var.zerowidth1 > 0 && var.precision_width2 >= lenstr)
        ft_width_trick(var.zerowidth1 - var.precision_width2, ' ', i);
    else if (var.zerowidth1 > 0 && var.precision_width2 < lenstr && var.precision_width2 >= 0)
        ft_width_trick(var.zerowidth1 - lenstr, ' ', i);
    if(var.precision_width2 >= 0)
         ft_width_trick(var.precision_width2 - lenstr, '0', i);
    if (var.zerowidth1 > 0 && var.precision_width2 < 0)
        ft_width_trick(var.zerowidth1 - lenstr, '0', i);
    if (lenstr == 2 && var.precision_width2 == 0)
        ft_putstr("0x", i);
    else
        ft_putstr(str, i);
    if (var.width < 0 && var.precision_width2 < (var.width * -1) && lenstr >= var.precision_width2 && var.precision_width2 > 0)
        ft_width_trick((var.width * -1) - lenstr, ' ', i);
    else if (var.width < 0 && var.precision_width2 < (var.width * -1) && lenstr < var.precision_width2 && var.precision_width2 > 0) 
        ft_width_trick((var.width * -1) - var.precision_width2, ' ', i);
    else if (var.width < 0 && var.precision_width2 <= 0)
        ft_width_trick((var.width * -1) - lenstr, ' ', i);
    if (var.zerowidth1 < 0 && var.precision_width2 <= 0)
        ft_width_trick((var.zerowidth1 * -1) - lenstr, ' ', i);
}

void    handle_char(va_list argptr, s_printf var, int *i)
{
    char c;
    
    c = va_arg(argptr, int);
    if (var.width >= 0)
    {
        ft_width_trick(var.width - 1, ' ', i);
    }
    ft_putchar(c, i);
    if(var.width < 0)
    {
        ft_width_trick((var.width * -1) - 1, ' ', i);
    }
}

void    handle_per(s_printf var, int *i)
{
    if (var.width >= 0)
    {
        ft_width_trick(var.width - 1, ' ', i);
    }
    if (var.zerowidth1 >= 0)
         ft_width_trick(var.zerowidth1 - 1, '0', i);
    ft_putchar(var.specifier, i);
    if(var.width < 0)
        ft_width_trick((var.width * -1) - 1, ' ', i);
    if (var.zerowidth1 < 0)
         ft_width_trick((var.zerowidth1 * -1) - 1, ' ', i);
}

void    handle_percent(const char  **fmt, va_list argptr, int   *i)
{
    char *str;
    s_printf    var;
    int nbr;
    
    var = ft_getaftermod(fmt, argptr);
    
    if (var.specifier == 's')
    {
        str = va_arg(argptr,char *);
        handle_string(str, var, i);
    }
    else if (var.specifier == 'x' || var.specifier == 'X')
    {
        if (var.specifier == 'x')
            str = decToBinary(va_arg(argptr, int), 1);
        else
            str = decToBinary(va_arg(argptr, int), 0);
        handle_x(str, var, i);
    }
    else if (var.specifier == 'd' || var.specifier == 'i')
    {
        nbr = va_arg(argptr, int);
        handle_int(nbr, var, i);
    }
    else if (var.specifier == 'c')
        handle_char(argptr, var, i);
    else if (var.specifier == 'p')
    {
        str = decToBinary_p(va_arg(argptr, int), 1);
        handle_p(str, var, i);
    }
    else if (var.specifier == 'u')
        handle_int(va_arg(argptr, unsigned int), var ,i);
    else if (var.specifier == '%')
        handle_per(var, i);
    else
        ft_putchar(var.specifier, i);
}
