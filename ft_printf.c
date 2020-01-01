/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:43:10 by sbensarg          #+#    #+#             */
/*   Updated: 2019/12/31 08:11:39 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *fmt, ...)
{
	va_list argptr;
	int printed_characters = 0;
	va_start(argptr, fmt);
	while (*fmt != '\0')
	{
		if (*fmt == '%' &&  *(fmt + 1) == '%')
		{
			ft_putchar('%', &printed_characters);
			fmt++;
		}
		else if (*fmt == '%' &&  *(fmt + 1) != '%')
			handle_percent(&fmt, argptr, &printed_characters);
		else
			ft_putchar(*fmt, &printed_characters);
		fmt++;
	}
	va_end(argptr);
	return (printed_characters);
}
/*
int main(void)
{
	printf("%d",ft_printf("|%*.s|", -20, "lfygdghfgdfgdfgc"));
	printf("%d",printf("|%*.s|", -20, "lfygdghfgdfgdfgc"));
	
}
*/