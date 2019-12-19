/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:43:10 by sbensarg          #+#    #+#             */
/*   Updated: 2019/12/19 17:52:34 by sbensarg         ###   ########.fr       */
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

int main(void)
{
	int t = 0;
	//t = ft_printf("%0d|\n", 200);
	//ft_printf("p2 %.10d\n", 55555);
	//printf("|%0*.*d|\n", 1, 10, -1);
	ft_printf("|%2.3d|\n", 100);
	printf("|%2.3d|\n", 100);
	//ft_printf("%083.92d|\n",  512090639);
	//printf("%020.*d|\n", -20,1);
	//printf("%083.92d|\n", 512090639);
	//printf("%020.55d|\n",1);
}
