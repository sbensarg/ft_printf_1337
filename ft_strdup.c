/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 04:03:49 by sbensarg          #+#    #+#             */
/*   Updated: 2019/12/23 22:18:19 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s1)
{
	char *dest;

	dest = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, s1, (ft_strlen(s1) + 1));
	return (dest);
}
