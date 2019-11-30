/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:43:10 by sbensarg          #+#    #+#             */
/*   Updated: 2019/11/29 01:43:43 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include <unistd.h>

int		ft_printf(const char *format, ...)
{
	va_list argptr;
	int i = 0;
	va_start(argptr, format);
	while (*format != '\0')
	{
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			write(1, &format[i], 1);
		}
		else if (*format == 's')
		{

		}
		else if (*format == 'p')
		{

		}
		else if (*format == 'd')
		{

		}
		else if (*format == 'i')
		{

		}
		else if (*format == 'u')
		{

		}
		else if (*format == 'x')
		{

		}
		else if (*format == 'X')
		{

		}
				++i;
	}
	va_end(argptr);
	return (0);
}

int main(void)
{
	ft_printf("%c", "salam sara");
}
