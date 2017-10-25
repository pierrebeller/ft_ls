/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 13:28:51 by heinfalt          #+#    #+#             */
/*   Updated: 2017/10/12 13:29:01 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
