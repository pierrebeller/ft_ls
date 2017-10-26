/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 15:59:51 by pbeller           #+#    #+#             */
/*   Updated: 2017/10/26 15:59:52 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

char		*ft_strchain(int c, int len)
{
	char	*ret;
	int		i;

	i = 0;
	ret = (char *)ft_memalloc(sizeof(char) * len + 1);
	while (i < len)
		ret[i++] = c;
	ret[i] = '\0';
	return (ret);
}
