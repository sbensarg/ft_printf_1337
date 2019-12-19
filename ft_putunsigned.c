/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 02:33:55 by sbensarg          #+#    #+#             */
/*   Updated: 2019/12/12 05:25:16 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putunsigned(unsigned int nb, int		*i)
{
	char	k;

	if (nb >= 10)
	{
		*i = *i + 1;
		ft_putunsigned(nb / 10, i);
		k = nb % 10 + 48;
		write(1, &k, 1);
	}
	else
	{
		*i = *i + 1;
		k = nb + 48;
		write(1, &k, 1);
	}
}