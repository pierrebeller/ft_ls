/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 14:22:06 by pbeller           #+#    #+#             */
/*   Updated: 2017/10/26 14:22:07 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		*ft_x_malloc(int size)
{
	char *new;

	new = (char *)malloc(size);
	if (!new)
	{
		ft_putstr_fd("malloc error\n", 2);
		exit(1);
	}
	(void)size;
	return (new);
}
