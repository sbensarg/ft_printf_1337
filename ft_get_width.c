/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 20:53:40 by sbensarg          #+#    #+#             */
/*   Updated: 2019/12/08 15:30:10 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_width(char *cmb)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	while (cmb[i] != '\0')
	{
		if (cmb[i] == '-' || (cmb[i] >= '0' && cmb[i] <= '9'))
			j++;
		if (j > 0 && cmb[i] != '-' && cmb[i] != '+'
				&& (cmb[i] < '0' || cmb[i] > '9'))
			break ;
		i++;
	}
	if (j > 0)
	{
		ret = malloc(j * sizeof(char) + 1);
		ret[j] = '\0';
		while (j-- >= 0)
			ret[j] = cmb[--i];
		return (ret);
	}
	return (NULL);
}
