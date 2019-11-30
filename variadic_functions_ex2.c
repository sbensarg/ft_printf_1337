/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadic_functions_ex2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 22:57:49 by sbensarg          #+#    #+#             */
/*   Updated: 2019/11/26 16:05:29 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

void printstr(int num, ...)
{
	va_list argptr;
	int count;
	char *ptr;
	count = 0;
	va_start(argptr, num);
	while(count < num)
	{
		ptr = va_arg(argptr, char *);
		printf("%s\n", ptr);
		count++;
	}

	va_end(argptr);
}
int main(void)
{
	printstr(3, "sara", "two", "bensarg");
}
