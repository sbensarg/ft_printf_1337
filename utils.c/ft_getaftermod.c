/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getaftermod.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 00:08:25 by sbensarg          #+#    #+#             */
/*   Updated: 2019/11/30 01:47:54 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "../libft/libft.h"

char	*ft_getaftermod(char *cmb)
{
	int i;
	char *ret;

	i = 0;
	while(cmb[i] != '\0')
	{
		if (cmb[i] != 'i' && cmb[i] != 'd'
			&& cmb[i] != 'x' && cmb[i] != 'X' && cmb[i] != 's'
			&& cmb[i] != 'c' && cmb[i] != 'u' && cmb[i] != 'p'
			&& cmb[i] != '0' && cmb[i] != '.' && cmb[i] != '-'
			&& cmb[i] != '*')
		{
			break;
		}
		i++;
	}
	ret = malloc(i * sizeof(char) + 1);
	ret[i] = '\0';
	while (i-- >= 0)
		ret[i] = cmb[i];
	return (ret); 
}

int	main()
{
	printf("%s", ft_getaftermod(".....****cpsd"));
}

