/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 15:56:23 by pbeller           #+#    #+#             */
/*   Updated: 2017/10/26 15:56:48 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

void		ft_putstr_free(char *str, int f)
{
	if (str)
	{
		write(1, str, ft_strlen(str));
		if (f)
			free(str);
	}
}
