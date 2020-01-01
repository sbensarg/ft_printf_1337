/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 03:48:24 by sbensarg          #+#    #+#             */
/*   Updated: 2020/01/01 04:12:37 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_int_first(long *nbr, s_printf *var, int *n, int *i)
{
	int l;

	if (*nbr == 0 && var->precision_width2 > -1)
		l = 0;
	else
		l = len_num(*nbr);
	if (*nbr < 0)
	{
		*nbr = *nbr * -1;
		*n = 1;
	}
	if (var->width > var->precision_width2 && var->precision_width2 >= l && *n == 0)
		ft_width_trick(var->width - var->precision_width2, ' ', i);
	else if (var->width > var->precision_width2 && var->precision_width2 >= l && *n == 1)
		ft_width_trick(var->width - var->precision_width2 - *n, ' ', i);
	else if (var->width > var->precision_width2 && var->precision_width2 < l)
		ft_width_trick(var->width - l, ' ', i);
	if (var->zerowidth1 > 0 && var->precision_width2 >= l && *n == 0)
		ft_width_trick(var->zerowidth1 - var->precision_width2, ' ', i);
	else if (var->zerowidth1 > 0 && var->precision_width2 >= l && *n == 1)
		ft_width_trick(var->zerowidth1 - var->precision_width2 - *n, ' ', i);
	else if (var->zerowidth1 > 0 && var->precision_width2 < l && var->precision_width2 >= 0)
		ft_width_trick(var->zerowidth1 - l, ' ', i);
	return (l);
}

void	handle_int(long nbr, s_printf var, int *i)
{
	int	lenstr;
	int	neg;

	neg = 0;
	lenstr = handle_int_first(&nbr, &var, &neg, i);
	if (neg == 1)
		ft_putchar('-', i);
	if (var.precision_width2 >= 0)
		ft_width_trick(var.precision_width2 - lenstr + neg, '0', i);
	if (var.zerowidth1 > 0 && var.precision_width2 < 0)
		ft_width_trick(var.zerowidth1 - lenstr, '0', i);
	if (lenstr == 0 && var.precision_width2 >= 0)
		len_num(nbr);
	else
		ft_putnbr(nbr, i);
	if (var.width < 0 && var.precision_width2 < (var.width * -1)
			&& lenstr >= var.precision_width2 && var.precision_width2 > 0)
		ft_width_trick((var.width * -1) - lenstr, ' ', i);
	else if (var.width < 0 && var.precision_width2 < (var.width * -1)
			&& lenstr < var.precision_width2 && var.precision_width2 > 0)
		ft_width_trick((var.width * -1) - var.precision_width2 - neg, ' ', i);
	else if (var.width < 0 && var.precision_width2 <= 0)
		ft_width_trick((var.width * -1) - lenstr, ' ', i);
	if (var.zerowidth1 < 0 && var.precision_width2 <= 0)
		ft_width_trick((var.zerowidth1 * -1) - lenstr, ' ', i);
}
