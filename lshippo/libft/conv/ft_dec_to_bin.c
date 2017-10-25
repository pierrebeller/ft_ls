/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_bin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 00:47:59 by heinfalt          #+#    #+#             */
/*   Updated: 2017/09/06 00:48:02 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char				*ft_dec_to_bin(unsigned int nbr)
{
	char			*ret;
	unsigned int	mod;

	mod = 2147483648;
	ret = ft_strdup("");
	while (mod)
	{
		if (nbr == nbr % mod)
			mod /= 2;
		else
		{
			while (mod)
			{
				if (nbr == nbr % mod)
					ret = ft_chrjoin_free(ret, '0', 1);
				else
				{
					ret = ft_chrjoin_free(ret, '1', 1);
					nbr = nbr % mod;
				}
				mod /= 2;
			}
		}
	}
	return (ret);
}
