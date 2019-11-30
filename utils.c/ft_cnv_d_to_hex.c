/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cnv_d_to_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 00:16:36 by sbensarg          #+#    #+#             */
/*   Updated: 2019/11/30 01:02:12 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
char *ft_caractere_add_front(char *string, char x)
{
	int i;
	int j;
	char *ptr;

	i = ft_strlen(string);
	ptr = malloc (i + 2);
	ptr[0] = x;
	i = 1;
	j = 0;
	while (string[j])
	{
		ptr[i] = string[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_cnv_d_to_hex(unsigned long long nbr)
{
	int		rmd;
	int		quotient;
	char	*ret;

	ret = NULL;
	if (!ret)
		ret = ft_strdup("");
	quotient = nbr /16;
	rmd = nbr % 16;
	while (quotient != 0)
	{
		if (rmd < 10)
			ret = ft_caractere_add_front(ret, rmd + '0');
		else if (rmd > 10)
			ret = ft_caractere_add_front(ret, rmd + 55);
		rmd = quotient % 16;
		quotient /= 16;
	};
	if (rmd < 10)
		ret = ft_caractere_add_front(ret, rmd + '0');
	else if (rmd > 10)
		ret = ft_caractere_add_front(ret, rmd + 55);
	return (ret);
}

int	main()
{
	int nbr = 1234566;
	char *hex;
	hex = ft_cnv_d_to_hex(12345681516);
	printf("%s", hex);
}
