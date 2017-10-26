/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 15:58:36 by pbeller           #+#    #+#             */
/*   Updated: 2017/10/26 15:58:38 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char		*ft_litoa(long long n)
{
	size_t	i;
	char	*str;

	i = ft_size_long(n);
	str = ft_strnew(i);
	if (str == NULL)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	else
		n = -n;
	while (i >= 1 && str[i - 1] != '-')
	{
		str[--i] = -(n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
