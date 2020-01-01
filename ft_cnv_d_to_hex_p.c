/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cnv_d_to_hex_p.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 22:16:04 by sbensarg          #+#    #+#             */
/*   Updated: 2019/12/30 22:23:07 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_del_zeros_p(char	*ret)
{
	char	*tmp;
	int	i;
	int	j;
	int k;

	i = 0;
	j = 0;
	if (ret[0] != '0')
		return (ret);
	while (ret[i] != '\0' && ret[i] == '0')
		i++;
	k = ft_strlen(ret) - i;
	tmp = malloc(k * sizeof(char) + 1);
	while (ret[i] != '\0')
	{
		tmp[j] = ret[i];
		i++;
		j++;
	}
	tmp[j] = '\0';
	return (tmp);
}

char *ft_convert_hex_p(char *ptr, int flag)
{
	char *ret;
	char *str;
	int i;
	int	j;
	int k;
	
	i = 0;
	k = 0;
	j = 0;
	str = malloc(17 * sizeof(char));
	while(i < 64)
	{
		ret = ft_substr(ptr, i, 4);
		k = ((ret[0] - 48) * 2 * 2 * 2) + ((ret[1] - 48) * 2 * 2)
		+ ((ret[2] - 48) * 2) + ((ret[3] - 48) * 1);
		if (k > 9 && flag == 1)
			str[j] = k + 87;
		else if(k > 9 && flag == 0)
			str[j] = k + 55;
		else
			str[j] = k + 48;
		j++;
		i += 4;
	}
	str[j] = '\0';
	str = ft_del_zeros_p(str);
	return(str);
}
void ft_rev_ta_p(char **arg)
{
	int i;
	int j;
	char *ret;
	char var;

	i = 0;
	j = 0;
	ret = *arg;
	while(ret[i] != '\0')
		i++;
	i--;
	while(i > j)
	{
		var = ret[i];
		ret[i] = ret[j];
		ret[j] = var;
		i--;
		j++;
	}
}

void	ft_neg_case_p(char **ret)
{
	char *ptr;
	int i;
	int	sign;
	
	i = 0;
	sign = 0;
	ptr = *ret;
	while(ptr[i] != '\0')
		i++;
	i--;
	while (i >= 0)
	{
		if (ptr[i] == '1' && sign == 0)
			sign = 1;
		else if (sign == 1)
		{
			if (ptr[i] == '1')
				ptr[i] = '0';
			else if (ptr[i] == '0')
				ptr[i] = '1';
		}
		i--;
	}
}
 
char	*decToBinary_p(long long n, int flag) 
{
	int		i;
	int		sign;
	char	*ret;

	i = 0;
	sign = 0;
	ret = malloc(65 * sizeof(char));
	if(n < 0 && (sign = 1))
		n = n * -1;
	if ( n == 0)
		return ft_strdup("0");
	while (n > 1)
	{
		ret[i] = n % 2 + 48;
		n = n / 2;
		i++;
	}
	ret[i++] = n + 48;
	while (i < 64)
		ret[i++] = '0';
	ret[i] = '\0';
	ft_rev_ta_p(&ret);
	if (sign == 1)
		ft_neg_case_p(&ret);
	ret = ft_convert_hex_p(ret, flag);
	return (ret);
}
