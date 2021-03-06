/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 21:17:38 by sbensarg          #+#    #+#             */
/*   Updated: 2019/12/29 21:53:49 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(long nb, int	*i)
{
	if (nb < 0)
	{
		ft_putchar('-', i);
		nb = nb * -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, i);
		ft_putchar((nb % 10) + '0', i);
	}
	else
		ft_putchar(nb + '0', i);
}
